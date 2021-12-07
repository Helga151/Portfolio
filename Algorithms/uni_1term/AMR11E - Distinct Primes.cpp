#include <iostream>
using namespace std;
bool is_Prime (int a)
{
    int i;
    for(i = 2; i * i <= a; i++)
    {
        if(a % i == 0) return false;
    }
    return true;
}
bool is_Lucky (int a)
{
    int i, res = 0;
    for(i = 2; i * 2 <= a; i++)
    {
        if((a % i == 0) && (is_Prime(i) == true)) res++; //does not count the same i, so for 60 is true because 2*3*5
        if(res >= 3) return true;
    }
    return false;
}
int main ()
{
    int lucky[1001];
    int i, j, t, n;
    j = 1;
    for(i = 30; i < 5000; i++)
    {
        if(is_Lucky(i) == true && j < 1001)
        {
            lucky[j] = i;
            j++;
        }
    }
    for (i = 1; i < 1001; i++)
    {
        cout << lucky[i] << " ";
    }
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << lucky[n] << "\n";
    }

return 0;
}
