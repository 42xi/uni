#include <string>
#include <ctime>
#include <iostream>

using namespace std;

// Aufzählungstyp für wählbare Objekte
// STEIN - 0, SCHERE - 1, PAPIER - 2
enum class Object
{
    ROCK,
    SCISSORS,
    PAPER
};

// Aufzählungstyp für mögliche Spielausgänge
enum class Result
{
    PLAYER_ONE_WINS,
    PLAYER_TWO_WINS,
    DRAW
};

// Struktur für einen Spieler bestehend aus Name und Wahl des Spielers
struct Player
{
    string name;
    Object choice;
};

// Name des Spielers eingeben
string insert_name()
{

    // HIER programmieren:
    // Den Namen des Spielers von der Konsole einlesen und zurückgeben
    // Tip: für das Einlesen eines Strings gibt es eine bestimmte Funktion, siehe auch Vorlesung Folie "Eine Zeile als String einlesen"
    string name;
    cout << "Name des Spielers: ";
    getline(cin, name);

    return name;
}

Object determine_choice(string choice)
{
    if (choice.compare("CoderunnerTestValueROCK") == 0)
    {
        return Object::ROCK;
    }
    else if (choice.compare("CoderunnerTestValueSCISSORS") == 0)
    {
        return Object::SCISSORS;
    }
    else if (choice.compare("CoderunnerTestValuePAPER") == 0)
    {
        return Object::PAPER;
    }
    else
    {
        // Den Computer zufällig waehlen lassen.

        // HIER beantworten Sie folgende Fragen:

        // Was bewirkt die funktion srand? Die Funktion setzt den Startwert Seed des Zufallsgenerators.

        // Warum wird hier die Zeit (time) als Eingabe für die Funktion srand verwendet? Initialisiert den Zufallszahlengenerator basierend auf der aktuellen Zeit. Das sorgt dafür, dass jedes Spiel unterschiedliche Zufallszahlen verwendet.

        // Wie funktioniert die funktion rand? Die rand-Funktion verwendet einen speziellen mathematischen Algorithmus, um Zufallszahlen zu erzeugen.

        // Warum wird hier modulo 3 verwendet? Das modulo 3 sorgt dafür, dass die Zahl im Bereich von 0 bis 2 liegt

        srand(static_cast<int>(time(nullptr)));
        int choice = rand() % 3;
        return static_cast<Object>(choice);
    }
}

// Die Wahl von Stein etc. als String zurückgeben lassen
string get_name(Object object)
{
    switch (object)
    {
    case Object::ROCK:
        return "Stein";
    case Object::SCISSORS:
        return "Schere";
    case Object::PAPER:
        return "Papier";
    default:
        // Rückgabe für unerwartete Fälle
        return "Unbekanntes Objekt";
    }
}

// Einen Text mit dem Namen des Spielers und seiner Wahl ausgeben
void print_choice(Player player)
{

    // HIER programmieren:
    // Auf der Konsole ausgeben, für welches Objekt sich der Spieler entschieden hat.
    // z.B.: "Computer hat das Objekt Schere gewählt"
    // TIP: Nutzen sie hierzu die Funktion get_name
    cout << player.name << " hat das Objekt " << get_name(player.choice) << " gewählt \n";
}

// Die Wahl des Spielers abfragen
Object choose()
{

    // HIER programmieren:
    // Die Wahl des Spielers von der Konsole einlesen und zurückgeben
    // Stellen sie sicher, dass es sich um eine gültige Wahl handelt!
    // TIP: Nutzen Sie dazu eine geeignete Schleife. Siehe auch Vorlesung Folie "Annehmende Schleifenanweisungen – Do"

    int z;

    do
    {
        cout << "Bitte Objektwahl eingeben (1 = Stein, 2 = Schere, 3 = Papier): ";
        cin >> z;
    } while (z < 1 || z > 3);

    return static_cast<Object>(z - 1);
}

Result determine_result(Player player_1, Player player_2)
{

    // HIER programmieren:
    // Vergleichen Sie die gewählten Objekte, ermitteln sie das Spielergebnis und geben sie es zurück.
    // TIP: Wenn Sie für den Vergleich mit ganzene Zahlen _rechnen_ wollen, dann nutzen sie den static_cast, siehe auch Vorlesung Folie "Casts in C++: Static_cast"

    if (player_1.choice == player_2.choice)
    {
        return Result::DRAW;
    }

    if ((player_1.choice == Object::ROCK && player_2.choice == Object::SCISSORS) ||
        (player_1.choice == Object::SCISSORS && player_2.choice == Object::PAPER) ||
        (player_1.choice == Object::PAPER && player_2.choice == Object::ROCK))
    {
        return Result::PLAYER_ONE_WINS;
    }

    return Result::PLAYER_TWO_WINS;
}

void print_result(Player player_1, Player player_2)
{

    // HIER programmieren:
    // Ermitteln Sie zunächst das Spielergebnis. Nutzen sie dazu die Funktion determine_result.
    // Geben Sie anschließend auf der Konsole aus, wer gewonnen hat.
    // z.B: "Spieler Computer hat gewonnen" oder "Unentschieden"
    Result result = determine_result(player_1, player_2);

    if (result == Result::DRAW)
    {
        cout << "Unentschieden" << endl;
    }
    else if (result == Result::PLAYER_ONE_WINS)
    {
        cout << "Spieler Computer hat gewonnen." << endl;
    }
    else
    {
        cout << "Spieler " << player_2.name << " hat gewonnen." << endl;
    }
}

int main(int argc, char *argv[])
{
    Player player_1, player_2;
    player_1.name = "Computer";
    player_2.name = insert_name();
    player_1.choice = determine_choice(player_2.name);
    cout << "Der Computer hat seine Wahl getroffen." << endl;
    player_2.choice = choose();
    print_choice(player_1);
    print_choice(player_2);
    print_result(player_1, player_2);

    return 0;
}
