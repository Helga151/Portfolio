#include <iostream>
using namespace std;
int main ()
{
    int t, s, maxx = 0, zm = 0;
    cin >> t;
    while(t--)
    {
        cin >> s;
        if(s == 1)
        {
            zm++;
            if(zm > maxx) maxx = zm;
        }
        else
        {
            zm = 0;
        }
    }
    cout << maxx;

return 0;
}
