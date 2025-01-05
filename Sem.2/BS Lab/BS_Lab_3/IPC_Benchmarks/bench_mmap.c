#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <string.h>
#include <limits.h>
#include <sys/time.h>
#include <errno.h>

#define MEASUREMENTS 100 // Anzahl der Wiederholungen pro Größe
#define SLEEP_TIME 1

int main()
{
    const int sizes[] = {64, 256, 1024, 4096, 16384, 65536, 262144, 1048576, 4194304, 16777216};
    const int sizes_num = sizeof(sizes) / sizeof(sizes[0]);
#define MAX_SIZE sizes[sizes_num - 1]

    char *anon;
    struct timeval tv_start, tv_stop;

    // Datei zum Speichern der Ergebnisse öffnen
    FILE *file = fopen("results_mmap.csv", "w");
    if (!file)
    {
        perror("Fehler beim Öffnen der Datei");
        exit(EXIT_FAILURE);
    }
    // Kopfzeile schreiben
    fprintf(file, "Size (Bytes), Bandwidth (MB/s)\n");

    // Anonyme Shared Memory Map erstellen
    anon = mmap(NULL, MAX_SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_SHARED, -1, 0);
    if (anon == MAP_FAILED)
    {
        perror("Fehler bei mmap");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    printf("Memory map erfolgreich erstellt.\n");

    for (int i = 0; i < sizes_num; i++)
    {
        int current_size = sizes[i];
        double time_sum = 0.0;

        sleep(SLEEP_TIME); // Kurze Pause

        // Messungen durchführen
        for (int j = 0; j < MEASUREMENTS; j++)
        {
            gettimeofday(&tv_start, NULL);   // Startzeit messen
            memset(anon, 'a', current_size); // Speicher beschreiben
            gettimeofday(&tv_stop, NULL);    // Endzeit messen

            // Zeitdifferenz in Mikrosekunden berechnen
            time_sum += ((tv_stop.tv_sec - tv_start.tv_sec) * 1000000.0 +
                         (tv_stop.tv_usec - tv_start.tv_usec));
        }

        // Durchschnittliche Zeit und Bandbreite berechnen
        double avg_time = time_sum / MEASUREMENTS;                              // Durchschnittszeit in µs
        double bandwidth = (current_size / avg_time) * 1e6 / (1024.0 * 1024.0); // Bandbreite in MB/s

        // Ergebnisse in die Datei schreiben
        fprintf(file, "%d, %.2f\n", current_size, bandwidth);
        fflush(file); // Sicherstellen, dass die Daten direkt geschrieben werden
        printf("Größe: %d Bytes, Bandbreite: %.2f MB/s gespeichert.\n", current_size, bandwidth);
    }

    // Speicher freigeben
    if (munmap(anon, MAX_SIZE) != 0)
    {
        perror("Fehler beim Freigeben des Speichers");
    }

    // Datei schließen
    if (fclose(file) != 0)
    {
        perror("Fehler beim Schließen der Datei");
        exit(EXIT_FAILURE);
    }
    printf("Ergebnisse erfolgreich in results_mmap.csv gespeichert.\n");

    return 0;
}
