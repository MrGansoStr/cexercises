#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include <iomanip>
using namespace std;

class estudiante{
    private:
        string nombre;
        float nota;
        friend void recibir();
    public:
        estudiante(){};
        estudiante(string _nombre, float _nota){
            nombre=_nombre;
            this->nota=_nota;
        }
        static bool forma(estudiante& a, estudiante& b){
            return a.nota>b.nota;
        }
};


void retornar();
bool swish(float& nota);
void ret_nota(float& nota);
void ret_nombre(string& nombre);
void anterior_posi();
void recibir();
int aprobados(vector<float> noti);
int desaprobados(vector<float> noti);

int main(){
    unsigned t0, t1;
    t0=clock();
    recibir();
    t1=clock();
    double tiempo = double(t1-t0)/CLOCKS_PER_SEC;
    cout<< fixed << setprecision(5) << tiempo << endl;
}

void recibir(){
    
    vector<string> nombres;
    vector<float> notas;
    int cantidad, error=0;
    float suma, promedio=0;
    cin>> cantidad;
    vector<estudiante> list_estudiantes;
    estudiante* list_n_ = new estudiante[cantidad];
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
        if(nota<0.0 || nota>101.0){
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
        list_n_[i]=estudiante(nombre, nota);
    }

    for(int j = 0; j < cantidad; j++){
        list_estudiantes.push_back(list_n_[j]);
        cout<< nombres[j] <<"\t"<< notas[j] << endl;
    }
    cout<< endl;
    sort(list_estudiantes.begin(),list_estudiantes.end(), estudiante::forma);
    if(error!=0)    cout<<"Hay un problema con " << nombres[error] << endl; 
    cout<<"El promedio es: "<< promedio <<endl;
    cout<<"Cantidad de aprobados: "<< aprobados(notas) << endl;
    cout<<"Cantidad de desaprobados: "<< desaprobados(notas) << endl;
    cout<<"La mayor nota la tiene: " << list_estudiantes[0].nombre <<" con: " << list_estudiantes[0].nota << endl;
    cout<<"La menor nota la tiene: " << list_estudiantes[cantidad-1].nombre <<" con: " << list_estudiantes[cantidad-1].nota<< endl;
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
