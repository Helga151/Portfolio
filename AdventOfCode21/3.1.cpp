#include <iostream>
#include <string>
#include<cmath>
using namespace std;
int main ()
{
string s;
int ones[12];
for(int i = 0; i < 12; i++) {
    ones[i] = 0;
}

int amount = 0;
while(cin >> s) {
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '1') {
            ones[i]++;
        }
    }
    amount++;
}

string gamma, epsilon;
for(int i = 0; i < 12; i++) {
    //if(ones[i] != 0) {
        if (ones[i] > amount / 2) {
            gamma += '1';
            epsilon += '0';
        }
        else {
            gamma += '0';
            epsilon += '1';
        }
    //}
}

cout << "\n" << gamma << "\n" << epsilon << "\n";

int dec_gamma = 0, dec_epsion = 0, j = 0;
for(int i = gamma.size() - 1; i >= 0; i--) {
    if(gamma[i] == '1') {
        dec_gamma += pow(2, j);
    }
    j++;
}
j = 0;
for(int i = epsilon.size() - 1; i >= 0; i--) {
    if(epsilon[i] == '1') {
        dec_epsion += pow(2, j);
    }
    j++;
}

cout << dec_gamma << " " << dec_epsion << " " << dec_gamma * dec_epsion << "\n";

return 0;
}
