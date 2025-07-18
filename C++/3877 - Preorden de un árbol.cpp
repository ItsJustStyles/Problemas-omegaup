#include <cstdio>
#include <vector>
using namespace std;

int arbol[100000];
int arbol_izq[100000];
int arbol_der[100000];
int nodos = 0;

int crear_nodo(int nodo){
    arbol[nodos] = nodo;
    arbol_izq[nodos] = -1;
    arbol_der[nodos] = -1;
    return nodos++;
}

void insertar_nodo(int raiz, int nodo){
    if(arbol[raiz] > nodo){
        if(arbol_izq[raiz] == -1){
            arbol_izq[raiz] = crear_nodo(nodo);
        }else{
            insertar_nodo(arbol_izq[raiz],nodo);
        }
    }else{
        if(arbol_der[raiz] == -1){
            arbol_der[raiz] = crear_nodo(nodo); 
        }else{
            insertar_nodo(arbol_der[raiz], nodo);
        }
    }
}


void preorden(int raiz, vector<int>& respuestas) {
  if (raiz == -1){
    return;
  }
  respuestas.push_back(arbol[raiz]);
  preorden(arbol_izq[raiz], respuestas);
  preorden(arbol_der[raiz], respuestas);
  
}



int main(){
    int n,m,padre;
    scanf("%d %d", &n, &padre);
    int raiz = crear_nodo(padre);
    vector<int> respuestas;
    n--;
    
    while(n--){
        int nodo;
        scanf("%d",&nodo);
        insertar_nodo(raiz, nodo);
    }

    preorden(raiz,respuestas);

    scanf("%d",&m);
     while(m--){
      int pregunta;
      bool validacion = false;
      scanf("%d",&pregunta);
      printf("%d\n", respuestas[pregunta-1]);
     }
}