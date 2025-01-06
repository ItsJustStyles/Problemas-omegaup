//RESUELTO MEDIANTE COUNTING SORT

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;  

    vector<int> edades(101, 0);  

    
    for (int i = 0; i < N; i++) {
        int edad;
        cin >> edad;
        edades[edad]++;  
    }

    
    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j < edades[i]; j++) {
            cout << i << " ";  
        }
    }
    cout << endl;

    return 0;
}