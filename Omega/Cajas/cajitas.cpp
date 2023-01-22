#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

class caja{
    private:
        int resistencia, num_caja;
    public:
        caja(){}
        caja(int _num_caja, int _resistencia){
            resistencia = _resistencia;
            num_caja = _num_caja;
        }
        virtual void mostrar(){
            cout<< num_caja <<" "<< resistencia<<" es una caja de: ";
        }
};

class caja_caucho : public caja{
    private:
        string tipo_caucho;
    public:
        caja_caucho(){}
        caja_caucho(int _num_caja, int _resistencia, string _tipo_caucho) : caja(_num_caja, _resistencia){
            tipo_caucho = _tipo_caucho;
        }
        void mostrar(){
            caja::mostrar();
            cout<< " " << tipo_caucho;
        }
};

class caja_metal : public caja{
    private:
        string tipo_metal;
    public:
        caja_metal(){}
        caja_metal(int _num_caja, int _resistencia, string _tipo_metal): caja(_num_caja, _resistencia){
            tipo_metal = _tipo_metal;
        }
        void mostrar(){
            caja::mostrar();
            cout<<" "<<tipo_metal;
        }
};

void cajas(){
    int n_cajas;
    cin>> n_cajas;
    caja* caja_o[n_cajas];
    //caja_o[0] = new caja_caucho(0, 1, "caucho");
    vector<caja*> cajitas;
    for(int i = 0; i < n_cajas; i++){
        int rest;
        cin>> rest;
        if((rest % 2) == 0){
            caja_o[i] = new caja_caucho(i, rest, "caucho");
            cajitas.push_back(caja_o[i]);
        }
        else{
            caja_o[i] = new caja_metal(i, rest, "metal");
            cajitas.push_back(caja_o[i]);
        }
        //caja_o[i]-> mostrar();
    }
    for(int i = 0; i < n_cajas; i++){
        cajitas[i]-> mostrar();
        // caja_o[i]-> mostrar();
        cout<< endl;
    }
}

int main(){
    cajas();
}