#include <iostream>
#include <set>
using namespace std;
int main ()
{

int n, x, y, zm, a, c, b, d, i, j, p;

multiset <int> left_;
multiset <int>::iterator l_it;
multiset <int> right_;
multiset <int>::iterator r_it;

//cin >> n >> x >> y;
while(cin >> n >> x >> y)
{
    if((n * 2 < x || n * 2 < y) && x != y)
    {
        zm = (n + 1) * (n + 1);
    }
    else
    {
        left_.clear();
        right_.clear();
        zm = 0;
        p = 1;
        for(a = 0; a < n; a++)
        {
            for(c = p; c <= n; c++)
            {
                i = x * (a * a - c * c);
                left_.insert(i);
            }
            p++;
        }

        /*for(l_it = left_.begin(); l_it != left_.end(); l_it++)
        {
            cout << *l_it << " ";
        }*/

        p = 1;
        for(b = 1; b <= n; b++)
        {
            for(d = 0; d < p; d++)
            {
                j = y * (d * d - b * b);
                right_.insert(j);
            }
            if(p > n)
            {
                break;
            }
            p++;
        }

        /*cout << "\n";
        for(r_it = right_.begin(); r_it != right_.end(); r_it++)
        {
            cout << *r_it << " ";
        }
        cout << "\n";*/
        for(l_it = left_.begin(); l_it != left_.end(); l_it++)
        {
            for(r_it = right_.begin(); r_it != right_.end(); r_it++)
            {
                if(*l_it >= 0)
                {
                    break;
                }
                if(*l_it == *r_it)
                {
                    //cout << *r_it << " ";
                    zm++;
                }

            }
        }
        zm = (zm * 2) + ((n + 1) * (n + 1));
        //cout << "\n";
    }
    cout << zm << "\n";
}

return 0;
}
