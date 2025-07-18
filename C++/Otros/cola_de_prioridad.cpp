#include <bits/stdc++.h>
using namespace std;

void cola_de_prioridad(){
    priority_queue<int> cola;    
    char entrada[10];
    while(true){
       cin >> entrada;
       if(entrada[2] == 'd'){
           break;
       }else if(entrada[0] == 'i'){
           int n;
           cin >> n;
           cola.push(n);
       }else{
           cout << cola.top() << endl;
           cola.pop();
       }
    }
}

int main(){
    cola_de_prioridad();
    return 0;
}