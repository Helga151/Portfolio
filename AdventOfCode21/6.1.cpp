#include <iostream>
#include <vector>
using namespace std;
int main ()
{
int a;
vector <int> vec;
while(cin >> a) {
    vec.push_back(a);
}

int add = 0; //how many 8 add in next iteration
for(int j = 0; j < 100; j++) {
    for(int i = 0; i < add; i++) {
        vec.push_back(8);
    }
    add = 0;
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i] > 0) vec[i]--;
        else {
            vec[i] = 6;
            add++;
        }
    }
}

cout << vec.size();

return 0;
}
