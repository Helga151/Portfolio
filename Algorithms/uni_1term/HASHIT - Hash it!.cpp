#include <iostream>
#include <string>
using namespace std;
int key (string s)
{
    int i, p = 0;
    for (i = 0; i < s.size(); i++)
    {
        p += (int)s[i] * (i + 1);
    }
    p = (p * 19) % 101;
    return p;
}
int main ()
{
    int t, n, i, k, Hash, j, solution, Hash2;
    string s, f, w;
    string arr[103];
    bool zm;
    cin >> t;
    while (t--)
    {
        cin >> n;
        solution = 0;
        for(k = 0; k <= 101; k++)
        {
            arr[k] = "";
        }
        while(n--)
        {
            cin >> s;
            f = w = "";
            zm = 1;
            for (i = 0; i <= 3; i++)
            {
                f += s[i]; //function
            }
            for (i = 4; i < s.size(); i++)
            {
                w += s[i]; //word
            }
            if (f == "ADD:")
            {
                for(i = 0; i <= 101; i++) //ignore when exist
                {
                    if(arr[i] == w)
                    {
                        zm = 0;
                        break;
                    }
                }
                if(zm == 1)
                {
                    Hash = key(w);
                    for(j = 0; j < 20; j++)
                    {
                        Hash2 = (Hash + j * j + 23 * j) % 101;
                        if(arr[Hash2] == "")
                        {
                            arr[Hash2] = w;
                            solution++;
                            break;
                        }
                    }
                }
            }
            else
            {
                for(i = 0; i <= 101; i++)
                {
                    if(arr[i] == w)
                    {
                        arr[i] = "";
                        solution--;
                        break;
                    }
                }
            }
        }

        cout << solution << "\n";
        for(i = 0; i <= 101; i++)
        {
            if(arr[i] != "")
            {
                cout << i << ":" << arr[i] << "\n";
            }
            //arr[i] = "";
        }
    }

return 0;
}
