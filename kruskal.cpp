#include <bits/stdc++.h>
#define lint long long
#define st first
#define nd second

using namespace std;

int pai[1000];
int tam[1000];
void init(int n){
    for(int i = 0; i < n; i++){
        pai[i] = i;
    }
}

int Find(int u){
    if(u == pai[u]){
        return u;
    }
    pai[u] = Find(pai[u]);
    return pai[u];
}


void Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u == v){
        return;
    }
    if(tam[u] < tam[v]){
        pai[u] = v;
        tam[v] += tam[u];
    } else {
        pai[v] = u;
        tam[u] += tam[v];
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    init(n);
    vector<pair<int, pair<int, int>>>arestas(m);
    for(int i = 0; i < m; i++){
        int p, u, v;
        cin >> u >> v >> p;
        arestas[i] = {p, {u, v}};

    }
    int total = 0;
    sort(arestas.begin(), arestas.end());
    for(int i = 0; i < m; i++){
        int u = arestas[i].nd.st;
        int v = arestas[i].nd.nd;
        int p = arestas[i].st;
        if(Find(u) != Find(v)){
            total += p;
            Union(u, v);
        }
    }
    cout << total << '\n';


    return 0;
}