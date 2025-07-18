#include <iostream>
using namespace std;
// Monticulos
int monticulo[100];
int N = 0;
int tapia;

void insertar(int monticulo[], int clave){
    int i, k;
    i = N++;
    monticulo[i] = clave;
    while(i > 0 && monticulo[(i-1)/2] < monticulo[i]){
        k = monticulo[(i-1)/2];
        monticulo[(i-1)/2] = monticulo[i];
        monticulo[i] = k;
        i = (i-1)/2;
    }
}

int eliminar(int monticulo[]){
    int i,k,r;
    r = monticulo[0];
    N--;
    monticulo[0] = monticulo[N];
    i = 0;
    while(2*i+1 < N){
        if(2*i+1 < N && monticulo[2*i+2] > monticulo[2*i+1]){
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
    int n;
    cin >> n; n--;
    cin >> tapia;
    int cuenta_de_sobornos = 0;
    
    while(n--){
        int competidores;
        cin >> competidores;
        insertar(monticulo, competidores);
    }

    while(true){
        if(tapia > monticulo[0]){
            break;
        }else{
            int soborno = monticulo[0];
            eliminar(monticulo);
            while(true){
                if(tapia > soborno){
                    break;
                }else{
                   if(soborno >= monticulo[0]){
                        soborno--;
                        tapia++;
                        cuenta_de_sobornos++;
                   }else{
                       insertar(monticulo, soborno);
                       soborno = monticulo[0];
                       eliminar(monticulo);
                   } 
                }
            }
        }
    }
    cout << cuenta_de_sobornos;
    return 0;
}