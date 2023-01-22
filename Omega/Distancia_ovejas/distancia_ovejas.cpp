#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class coordenada{
    private:
        int _x, _y;
        friend class coordenadas;
        friend class coord_x_p;
        //friend void comparacion(coord_x_p a[]);
        friend void ovejitas();
    public:
        coordenada(){}
        coordenada(int __x, int __y){
            this->_x = __x;
            this->_y = __y;
        }
        static bool comparar_x(coordenada& a, coordenada&b){
            return a._x < b._x;
        }
        static bool comparar_y(coordenada& a, coordenada&b){
            return a._y < b._y;
        }
        int distancia(coordenada p1, coordenada p2){
            return ((p1._x-p2._x)*(p1._x-p2._x)+(p1._y-p2._y)*(p1._y-p2._y));
        }
        void mostrar(){
            cout<< _x <<"  "<< _y << endl;
        }
        int _get_x(){
            return _x;
        }
        int _get_y(){
            return _y;
        }
};
class coordenadas{
    private:
        vector<coordenada> coords;
        friend class coordenada;
    public:
        coordenadas(){
        }
        coordenadas(vector<coordenada> _coods){
            coords = _coods;
        }
        int get_x(int i){
            return coords[i]._x;
        }
        int get_y(int i){
            return coords[i]._y;
        }
        void get_x_y(int i){
            cout<< coords[i]._x <<" "<< coords[i]._y<< endl;
        }
        
};
class coord_x_p: private coordenada{
    private:
        coordenada coords;
        vector<coordenada> coords_s;
        //coordenadas coords_o;
        vector<coordenada> coords_o;
        friend void comparacion(coord_x_p a);
        friend class coordenada;
        friend void ovejitas();
    public:
        coord_x_p(){}
        coord_x_p(coordenada _coords, vector<coordenada> _coords_s, vector<coordenada> _coords_o){
            coords = _coords;
            coords_s = _coords_s;
            coords_o = _coords_o;
        }
        int get__x(int i){
            return coords_s[i]._x;
        }
        int get__y(int i){
            return coords_s[i]._y;
        }
        void ordenar(){
            sort(coords_s.begin(), coords_s.end(), coordenada::comparar_x);
            //sort(coords_s.begin(), coords_s.end(), coordenada::comparar_y);
            
        }
        void leer(){
            for(int i = 0; i < coords_s.size(); i++){
                cout<< coords._x << " " << coords._y << " -> ";
                cout<< coords_s[i]._x << " " << coords_s[i]._y << " <- ";
                coords_o[i].mostrar();
                //coords_o.get_x_y(i);
                //cout<< " <- "<< coords_o[i] << " " << coords_o << endl; 
            }
        }
};

void comparacion(coord_x_p a){
    coordenada temp;
    coordenada temp1;
    for(int i = 0; i < a.coords_s.size() ;i++){
        for(int j = i + 1; j < a.coords_s.size(); j++){
            if((a.coords_s[i]._get_x() + a.coords_s[i]._get_y()) > (a.coords_s[j]._get_x()+ a.coords_s[j]._get_y())){
                temp = a.coords_s[i];
                temp1 = a.coords_o[i];
                a.coords_s[i] = a.coords_s[j];
                a.coords_o[i] = a.coords_o[j];
                a.coords_s[j] = a.coords_s[i];
                a.coords_o[j] = a.coords_o[i];
                a.coords_s[j] = temp;
                a.coords_o[j] = temp1;
            }
        }
    }/*
    coordenada temp2;
    coordenada temp3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(a.coords_s[i]._get_y() > a.coords_s[j]._get_y()){
                temp2 = a.coords_s[i];
                temp3 = a.coords_o[i];
                a.coords_s[i] = a.coords_s[j];
                a.coords_o[i] = a.coords_o[j];
                a.coords_s[j] = a.coords_s[i];
                a.coords_o[j] = a.coords_o[i];
                a.coords_s[j] = temp2;
                a.coords_o[j] = temp3;
            }
        }
    }*/
    a.leer();
    cout<<"En la posicion: (" << a.coords._get_x()<<","<<a.coords._get_y()<<")" <<" la oveja mas cercana es: ("<<a.coords_o[0]._get_x()<< ","<<a.coords_o[0]._get_y()<<")";
    cout<<" con la distancia: "<<(a.coords_s[0]._get_x() + a.coords_s[0]._get_y()) << endl;
}

int bus_p_x(int pos_ini, int __x){
    if(pos_ini == __x){
        //cout<< 0 << endl;
        return 0;
    }
    if(__x < pos_ini){
        int count = 0;
        for(int i = pos_ini; i >= __x; i--){
            count++;
        }
        //cout<< count - 1<< endl;
        return count - 1;
    }
    else if(__x > pos_ini){
        int count = 0;
        for(int i = pos_ini; i <= __x; i++){
            count++;
        }
        //cout<< count - 1 << endl;
        return count - 1;
    }
}

void ovejitas(){
    int N_ovejas, N_preg;
    cin>> N_ovejas >> N_preg;
    coordenada* n_coord = new coordenada[N_ovejas];
    coordenada* p_coord = new coordenada[N_preg];
    coordenada* NN_coord = new coordenada[N_preg];
    coord_x_p* PP_coord = new coord_x_p[N_ovejas];
    vector<coordenada> coordin;
    vector<coordenada> p_coords;
    int pos_ove[N_ovejas][N_ovejas];
    vector<int> posi_;
    //vector<int> posi_per;
    for(int i = 0; i < N_ovejas; i++){
        int _x, _y;
        cin>> _x >> _y;
        //cout<< " co" << _x <<" "<< _y << endl;
        n_coord[i] = coordenada(_x, _y);
        coordin.push_back(n_coord[i]);
    }
    
    for(int i = 0; i < N_preg; i++){
        int p_x, p_y;
        cin>> p_x >> p_y;
        p_coord[i] = coordenada(p_x, p_y);
        p_coords.push_back(p_coord[i]);
    }
    coordenadas coor = coordenadas(coordin);
    cout<< endl;
    vector<coord_x_p> cooord;
    for(int i = 0; i < N_preg; i++){
        coordenada* coua_temp = new coordenada[N_ovejas];
        coordenada* coua_temp1 = new coordenada[N_ovejas];
        vector<coordenada> coua_x_y;
        vector<coordenada> coua_x_y1;
        for(int j = 0; j < N_ovejas; j++){
            cout<< p_coords[i]._x << "  " << p_coords[i]._y <<" -> " ;
            int __x =  bus_p_x(p_coords[i]._x, coordin[j]._x) ;
            //coua_temp[j] = coordenada(p_coords[j]._x, p_coords[])
            int __y = bus_p_x(p_coords[i]._y, coordin[j]._y);
            coua_temp[j] = coordenada(__x, __y);
            coua_temp1[j] = coordenada(n_coord[j]._x, n_coord[j]._y);
            coua_x_y1.push_back(coua_temp1[j]);
            coua_x_y.push_back(coua_temp[j]);
            cout<< __x <<" "<< __y << endl;
            //PP_coord[i] = coord_x_p(p_coords[i]);
            //NN_coord[i] = coordenada(bus_p_x(p_coords[i]._x, coordin[j]._x), bus_p_x(p_coords[i]._y, coordin[j]._y));
            
        }
        PP_coord[i] = coord_x_p(p_coords[i], coua_x_y, coua_x_y1);
        cooord.push_back(PP_coord[i]);
        delete[] coua_temp;
        delete[] coua_temp1;
    }
    cout<< endl;
    cout<< coordin[0].distancia(coordin[0], coordin[2]) << endl;
    cout<< endl;
    //sort(cooord.begin(), cooord.end(), coordenada::comparar_x);

    for(int i = 0; i < N_preg; i++){
        //PP_coord[i].ordenar();
        PP_coord[i].leer();
    }
    cout<< endl;
    for(int i = 0; i < N_preg; i++){
        comparacion(PP_coord[i]);
    }
    /*
    comparacion(PP_coord[0]);
    comparacion(PP_coord[1]);
    */
    //cout<<"En la posicion: " << PP_coord[0].coords._get_x() <<" la oveja mas cercana es: "<<PP_coord[0].coords_o[1]._get_x()<< " "<<PP_coord[0].coords_o[1]._get_y() << endl;
    //cout<< coordix.bus_p_x(5) << endl; 
    delete[] NN_coord;
    delete[] n_coord;
    delete[] p_coord;
}

int main(){
    ovejitas();
    //bus_p_x(1,3);
    // << endl;
    //bus_p_x(3,1);
    // << endl;
}