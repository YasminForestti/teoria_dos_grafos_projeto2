#include <bits/stdc++.h>
#define first st
#define second nd
#define INF 0x3f3f3f3f
#define MAXN 100
using namespace std;
typedef pair<int, int>pii;

int pred[MAXN][MAXN];
int n, m;

void floyd_warshal(vector<vector<float>>&g){
    for(int i =0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j || g[i][j] == INF){
                pred[i][j] = -1;
            } else {
                pred[i][j] = i;
            }
        }
    }

    for(int k =0; k < n; k++){
        for(int u = 0; u < n; u++){
            for(int v = 0; v < n; v++){
                if((u == v) && (u == pred[v][k])) continue;
                if(g[u][v] > g[u][k] + g[k][v]){
                    cout << "d[" << u << "][" << v << "] = d[" << u << "][" << k << "] + d[" << k << "][" << v << "]";
                    cout << '\n';
                    cout << g[u][k] + g[k][v] << '\n';
                    g[u][v] = g[u][k] + g[k][v];
                    pred[u][v] = pred[k][v];
                }
            }
        }
    }


}       



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<vector<float>>g(n, vector<float>(n, INF));

    for(int u = 0; u < n; u++){
        g[u][u] = 0;
    }

    while(m--){
        int u, v;
        float p;
        cin >> u >> v  >> p;
        u--;
        v--;
        g[u][v] =  g[v][u]  = p; 
    }


    floyd_warshal(g);
    cout << g[0][2] << '\n'; 
    return 0;
}
