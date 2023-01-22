#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

fstream ArchivoConPuntajes;
fstream ArchivoConPuntajesTodo;
fstream ArchivoConEstudiantes;
fstream ArchivoConEstudiantes_remasted;
fstream ArchivoBiomedicas;
fstream ArchivoIngenieria;
fstream ArchivoSociales;
fstream ArchivoBiomedicas_remasted;
fstream ArchivoIngenieria_remasted;
fstream ArchivoSociales_remasted;

class estudiante{
    private:
        string dni, apellido_paterno, apellido_materno, nombres;
        float puntaje;
        friend void LeerPuntajes_remasted();
        friend class BloqueEstudiantes;
        friend void LeerPuntajes();
        friend void OrdenarBiomedicas();
        friend void OrdenarIngenierias();
        friend void OrdenarSociales();
    public:
        estudiante(){}
        estudiante(string _dni, string _apellido_paterno, string _apellido_materno, string _nombres, float _puntaje){
            dni = _dni;
            apellido_paterno = _apellido_paterno;
            apellido_materno = _apellido_materno;
            nombres = _nombres;
            puntaje = _puntaje; 
        }
        static bool CompararPuntaje(estudiante& a, estudiante& b){
            return a.puntaje > b.puntaje;
        }
        string GetDni(){
            return dni;
        }
};

class BloqueEstudiantes : private estudiante{
    private:
        string IdCarrera;
        vector<string> Estudiantes;
        friend void LeerPuntajes();
    public:
        BloqueEstudiantes(){}
        BloqueEstudiantes(string _IdCarrera, vector<string> _Estudiantes){
            IdCarrera = _IdCarrera;
            Estudiantes = _Estudiantes;
        }
        string GetId(){
            return IdCarrera;
        }
        void MostrarEstudiantes(){
            for(int i = 0; i < Estudiantes.size(); i++){
                cout<< Estudiantes.at(i) << endl;
            }
            cout<< Estudiantes.size() << endl;
        }
        string GetLineaEstudiante(int i){
            return Estudiantes.at(i);
        }
        int GetTamanioVector(){
            return Estudiantes.size();
        }
};

void LeerPuntajes();
void LeerPuntajesTodo();
bool BuscarId(string _linea, string _Id);
bool BuscarCaracter(string& _linea, string _caracter);
void LeerPuntajes_remasted();
void IngresarDatos();
void OrdenarBiomedicas();
void OrdenarIngenierias();
void OrdenarSociales();
vector<string> GetIdCarrera(int desde, int hasta);

int main(){
    //GetIdCarrera();
    //LeerPuntajes();
    //LeerPuntajesTodo();
    //LeerPuntajes_remasted();
    OrdenarBiomedicas();
    OrdenarIngenierias();
    OrdenarSociales();
}
void OrdenarSociales(){
    ArchivoSociales.open("Sociales.txt", ios::in);
    ArchivoSociales_remasted.open("Sociales_remasted", ios::out);
    estudiante* estudiantes_Soc = new estudiante[5000];
    vector<string> lineas;
    vector<estudiante> ListaEstudiantes;
    if(ArchivoSociales.is_open()){
        string linea;
        while(getline(ArchivoSociales, linea)){
            lineas.push_back(linea);
        }
    }
    else{
        cout<<"No se encontro el archivo" << endl;
    }
    for(int i = 0; i < lineas.size(); i++){
        string _puesto = lineas.at(i).substr(5, 2);
        string _dni = lineas.at(i).substr(11, 8);
        string nombre_generico = lineas.at(i).substr(24, 51);
        string _puntaje = lineas.at(i).substr(81, 7);
        float puntaje = stof(_puntaje);
        string nombre_normal = nombre_generico.substr(nombre_generico.find(',')+1, 40);
        string apellido_paterno = nombre_generico.substr(0,nombre_generico.find(' '));
        string apellido_materno = nombre_generico.substr(nombre_generico.find(' ')+1, ((nombre_generico.find(',') - nombre_generico.find(' ')) - 1));
        cout << _puesto <<" "<< _dni <<" " << nombre_generico << " "<< puntaje << endl;
        estudiantes_Soc[i] = estudiante(_dni, apellido_paterno, apellido_materno, nombre_normal, float(puntaje));
        ListaEstudiantes.push_back(estudiantes_Soc[i]);
        //cout<< Estudiantes_v[i].GetDni() <<" "<< Estudiantes_v[i].apellido_paterno << " " << Estudiantes_v[i].apellido_materno << endl;
    }
    //cout<< Estudiantes_v[5].GetDni();
    sort(ListaEstudiantes.begin(),ListaEstudiantes.end(),estudiante::CompararPuntaje);
    ArchivoSociales_remasted<<"Puesto\t\t"<<"DNI\t\t\t"<<"Apellidos y Nombres\t\t\t\t\t\t\t"<<"\tPuntaje"<< endl;
    
    for(int i = 0; i < ListaEstudiantes.size(); i++){
        //cout<< ListaEstudiantes.at(i).nombres << endl;
        ArchivoSociales_remasted<< i+1 <<"\t\t"<< ListaEstudiantes[i].dni << "\t\t" << ListaEstudiantes[i].apellido_paterno << ", "<< ListaEstudiantes[i].apellido_materno <<" " << ListaEstudiantes[i].nombres << ListaEstudiantes[i].puntaje<<"\n";
    }
    ArchivoSociales_remasted<<"Cantidad de estudiantes: "<<ListaEstudiantes.size();
}
void OrdenarIngenierias(){
    ArchivoIngenieria.open("Ingenierias.txt", ios::in);
    ArchivoIngenieria_remasted.open("Ingenierias_remasted", ios::out);
    estudiante* estudiantes_Ing = new estudiante[5000];
    vector<string> lineas;
    vector<estudiante> ListaEstudiantes;
    if(ArchivoIngenieria.is_open()){
        string linea;
        while(getline(ArchivoIngenieria, linea)){
            lineas.push_back(linea);
        }
    }
    else{
        cout<<"No se encontro el archivo" << endl;
    }
    for(int i = 0; i < lineas.size(); i++){
        string _puesto = lineas.at(i).substr(5, 2);
        string _dni = lineas.at(i).substr(11, 8);
        string nombre_generico = lineas.at(i).substr(24, 51);
        string _puntaje = lineas.at(i).substr(81, 7);
        float puntaje = stof(_puntaje);
        string nombre_normal = nombre_generico.substr(nombre_generico.find(',')+1, 40);
        string apellido_paterno = nombre_generico.substr(0,nombre_generico.find(' '));
        string apellido_materno = nombre_generico.substr(nombre_generico.find(' ')+1, ((nombre_generico.find(',') - nombre_generico.find(' ')) - 1));
        cout << _puesto <<" "<< _dni <<" " << nombre_generico << " "<< puntaje << endl;
        estudiantes_Ing[i] = estudiante(_dni, apellido_paterno, apellido_materno, nombre_normal, float(puntaje));
        ListaEstudiantes.push_back(estudiantes_Ing[i]);
        //cout<< Estudiantes_v[i].GetDni() <<" "<< Estudiantes_v[i].apellido_paterno << " " << Estudiantes_v[i].apellido_materno << endl;
    }
    //cout<< Estudiantes_v[5].GetDni();
    sort(ListaEstudiantes.begin(),ListaEstudiantes.end(),estudiante::CompararPuntaje);
    ArchivoIngenieria_remasted<<"Puesto\t\t"<<"DNI\t\t\t"<<"Apellidos y Nombres\t\t\t\t\t\t\t"<<"\tPuntaje"<< endl;
    
    for(int i = 0; i < ListaEstudiantes.size(); i++){
        //cout<< ListaEstudiantes.at(i).nombres << endl;
        ArchivoIngenieria_remasted<< i+1 <<"\t\t"<< ListaEstudiantes[i].dni << "\t\t" << ListaEstudiantes[i].apellido_paterno << ", "<< ListaEstudiantes[i].apellido_materno <<" " << ListaEstudiantes[i].nombres << ListaEstudiantes[i].puntaje<<"\n";
    }
    ArchivoIngenieria_remasted<<"Cantidad de estudiantes: "<<ListaEstudiantes.size();
}
void OrdenarBiomedicas(){
    ArchivoBiomedicas.open("Biomedicas.txt", ios::in);
    ArchivoBiomedicas_remasted.open("Biomedicas_remasted.txt", ios::out);
    estudiante* estudiantes_Bio = new estudiante[5000]; 
    vector<string> lineas;
    vector<estudiante> ListaEstudiantes;
    if(ArchivoBiomedicas.is_open()){
        string linea;
        while(getline(ArchivoBiomedicas, linea)){
            lineas.push_back(linea);
            //cout<< linea << endl;
        }
        ArchivoBiomedicas.close();
    }
    else{
        cout<<"No se encontro el archivo" << endl;
    }
    for(int i = 0; i < lineas.size(); i++){
        string _puesto = lineas.at(i).substr(5, 2);
        string _dni = lineas.at(i).substr(11, 8);
        string nombre_generico = lineas.at(i).substr(24, 51);
        string _puntaje = lineas.at(i).substr(81, 7);
        float puntaje = stof(_puntaje);
        string nombre_normal = nombre_generico.substr(nombre_generico.find(',')+1, 40);
        string apellido_paterno = nombre_generico.substr(0,nombre_generico.find(' '));
        string apellido_materno = nombre_generico.substr(nombre_generico.find(' ')+1, ((nombre_generico.find(',') - nombre_generico.find(' ')) - 1));
        cout << _puesto <<" "<< _dni <<" " << nombre_generico << " "<< puntaje << endl;
        estudiantes_Bio[i] = estudiante(_dni, apellido_paterno, apellido_materno, nombre_normal, float(puntaje));
        ListaEstudiantes.push_back(estudiantes_Bio[i]);
        //cout<< Estudiantes_v[i].GetDni() <<" "<< Estudiantes_v[i].apellido_paterno << " " << Estudiantes_v[i].apellido_materno << endl;
    }
    //cout<< Estudiantes_v[5].GetDni();
    sort(ListaEstudiantes.begin(),ListaEstudiantes.end(),estudiante::CompararPuntaje);
    ArchivoBiomedicas_remasted<<"Puesto\t\t"<<"DNI\t\t\t"<<"Apellidos y Nombres\t\t\t\t\t\t\t"<<"\tPuntaje"<< endl;
    
    for(int i = 0; i < ListaEstudiantes.size(); i++){
        //cout<< ListaEstudiantes.at(i).nombres << endl;
        ArchivoBiomedicas_remasted<< i+1 <<"\t\t"<< ListaEstudiantes[i].dni << "\t\t" << ListaEstudiantes[i].apellido_paterno << ", "<< ListaEstudiantes[i].apellido_materno <<" " << ListaEstudiantes[i].nombres << ListaEstudiantes[i].puntaje<<"\n";
    }
    ArchivoBiomedicas_remasted<<"Cantidad de estudiantes: "<<ListaEstudiantes.size();
}
void LeerPuntajes_remasted(){
    ArchivoConEstudiantes.open("ArchivoConEstudiantes.txt", ios::in);
    ArchivoConEstudiantes_remasted.open("ArchivoConEstudiantes_remasted.txt", ios::out);
    vector<estudiante> ListaEstudiantes;
    int iterador = 0;
    //Estudiantes_v[0] = estudiante("asda1", "asda2", "asda3","asda4", 4801.2);
    //Estudiantes_v[1] = estudiante("asda1", "asda2", "asda3","asda4", 4801.2);
    //Estudiantes_v[2] = estudiante("asda1", "asda2", "asda3","asda4", 4801.2);
    //cout<< Estudiantes_v[1].GetDni();
    //Estudiantes[0] = estudiante("asda1", "asda2", "asda3","asda4", 4801.2);
    //cout<< Estudiantes[0].GetDni();
    estudiante* Estudiantes_v = new estudiante[5000];
    vector<string> lineas;
    if(ArchivoConEstudiantes.is_open()){
        string linea;
        //float puntaje;
        //string _dni, apellido_paterno, apellido_materno, nombre_normal, nombre_generico;
        while(getline(ArchivoConEstudiantes, linea) && !ArchivoConEstudiantes.eof()){
            lineas.push_back(linea);
            //_dni = linea.substr(0, 8);
            //string _puntaje;
            //nombre_generico = linea.substr(9,45);
            //_puntaje = linea.substr(61, 6);
            //puntaje = stof(_puntaje);
            //nombre_normal = nombre_generico.substr(nombre_generico.find(',')+1, 40);
            //apellido_paterno = nombre_generico.substr(0,nombre_generico.find(' '));
            //apellido_materno = nombre_generico.substr(nombre_generico.find(' ')+1, ((nombre_generico.find(',') - nombre_generico.find(' ')) - 1));
            
            //cout<< Estudiantes_v[iterador++].GetDni() << endl;
            //cout<<ListaEstudiantes.size()<< endl;
            //cout<< ListaEstudiantes.at(4).GetDni()<< endl;
            //cout<< Estudiantes_v[420].apellido_materno << endl;
            //fflush(stdin);
        }
        //Estudiantes_v[0] = estudiante("DNIIIII", "fkjals", "alksjdf", "asdf", 4802.42);
        //ListaEstudiantes.push_back(Estudiantes_v[iterador++]);
        //Estudiantes_v[0].GetDni();
        ArchivoConEstudiantes.close();
    }
    else{
        cout<<"No se encontro el archivo" << endl;
    }
    for(int i = 0; i < lineas.size(); i++){
        string _dni = lineas.at(i).substr(0, 8);
        string nombre_generico= lineas.at(i).substr(9, 45);
        string _puntaje = lineas.at(i).substr(61, 6);
        float puntaje = stof(_puntaje);
        string nombre_normal = nombre_generico.substr(nombre_generico.find(',')+1, 40);
        string apellido_paterno = nombre_generico.substr(0,nombre_generico.find(' '));
        string apellido_materno = nombre_generico.substr(nombre_generico.find(' ')+1, ((nombre_generico.find(',') - nombre_generico.find(' ')) - 1));
        //_dni = linea.substr(0, 8);
            //string _puntaje;
            //nombre_generico = linea.substr(9,45);
            //_puntaje = linea.substr(61, 6);
            //puntaje = stof(_puntaje);
            //nombre_normal = nombre_generico.substr(nombre_generico.find(',')+1, 40);
            //apellido_paterno = nombre_generico.substr(0,nombre_generico.find(' '));
            //apellido_materno = nombre_generico.substr(nombre_generico.find(' ')+1, ((nombre_generico.find(',') - nombre_generico.find(' ')) - 1));
        Estudiantes_v[i] = estudiante(_dni, apellido_paterno, apellido_materno, nombre_normal, float(puntaje));
        ListaEstudiantes.push_back(Estudiantes_v[i]);
        //cout<< Estudiantes_v[i].GetDni() <<" "<< Estudiantes_v[i].apellido_paterno << " " << Estudiantes_v[i].apellido_materno << endl;
    }
    //cout<< Estudiantes_v[5].GetDni();
    sort(ListaEstudiantes.begin(),ListaEstudiantes.end(),estudiante::CompararPuntaje);
    ArchivoConEstudiantes_remasted<<"Puesto\t\t"<<"DNI\t\t\t"<<"Apellidos y Nombres\t\t\t\t\t\t\t"<<"Puntaje"<< endl;
    
    cout<<ListaEstudiantes.size();
    for(int i = 0; i < ListaEstudiantes.size(); i++){
        //cout<< ListaEstudiantes.at(i).nombres << endl;
        ArchivoConEstudiantes_remasted<< i <<"\t\t"<< ListaEstudiantes[i].dni << "\t\t" << ListaEstudiantes[i].apellido_paterno << ", "<< ListaEstudiantes[i].apellido_materno <<" " << ListaEstudiantes[i].nombres << ListaEstudiantes[i].puntaje<<"\n";
    }
}
void LeerPuntajesTodo(){
    ArchivoConPuntajesTodo.open("TodoPuntajes.txt", ios::in);
    ArchivoConEstudiantes.open("ArchivoConEstudiantes.txt", ios::out);
    int contador = 0;
    if(ArchivoConPuntajesTodo.is_open()){
        //int Puesto;
        string linea;
        //float puntaje;
        while(getline(ArchivoConPuntajesTodo, linea)){
            contador++;
            fflush(stdin);
            string puesto = linea.substr(5, 2);
            string Dni = linea.substr(11, 8);
            string nombres = linea.substr(24,51);
            string _puntaje = linea.substr(81,7); 
            float puntaje = stof(_puntaje);
            cout<< puesto << " " << Dni << " " << nombres << " " << puntaje << endl;
            //ArchivoConPuntajesTodo>> resto;// Nombres >> puntaje;
            ArchivoConEstudiantes <<Dni<<"\t"<< nombres <<"\t"<< puntaje << "\n";
        }
        ArchivoConPuntajes.close();
        ArchivoConEstudiantes.close();
    }
    else{
        cout<<"no se encontro el archivo "<< endl;
    }
}

void LeerPuntajes(){
    ArchivoConPuntajes.open("puntajes.txt", ios::in);
    ArchivoConPuntajesTodo.open("TodoPuntajes.txt", ios::out);
    ArchivoBiomedicas.open("Biomedicas.txt", ios::out);
    ArchivoIngenieria.open("Ingenierias.txt", ios::out);
    ArchivoSociales.open("Sociales.txt", ios::out);
    BloqueEstudiantes* B_Estudiantes = new BloqueEstudiantes[5000];
    vector<string> Biomedicas;
    vector<string> Ingenierias;
    vector<string> Sociales;
    vector<string> Lineas;
    Biomedicas = GetIdCarrera(1, 6);
    Biomedicas.push_back("[ 45 ]");
    Biomedicas.push_back("[ 46 ]");
    Biomedicas.push_back("[ 47 ]");
    Ingenierias = GetIdCarrera(23, 37);
    Ingenierias.push_back("[ 48 ]");
    Ingenierias.push_back("[ 49 ]");
    Sociales = GetIdCarrera(7, 21);
    Sociales.push_back("[ 39 ]");
    Sociales.push_back("[ 40 ]");
    Sociales.push_back("[ 41 ]");
    Sociales.push_back("[ 42 ]");
    Sociales.push_back("[ 43 ]");
    //ArchivoConPuntajesTodo.open("TodoPuntajes.txt", ios::in);
    //ArchivoPrueba.open("ArchivoPrueba.txt", ios::out);
    //vector<int> C_estudiantes;
    if(ArchivoConPuntajes.is_open()){
        string linea, LineaTodo;
        int contador = 0, contador1 = 0, i = 0;
        while(getline(ArchivoConPuntajes, linea)){
            //int CantidadEstudiantes = 0;
            //cout<< linea << endl;
            //string TempId;
            Lineas.push_back(linea);/*
            if(BuscarId(linea, "[")){
                cout<<"Encontrado>>>>>>>>>"<<linea <<endl;
                TempId = linea;
            }*/
            if(BuscarCaracter(linea, "=")){
                contador++;
                //cout<< "aeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeea" << endl;
            }
            if(contador == 2){
                //cout<< "faaaaaaaaaaaaaaaaaaaa";
                if(!BuscarCaracter(linea, "=")){
                    ArchivoConPuntajesTodo << linea << "\n";
                    //CantidadEstudiantes++;
                }
            }
            else if(contador == 3){
                contador = 0;
                //TempId ="";
            }
            //C_estudiantes.push_back(CantidadEstudiantes);
            //cout<< BuscarCaracter(linea, "=");
            //BuscarId(linea, "[ 1 ]");
        }
        ArchivoConPuntajesTodo.close();
        ArchivoConPuntajes.close();
    }
    else{
        cout<< "No se encontro el archivo " << endl;
    }
    int contador1 = 0, j1 = 0;
    string TempId;
    vector<string> DatosEstudiantes;
    for(int i = 0; i < Lineas.size(); i++){
        bool sich = false;
        int contador;
        if(BuscarId(Lineas.at(i), "[")){
            TempId = Lineas.at(i);
            contador++;
            //cout<<"Encontrado>>>>>>>>>"<< TempId <<endl;
        }
        if(BuscarCaracter(Lineas.at(i), "=")){
            contador1++;
            //cout<< contador1 << endl;
            //cout<< "aeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeea" << endl;
        }
        if(contador1 == 2){
            if(!BuscarCaracter(Lineas.at(i), "="))
                DatosEstudiantes.push_back(Lineas.at(i));
            //cout<< TempId << endl;
            
            //cout<< "faaaaaaaaaaaaaaaaaaaa" << endl;
        }/*
        for(int j = 0; j < Biomedicas.size(); j++){
            cout<< Biomedicas.at(j) << " " << Lineas.at(i) << " ";
            cout<< BuscarId(Lineas.at(i), Biomedicas.at(j)) << endl;
            if(BuscarId(Lineas.at(i),Biomedicas.at(j))){
                contador = i;
                cout<< "contador: "<< contador <<" " << contador1 <<" ";
                if(contador1 == 1){
                    ArchivoBiomedicas<< "Biomedicas" <<Lineas.at(i) << "\n";
                }
            }
        }*/
        if(contador1 == 3){
            //BloqueEstudiantes* B_Estudiantes = new BloqueEstudiantes[5000];
            //cout<< TempId << endl;
            B_Estudiantes[j1++] =  BloqueEstudiantes(TempId, DatosEstudiantes);
            contador1 = 0;
            TempId = "";
            DatosEstudiantes.clear();
        }
        /*
        if(i == 54){
            break;
        }*/
        //B_Estudiantes[i].MostrarId();
        //B_Estudiantes[i].MostrarEstudiantes();
    }
    for(int i = 0; i < j1; i++){
        //cout<<"aeaaa" << endl;
        cout<< B_Estudiantes[i].GetId() << endl;
        B_Estudiantes[i].MostrarEstudiantes();
    }
    int countBiomedicas = 0, countIngenierias = 0, countSociales = 0;
    for(int i = 0; i < j1; i++){
        for(int j = 0; j < Biomedicas.size(); j++){
            if(B_Estudiantes[i].GetId().substr(1, 6) == Biomedicas.at(j) || B_Estudiantes[i].GetId().substr(1, 5) == Biomedicas.at(j)){
                //ArchivoBiomedicas<< B_Estudiantes[i].GetId() <<"\n";
                for(int k = 0; k < B_Estudiantes[i].GetTamanioVector(); k++){
                    ArchivoBiomedicas<< B_Estudiantes[i].GetLineaEstudiante(k) <<"\n";
                }
                countBiomedicas++;
                //cout<< B_Estudiantes[i].GetId().substr(1, 6) <<" "<< Biomedicas.at(j) << endl;
            }
        }
        for(int j = 0; j < Ingenierias.size(); j++){
            if(B_Estudiantes[i].GetId().substr(1, 6) == Ingenierias.at(j) || B_Estudiantes[i].GetId().substr(1, 5) == Ingenierias.at(j)){
                //ArchivoIngenieria<< B_Estudiantes[i].GetId() <<"\n";
                for(int k = 0; k < B_Estudiantes[i].GetTamanioVector(); k++){
                    ArchivoIngenieria<< B_Estudiantes[i].GetLineaEstudiante(k) <<"\n";
                }
                countIngenierias++;
            }
        }
        for(int j = 0; j < Sociales.size(); j++){
            if(B_Estudiantes[i].GetId().substr(1, 6) == Sociales.at(j) || B_Estudiantes[i].GetId().substr(1, 5) == Sociales.at(j)){
                //ArchivoSociales<< B_Estudiantes[i].GetId() << "\n";
                for(int k = 0; k < B_Estudiantes[i].GetTamanioVector(); k++){
                    ArchivoSociales<< B_Estudiantes[i].GetLineaEstudiante(k) <<"\n";
                }
                countSociales++;
            }
        }
        cout<< B_Estudiantes[i].GetId() << endl;
    }
    cout<< countBiomedicas<<" " << countIngenierias <<" "<< countSociales << endl;
    /*
    for(int i = 0; i < countBiomedicas; i++){
        for(int  j = 0; j < B_Estudiantes[i])
    }*/
}
bool BuscarCaracter(string& _linea, string _caracter){
    if(_linea.find("=", 2) == 2){
        //cout<< _linea.size()<<" <- ";
        //cout<< _linea.find("=", 2) << " -> ";
        return true;
    }
    else{
        return false;
    }
       /*
    cout<< _linea.size();
    for(int i = 0; i < _linea.size(); i++){
        cout<< _linea.substr(i, _caracter.size());
        if(_linea.substr(i,_caracter.size()) == _caracter){
            cout<< "ENCONTRADO CMSREEEEEEEEEEEEEEEEE" << endl;
            return true;
            //break;
        }
        else{
            return false;
        }
    }*/
}
bool BuscarId(string _linea, string _Id){
    //cout<< _linea.find("[") <<" aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "<< endl; 
    if( _linea.find("[")  == 1){
        return true;
    }
    else{
        return false;
    }
}
vector<string> GetIdCarrera(int desde, int hasta){
    vector<string> IdCarrera;
    for(int i = desde ; i <= hasta ; i++){
        string _i = "[ ";
        _i.append(string(to_string(i)));
        _i.append(" ]");
        IdCarrera.push_back(_i);
    }/*
    for(int i = desde; i < hasta; i++){
        cout<< IdCarrera.at(i) << endl;
    }*/
    return IdCarrera;
}