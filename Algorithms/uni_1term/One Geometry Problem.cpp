#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool isSmaller(string a, string b) //a < b true
{
    int i;
    if(a.size() < b.size()) return true;
    if(a.size() > b.size()) return false;
    else
    {
        for(i = 0; i < a.size(); i++)
        {
            if(a[i] < b[i]) return true;
            else if(a[i] > b[i]) return false;
        }
        return false;
    }
}
string subtract(string a, string b)
{
    int i, j, sub, carry;
    string s = "";
    if(isSmaller(a, b) == true) swap(a, b); //chce wieksza liczbe na miejscu a
    j = a.size() - 1;
    carry = 0;
    for(i = b.size() - 1; i >= 0; i--, j--)
    {
        sub = (a[j] - '0') - (b[i] - '0') - carry;
        if(sub < 0)
        {
            sub += 10;
            carry = 1;
        }
        else carry = 0;
        s += to_string(sub);
    }
    for(i = a.size() - b.size() - 1; i >= 0; i--)
    {
        sub = (a[i] - '0') - carry;
        if(sub < 0)
        {
            sub += 10;
            carry = 1;
        }
        else carry = 0;
        s += to_string(sub);
    }
    reverse(s.begin(), s.end());
    i = 0;
    while(i < s.size() - 1 && s[i] == '0')
    {
        s.erase(s.begin() + i);
        i++;
    }
return s;
}

string multiply(string a, string b)
{
    if(a == "0" || b == "0") return "0";

    int i, j, carry, mul, as, bs, ai, bi, an, bn;
    string s = "";
    as = a.size(); //size
    bs = b.size();
    vector <int> result (as + bs, 0);
    ai = bi = 0; //index
    for(i = as - 1; i >= 0; i--)
    {
        carry = 0;
        an = a[i] - '0'; //number
        bi = 0;
        for(j = bs - 1; j >= 0; j--)
        {
            bn = b[j] - '0';
            mul = an * bn + carry + result[ai + bi];
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
        s += to_string(result[i--]);
    }
return s;
}




/*bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    for (int i = 0; i < n1; i++) {
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
    }
    return false;
}

// Function for finding difference of larger numbers
string substract(string str1, string str2)
{
    // Before proceeding further, make sure str1
    // is not smaller
    if (isSmaller(str1, str2))
        swap(str1, str2);

    // Take an empty string for storing result
    string str = "";

    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();
    int diff = n1 - n2;

    // Initially take carry zero
    int carry = 0;

    // Traverse from end of both strings
    for (int i = n2 - 1; i >= 0; i--) {
        // Do school mathematics, compute difference of
        // current digits and carry
        int sub = ((str1[i + diff] - '0') - (str2[i] - '0')
                   - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    // subtract remaining digits of str1[]
    for (int i = n1 - n2 - 1; i >= 0; i--) {
        if (str1[i] == '0' && carry) {
            str.push_back('9');
            continue;
        }
        int sub = ((str1[i] - '0') - carry);
        if (i > 0 || sub > 0) // remove preceding 0's
            str.push_back(sub + '0');
        carry = 0;
    }

    // reverse resultant string
    reverse(str.begin(), str.end());

    return str;
}

string multiply(string num1, string num2)
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
    int t;
    string b, c, d, zm1, zm2, zm3;
    cin >> t;
    while (t--)
    {
        cin >> b >> c >> d;
        //zm = 2 * c - d - b;
        zm1 = multiply("2", c);
        zm2 = subtract(zm1, d);
        zm3 = subtract(zm2, b);
        cout << zm1 << " " << zm2 << " " << zm3 << "\n";
    }


return 0;
}
