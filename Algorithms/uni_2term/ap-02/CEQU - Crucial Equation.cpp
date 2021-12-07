#include <iostream>
using namespace std;
int nwd(int a, int b)
{
    while(b)
    {
        swap(a %= b, b);
    }
    return a;
}
//linear diophantine equation
int main ()
{
int n, a, b, c, i;
cin >> n;
for(i = 1; i <= n; i++)
{
    cin >> a >> b >> c;
    cout << "Case " << i;
    if(c % nwd(a, b) == 0) cout << ": Yes\n";
    else cout << ": No\n";

}

return 0;
}
