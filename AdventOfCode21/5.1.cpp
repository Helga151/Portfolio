#include <iostream>
int tab[1000][1000];
using namespace std;
int main ()
{

for(int i = 0; i < 1000; i++) {
    for(int j = 0; j < 1000; j++) {
        tab[i][j] = 0;
    }
}
int x1, y1, x2, y2;
while(cin >> x1 >> y1 >> x2 >> y2) {
    //horizontal or vertical lines
    if(x1 == x2) {
        //cout << x1 << " = " << x2 << "\n";
        int ymin = min(y1, y2);
        int ymax = max(y1, y2);
        for(int i = ymin; i <= ymax; i++) {
            //cout << i << ": ";
            tab[i][x1]++;
            //cout << tab[i][x1] << " ";
        }
    //cout << "\n";
    }
    else if (y1 == y2) {
        //cout << y1 << " = " << y2 << "\n";
        int xmin = min(x1, x2);
        int xmax = max(x1, x2);
        for(int i = xmin; i <= xmax; i++) {
            //cout << i << ": ";
            tab[y1][i]++;
            //cout << tab[y1][i] << " ";
        }
    //cout << "\n";
    }
}

int res = 0;
for(int i = 0; i < 1000; i++) {
    for(int j = 0; j < 1000; j++) {
        //cout << tab[i][j] << " ";
        if(tab[i][j] > 1) res++;
    }
    //cout << "\n";
}
cout << res;

return 0;
}
