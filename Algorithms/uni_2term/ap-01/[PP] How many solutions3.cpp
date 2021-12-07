#include <iostream>
using namespace std;
int wyniki[1000000];
/*porownywanie inta i doubla
double e = 0.0000001;
if(b + e > a && b - e < a) {

}*/
int main ()
{
int n, x, y, i, j, p, rez;

//while(
        cin >> n >> x >> y;//)
//{

    if((n * 2 < x || n * 2 < y) && x != y)
    {
        rez = (n + 1) * (n + 1);
    }

    else
    {
        rez = 0;
        double ulamek = double(x) / double(y);
        //cout << ulamek << "\n";

        for(i = 0; i <= n * n; i++)
        {
            wyniki[i] = 0;
        }

        p = 1;
        for(i = 0; i < n; i++)
        {
            for(j = p; j <= n; j++)
            {
                wyniki[(j * j) - (i * i)]++;
            }
            p++;
        }

        /*for(i = 0; i <= n * n; i++)
        {
            cout << i << ": " << wyniki[i] << "\n";
        }*/

        for(i = 1; i <= n * n; i++) //do kwadratu z n starczy
        {
            if(wyniki[i] != 0)
            {
                //chce tylko liczby calkowite
                if((x * i) % y == 0 && (x * i)/y <= 1000*1000)
                {
                    rez += wyniki[(x * i) / y] * wyniki[i];
                    //cout << wyniki[i_iloczyn] << " ";
                    //cout << i << ":" << i_iloczyn << " rez - " << rez << " ";
                }
            }
        }
        //cout << "\n" << rez << "\n";
        rez = (rez * 2) + (n + 1) * (n + 1);
    }

    cout << rez << "\n";
//}

return 0;
}
