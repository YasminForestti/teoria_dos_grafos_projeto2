#include <iostream>
#include <utility>
#include <stdio.h>
#include <bits/stdc++.h>
#include <time.h>
#include <string>
#define INF 0x3f3f3f3f
#define st first
#define nd second
using namespace std;
typedef pair<float,int> pfi;

class biblioteca{
    int numVertices, peso, neg;
    vector<vector<int>> matrizPred;
    vector<vector<pfi>>grafo;
    vector<vector<float>>matrizGrafo;
    vector<int>pais;
    public:
        biblioteca(int);
        
        float dijkstra(int u, int b){
            vector<float>dist(numVertices);
            vector<bool>vis(numVertices);
            pais.resize(numVertices, -1);
            for(int i = 0; i < grafo.size(); i++){
                dist[i] = INF;
                vis[i] = false;   
            } 
            
            priority_queue <pfi, vector<pfi>, greater<pfi> > q;
            dist[u] = 0;
            q.push({dist[u], u});
            
            while(!q.empty()) {
                int f=q.top().nd;

                if(f == b){
                    return dist[b];
                }
                q.pop(), vis[f]=true;
                for(pfi e: grafo[f]){
                    float p = e.st;
                    int v = e.nd;
                    if (vis[v]) continue;
                    float novo_dist = dist[f] + p;
                    if(novo_dist<dist[v]){
                        dist[v] = novo_dist;
                        q.push({dist[v],v});
                        pais[v] = f;
                    }
                }
            }
        }
        void Verifica_input(string line){
            int space=0;
            for(int i=0;i<line.size();i++){
                if(line[i] == ' '){
                    space += 1;
                }
            }
            if(space == 1){
                peso = 0;
            } else {
                peso = 1;
            }
            return;
        }        
        void Insert(){
            string line;
            // grafo.resize(numVertices);    
            vector<vector<pfi>>g(numVertices);
            vector<vector<float>>matriz(numVertices , vector<float>(numVertices,INF));
            peso = -1;
            neg = 0;
            while(getline(cin,line)){
                if(!line.size()) continue;
                if(peso == -1) Verifica_input(line);
                if(peso){
                    int u, v;
                    float p;
                    string vertice1,vertice2,peso_value;
                    int indice;
                    for(int i=0; i<line.size(); i++){
                        if(line[i] != ' '){
                            vertice1 += line[i];
                        }else{
                            indice=i;
                            v = stoi(vertice1);
                            break;
                        }
                    }
                    for(int i=indice+1; i<line.size(); i++){
                        if(line[i] != ' '){
                            vertice2 += line[i];
                        }else{
                            indice=i;
                            u = stoi(vertice2);
                            break;
                        }
                    }    
                    for(int i=indice+1; i<line.size(); i++){
                        peso_value += line[i];
                    }
                    p = stof(peso_value);  
                    if(p < 0) neg = 1;  
                    u--;
                    v--;
                    g[u].push_back({p, v});
                    g[v].push_back({p, u});
                    matriz[v][u] = p;

                } else {
                    string vertice1,vertice2;
                    int v,u,indice;
                    for(int i=0; i<line.size(); i++){
                        if(line[i] != ' '){
                            vertice1 += line[i];
                        }else{
                            indice=i;
                            v = stoi(vertice1);
                            break;
                        }
                    }    
                    for(int i=indice+1; i<line.size(); i++){
                        vertice2 += line[i];
                    }
                    u = stoi(vertice2);      
                    u--;
                    v--;
                    g[u].push_back({1.0, v});
                    g[v].push_back({1.0, u});
                }

            }
            grafo = g;
            matrizGrafo = matriz;
        }

        vector<vector<float>> floyd_warshal(){
            vector<vector<int>>pred(numVertices , vector<int>(numVertices ));
            vector<vector<float>>matrizFloyd;
            matrizFloyd = matrizGrafo;
            
            for(int i =0; i < numVertices; i++){
                matrizFloyd[i][i] = 0;
                for(int j = 0; j < numVertices; j++){
                    if(i == j || matrizFloyd[i][j] == INF){
                        pred[i][j] = -1;
                    } else {
                        pred[i][j] = i;
                    }
                }
            }
            for(int k =0; k < numVertices; k++){
                for(int u = 0; u < numVertices; u++){
                    for(int v = 0; v < numVertices; v++){
                        if(matrizFloyd[u][v] > matrizFloyd[u][k] + matrizFloyd[k][v]){
                            matrizFloyd[u][v] = matrizFloyd[u][k] + matrizFloyd[k][v];
                            pred[u][v] = pred[k][v];
                        }
                    }
                    
                }
            }

            matrizPred = pred;
            return matrizFloyd;
        }       


        int distancia(int i, int f){
            i--;
            f--;
            vector<vector<float>>matrizDist;
            if(neg){
                cout << "Distancia: " << '\n';
                matrizDist = floyd_warshal();
                cout << matrizDist[i][f] << '\n';
                cout << "Caminho Minimo: " << '\n';
                int pai = f;
                    while(pai != -1){
                        cout << pai + 1 << " ";
                        pai = matrizPred[i][pai];
                    }
                    cout << '\n';

            } else if (peso) {
                cout << "Distancia: " << '\n';
                cout << dijkstra(i, f) << '\n';
                cout << "Caminho Minimo: " << '\n';
                int pai = f;
                while(pai != -1){
                    cout << pai + 1 << " ";
                    pai = pais[pai];
                }
                cout << '\n';
            } else {
                cout << "bfs" << '\n';
            }
        }     
};

biblioteca::biblioteca(int n){
    numVertices = n;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numVertices,u,v;
    
    cin >> numVertices;
    biblioteca teste(numVertices);
    teste.Insert();
    teste.distancia(3, 5);
    return 0;
}
