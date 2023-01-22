#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <cstdlib>


using namespace std;

fstream archivo;
fstream archivo_ordenado;

void ordenar(){
    archivo.open("proxies.txt", ios::in);
    archivo_ordenado.open("proxies_ordenadas.txt", ios::out);
    int contador=0;
    
    if(archivo.is_open()){
        string proxy, puerto;
        while(!archivo.eof()){
            string proxy_completo;
            if(archivo.is_open()){
                archivo>> proxy >> puerto;
                proxy_completo.append(proxy);
                proxy_completo.append(":");
                proxy_completo.append(puerto);
                cout<<proxy <<" -> "<< proxy_completo<< endl;;
                archivo_ordenado<<proxy_completo<<"\n";
                contador++;
                if(contador==10){
                    break;
                }
            }
        }
        cout<< contador;
    }
    else{
        cout<<"No se encontro el archivo "<< endl;
    }
}

int main(){
    ordenar();

}