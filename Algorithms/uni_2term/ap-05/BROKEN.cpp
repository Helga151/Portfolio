#include <iostream>
#include <string>
using namespace std;
int main ()
{

int m;
while(cin >> m)
{
    if(m == 0) return 0;

    string s;
    cin.ignore(); //erasing '\n' left by previous element 'cin'
    getline(cin, s);

    if(m >= s.size()) cout << s.size() << "\n";

    else
    {
        int how_much[260];
        for(int i = 0; i < 259; i++)
        {
            how_much[i] = 0;
        }

        int uniq = 0, maxi = 0, leng = 0, beg = 0, now = 0;
        //uniq - unique letter; maxi - max length; leng - length of current word; beg - starting letter; now - index of current letter
        while(now < s.size())
        {
            int zm = int(s[now]);
            how_much[zm]++;

            if(how_much[zm] == 1) uniq++;

            if(uniq > m)
            {
                //erasing current first element which wont be needed in the new, next word
                zm = int(s[beg]);
                if(how_much[zm] == 1)
                {
                    uniq--;
                }
                how_much[zm]--;
                beg++;
            }

            else leng++;

            if(leng >= maxi) maxi = leng;
            //cout << now << ": " << maxi << " " << leng << "\n";
            now++;
        }

        cout << maxi << "\n";
    }

}

return 0;
}
