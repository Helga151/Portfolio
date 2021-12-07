#include <iostream>
using namespace std;

int main ()
{
int n, x, i, variable, c, solution, zm;
int tab[1001];
cin >> n;
while (n--)
{
    cin >> x;
    c = 0;
    solution = 1;
    //5 * 2 daje mi 10, jak przez nie podzielê, to nie bêdê mieæ zer na koñcu
    for (i = 2; i <= x; i++) //wpisujê wszystkie przed x do tablicy
    {
        variable = i;
        while (variable % 5 == 0) //sprawdzam podzielnoœæ przez 5
        {
            variable /= 5;
            c++; //ile jest pi¹tek
        }
        tab[i] = variable; //podstawiam pozosta³oœci po dzieleniu przez 5
    }

    for (i = 2; i <= x; i++)
    {
        variable = tab[i];
        while (c && variable % 2 == 0) //usuwam dwójki
        {
            variable /= 2;
            c--;
        }
        tab[i] = variable;
    }
    //ju¿ nie mam zer na koñcu
    //u¿ywam wzoru z arytmetyki modularnej (a*b)mod 10 == ((a mod 10)(b mod 10)) mod 10
    for (i = 2; i <= x; i++)
    {
        zm = tab[i] % 10;
        cout << zm << " ";
        solution = (zm * (solution % 10)) % 10;
        cout << solution << "\n";
    }
    cout << solution << "\n";
}

return 0;
}
