#include <bits/stdc++.h>
using namespace std;

int main(){  
  string input;
  while(getline(cin,input)){
      if(input.empty()){
          break;
      }

  int dia,mes,ano;
  stringstream ss(input);
  char delimiter;
    // Si fuera en lugar de / un espacio se haria de igual forma pero borrando la linea char delimiter;
    // y quitarlo de los demás lugares donde aparece, quedando asi:
    // ss >> dia >> mes >> ano;
  ss >> dia >> delimiter >> mes >> delimiter >> ano;
  if(ano >= 74){
    cout << dia << "/" << mes << "/19" << ano << endl;
  }else
  {
    cout << dia << "/" << mes << "/20" << ano << endl;
  }  
    }

  
}