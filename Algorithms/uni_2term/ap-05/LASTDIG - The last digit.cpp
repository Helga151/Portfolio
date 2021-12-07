#include <iostream>
using namespace std;
int main ()
{
int t, a;
long long b, zm;
cin >> t;
while(t--)
{
    cin >> a >> b;

    //only one option for those ones
    if(b == 0) cout << "1\n";

    else if(a == 0 || a == 1 || a == 5 || a == 6 || a == 10 || a == 11 || a == 15 || a == 16 || a == 20)
    {
        if(a < 10) cout << a << "\n";
        else cout << a % 10 << "\n";
    }

    else if(a == 2 || a == 12)
    {
        zm = b % 4;

        if(zm == 0) cout << "6\n";
        if(zm == 1) cout << "2\n";
        if(zm == 2) cout << "4\n";
        if(zm == 3) cout << "8\n";
    }

    else if(a == 3 || a == 13)
    {
        zm = b % 4;

        if(zm == 0) cout << "1\n";
        if(zm == 1) cout << "3\n";
        if(zm == 2) cout << "9\n";
        if(zm == 3) cout << "7\n";
    }

    else if(a == 4 || a == 14)
    {
        zm = b % 2;

        if(zm == 0) cout << "6\n";
        if(zm == 1) cout << "4\n";
    }

    else if(a == 7 || a == 17)
    {
        zm = b % 4;

        if(zm == 0) cout << "1\n";
        if(zm == 1) cout << "7\n";
        if(zm == 2) cout << "9\n";
        if(zm == 3) cout << "3\n";
    }

    else if(a == 8 || a == 18)
    {
        zm = b % 4;

        if(zm == 0) cout << "6\n";
        if(zm == 1) cout << "8\n";
        if(zm == 2) cout << "4\n";
        if(zm == 3) cout << "2\n";
    }

    else //if(a == 9 || a == 19)
    {
        zm = b % 2;

        if(zm == 0) cout << "1\n";
        if(zm == 1) cout << "9\n";
    }

}

return 0;
}
