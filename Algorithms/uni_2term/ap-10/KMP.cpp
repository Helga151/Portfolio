#include <iostream>
#include <string>
using namespace std;

int arr_s[1'000'001]; //arr of counted prefixes same as sufixes

void KMP_arr(string s)
{
    arr_s[0] = 0; //as no prefix - one letter
    int length = 0;

    for(int i = 1; i < s.size(); i++)
    {
        cout << "\n" << i << ": ";
        if(s[length] == s[i])
        {
            length++;
            arr_s[i] = length;
            cout << arr_s[i];
        }
        else
        {
            if(length != 0)
            {
                length = arr_s[length - 1];
                i--; //to go through this letter again
            }
            else
            {
                arr_s[i] = 0;
                cout << arr_s[i];
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        string s1, s2;
        cin >> n >> s1 >> s2;
        KMP_arr(s1);
        cout << "\n";
        /*for(int i = 0; i < n; i++)
        {
            cout << arr_s << " ";
        }
        cout << "\n";*/
    }

    return 0;
}
