#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <climits>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;
void reconocer();
bool entrada1(float& nota);
void xde1(int& aea);
void ejercicio3();
bool comparador(int x, int y);

int main(){
    //int cosa;
    //cin>> cosa;
    //cout<<cosa << endl;
    //entrada1(cosa);
    //xde1(cosa);
    //reconocer();

    ejercicio3();
    return 0;
}

bool comparador(int x, int y){
    return (x > y);
}
void ejercicio3(){
    vector <int> A{45,78,10,9,7,98,-96,18,79};
    sort(A.begin(),A.end(), comparador);
    for(int i = 0; i < A.size(); i++){
        cout<< A[i] <<endl;
    }
}
void xde1(int& aea){
    bool xd = cin.good();
    if(xd==1){
        cout<<"its ok" << endl;
    }
    else{
        cout<< "no wey " << endl;
    }
}
float notitas(float& notas){
    cin>>notas;
    return notas;
}
string nombres(string cosa){
    
}

void reconocer(){
    cout<<"Ingresar texto con espacio: " << endl;
    vector <float> notas;
    string palabra_hecha[4];
    //float notas[4];
    for(int i = 0; i < 4;i++){
        string polobra;
        float noti;
        getline(cin, polobra);
        cin>>noti;
        entrada1(noti);
        if(entrada1(noti)==0){
            cin.ignore(256,'\n');
            getline(cin, polobra);
            cin.get();
            palabra_hecha[i-1] = polobra;
        }
        else{
            palabra_hecha[i]=polobra;
            cin.get();
        }
        notas.push_back(noti);
    }
    for(int i = 0; i < 4; i++){
        cout<< palabra_hecha[i] <<"con nota"<< notas[i] << endl;
    }

    cout<< endl;
}

bool entrada1(float& nota){
    //cin>>numero;
    bool ok = cin.good();
    cout<<ok << endl;
    if(ok==1){
        cin.clear();
        cout<< "esta bien" << endl;
    }
    else{
        cin.clear();
        cout<< "Esta mal" << endl;
        return ok;
    }
}