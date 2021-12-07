#include <iostream>
#include <set>
using namespace std;
int main ()
{
    int t, n;
    long long x, b, e;
    unsigned long long result = 0;
    multiset <long long> ms;
    multiset <long long>::iterator it_ms;
    multiset <long long>::reverse_iterator rit_ms;
    cin >> t;
    while (t--)
    {
        cin >> n;
        while (n--)
        {
            cin >> x;
            ms.insert(x);
        }
        it_ms = ms.begin();
        b = *it_ms;
        ms.erase(it_ms);
        rit_ms = ms.rbegin();
        e = *rit_ms;
        ms.erase((++rit_ms).base()); //reverse_iterator na iterator
        result += (e - b);
    }
    cout << result;

return 0;
}
