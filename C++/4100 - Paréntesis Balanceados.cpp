#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    while(n--){
        string parentesis;
        queue<char> cola;
        stack<char> pila;
        
        cin >> parentesis;
        int validacion = 1;
        
        for(int i = 0; i < parentesis.size(); i++){
            if(parentesis[i] == '[' || parentesis[i] == '{' || parentesis[i] == '('){
                pila.push(parentesis[i]);
            }else{
                if(pila.empty()){
                    validacion = 0;
                    break;
                }
                
                cola.push(parentesis[i]);           
                if(pila.top() == '(' && cola.front() == ')' ||
                pila.top() == '[' && cola.front() == ']' ||
                pila.top() == '{' && cola.front() == '}'){
                cola.pop();
                pila.pop();
                
           }else{
               validacion = 0;
               break;
           }
                
        }
    }

        if(validacion == 1 && pila.empty()){
        cout << "SI" << endl;
        }
        else{
        cout << "NO" << endl;
        }
    }
}