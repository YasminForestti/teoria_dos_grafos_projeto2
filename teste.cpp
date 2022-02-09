#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <time.h>
#include <string>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>pai;
    pai.insert(pai.begin(),2);
    pai.insert(pai.begin(),7);
    for(int i =0; i<pai.size(); i++){
        cout<< pai[i] << ' ';
    }
    return 0;
}