#include <bits/stdc++.h>
using namespace std;


int particion(vector<int>& numeros,int bajo,int alto){
    int p = numeros[alto];
    int i = bajo-1;
    for(int j = bajo; j < alto; j++){
        if(numeros[j] <= p){
            i++;
            swap(numeros[i], numeros[j]);
            
        }
    }
    swap(numeros[i+1],numeros[alto]);
    return i + 1;
}

void quicksort(vector<int>& numeros,int bajo,int alto){
    if(bajo < alto){
        int q = particion(numeros,bajo,alto);
        quicksort(numeros,bajo,q-1);
        quicksort(numeros,q+1,alto);
    }
}


int main(){
    int n;
    cin >> n;
    
    vector<int> numeros(n);
    for(int i = 0; i < n; i++){
        cin >> numeros[i];
    }       
    
    quicksort(numeros,0,n-1);
    
    for(int i : numeros){
       cout << i << " "; 
    }
}