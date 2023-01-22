#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

void elimin(){
    vector<string> numeros;
    vector<string> numeros_sin;
    int cantidad;
    cin>> cantidad;
    for(int i = 0; i < cantidad; i++){
        string numero;
        cin>> numero;
        numeros.push_back(numero);
    }
    cout<< endl;
    //int j = 0;
    for(int i = 0; i < cantidad; i++){
        int contador = 0, contador1 = 0;
        for(int j = i; j < cantidad; j++){
            if(numeros[i] == numeros[j]){
                contador++;
            }
        }
        for(int j = 0; j < cantidad; j++){
            if(numeros[i] == numeros[j]){
                contador1++;
            }
        }
        if(contador == 2 || contador1 == 1){
            numeros_sin.push_back(numeros[i]);
        }
        cout<< numeros[i] <<" "<< contador << endl;
    }
    cout<< endl;
    for(int i = 0; i < numeros_sin.size(); i++){
        cout<< numeros_sin[i] << endl;
    }
}

int main(){
    elimin();
}