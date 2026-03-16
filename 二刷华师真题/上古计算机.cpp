#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int reg[5];
// 耗时13min
int main(){

    unordered_map<string, int> mp;
    mp["AX"] = 1;
    mp["BX"] = 2;
    mp["CX"] = 3;
    mp["DX"] = 4;
    string ins1, ins2;
    while(true){
        cin >> ins1 >> ins2;
        string regName = ins2.substr(0, 2);
        if(ins1 == "IN"){
            string number = ins2.substr(ins2.find(',') + 1);
            int num = stoi(number);
            // cout << regName << " " << number;
            reg[mp[regName]] = num;
        }
        if(ins1 == "MOV"){
            string regName2 = ins2.substr(ins2.find(',') + 1);
            reg[mp[regName]] = reg[mp[regName2]];
        }
        if(ins1 == "ADD"){
            string regName2 = ins2.substr(ins2.find(',') + 1);
            reg[mp[regName]] += reg[mp[regName2]];
        }
        if(ins1 == "SUB"){
            string regName2 = ins2.substr(ins2.find(',') + 1);
            reg[mp[regName]] -= reg[mp[regName2]];
        }
        if(ins1 == "MUL"){
            string regName2 = ins2.substr(ins2.find(',') + 1);
            reg[mp[regName]] *= reg[mp[regName2]];
        }
        if(ins1 == "DIV"){
            string regName2 = ins2.substr(ins2.find(',') + 1);
            reg[mp[regName]] /= reg[mp[regName2]];
        }
        if(ins1 == "OUT"){
            cout << reg[mp[regName]] << endl;
            break;
        }
    }
}