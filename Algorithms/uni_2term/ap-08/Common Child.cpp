#include <iostream>
#include <string>

using namespace std;

int dp[5001][5001];
void Dynamic (string a, string b)
{
    for(int i = 0; i <= a.size(); i++)//first row
    {
        dp[0][i] = 0; //0 length
        cout << "0 ";
    }

    for(int i = 0; i <= b.size(); i++)//first column
    {
        dp[i][0] = 0; //0 length
    }

    cout << "\n";
    for(int i = 1; i <= a.size(); i++)
    {
        cout << "0 ";
        for(int j = 1; j <= b.size(); j++)
        {
            //if chars are the same, increase diagonal value
            if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    //return dp[a.size()][b.size()];
}

int main()
{
    string a, b;
    while(cin >> a >> b)
    {
        cout << a.size() << " " << b.size() << "\n";
    //cout <<
        Dynamic(a, b);
    }


    return 0;
}
