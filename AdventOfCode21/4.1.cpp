#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int main ()
{
vector <int> v;
int tab[101];
for(int i = 0; i < 100; i++) {
    cin >> tab[i];
}

int all [100][5][5];
for(int k = 0; k < 100; k++) {
    int a;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> all[k][i][j];
        }
    }
}

int win;
int last;
for(int l = 0; l < 100; l++) {
    //zaznacz we wszystkich tabelkach wylosowana liczbe
    for(int k = 0; k < 100; k++) {
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(all[k][i][j] == tab[l]) {
                    all[k][i][j] = -1;
                }
            }
        }
    }
    win = -1;
    //sprawdz czy ktoras wygrala
    for(int k = 0; k < 100; k++) {
        if(win == -1) {
            for(int i = 0; i < 5; i++) {
                if((all[k][i][0] == -1 && all[k][i][1] == -1 && all[k][i][2] == -1 && all[k][i][3] == -1 && all[k][i][4] == -1) ||
                   (all[k][0][i] == -1 && all[k][1][i] == -1 && all[k][2][i] == -1 && all[k][3][i] == -1 && all[k][4][i] == -1)) {
                    win = k;
                    last = tab[l];
                    //cout << k << " " << tab[l] << "\n";
                }
            }
        }
        else {
            break;
        }
    }
    if(win != -1) {
        break;
    }
}

//mam zwyciezce, musze wypisac wynik
int sum = 0;
for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
        if(all[win][i][j] != -1) {
            sum += all[win][i][j];
        }
    }
}
cout << sum << " " << last << " " << sum * last;

return 0;
}
