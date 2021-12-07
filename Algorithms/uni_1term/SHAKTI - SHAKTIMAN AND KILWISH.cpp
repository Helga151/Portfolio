#include <iostream>
using namespace std;
/*bool factors (int N)
{
    int i, result = 1;
    if (N == 1)
    {
        return false;
    }
    for (i = 2; i * i < N; i++)
    {
        if (N % i == 0)
        {
            result += 2;
        }
    }
    if (i * i == N) result ++;
    //return result;
    if (result % 2 == 0)
    {
        return false;
    }
    return true;
}*/
int main ()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);*/

    int N, t;
    cin >> t;
    while (t--)
    {
        cin >> N;
        if (N % 2 == 0) cout << "Thankyou Shaktiman\n";
        else cout << "Sorry Shaktiman\n";
    }


return 0;
}
