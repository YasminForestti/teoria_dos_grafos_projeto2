#include <bits/stdc++.h>
#define lint long long
#define st first
#define nd second
#define INF 0x3f3f3f3f
#define MAXN 10000
using namespace std;

typedef pair<int, int> pii;
int burac[MAXN];
bool vis[MAXN];

int dijkstra(int u, vector<vector<pii> > &g, int b){
    for(int i = 0; i < g.size(); i++){
   	 burac[i] = INF;
     vis[i] = false;   
    } 
    
    priority_queue <pii, vector<pii>, greater<pii> > q;
    burac[u] = 0;
    q.push({burac[u], u});
    
    while(!q.empty()) {
   	    int f=q.top().nd;
   	    q.pop(), vis[f]=true;
        if(b == f){
            return burac[f];
        }
   	 for(pii e: g[f]){
   		 int p = e.st, v = e.nd;
   		 if (vis[v]) continue;
   		 int novo_burac = burac[f] + p;
   		 if(novo_burac<burac[v]){
   			 burac[v] = novo_burac;
   			 q.push({burac[v],v});
   		    }
   	    }
    }
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pii>>grafo(n+2);
    for(int i = 0; i < m; i++){
        int u, v, p;
        cin >> u >> v >> p;
        grafo[u].push_back({p, v});
        grafo[v].push_back({p, u});
    }
    cout << dijkstra(0, grafo, n+1) << '\n';
    return 0;
}