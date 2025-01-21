#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

int main(){
    string nombreArch;
    cout << "Ingrese el nombre del archivo: ";
    cin >> nombreArch;
    fstream arch(nombreArch);

    string linea;
    if(arch.is_open()){
        while(getline(arch, linea)){
            cout << linea << endl;
        }
        arch.close();
    }else{
        cout << "No se pudo abrir el archivo";
    }

    return 0;
}