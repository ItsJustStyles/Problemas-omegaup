#include<cstdio>
#include<queue>
#include<stack>
#include<string>
using namespace std;

int main(){
    int n;
    queue<string> cola;
    stack<string> pila;
    
    scanf("%d",&n);
    
    while(n > 0){
        char letra; int numero; char nombre[100];
        scanf(" %c %d",&letra, &numero);
        if(letra == 'E'){
            scanf("%s",nombre);
            if(numero == 1){
                cola.push(nombre);
            }else{
                pila.push(nombre);
            }
        }else{
            if(numero == 1){
                printf("%s\n",cola.front().c_str());
                cola.pop();
            }else{
                printf("%s\n",pila.top().c_str());
                pila.pop();
        }
        
       
    } 
        n--;
    }
}