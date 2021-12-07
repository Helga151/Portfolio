#include <iostream>
#include <set>
using namespace std;
int main ()
{
    int t, f, x;
    set <int> s;
    set <int>::iterator it_s;
    cin >> t;
    while(t--)
    {
        cin >> f;
        if(f == 3)
        {
            it_s = s.begin();
            cout << *it_s << "\n";
        }
        else if(f == 1)
        {
            cin >> x;
            s.insert(x);
        }
        else //if f == 2
        {
            cin >> x;
            s.erase(x);
        }
    }

return 0;
}
