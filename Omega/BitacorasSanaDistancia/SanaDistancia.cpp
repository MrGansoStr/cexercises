#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

int main(){
    vector<int> tiempos;
    vector<string> nums;
    int cant;
    cout<<"Ingrese cantidad" << endl;
    cin>> cant;
    for(int i = 0; i < cant; i++){
        cout<<"Ingrese los tiempos" << endl;
        int temp;
        cin>> temp;
        tiempos.push_back(temp);
    }
    
    for(int i = 0; i < cant; i++){
        cout<<"Ingrese los numeros" << endl;
        string temp;
        cin>> temp;
        nums.push_back(temp);
    }
    for(int i = 0; i < cant; i++){
        cout<< tiempos.at(i) << endl;
    }
    //tiempos.insert(tiempos.begin() + 0, 1000);
    
    for(int i = 0; i < cant - 2; i++){
        int aux = 0;
        string aux1 = "";
        
        if((tiempos.at(i) - tiempos.at(i + 1)) < tiempos.at(i)){
            aux = tiempos.at( i + 1 );
            tiempos.insert(tiempos.begin() + i + 1 , tiempos.at(i + 2));
            tiempos.erase(tiempos.begin() + i + 3);
            nums.insert(nums.begin() + i + 1, nums.at(i + 2));
            nums.erase(nums.begin() + i + 3);
        }
    }
    cout<< endl;
    for(int i = 0; i < cant ; i++){
        cout<< tiempos.at(i) <<" "<< nums.at(i) << endl;
    }
    return 0;
}