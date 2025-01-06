#include <bits/stdc++.h>
using namespace std;


int menor_diferencia(vector<int>& postes,int n,int k){
    int minimo = numeric_limits<int>::max();
    for(int i = 0; i <= n-k; i++){
        int diferencia = postes[i+k-1] - postes[i];
        minimo = min(minimo, diferencia);
    }
    return minimo;
}


int partition(vector<int>& postes, int bajo, int alto){
    int pivote = postes[alto];
    int i = bajo - 1;
    for(int j = bajo; j <= alto - 1; j++){
        if(postes[j] < pivote){
            i++;
            swap(postes[i],postes[j]);
        }
    }
    swap(postes[i+1],postes[alto]);
    return i+1;
}

void quickSort(vector<int>& postes, int bajo, int alto){
    if(bajo < alto){
        int q = partition(postes,bajo,alto);
        quickSort(postes,bajo,q-1);
        quickSort(postes,q+1,alto);
    }
}

int main(){
    int k,n;
    cin >> k >> n;
    vector<int> postes(n);
    
    for(int i = 0; i < n; i++){
        cin >> postes[i];
    }
    
    quickSort(postes,0,n-1);
    int diferencia = menor_diferencia(postes,n,k);
    
    cout << diferencia << endl;

}