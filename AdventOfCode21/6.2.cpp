#include <iostream>
using namespace std;
int main ()
{
long long tab[10];
for(int i = 0; i < 9; i++) { //numbers from 0 to 8
    tab[i] = 0;
}

int a;
while(cin >> a) {
    tab[a]++;
}

for(int j = 0; j < 256; j++) {
    //cout << j << ": ";
    for(int i = 0; i < 9; i++) {
        //cout << tab[i] << " ";
    }
    long long add = tab[0]; //number 0 to know many add to 6 and 8
    for(int i = 0; i < 8; i++) {
        tab[i] = tab[i + 1];
    }
    tab[6] += add;
    tab[8] = add;

    //cout << "\n";
}

long long res = 0;
for(int j = 0; j < 9; j++) {
    res += tab[j];
}
cout << res;

return 0;
}
