#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class numero{
    private:
        string numerito;
        int veces, iteraciones;
        friend int buscar(string numerito, vector<string> numeritos, int posi);
        friend void veces();
        friend void elimin(vector<numero>& numeros);
        friend int veces_(vector<numero> numerosi);
    public:
        numero(){}
        numero(string _numerito,int _iteraciones, int _veces){
            numerito=_numerito;
            this->iteraciones=_iteraciones;
            this->veces=_veces;
        }

        static bool comparar(numero &a, numero &b){
            return a.iteraciones < b.iteraciones;
        }

        static bool comparar1(numero &a, numero &b){
            return a.veces > b.veces;
        }
};

void veces();
int buscar(string numerito, vector<string> numeritos, int posi);
int buscar_puntos(string numerito, vector<string> numeritos);
void eliminar_repe(vector<string> numeritos, int veces);
int retornar_veces(string numero, vector<string> numeritos);
void elimin(vector<numero>& numeros);
int veces_(vector<numero> numerosi);

int main(){
    veces();
    return 0;
}

int buscar_puntos(string numerito, vector<string> numeritos){
    int contador = 0;
    int j = 0;
    for(int i = 0; i < numeritos.size(); i++){
        if(numerito == numeritos[j++]){
            contador++;
        }
        if(contador == 1){
            break;
        }
        
    }
    //cout<< numerito <<" : "<< j << endl;
    return j;
}

int retornar_veces(string numero, vector<string> numeritos){
    int contador = 0;
    for(int i = 0; i < numeritos.size(); i++){
        if(numero == numeritos[i]){
            contador++;
        }
    }
    return contador;
}

int buscar(string numerito, vector<string> numeritos, int posi){
    int contador=0;
    int contador1=0;
    //cout<< endl;
    for(int i = posi; i < numeritos.size(); i++){
        contador1++;
        if(numerito==numeritos[i]){
            contador++;
            //numeritos.erase(numeritos.begin()+i);
        }
        if(contador >= 1) break;
    }
    //cout<< numerito <<"  "<< contador1 <<" <- ->" << contador;
    return contador1;
}

void veces(){
    int cantidad;
    cin>>cantidad;
    numero* nv_numero = new numero[cantidad];
    vector<string> numeros;
    vector<string> copy_numeros;
    vector<numero> lista_numeros;
    for(int i = 0; i < cantidad; i++){
        string numero;
        cin>>numero;
        numeros.push_back(numero);
    }
    copy_numeros=numeros;

    //buscar(numeros[0],numeros,cantidad);
    cout<< endl;
    
    for(int i = 0; i < numeros.size(); i++){
        int posicion, iteraciones;
        //cout<< copy_numeros[i] << endl;
        //cout<< copy_numeros[i] <<" veces: "<<buscar(numeros[i],copy_numeros,cantidad) << endl;
        posicion=buscar_puntos(numeros[i], copy_numeros);
        //cout<< posicion << endl;
        iteraciones = buscar(numeros[i], copy_numeros, posicion);
        //cout<< retornar_veces(numeros[i],copy_numeros);
        nv_numero[i] = numero(numeros[i],iteraciones,retornar_veces(numeros[i],copy_numeros));
        lista_numeros.push_back(nv_numero[i]);
    }
    cout<< endl;
    for(int i = 0; i < lista_numeros.size(); i++){
        cout<< lista_numeros[i].numerito << " "<< lista_numeros[i].iteraciones<<"  "<<lista_numeros[i].veces << endl;
    }
    cout<< endl;
    elimin(lista_numeros);
    sort(lista_numeros.begin(),lista_numeros.end(),numero::comparar);
    sort(lista_numeros.begin(),lista_numeros.end(),numero::comparar1);
    for(int i = 0; i < lista_numeros.size(); i++){
        cout<< lista_numeros[i].numerito << " "<< lista_numeros[i].iteraciones<<"  "<<lista_numeros[i].veces << endl;
    }
    cout<< "El numero: " << lista_numeros[0].numerito << " fue llamado "<< lista_numeros[0].veces << " veces y fue el primero " << endl;
    cout<< veces_(lista_numeros) << " telefonos fueron llamados " << 2 <<" veces " << endl;
}
void elimin(vector<numero>& numeros){
    vector<numero> numeros_sin;
    for(int i = 0; i < numeros.size(); i++){
        int contador = 0, contador1 = 0;
        for(int j = i; j < numeros.size(); j++){
            if(numeros[i].numerito == numeros[j].numerito){
                contador++;
            }
        }
        for(int j = 0; j < numeros.size(); j++){
            if(numeros[i].numerito == numeros[j].numerito){
                contador1++;
            }
        }
        if(contador == 2 || contador1 == 1){
            numeros_sin.push_back(numeros[i]);
        }
        //cout<< numeros[i].numerito <<" "<< contador << endl;
    }
    cout<< endl;
    numeros = numeros_sin;/*
    for(int i = 0; i < numeros_sin.size(); i++){
        cout<< numeros_sin[i].numerito << numeros_sin[i].iteraciones<<" "<<numeros_sin[i].veces << endl;
    }*/
}
int veces_(vector<numero> numerosi){
    //cout<< numerosi[0].veces;
    int contador = 0;
    for(int i = 0; i < numerosi.size(); i++){
        if(numerosi[i].veces == 2){
            contador++;
            //cout<< numerosi[i].veces << " ";
        }
    }
    return contador;
}