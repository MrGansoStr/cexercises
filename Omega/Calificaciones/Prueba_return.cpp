#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

void retornar();
bool swish(float& nota);
void ret_nota(float& nota);
void ret_nombre(string& nombre);
void anterior_posi();
void recibir();
int aprobados(vector<float> noti);
int desaprobados(vector<float> noti);

int main(){
    //retornar();
    //anterior_posi();
    recibir();
}

void recibir(){
    vector<string> nombres;
    vector<float> notas;
    int cantidad, error;
    float suma, promedio=0;
    cin>> cantidad;
    for(int i = 0 ; i < cantidad; i++){
        point1:
        fflush(stdin);
        string nombre;
        float nota;
        cout<< endl;
        ret_nombre(nombre);
        cout<< endl;
        point2:
        ret_nota(nota);
        if(nota<0 || nota>101.0){
            cout<<"UPS, ERROR!, DIGITE DE NUEVO LA CALIFICACION DE "<< nombre << endl; 
            error=i;
            goto point2;
            fflush(stdin);
            cin.ignore('\n');
            cout<<"Si es mayor" << nota << endl;
            cout<< nota << endl;
        }
        cout<< endl;
        nombres.push_back(nombre);
        notas.push_back(nota);
        promedio+=(notas[i]/cantidad);
        cout<< endl;
        if(swish(nota)==false){
            cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<< endl;
            nombres.erase(nombres.begin()+i);
            notas.erase(notas.begin()+i);
            goto point1; 
        }
    }

    for(int j = 0; j < cantidad; j++){
        cout<< nombres[j] <<"\t"<< notas[j] << endl;
    }
    cout<<"Hay un problema con " << nombres[error] << endl; 
    cout<<"El promedio es: "<< promedio <<endl;
    cout<<"Cantidad de aprobados: "<< aprobados(notas) << endl;
    cout<<"Cantidad de desaprobados: "<< desaprobados(notas) << endl;
}

int aprobados(vector<float> noti){
    int contador=0;
    for(int i = 0; i < noti.size(); i++){
        if(noti[i]>=60.0){
            contador++;
        }
    }
    return contador;
}

int desaprobados(vector<float> noti){
    int contador=0;
    for(int i = 0; i < noti.size(); i++){
        if(noti[i]<60.0){
            contador++;
        }
    }
    return contador;
}

void anterior_posi(){
    vector<string> nombres;
    for(int i = 0; i < 3; i++){
        fflush(stdin);
        string name_temp;
        ret_nombre(name_temp);
        nombres.push_back(name_temp);
    }
    cout<< endl;
    for(int j = 0; j < 3; j++){
        cout<< nombres[j] << endl;
    }
}

void ret_nombre(string& nombre){
    cout<<"Ingresa nombre" << endl;
    getline(cin, nombre);
}

void ret_nota(float& nota){
    cout<<"Ingresa nota" << endl;
    cin>> nota;
}

void retornar(){
    vector <float> notitas;
    //int i=0;
    for(int i = 0; i < 3; i++){
        linea20:
        fflush(stdin);
        float note;
        ret_nota(note);
        if(swish(note)==false){
            goto linea20;
        }
        notitas.push_back(note);
    }
    notitas.erase(notitas.begin()+1);
    notitas.insert(notitas.begin()+1,100.4);
    cout<< endl;
    for(int j = 0; j < 3; j++){
        cout<< notitas[j] << endl;
    }
}

bool swish(float& nota){
    //cin>> nota;
    bool ok = cin.good();
    cout<<ok << endl;
    if(ok==1){
        cin.clear();
        cout<< "esta bien" << endl;
        return true;
    }
    else{
        cin.clear();
        cout<< "Esta mal" << endl;
        return false;
    }
}
