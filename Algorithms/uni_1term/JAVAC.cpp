#include <iostream>
#include <string>
using namespace std;
int main ()
{
    string s, sj;
    int i, j, sizee, result, zm, allunder, allcapital;
    while (cin >> s)
    {
        zm = 0;
        allunder = 0;
        allcapital = 0;
        result = 1;
        sizee = s.size();
        sj = "";
        if(s[0] <= 'Z' || int(s[0]) == '_' || int(s[sizee - 1]) == '_')//first letter can't be capital and first and last can't be "_"
        {
            cout << "Error!\n";
            continue;
        }
        for(i = 1; i < sizee; i++)
        {
            //Java case
            if(s[i] <= 'Z') //big letter need to be changed to "_smaller"
            {
                if(zm == 1 || (allunder >= 1 && s[i - 1] >= 'a')) //unacceptable style
                {
                    cout << "Error!\n";
                    result = 0;
                    break;
                }
                else
                {
                    result = 2;
                    allcapital++;
                }
            }

            //C case
            else if(s[i] == '_')
            {
                zm++;
                allunder++;
                if(zm > 1 || allcapital > 0)
                {
                    cout << "Error!\n";
                    result = 0;
                    break;
                }
            }

            else
            {
               if(zm == 1) //check if changing to big letter is needed
               {
                    //change small letter to big one and erase "_"
                    s[i] -= 32;
                    zm = 0; //bool = false
               }
            }
        }
        if(result == 1)
        {
            for(i = 0; i < sizee; i++)
            {
                if(s[i] != '_')
                {
                   cout << s[i];
                }
            }
            cout << "\n";
        }

        //Java edit
        else if(result == 2)
        {
            j = 0;
            while(j < sizee)
            {
                if(zm == 1) //changing capital letter to small
                {
                    sj += s[j] + 32;
                    zm = 0;
                    j++;
                }
                else if(s[j] >= 'a')//if small letter - copy from s to sj
                {
                    sj += s[j];
                    j++;
                }
                else//else - change to "_small"
                {
                    sj += '_';
                    zm = 1; //another letter will be changed
                }
            }
            cout << sj << "\n";
        }
    }

return 0;
}
