#include <iostream>
using namespace std;

int clave[1000000]; 
int izq[1000000]; 
int der[1000000];
int nodos=0;

int crear_nodo(int dato) {
  clave[nodos] = dato;
  izq[nodos] = -1;
  der[nodos] = -1;
  return nodos++;
}

void insertar_nodo(int nodo, int hijo, int& comparacion){
    if(clave[nodo] > hijo){
        comparacion++;
        if(izq[nodo] == -1){
            izq[nodo] = crear_nodo(hijo);
        }else{
            insertar_nodo(izq[nodo],hijo,comparacion);
        }
    }else{            
        comparacion++;
        if(der[nodo] == -1){
            der[nodo] = crear_nodo(hijo);
        }else{
            insertar_nodo(der[nodo],hijo, comparacion);
        }
    }
}


int main(){
    int n,inicio;
    cin >> n >> inicio;
    int raiz = crear_nodo(inicio);
    cout << 0 << endl;
    n--;
    
    while(n--){
        int nodo;
        cin >> nodo;
        int comparacion = 0;
        insertar_nodo(raiz,nodo,comparacion);
        cout << comparacion << endl;
    }
}