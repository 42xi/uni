#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/time.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h> // Für wait()

#define MEASUREMENTS 1000 // Anzahl der Wiederholungen pro Paketgröße

int main()
{
    // Paketgrößen: von 64 Bytes bis 16 MB
    const int sizes[] = {64, 256, 1024, 4096, 16384, 65536, 262144, 1048576, 4194304, 16777216};
    const int sizes_num = sizeof(sizes) / sizeof(sizes[0]);
    int pipe_fd[2]; // Dateideskriptoren für die Pipe
    pid_t pid;
    char *buffer;
    struct timeval tv_start, tv_stop;

    // Datei zum Speichern der Ergebnisse öffnen
    FILE *file = fopen("results_pipe.csv", "w");
    if (!file)
    {
        perror("Fehler beim Öffnen der Datei");
        exit(EXIT_FAILURE);
    }

    // Kopfzeile nur einmal schreiben
    fprintf(file, "Size (Bytes), Bandwidth (MB/s)\n");
    printf("Kopfzeile erfolgreich geschrieben.\n");

    // Pipe erstellen
    if (pipe(pipe_fd) == -1)
    {
        perror("Fehler beim Erstellen der Pipe");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    pid = fork(); // Kindprozess erstellen
    if (pid == -1)
    {
        perror("Fehler beim Erstellen des Kindprozesses");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        // Kindprozess: Lesen
        close(pipe_fd[1]);                     // Schreib-Ende schließen
        buffer = malloc(sizes[sizes_num - 1]); // Maximalgröße reservieren
        if (!buffer)
        {
            perror("Fehler beim Allozieren des Puffers");
            close(pipe_fd[0]);
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < sizes_num; i++)
        {
            int size = sizes[i];
            for (int j = 0; j < MEASUREMENTS; j++)
            {
                if (read(pipe_fd[0], buffer, size) != size)
                {
                    perror("Fehler beim Lesen aus der Pipe");
                    free(buffer);
                    close(pipe_fd[0]);
                    exit(EXIT_FAILURE);
                }
            }
        }
        free(buffer);
        close(pipe_fd[0]); // Lese-Ende schließen
        exit(EXIT_SUCCESS);
    }
    else
    {
        // Elternprozess: Schreiben
        close(pipe_fd[0]);                     // Lese-Ende schließen
        buffer = malloc(sizes[sizes_num - 1]); // Maximalgröße reservieren
        if (!buffer)
        {
            perror("Fehler beim Allozieren des Puffers");
            fclose(file);
            close(pipe_fd[1]);
            exit(EXIT_FAILURE);
        }
        memset(buffer, 'A', sizes[sizes_num - 1]); // Puffer mit Daten füllen

        for (int i = 0; i < sizes_num; i++)
        {
            int size = sizes[i];
            double time_sum = 0.0;

            for (int j = 0; j < MEASUREMENTS; j++)
            {
                gettimeofday(&tv_start, NULL); // Startzeit messen
                if (write(pipe_fd[1], buffer, size) != size)
                {
                    perror("Fehler beim Schreiben in die Pipe");
                    free(buffer);
                    fclose(file);
                    close(pipe_fd[1]);
                    exit(EXIT_FAILURE);
                }
                gettimeofday(&tv_stop, NULL); // Endzeit messen

                // Zeitdifferenz in Mikrosekunden berechnen
                time_sum += ((tv_stop.tv_sec - tv_start.tv_sec) * 1000000.0 +
                             (tv_stop.tv_usec - tv_start.tv_usec));
            }

            // Durchschnittliche Zeit und Bandbreite berechnen
            double avg_time = time_sum / MEASUREMENTS;                      // Durchschnittszeit in µs
            double bandwidth = (size / avg_time) * 1e6 / (1024.0 * 1024.0); // Bandbreite in MB/s

            // Nur Messwerte speichern
            if (fprintf(file, "%d, %.2f\n", size, bandwidth) < 0)
            {
                perror("Fehler beim Schreiben in die Datei");
                free(buffer);
                fclose(file);
                close(pipe_fd[1]);
                exit(EXIT_FAILURE);
            }
            fflush(file); // Sicherstellen, dass die Daten sofort geschrieben werden
            printf("Größe: %d Bytes, Bandbreite: %.2f MB/s gespeichert.\n", size, bandwidth);
        }

        free(buffer);
        close(pipe_fd[1]); // Schreib-Ende schließen
        wait(NULL);        // Auf Kindprozess warten
    }

    // Datei schließen
    if (fclose(file) != 0)
    {
        perror("Fehler beim Schließen der Datei");
        exit(EXIT_FAILURE);
    }
    printf("Datei erfolgreich geschlossen.\n");

    return 0;
}
