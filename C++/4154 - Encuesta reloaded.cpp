#include <bits/stdc++.h>
using namespace std;

struct persona{
    int id;
    string nombre;
    double peso;
    double estatura;
    double imc;
    
    //void calcular_imc(){
        //persona.imc = persona.peso / (persona.estatura*persona.estatura);
    //}
    
};    

void calcular_imc(persona &p) {
    p.imc = p.peso / (p.estatura * p.estatura);
}

bool ordenarIMC(const persona& a, const persona& b){
    return a.imc > b.imc;
}

int main(){
    int n;
    cin >> n;
    
    vector<persona> personas(n);
    for(int i = 0; i < n; i++){
        cin >> personas[i].id;
        cin.ignore();
        getline(cin,personas[i].nombre);
        cin >> personas[i].peso;
        cin >> personas[i].estatura;
        //personas[i].calcular_imc();
        calcular_imc(personas[i]);
    }
    
    sort(personas.begin(),personas.end(),ordenarIMC);
    
    for(const auto& i : personas){
        cout <<  i.id << " " << i.nombre << " " << fixed << setprecision(1) << i.imc << endl;
    }
}