#include <bits/stdc++.h>
#define first st
#define second nd
#define INF 0x3f3f3f3f
#define MAXN 100
using namespace std;
typedef pair<int, int>pii;
int g[MAXN][MAXN];
int pred[MAXN][MAXN];
int n, m;

void floyd_warshal(){
    for(int i =0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j || g[i][j] == INF){
                pred[i][j] = -1;
            } else {
                pred[i][j] = i;
            }
        }
    }

    for(int k =0; k < n+1; k++)
        for(int u = 0; u < n; u++)
            for(int v = 0; v < n; v++)
                if(g[u][v] > g[u][k] + g[k][v]){
                    //verificar se entrou nesse loop na n-ésima primeira iteração para detectar ciclo
                    g[u][v] = g[u][k] + g[k][v];
                    pred[u][v] = pred[k][v];
                } else {
                    g[u][v] = g[u][v];
                }

}       



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    memset(g, INF, sizeof g);
    for(int u = 0; u < n; u++){
        g[u][u] = 0;
    }

    while(m--){
        int u, v, p;
        cin >> u >> v  >> p;
        g[u][v] = g[v][u] =  p; 
    }

    floyd_warshal();
    int i = 0, j = 2;
    cout << j << '\n';
    while(true){
        j = pred[i][j];
        if(j == -1){
            break;
        } else {
            cout << j << '\n';
        }
    }

    return 0;
}
