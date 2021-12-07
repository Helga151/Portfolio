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

int win[100];
for(int k = 0; k < 100; k++) {
    win[k] = 0;
}
int last, last_win;
for(int l = 0; l < 100; l++) {
    //zaznacz we wszystkich tabelkach wylosowana liczbe
    for(int k = 0; k < 100; k++) {
        if(win[k] != 1) { //juz wygral, to nie sprawdzam kolejny raz
            for(int i = 0; i < 5; i++) {
                for(int j = 0; j < 5; j++) {
                    if(all[k][i][j] == tab[l]) {
                        all[k][i][j] = -1;
                    }
                }
            }
        }
    }
    //sprawdz czy ktoras wygrala
    for(int k = 0; k < 100; k++) {
        if(win[k] != 1) { //juz wygral, to nie sprawdzam kolejny raz
            for(int i = 0; i < 5; i++) {
                if((all[k][i][0] == -1 && all[k][i][1] == -1 && all[k][i][2] == -1 && all[k][i][3] == -1 && all[k][i][4] == -1) ||
                   (all[k][0][i] == -1 && all[k][1][i] == -1 && all[k][2][i] == -1 && all[k][3][i] == -1 && all[k][4][i] == -1)) {
                    win[k] = 1;
                    last_win = k;
                    last = tab[l];
                    cout << l << ": " << k << " " << tab[l] << "\n";
                }
            }
        }
    }
}

//mam zwyciezce, musze wypisac wynik
int sum = 0;
for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
            cout << all[last_win][i][j] << " ";
        if(all[last_win][i][j] != -1) {
            sum += all[last_win][i][j];
        }
    }
    cout << "\n";
}
cout << sum << " " << last << " " << sum * last;

return 0;
}
