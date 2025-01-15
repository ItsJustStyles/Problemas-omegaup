#include <cstdio>
#include <vector>
using namespace std;

void generar_secuencia(int n, int inicio, vector<int>& secuencia, int& valor, vector<int>& validacion){
    if(secuencia.size() >= n){
        if(secuencia[0] == secuencia[n-1]){
            if(secuencia != validacion){
                validacion = secuencia;
                valor++;
                // for(int i = 0; i < n; i++){
                // printf("%d ",secuencia[i]);
                // }           
                // printf("\n");
            }
        }
        return;
    }
    
    secuencia.push_back(inicio);
    
    if(inicio > 0){
        generar_secuencia(n,inicio - 1, secuencia, valor, validacion);
    } 
    
    if(inicio < 9){
        generar_secuencia(n,inicio + 1, secuencia, valor, validacion);
    } 
        
    secuencia.pop_back();
    
}

int contar_secuencias(int n){
    int resultados = 0;
    for(int i = 0; i <= 9; i++){    
        vector<int> secuencia;
        vector<int> validacion;
        int valor = 0;
        generar_secuencia(n,i,secuencia,valor,validacion);
        resultados += valor;
    }
    return resultados;
}

int main(){
    int n;
    scanf("%d",&n);
    int resultado = contar_secuencias(n);
    printf("%d",resultado);
}