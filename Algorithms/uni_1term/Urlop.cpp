#include <iostream>
#include <string>
using namespace std;
int main ()
{
int n, res = 0, maxx = 0;
char t;
cin >> n;
while(n--)
{
    cin >> t;
    if(t == 'S')
    {
        res++;
        if(res > maxx)
        {
            maxx = res;
        }
    }
    else
    {
        res = 0;
    }
}
cout << maxx;
return 0;
}
