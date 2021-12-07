#include <iostream>
#include <string>
using namespace std;
int main ()
{
string s;
int n, h = 0, d = 0, a = 0;
while(cin >> s >> n) {
    //cout << "s: " << s << " n: " << n << "\n";
    if(s == "forward") {
        h += n;
        d += a * n;
        //cout << "f: " << h << "\n\n";
    }
    else if(s == "down") {
        a += n;
        //cout << "di: " << d << "\n\n";
    }
    else {
        a -= n;
        //cout << "dd: " << d << "\n\n";
    }
}

cout << d << " " << h << " " << d * h;

return 0;
}
