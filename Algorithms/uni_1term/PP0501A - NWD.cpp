#include <iostream>
using namespace std;
int euklides(int a, int b)
{
	while(b)
    {
       swap(a %= b, b);
    }
	return a;
}
int main ()
{
    int n, a, b;
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        cout << euklides (a, b) << "\n";
    }
return 0;
}
