#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string multiply(string a, string b)
{
    int i, j, mul, as, bs, ai, bi, an, bn, carry;
    string s;
    as = a.size();
    bs = b.size();
    vector <int> result(as + bs, 0);
    ai = bi = 0;
    for(i = as - 1; i >= 0; i--)
    {
        an = a[i] - '0';
        carry = 0;
        bi = 0;
        for(j = bs - 1; j >= 0; j--)
        {
            bn = b[j] - '0';
            mul = bn * an + carry + result[ai + bi];
            carry = mul / 10;
            result[ai + bi] = mul % 10;
            bi++;
        }
        if(carry > 0)
        {
            result[ai + bi] += carry;
        }
        ai++;
    }

    i = result.size() - 1;
    while(i >= 0 && result[i] == 0)
    {
        i--;
    }
    while(i >= 0)
    {
        s += result[i--] + '0';
    }
return s;
}

/*string multiply(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
    return "0";

    // will keep the result number in vector
    // in reverse order
    vector<int> result(len1 + len2, 0);

    // Below two indexes are used to find positions
    // in result.
    int i_n1 = 0;
    int i_n2 = 0;

    // Go from right to left in num1
    for (int i=len1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0;

        // Go from right to left in num2
        for (int j=len2-1; j>=0; j--)
        {
            // Take current digit of second number
            int n2 = num2[j] - '0';

            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position.
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;

            // Carry for next iteration
            carry = sum/10;

            // Store result
            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }

        // store carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }

    // ignore '0's from the right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
    i--;

    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
    return "0";

    // generate the result string
    string s = "";

    while (i >= 0)
        s += to_string(result[i--]);

    return s;
}*/
int main ()
{
    int t, i, n;
    string f;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n == 0)
        {
            cout << 1 << "\n";
        }
        else
        {
            f = to_string(n);
            //cout << f << " ";
            for(i = (n - 1); i > 1; i--)
            {
                f = multiply(f,(to_string(i)));
                //cout << i << " " << f << "\n";
            }
            cout << f << "\n";
        }
    }

return 0;
}
