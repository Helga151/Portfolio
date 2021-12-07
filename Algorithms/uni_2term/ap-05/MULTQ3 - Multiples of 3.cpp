#include <iostream>
using namespace std;
int main ()
{
int n, q;
cin >> n >> q;
int* tab = new int[n];

for(int i = 0; i < n; i++)
{
    tab[i] = 0;
}

while(q--)
{
    int f, a, b;
    cin >> f >> a >> b;

    if(f == 1)
    {
        int zm = 0;

        for(int i = a; i <= b; i++)
        {
            if(tab[i] % 3 == 0) zm++;
        }
        cout << zm << "\n";
    }

    else
    {
        for(int i = a; i <= b; i++)
        {
            tab[i]++;
        }
    }
}

delete [] tab;

return 0;
}
