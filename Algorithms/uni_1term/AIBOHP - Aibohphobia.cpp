#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int dp[6101][6101];
int insertion(string &s, int ssize)
{
    int i, j, en;
    for(i = 2; i <= ssize; i++)
    {
        for(j = 0; j <= ssize - i; j++)
        {
            en = i + j - 1; //last element index
            if(s[j] == s[en])
            {
                dp[j][en] = dp[j + 1][en - 1];
                if(i == 2)
                {
                    dp[j][en] = 0;
                }
            }
            else
            {
                dp[j][en] = min(dp[j + 1][en], dp[j][en - 1]) + 1;
            }
        }
    }
    return dp[0][ssize - 1];
    /*if(beg == en || en < beg)
    {
        return 0;
    }
    if(dp[beg][en] != -1)
    {
        return dp[beg][en];
    }

    if(s[beg] == s[en])
    {
        dp[beg][en] = insertion(s, beg + 1, en - 1); //ignore first and last element, no element has been added
    }
    else
    {
        i = insertion(s, beg + 1, en) + 1; //in both variations adding at least 1 letter is needed
        j = insertion(s, beg, en - 1) + 1;
        dp[beg][en] = min(i, j); //decide which is lower
    }*/
}

int main ()
{
    int t, ssize, i, j;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        ssize = s.length();
        if (ssize == 1)
        {
            cout << 0 << "\n";
        }
        else
        {
            memset(dp, 0, sizeof(dp));
            cout << insertion(s, ssize) << "\n";
        }
    }

return 0;
}
