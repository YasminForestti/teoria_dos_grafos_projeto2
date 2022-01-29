#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <time.h>
#include <string>
using namespace std;
    void input_semPeso(string line){
            
            string vertice1,vertice2;
            vector<int> input(2);
            int v,u,indice;
            for(int i=0; i<line.size(); i++){
                if(line[i] != ' '){
                    vertice1 += line[i];
                }else{
                    
                    indice=i;
                    v = stoi(vertice1);
                    
                    input[0] = v;
                    cout << input[0] << "\n";
                    break;
                }
            }    
            for(int i=indice+1; i<line.size(); i++){
                    vertice2 += line[i];
                    u = stoi(vertice2);
                    input[1] = u;            
            }
          
        cout << input[0] << ' ' << input[1];
        };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    getline(cin, line);
    input_semPeso(line);
    return 0;
}