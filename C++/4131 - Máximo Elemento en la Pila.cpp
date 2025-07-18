#include <iostream>
#include<stack>
using namespace std;
// Monticulos:

long long monticulo[1000000];
int N = 0;

void insertar(long long monticulo[], long long clave){
   long long i, k;
   i = N++;
   monticulo[i] = clave;
   while( i > 0 && monticulo[(i-1)/2] < monticulo[i]) {
    k = monticulo[(i-1)/2];
    monticulo[(i-1)/2] =  monticulo[i];
    monticulo[i] = k ;
    i = (i-1) / 2;
    }

}

long long eliminar(long long monticulo[]){
    int i,k,r;
    r = monticulo[0];
    N--;
    monticulo[0] = monticulo[N];
    i = 0;
    while(2*i+1<N){
        if(2*i+2 < N && monticulo[2*i+2] > monticulo[2*i+1]){
            k = 2*i+2;
        }else{
            k = 2*i+1;
        }
        if(monticulo[k] > monticulo[i]){
            i = k;
            k = monticulo[(i-1)/2];
            monticulo[(i-1)/2] = monticulo[i];
            monticulo[i] = k;
        }else{
            break;
        }
    }
    return r;
}


int main(){
    long long n;
    cin >> n;
    stack<long long> pila;
    while(n--){
        long long accion, numero;
        cin >> accion;
        if(accion == 1){
            cin >> numero;
            pila.push(numero);
            if(N == 0 || numero >= monticulo[0]){
                insertar(monticulo,numero);
            }
            
         }
        else if(accion == 2){
            if(pila.top() == monticulo[0]){
                eliminar(monticulo);
            }
            pila.pop();
        }else{
            cout << monticulo[0] << endl;
        }
    }
    return 0;
}