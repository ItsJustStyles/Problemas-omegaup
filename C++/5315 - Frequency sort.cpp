#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int N, C;
    cin >> N >> C; 

    vector<int> numeros(N);
    unordered_map<int, int> frecuencia; // Mapa para contar frecuencias
    vector<int> orden; // Vector para mantener el orden de aparición

    // Leer los números y contar sus frecuencias
    for (int i = 0; i < N; i++) {
        cin >> numeros[i];
        if (frecuencia[numeros[i]] == 0) {
            orden.push_back(numeros[i]); // Agregar al orden si es la primera aparición
        }
        frecuencia[numeros[i]]++;
    }

    // Ordenar los números según la frecuencia y el orden de aparición
    sort(numeros.begin(), numeros.end(), [&](int a, int b) {
        if (frecuencia[a] != frecuencia[b]) {
            return frecuencia[a] > frecuencia[b]; // Ordenar por frecuencia
        }
        return find(orden.begin(), orden.end(), a) < find(orden.begin(), orden.end(), b); // Ordenar por orden de aparición
    });

    // Imprimir los números ordenados
    for (int i = 0; i < N; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    return 0;
}