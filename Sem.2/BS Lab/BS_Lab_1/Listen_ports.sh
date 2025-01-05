#!/bin/bash

# Funktion für die Hilfemeldung
function show_help {
    echo
    echo "Usage:  [-c | --command] [-u | --user] [-h | --help] [-q | --quit]"
    echo "-c oder --command  Startet den lsof Befehl"
    echo "-u oder --user  Gibt die User ID des Prozesses aus (mit ss)"
    echo "-h oder --help  Zeigt diese Hilfemeldung"
    echo "-q oder --quit  Beendet das Programm"
    echo
}

# do-while Schleife zur Eingabeüberprüfung
while true; do
    echo
    read -p "Bitte geben Sie einen Parameter ein ( [-c | --command] [-u | --user] [-h | --help] [-q | --quit] ): " input

    case $input in
        -q | --quit)
            echo "Programm beendet."
            break
            ;;
        -c | --command)
            echo "Starte lsof..."
            lsof -i -nP | grep TCP | awk '{print $1, $2, $3, $9}' | sort | uniq | head
            ;;
        -u | --user)
            echo "Zeige User IDs der Prozesse..."
            ss -au -t4ln| awk '{print $1, $5}' |grep -v State | sort | uniq | head
            ;;
        -h | --help)
            echo "Zeige Hilfetext..."
            show_help
            ;;
        *)
            # Wiederhole die Schleife bei falscher Eingabe
            echo "Ungültige Eingabe. Bitte -c, -u, -h oder -q eingeben."
            ;;
    esac
done