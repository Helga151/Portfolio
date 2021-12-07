#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string doSum(string a, string b)
{
    int i, j, zm;
    if(a.size() < b.size()) swap(a, b);
    j = a.size() - 1;
    for(i = b.size() - 1; i >= 0; j--, i--)
    {
        a[j] += (b[i] - '0');
    }
    for(i = a.size() - 1; i > 0; i--)
    {
        if(a[i] > '9')
        {
            zm = a[i] - '0';
            a[i - 1] = (a[i - 1] - '0') + zm / 10 + '0';
            a[i] = zm % 10 + '0';
        }
    }
    string s;
    if(a[0] > '9')
    {
        s += a[0];
        s[0] = (s[0] - '0') / 10 + '0';
        a[0] = (a[0] - '0') % 10 + '0';
        a = s + a;
    }
    reverse(a.begin(), a.end());
    i = 0;
    while(i < a.size() - 1 && a[i] == '0')
    {
        i++;
    }
    a.erase(0, i);
    return a;
}

int main ()
{
    int t, i;
    string s1, s2, sum;
    cin >> t;
    while(t--)
    {
        cin >> s1 >> s2;
        if(s1 == "0" && s2 == "0")
        {
            cout << "0\n";
        }
        else
        {
            // usuwa wszystkie zera; fajne, ale siê nie przyda  = s1.erase(remove(s1.begin(), s1.end(), '0'), s1.end());
            reverse (s1.begin(), s1.end());
            i = 0;
            while(s1[i] == '0')
            {
                i++;
            }
            s1.erase(0, i);
            reverse (s2.begin(), s2.end());
            i = 0;
            while(s2[i] == '0')
            {
                i++;
            }
            s2.erase(0, i);
            sum = doSum(s1,s2);
            for(i = 0; i < sum.size(); i++)
            {
                cout << sum[i];
            }
            cout << "\n";
        }
    }

return 0;
}
