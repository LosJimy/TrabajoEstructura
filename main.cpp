#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    string nombreArch;
    cout << "Ingrese el nombre del archivo: ";
    cin >> nombreArch;
    fstream arch(nombreArch);

    if (arch.is_open()){
        int n;
        arch >>  n;
        arch.ignore();
        
        vector<vector<int>> matriz(n, vector<int>(n));

        for(int i =0; i<n; i++){
            string linea;
            getline(arch, linea);
            stringstream ss(linea);
            string num;

            for(int j= 0;j<n;j++){
                getline(ss, num, ',');
                matriz[i][j] = stoi(num);
            }
        }

        arch.close();

        cout << "Matriz leida del archivo: " << endl;
        for(int i = 0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }

    }else{
        cout << "No se pudo abrir el archivo. " << endl;
    }


    return 0;
}