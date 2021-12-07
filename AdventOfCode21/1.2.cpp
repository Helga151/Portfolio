#include <iostream>
#include <vector>
using namespace std;
int main ()
{
int res = 0, a, b, c;
vector <int> current;
vector <int> prev;
cin >> a >> b >> c;
prev.push_back(a);
prev.push_back(b);
prev.push_back(c);
current.push_back(b);
current.push_back(c);

while(cin >> a)
{
    int s_prev = 0, s_curr = 0;
    current.push_back(a);

    for(int i = prev.size() - 1; i >= 0; i--) {
        s_prev += prev[i];
    }

    for(int i = current.size() - 1; i >= 0; i--) {
        s_curr += current[i];
    }
    //cout << s_prev << " " << s_curr << "\n";
    if(s_curr > s_prev) {
        res++;
    }
    prev.erase(prev.begin());
    current.erase(current.begin());
    prev.push_back(a);

}

cout << res;
return 0;
}
