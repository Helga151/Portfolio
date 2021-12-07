#include <iostream>
#include <map>
using namespace std;
int tab[1500][2];
double a[1500][1500];

int main ()
{
int n, i, j, tri = 0;
double x1, x2, y1, y2;
cin >> n;
for(i = 0; i < n; i++)
{
    cin >> tab[i][0] >> tab[i][1];
}

for(i = 0; i < n - 1; i++) //a == (y1-y2)/(x1-x2)
{
    x1 = tab[i][0]; cout << x1 << " ";
    y1 = tab[i][1]; cout << y1 << " ";
    for(j = i + 1; j < n; j++)
    {
        cout << "\n";
        x2 = tab[j][0]; cout << x2 << " ";
        y2 = tab[j][1]; cout << y2 << " ";
        if(x1 == x2 || y1 == y2) //vertical or horizontal line
        {
            a[i][j] = 0;
        }
        else
        {
            a[i][j] = (y1-y2)/(x1-x2);
            cout << a[i][j] << " ";
        }
    }
    cout << "\n*******\n";
}

/*for(i = 0; i < n - 1; i++)
{
    zm = a[i][j];
    for(j = n; j > 0; j--)
    {
        if(a[i][j] != 0 && )
        {
            tri++;
        }
    }
}*/
//cout << "tri: " << tri << " ";

for(i = 0; i < n - 1; i++)
{
    for(j = i + 1; j < n; j++)
    {
        cout << a[i][j] << " ";
    }
    cout << "\n";
}
return 0;
}
