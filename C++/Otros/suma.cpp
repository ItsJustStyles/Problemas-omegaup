#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

//Este problema es uno clasico y es el subset sum partition problem. Esta versión es en c++.
int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    int sumaTotal = 0;

    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
        sumaTotal += numbers[i];
    }

    int objetivo = sumaTotal / 2;
    unordered_set<int> posibles;
    posibles.insert(0);

    for (int number : numbers) {
        unordered_set<int> nuevos;
        for (int suma : posibles) {
            if (suma + number <= objetivo) {
                nuevos.insert(suma + number);
            }
        }
        posibles.insert(nuevos.begin(), nuevos.end());
    }

    int mejorSuma = 0;
    for (int suma : posibles) {
        if (suma > mejorSuma) {
            mejorSuma = suma;
        }
    }

    cout << (sumaTotal - 2 * mejorSuma) << endl;

    return 0;
}
