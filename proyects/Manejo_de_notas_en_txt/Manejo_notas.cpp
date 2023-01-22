#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

fstream archivo_con_respuestas;
fstream archivo_con_nota;
fstream archivo_con_nota_ordenado;

class estudiante{
	private:
		string id, dni, respuesta;
		int nota;
		friend void _ordenar(vector<estudiante> &vect, int tamanio);
		friend void escribir_ranking(vector<estudiante> &vecto,int cantidad);
		friend void leer_vector(vector<estudiante> &vec,int tam);
	public:
		estudiante(){ //Constructor por defecto
		}
		estudiante(string _id, string _dni,string _respuesta, int _nota){// Constructor parametrizado
			id=_id;
			dni=_dni;
			respuesta=_respuesta;
			this->nota=_nota;
		}
		static bool comparar(estudiante &a, estudiante &b){ //Comparar las notas
			return a.nota < b.nota;
		}
};
void leer_vector(vector<estudiante> &vec,int tam);
string respuesta_oficial();
string reemplazar(string respuesta);
string hacer_respuestas_random();
string hacer_DNI_random();
void ordenar_ranking(int cantidad);
void calificar_respuestas(int cantidad);
void hacer_respuestas_en_texto(int cantidad);




int main(){
	//srand(time(NULL));
	//hacer_respuestas_en_texto(30);
	//calificar_respuestas(30);
	ordenar_ranking(30);
	return 0;
}

void hacer_respuestas_en_texto(int cantidad){
	srand(time(NULL));
	archivo_con_respuestas.open("Archivo_con_respuestas.txt",ios::out);
	if(archivo_con_respuestas.is_open()){//Si el archivo esta abierto :v
		for(int i = 1; i <= cantidad; i++){
			archivo_con_respuestas<<i<<"\t"<< hacer_DNI_random() <<"\t"<< reemplazar(hacer_respuestas_random()) <<"\n";
		}
		archivo_con_respuestas.close();
	}
	else{
		cout << "No se encontro el archivo"<<endl;
	}
}

void ordenar_ranking(int cantidad){
	archivo_con_nota.open("Archivo_con_nota.txt",ios::in); //Abre el archivo con las notas
	//archivo_con_nota_ordenado.open("Archivo_con_nota_ordenado.txt",ios::out);
	vector<estudiante> lista_V;
	estudiante* lista_N=new estudiante[cantidad];
	int iterador=0;
	if(archivo_con_nota.is_open()){
		string ID, DNI, respuesta;
		int nota;
		while(!archivo_con_nota.eof()){
			archivo_con_nota >> ID >> DNI >> respuesta >> nota;
			if(!archivo_con_nota.eof()){
				lista_N[iterador++]=estudiante(ID,DNI,respuesta,nota);
			}
		}
		for(int i = 0; i < cantidad; i++){
			lista_V.push_back(lista_N[i]);
		}
		leer_vector(lista_V,cantidad);
		sort(lista_V.begin(),lista_V.end(),estudiante::comparar);//Ordena la lista de estudiantes por la nota
		leer_vector(lista_V,cantidad);
		escribir_ranking(lista_V,cantidad);
	}
	else{
		cout<<"No se encontro el archivo"<<endl;
	}
	
	
}

void calificar_respuestas(int cantidad){
	archivo_con_respuestas.open("Archivo_con_respuestas.txt",ios::in);//Para leer el archivo con respuestas
	archivo_con_nota.open("Archivo_con_nota.txt",ios::out);//Para ingresar las notas en un nuevo archivo
	string respu_oficial = respuesta_oficial();
	cout << respu_oficial << endl;
	if(archivo_con_nota.is_open()){
		string ID, DNI, respuestas;
		while(!archivo_con_respuestas.eof()){
			archivo_con_respuestas >> ID >> DNI >> respuestas;//Lee el archivo en el orden ID - DNI - respuestas para cada linea
			if(!archivo_con_respuestas.eof()){
				cout<<respuestas<<endl;
				int _nota =0;
				for(int i = 0; i < cantidad; i++){
					//cout << respuestas[i] <<" "<< respu_oficial[i]<<endl;
					if(respuestas[i]==respu_oficial[i]){
						_nota+= 10;
					}
					if(respuestas[i]=='*'){
						_nota+= 100;
					}
					else if(respuestas[i]!=respu_oficial[i]){
						_nota+= 1;
					}
					else{
						_nota+= 1;
					}
				}
				archivo_con_nota << ID <<"\t"<< DNI <<"\t"<< respuestas <<"\t"<< _nota <<"\n";
			}
		}
	}
	else{
		cout<<"No se encontro el archivo"<<endl;
	}
}
void escribir_ranking(vector<estudiante> &vecto,int cantidad){
	archivo_con_nota_ordenado.open("Archivo_con_nota_ordenado.txt",ios::out);
	//archivo.open("PRUEBA_textoxd.txt",ios::out|ios::app);
	if(archivo_con_nota_ordenado.is_open()){
		for(int i=0;i<cantidad;i++){
			archivo_con_nota_ordenado<<vecto[i].id<<"\t"<<vecto[i].dni<<"\t"<< vecto[i].respuesta<<"\t"<<vecto[i].nota<<"\n";
		}
		archivo_con_nota_ordenado.close();
	}
	else{
		cout<<"no se encontro el archivo ";
	}
}
void leer_vector(vector<estudiante> &vec,int tam){
    for(int i=0;i<tam;i++){
    	cout<<vec[i].id<<vec[i].dni<<" con nota: "<<vec[i].nota<<endl;
	}
    cout << endl;
}

string respuesta_oficial(){
	srand(time(NULL));
	string resp_oficial=hacer_respuestas_random();
	return resp_oficial;
	
}

string reemplazar(string respuesta){ 
	for(int i=0;i<respuesta.size();i++){
		if(respuesta[i] == 'F'){//Reemplaza cuando una alternativa es F
			respuesta[i] = '*';//La reemplaza por *
		}
	}
	return respuesta;
}

string hacer_respuestas_random(){
	char respuestas[30];
	string _respuesta;
	int aux;
	for(int i = 0; i < 30; i++)
		respuestas[i] = (65 + rand() % 6); //Hace la respuesta con codigo ASCII 
	_respuesta = respuestas; 
	return _respuesta;
}

string hacer_DNI_random(){
	char DniRandom[10];
	string dni;
	for(int i=0; i < 8; i++)
		DniRandom[i] = 48 + rand() % 10; // Hace el DNI con codigo ASCII
		DniRandom[8]=0;
	dni = DniRandom;
	return dni;
}

