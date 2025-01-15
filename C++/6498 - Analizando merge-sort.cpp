#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int resultado1,resultado2;

    resultado1 = (n/2) * log2(n);
    resultado2 = (n) * log2(n) - n + 1;
    cout << resultado1 << " " << resultado2; 


}