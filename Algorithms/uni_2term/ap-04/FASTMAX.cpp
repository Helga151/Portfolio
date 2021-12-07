#include <iostream>
#include <cmath>
using namespace std;

int tab[1'000'000];
int maxi_arr[200'010];

int main ()
{
int n, r, q, a, b, i, change, bucket, maxi, first, last, bucket_amount;
while(cin >> n >> r)//;
{
    bucket = ceil(sqrt(n)); //size of each bucket

    for(i = 0; i <= n; i++)
    {
        tab[i] = 0;
        maxi_arr[i] = 0;
    }

    while(r--)
    {
        cin >> q >> a >> b;
        if(q == 1)
        {
            tab[a] = b;

            change = a / bucket; //number of bucket in which is a change
            maxi = 0;

            //if(b > maxi) maxi_arr[change] = maxi;

            for(i = 0; i < bucket; i++)
            {
                if(tab[i + change * bucket] > maxi)
                {
                    maxi = tab[i + change * bucket]; //index of each element is i + (number of bucket * number of items)
                    //cout << ">>>>>>> " << maxi << "\n";
                }
                //cout << "++++++++ " << i + change * bucket << "\n";
            }
            //cout << "-------- " << tab[a] << " || " << maxi << "\n";
            maxi_arr[change] = maxi;
        }

        else
        {
            //which buckets have to be checked
            first = a / bucket;
            last = b / bucket;
            //if(bucket * bucket != n) last += 1;
            //cout << first << " " << last << "\n";

            maxi = 0;
            bucket_amount = last - first + 1;

            if(bucket_amount > 2)
            {
                for(i = (first + 1); i <= (last - 1); i++) //middle buckets
                {
                    maxi = max(maxi_arr[i], maxi);
                }
                //last max 2 not full buckets
                //i % bucket are indexes of first elements in each bucket
                for(i = a; ; i++) //there is no full bucket or 1 or 2 full
                {
                    if(i % bucket == 0 && i != a) break; //I dont want to check the first element of the next bucket
                    //cout << "ai: " << i << " " << maxi << "\n";
                    if(tab[i] > maxi) maxi = tab[i];
                }

                for(i = b; ; i--) //there is no full bucket or 1 or 2 full
                {
                    if(tab[i] > maxi) maxi = tab[i];
                    //cout << "bi: " << i << " " << maxi << "\n";
                    if(i % bucket == 0) break; //I need to check first element in the bucket (last from right side)
                }
            }

            else
            {
                for(i = a; i <= b; i++) //there is no full bucket or 1 or 2 full
                {
                    if(tab[i] > maxi) maxi = tab[i];
                }
            }

            cout << maxi << "\n";

        }
    }
}


return 0;
}
