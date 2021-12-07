#include <iostream>
#include <string>
using namespace std;
int main ()
{
int t, res, i;
string n;
cin >> t;
while(t--)
{
    res = 0;
    cin >> n;
    for(i = 0; i < n.size(); i++)
    {
        res += ((int)n[i] - 48);
    }
    cout << res << "\n";
}

return 0;
}
