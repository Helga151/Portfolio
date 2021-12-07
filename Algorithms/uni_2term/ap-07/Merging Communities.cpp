#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int parent[1'000'000];
int find(int a)
{
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q;//n - the number of people and q - the number of queries
    cin >> n >> q;

    int* sizee = new int[n + 1];

    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sizee[i] = 1;
    }

    while(q--)
    {
        char f;
        int a;
        cin >> f >> a;

        if(f == 'M')//communities containing people a and b are merged if they belong to different communities
        {
            int b;
            cin >> b;

            //union
            a = find(a);
            b = find(b);
            //cout << a << " " << b << "\n";

            if(a != b)
            {
                if(sizee[a] <= sizee[b]) swap(a,b); //in 'a' i want to have bigger size
                parent[b] = a;
                sizee[a] += sizee[b];

            }
            //cout << "1. " << sizee[a] << " " << sizee[b] << "\n";

        }
        else//print the size of the community to which person a belongs
        { //"2. " <<
            cout << sizee[find(a)] << "\n";
        }
    }


    return 0;
}
