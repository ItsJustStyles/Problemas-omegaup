#include <cstdio>
#include <string>
#include <cstring>
#include <list>
#include <iterator>
using namespace std;

int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    list<int> numeros;

    for(int i = 0; i < n; i++){
        numeros.push_back(i);
    }    
    list<int>::iterator it = numeros.begin();
    
    while(m--){
       char accion[100];
       int recorrerOagregar;
       
       scanf("%s", accion);
       if(strcmp(accion,"AVANZA")== 0){
           scanf("%d",&recorrerOagregar);
           advance(it,recorrerOagregar);
       }else if(strcmp(accion,"INSERTA_ATRAS")== 0){
           scanf("%d",&recorrerOagregar);
           numeros.insert(it,recorrerOagregar);
       }else{
           scanf("%d",&recorrerOagregar);
           numeros.erase(prev(it));
       }
       
    }
    
    list<int>::iterator start = numeros.begin();
    while (start != it) {
        printf("%d ", *start);
        ++start;
    }
    printf("\n");
    printf("%d\n",*it);

    list<int>::iterator end = numeros.end();
    start = next(it);
    
    while(start != end){
        printf("%d ",*start);
        ++start;
    }
    return 0;
}