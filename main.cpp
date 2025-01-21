#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(const vector<vector<int>> &graph, int src, int dest){
    int n = graph.size();
    vector<int> dist(n,INF);
    vector<int> parent(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        for (int v =0; v<n;v++){
            if(graph[u][v] && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
                parent[v] =u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[dest] == INF){
        cout << "No hay un camino desde el nodo inicial hasta el nodo destino." << endl;
    } else{
        cout << "La distancia minima desde el nodo inicial hasta el nodo destino es: " << dist[dest] << endl;
        cout << "El camino mas corto es: ";

        vector<int> path;
        for (int v= dest; v != -1; v = parent[v]) {
            path.push_back(v);
        }

        for(int i = path.size() -1; i >=0; i--){
            cout << char('A' + path[i]);
            if (i > 0){
                cout << "->";
            }
        }
        cout << endl;
    }

}


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

    char nodo_destino;
    cout << "Ingrese hasta que nodo quiere llegar (A, B, C, D, E...): ";
    cin >> nodo_destino;

    int dest = nodo_destino - 'A';

    dijkstra(matriz, 0, dest);
    
    }else{
        cout << "No se pudo abrir el archivo. " << endl;
    }


    return 0;
}