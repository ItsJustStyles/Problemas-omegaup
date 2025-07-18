#include<iostream>
#include<stack>
using namespace std;

int main(){
    int n;
    cin >> n;
    stack<int> pila;
    string accion;
    int numero;
    
    while(n--){
        cin >> accion;
        if(accion == "AGREGA"){
            cin >> numero;
            pila.push(numero);
        }else if(accion == "CONSUME"){
            int valor1 = pila.top(); 
            pila.pop();
            int valor2 = pila.top();
            pila.pop();
            int suma = valor1 + valor2;
            pila.push(suma);
        }else{
            cout << pila.top() << endl;
        }
}
}