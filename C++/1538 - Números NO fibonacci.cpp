#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n){
    if(n <= 1){
        return n;
    }else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> numeros;
    for(int i = 1; i < n; i++){
        if(fibonacci(i) > n){
            break;
        }else{
            numeros.push_back(fibonacci(i));
        }
    }
    
    for(int i = 1; i < n; i++){
        if(find(numeros.begin(),numeros.end(),i) == numeros.end()){
            cout << i << " ";
        }
    }
    
}