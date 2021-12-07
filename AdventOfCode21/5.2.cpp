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
        int ymin = min(y1, y2);
        int ymax = max(y1, y2);
        for(int i = ymin; i <= ymax; i++) {
            tab[i][x1]++;
        }
    }
    else if (y1 == y2) {
        int xmin = min(x1, x2);
        int xmax = max(x1, x2);
        for(int i = xmin; i <= xmax; i++) {
            tab[y1][i]++;
        }
    }
    else { //diagonal lines
        int xmin = min(x1, x2);
        int xmax = max(x1, x2);
        int ymin = min(y1, y2);
        int ymax = max(y1, y2);
        for(int i = 0; i <= (xmax - xmin); i++) {
            int xi = i, yi = i;
            if(x1 > x2) xi *= (-1);
            if(y1 > y2) yi *= (-1);
            //cout << xi << " " << yi << " : ";
            tab[y1 + yi][x1 + xi]++;
        }
    }
    //cout << "\n";
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
