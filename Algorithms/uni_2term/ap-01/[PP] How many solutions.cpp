#include <iostream>
using namespace std;
int main ()
{
//ios::sync_with_stdio(false);

int n, x, y, zm;
int right, left;
//cin >> n >> x >> y;
while(cin >> n >> x >> y)
{
    if((n * 2 < x || n * 2 < y) && x != y)
    {
        zm = (n + 1) * (n + 1);
    }
    else
    {
        zm = 0;
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                for(int k = 0; k <= n; k++)
                {
                    for(int l = 0; l <= n; l++)
                    {
                        right = y * (l * l - j * j);
                        //cout << "\n" << right << "rrr";
                        left = x * (i * i - k * k);
                        //cout << "\n" << left << "lll";
                        if(left == right)
                        {
                            zm++;
                            cout <<  zm << ": " << i << " " << j << " " << k << " " << l << "\n";
                        }
                    }
                }
            }
        }
    }

    cout << "tu jest zm -- > " << zm << "\n";
    //cout << zm << "\n";
}

return 0;
}
