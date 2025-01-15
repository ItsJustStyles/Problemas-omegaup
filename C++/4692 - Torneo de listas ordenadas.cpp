#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void torneo_binario(int L, int N, int K, vector<vector<int>>& listas) {
    vector<int> cabezas(L);
    vector<int> indices(L, 0);  // Para llevar el índice de cada lista

    // Inicializar las cabezas de las listas
    for (int i = 0; i < L; i++) {
        cabezas[i] = listas[i][0];
    }

    for (int k = 1; k < K; k++) {
        // Fase del torneo
        vector<int> ronda(L);
        vector<int> ganadores;  // Para almacenar los ganadores de esta ronda

        for (int i = 0; i < L; i++) {
            if (indices[i] < N) {
                ronda[i] = cabezas[i];
            } else {
                ronda[i] = numeric_limits<int>::max();  // Lista vacía
            }
        }

        // Imprimir el estado actual de las cabezas
        //for (int i = 0; i < L; i++) {
            //cout << (cabezas[i] != numeric_limits<int>::max() ? cabezas[i] : -1) << " ";
        //}
        //cout << endl;

        // Realizar el torneo
        for (int i = 0; i < L; i += 2) {
            if (ronda[i] != numeric_limits<int>::max() && ronda[i + 1] != numeric_limits<int>::max()) {
                if (ronda[i] < ronda[i + 1]) {
                    ganadores.push_back(ronda[i]);
                } else {
                    ganadores.push_back(ronda[i + 1]);
                }
            } else if (ronda[i] != numeric_limits<int>::max()) {
                ganadores.push_back(ronda[i]);
            } else {
                ganadores.push_back(ronda[i + 1]);
            }
        }

        // Imprimir los ganadores de esta ronda
        //for (int g : ganadores) {
            //cout << g << " ";
        //}
        //cout << endl;

        // Encontrar el mínimo de los ganadores
        int min_value = numeric_limits<int>::max();
        int min_index = -1;
        for (int i = 0; i < ganadores.size(); i++) {
            if (ganadores[i] < min_value) {
                min_value = ganadores[i];
                min_index = i;
            }
        }

        // Extraer el mínimo
        if (min_index != -1) {
            // Encontrar de qué lista proviene el ganador
            for (int i = 0; i < L; i++) {
                if (cabezas[i] == ganadores[min_index]) {
                    indices[i]++;  // Mover el índice de la lista
                    if (indices[i] < N) {
                        cabezas[i] = listas[i][indices[i]];
                    } else {
                        cabezas[i] = numeric_limits<int>::max();  // Lista vacía
                    }
                    break;
                }
            }
        }
    }
    
    
        vector<int> ronda(L);
        vector<int> ganadores;  // Para almacenar los ganadores de esta ronda
        
        for (int i = 0; i < L; i++) {
            if (indices[i] < N) {
                ronda[i] = cabezas[i];
            } else {
                ronda[i] = numeric_limits<int>::max();  // Lista vacía
            }
        }

        // Imprimir el estado actual de las cabezas
        for (int i = 0; i < L; i++) {
            cout << (cabezas[i] != numeric_limits<int>::max() ? cabezas[i] : -1) << " ";
        }
        cout << endl;
        
        
        

        while(true){
        // Realizar el torneo
        for (int i = 0; i < L; i += 2) {
            if (ronda[i] != numeric_limits<int>::max() && ronda[i + 1] != numeric_limits<int>::max()) {
                if (ronda[i] < ronda[i + 1]) {
                    ganadores.push_back(ronda[i]);
                } else {
                    ganadores.push_back(ronda[i + 1]);
                }
            } else if (ronda[i] != numeric_limits<int>::max()) {
                ganadores.push_back(ronda[i]);
            } else {
                ganadores.push_back(ronda[i + 1]);
            }
        }

        // Imprimir los ganadores de esta ronda
        for (int g : ganadores) {
            cout << g << " ";
        }  
        cout << endl;
        
        int min_value = numeric_limits<int>::max();
        int min_index = -1;
        for (int i = 0; i < ganadores.size(); i++) {
            if (ganadores[i] < min_value) {
                min_value = ganadores[i];
                min_index = i;
            }
        }

        // Extraer el mínimo
        if (min_index != -1) {
            // Encontrar de qué lista proviene el ganador
            for (int i = 0; i < L; i++) {
                if (cabezas[i] == ganadores[min_index]) {
                    indices[i]++;  // Mover el índice de la lista
                    if (indices[i] < N) {
                        cabezas[i] = listas[i][indices[i]];
                    } else {
                        cabezas[i] = numeric_limits<int>::max();  // Lista vacía
                    }
                    break;
                }
            }
        }
        
        
        if(ganadores.size() <= 1){
            break;
        }
        
        L = ganadores.size();
        ronda.clear();
        for(int i : ganadores){
            ronda.push_back({i});
        }
        ganadores.clear();


        


}
}




int main() {
    int L, N, K;
    cin >> L >> N >> K;
    vector<vector<int>> listas(L, vector<int>(N));

    // Leer las listas
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < N; j++) {
            cin >> listas[i][j];
        }
    }

    // Ejecutar el torneo
    torneo_binario(L, N, K, listas);

    return 0;
}
