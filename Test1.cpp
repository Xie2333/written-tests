#include<iostream>
#include<vector>
#include<string>
using namespace std;

void reTurnOut(vector<vector<string>>&intPut,vector<string>&outPut,string s,int intNumb) {
    if (intNumb == intPut.size()) {
        outPut.push_back(s);
        return;
    }
    for (int i = 0; i < intPut[intNumb].size(); i++) {
        string s1 = s;
        reTurnOut(intPut, outPut, s += intPut[intNumb][i], intNumb + 1);
        s = s1;
    }
}
vector<string> reTurn(vector<vector<string>>intPut) {
    if (intPut.size() == 0) {
        return {};
    }
    if (intPut.size() == 1) {
        return intPut[0];
    }
    vector<string>OutPut;
    reTurnOut(intPut, OutPut, "", 0);
    return OutPut;
}

int main(void) {
    vector<string>v1{ "a","b","cd" };
    vector<string>v2{ "de"};
    vector<string>v3{ "e","f" };
    vector<vector<string>>v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    vector<string>Out = reTurn(v);cout << endl;
    for (string s : Out) {
        cout << s << " ";
    }
}