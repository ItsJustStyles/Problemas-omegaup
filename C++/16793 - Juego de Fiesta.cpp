#include <iostream>
#include <vector>
using namespace std;
int maxNum = 10000000;
void criba(vector<bool>& numerosPrimos){
    for(int i = 2; i*i <= maxNum; i++){
        if(numerosPrimos[i]){
            for(int j = i*i; j <= maxNum; j += i){
                numerosPrimos[j] = false;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<bool> numerosPrimos(maxNum + 1, true);
    numerosPrimos[0] = false;
    numerosPrimos[1] = false;
    criba(numerosPrimos);
    int mayorNum = 1;
    int contador = 0;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(numerosPrimos[num]){
            contador++;
            if(mayorNum < num){
                mayorNum = num;
            }
        }
    }
    cout << mayorNum << " " << contador << endl;
}