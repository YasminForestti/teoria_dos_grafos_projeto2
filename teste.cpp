#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <time.h>
#include <string>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line, num,outro,peso;
    int num1,num2, indice;
    float pes;
    vector<int> input;
    line = "10 9 2.999";
    
    for(int i=0; i< line.size(); i++){
        if(line[i] != ' '){
            num +=line[i];
        }else{
            indice = i;
            num1 = stoi(num);
            input.push_back(num1);
            break;
        }
    }
        for(int i=indice + 1; i< line.size(); i++){
        if(line[i] != ' '){
            outro +=line[i];
        }else{
            indice = i;
            num2 = stoi(outro);
            input.push_back(num2);
            break;
        }
    }
    if(indice != line.size()){
        for(int i=indice + 1; i < line.size(); i++){
            peso +=line[i];
    }
    
    pes = stof(peso);
    cout << pes << '\n';
    input.push_back(pes);
    }
    cout << ' '<< input[0]<< ' '<< input[1] << ' ' << pes; 

    return 0;
}