#include <iostream>
using namespace std;
int main ()
{
int current, prev, res = 0;
cin >> prev;
while(cin >> current)
{
    if(current > prev) {
        res++;
    }
    prev = current;
}

cout << res;
return 0;
}
