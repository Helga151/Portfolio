#include <iostream>
#include <string>
using namespace std;
int main ()
{
	int i, znak;
	string s;
	while (getline (cin , s))
    {
       for (i = 0; i < s.size(); i++)
        {
        znak = int (s[i]);
        if (znak == 32)
        {
            cout << " ";
            continue;
        }
        znak += 3;
        if (znak > 90)
        {
            znak -= 26;
        }
        cout << char (znak);
        }
        cout << "\n";
    }

return 0;
}
