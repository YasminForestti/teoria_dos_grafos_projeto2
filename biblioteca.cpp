#include <iostream>
#include <utility>
#include <stdio.h>
#include <bits/stdc++.h>
#include <time.h>
#include <string>
using namespace std;
typedef pair<float,int> pfi;

class biblioteca{
    int numVertices, peso;
    
    vector<vector<pfi>>grafo;

    public:
        biblioteca(int);
        
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
            peso = -1;
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
                    u--;
                    v--;
                    g[u].push_back({p, v});
                    g[v].push_back({p, u});
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
    return 0;
}
