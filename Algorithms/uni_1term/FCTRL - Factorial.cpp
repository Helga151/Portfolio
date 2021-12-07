#include <iostream>
using namespace std;
int main ()
{
    int t, n, res;
    cin >> t;
    while (t--)
    {
        res = 0;
        cin >> n;
        while(n > 1)
        {
            n /= 5;
            res += n;
        }
        cout << res << "\n";
    }

return 0;
}
