#include <iostream>
using namespace std;
int main ()
{
int n;
cin >> n;

int* tab = new int[n];
int* res = new int[n];
long long sum = 0;

for(int i = 0; i < n; i++)
{
    cin >> tab[i];
    sum += tab[i];
}

long long* arr = new long long[sum + 1];

long long i = 0;
while(i != sum)
{
    for(int j = 0; j < n; j++)
    {
        if(tab[j] > 0)
        {
            arr[i] = tab[j];
            tab[j]--;
            if(tab[j] == 0)
            {
                res[j] = i + 1;
            }
            i++;
        }
    }
}

for(int i = 0; i < n; i++)
{
    cout << res[i] << "\n";
}

delete [] tab;
delete [] arr;

return 0;
}
