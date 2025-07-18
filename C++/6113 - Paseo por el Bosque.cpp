#include <cstdio>
using namespace std;

int arbol[100000];
int arbol_izq[100000];
int arbol_der[100000];
int nodos = 0;

int crear_nodo(int padre){
    arbol[nodos] = padre;
    arbol_izq[nodos] = -1;
    arbol_der[nodos] = -1;
    return nodos++;
}

void insertar_nodo(int raiz, int nodo){
    if(arbol[raiz] > nodo){
        if(arbol_izq[raiz] == -1){
            arbol_izq[raiz] = crear_nodo(nodo);
        }else{
            insertar_nodo(arbol_izq[raiz], nodo);
        }
    }else{
        if(arbol_der[raiz] == -1){
            arbol_der[raiz] = crear_nodo(nodo);
        }else{
            insertar_nodo(arbol_der[raiz], nodo);
        }
    }
}

void preorden(int raiz){
    if(raiz == -1){
        return;
    }
    printf("%d ", arbol[raiz]);
    preorden(arbol_izq[raiz]);
    preorden(arbol_der[raiz]);
}

void orden(int raiz){
    if(raiz == -1){
        return;
    }
    orden(arbol_izq[raiz]);
    printf("%d ", arbol[raiz]);
    orden(arbol_der[raiz]);
}

void postorden(int raiz){
    if(raiz == -1){
        return;
    }
    postorden(arbol_izq[raiz]);
    postorden(arbol_der[raiz]); 
    printf("%d ", arbol[raiz]);
}

int main(){
    int n,padre;
    scanf("%d %d",&n, &padre);
    int raiz = crear_nodo(padre);
    n--;
    while(n--){
        int nodo;
        scanf("%d", &nodo);
        insertar_nodo(raiz, nodo);
    }
    
    preorden(raiz);
    printf("\n");
    orden(raiz);
    printf("\n");
    postorden(raiz);
    return 0;
}