#include <iostream>

using namespace std;

int main()
{

    int n;
    do
    {

        // Anzahl der Zahlen
        cout << "Anzahl eingeben: \n";
        cin >> n;
    } while (n < 0 || n > 10);

    int arr[10]; // Array
    double summe = 0;

    // Zahlen lesen
    for (int i = 0; i < n; i++)
    {
        cout << "Zahl eingeben: \n";
        cin >> arr[i];
        summe += arr[i];
    }

    // Zahlen ausgeben
    for (int i = 0; i < n; i++)
    {
        cout << "Zahl[" << i << "]: " << arr[i] << '\n';
    }

    // Durchschnitt berechnen und ausgeben
    double durchschnitt = summe / n;
    cout << "Durchschnitt: " << durchschnitt << '\n';

    return 0;
}
