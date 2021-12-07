#include <iostream>
#include <string>
using namespace std;

int tab_b[100001];

void KMP_table(string b) //text which I want to search
{ //LPS algorithm
    tab_b[0] = 0;//first is 0 as no prefix
    int length = 0;

    for(int i = 1; i < b.size(); i++)
    {
        if(b[length] == b[i])
        {
            length++;
            tab_b[i] = length;
        }
        else
        {
            if(length != 0)
            {
                length = tab_b[length - 1];
                i--;//to avoid decreasing - want to stay on this letter
            }
            else tab_b[i] = 0;
        }
    }
}

bool KMP(string a, string b)
{
    KMP_table(b); //creating array

    int i = 0,j = 0; //j - iterate through b
    while(i < a.size()) //i - iterate through a
    {
        if(a[i] != b[j])
        {
            if(j != 0) j = tab_b[j - 1];
            else i++; //go further only in main string, when j = 0
        }
        else //same - go further in both strings
        {
            i++;
            j++;
            if(j == b.size()) return true;//all letters from b checked, so pattern found
        }
    }
    return false;
}

int main ()
{
    int n;
    cin >> n;
    while(n--)
    {
        string a, b;
        cin >> a >> b;
        /*size_t found = a.find(b);
        if(found != string::npos) cout << "YES\n";
        else cout << "NO\n";*/
        if(KMP(a,b) == true) cout << "YES\n";
        else cout << "NO\n";
    }


return 0;
}
