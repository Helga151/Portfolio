#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
int main ()
{
string s, res_co2, res_oxygen;
vector <string> all;
vector <string> all_co2;
int amount = 0, o = 0, o_co2 = 0;
while(cin >> s) {
    all.push_back(s);
    all_co2.push_back(s);
    if(s[0] == '1') {
        o++;
        o_co2++;
    }
    amount++;
}

vector <string> oxygen;
int sizee = 2;
for(int j = 0; j < 12; j++) {
    if(sizee > 1) {
        if(o >= (double)amount / 2) { //jedynek jest wiecej lub rowno
            for(int i = 0; i < all.size(); i++) {
                if(all[i][j] == '1') {
                    oxygen.push_back(all[i]); //1 do tlenu
                }
            }
        }

        else { //wiecej zer
            for(int i = 0; i < all.size(); i++) {
                if(all[i][j] == '0') {
                    oxygen.push_back(all[i]); //0 do tlenu
                }
            }
        }

        sizee = oxygen.size();
        amount = oxygen.size();
        o = 0;
        all.clear();
        for(int i = 0; i < oxygen.size(); i++) {
            all.push_back(oxygen[i]);
            if(oxygen[i][j + 1] == '1' && j + 1 < 12) o++;
        }
        oxygen.clear();
        //cout << "\n";
    }
    else {
        break;
    }
}
res_oxygen = all[0];

vector <string> co2;
sizee = 2;
amount = all_co2.size();
for(int j = 0; j < 12; j++) {
    //cout << j << ": " << "amount: " << amount << " jedynki: " << o_co2 << " ";
    if(sizee > 1) {
        if(o_co2 > (double)amount / 2) { //jedynek wiecej
            //cout << "pierwsza: ";
            for(int i = 0; i < all_co2.size(); i++) {
                if(all_co2[i][j] == '0') {
                    co2.push_back(all_co2[i]); //0 do co2
                }
            }
        }
        else if(o_co2 == (double)amount / 2) {
            //cout << "trzecia: ";
            for(int i = 0; i < all_co2.size(); i++) {
                if(all_co2[i][j] == '0') {
                    co2.push_back(all_co2[i]); //0 do co2
                }
            }
        }
        else{ //wiecej zer
            //cout << "druga: ";
            for(int i = 0; i < all_co2.size(); i++) {
                if(all_co2[i][j] == '1') {
                    co2.push_back(all_co2[i]); //1 do co2
                }
            }
        }

        sizee = co2.size();
        amount = co2.size();
        o_co2 = 0;
        all_co2.clear();
        for(int i = 0; i < co2.size(); i++) {
            all_co2.push_back(co2[i]);
            if(co2[i][j + 1] == '1' && j + 1 < 12) o_co2++;
        }
        co2.clear();
        //cout << "\n";
    }
    else {
        break;
    }
}
res_co2 = all_co2[0];

int j = 0, res_o = 0, res_c = 0;
for(int i = res_oxygen.size() - 1; i >= 0; i--) {
    if(res_oxygen[i] == '1') {
        res_o += pow(2, j);
    }
    if(res_co2[i] == '1') {
        res_c += pow(2, j);
    }
    j++;
}

cout << res_oxygen << " " << res_co2 << " " << res_o << " " << res_c << " " << res_c * res_o;

return 0;
}
