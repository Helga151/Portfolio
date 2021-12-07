#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string subtract(string n)
{
    int i, sizee, last;
    sizee = n.size();
    last = n[sizee - 1] - '0';
    if(last == 0)
    {
        i = sizee - 1;
        while(n[i] == '0')
        {
            n[i] = '9';
            i--;
        }
        n[i] = (n[i] - '0') - 1 + '0';
    }
    else
    {
        n[sizee - 1] = (last - 1) + '0';
    }
    return n;
}

string multiply(string s)
{
    int i, carry = 0, mul;
    string result = "";
    for(i = s.size() - 1; i >= 0; i--)
    {
        mul = (s[i] - '0') * 2 + carry;
        carry = mul / 10;
        result += to_string(mul % 10);
    }
    if(carry > 0)
    {
        result += to_string(carry);
    }
    reverse(result.begin(), result.end());
    return result;
}

/*string substract (string n)
{
    int sizee, last, i;
    sizee = n.size();
    last = n[sizee - 1] - 48; //ASCII code
    if(sizee == 1 && last == 0)
    {
        return n;
    }
    if(last != 0)
    {
        last -= 1;
        n[sizee - 1] = last + 48;
    }
    else
    {
        i = sizee - 1;
        while((n[i] - 48) == 0)
        {
            n[i] = 9 + 48; //change to 0
            i--;
        }
        n[i] -= 1;
    }
    return n;
}*/

int main ()
{
    string n, s, m;
    while(cin >> n)
    {
        if(n == "1")
        {
            cout << 1;
        }
        else
        {
            s = subtract(n);
            m = multiply(s);
            cout << m;
        }
        cout << "\n";
    }


return 0;
}
