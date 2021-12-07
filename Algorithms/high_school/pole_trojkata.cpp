#include <iostream>
#define sqrt3 1.73205081

using namespace std;

int main()
{

   double a, pole;

   cin >> a;
   pole = (a*a*sqrt3)/4;
   cout.setf(ios::fixed);
   cout.precision(2);

   cout << pole << endl;

   return 0;
}

