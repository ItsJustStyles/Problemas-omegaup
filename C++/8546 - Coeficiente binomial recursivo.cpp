#include <bits/stdc++.h>
using namespace std;

int coeficiente_binomial(int n, int k, int& valor){
    valor++;
    if(k == 0 || n == k){
        return 1;
    }else{
        return coeficiente_binomial(n-1,k,valor) + coeficiente_binomial(n-1,k-1,valor);
    }
}

int main(){
    int n,k,valor = 0;
    cin >> n >> k;
    
    int resultado = coeficiente_binomial(n,k,valor);
    cout << resultado << " " << valor;
}