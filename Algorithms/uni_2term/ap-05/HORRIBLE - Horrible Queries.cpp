#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> tab;
vector<ll> arr_sum;
vector<ll> delta_arr; //temporary value of sum which need to be added to each bucket

void bucket_touch(int bucket_size, int bucket_id)
{
    //adding delta to all elements in selected bucket
    int bucket = bucket_size * bucket_id;
    for(int i = 0; i < bucket_size; i++)
    {
        tab[bucket + i] += delta_arr[bucket_id];
    }
    delta_arr[bucket_id] = 0;
}

int main () {

    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--)
    {

        int n, c;
        cin >> n >> c;
        if(n == 0)
        {
            cout << "0\n";
            continue;
        }

        int bucket = ceil(sqrt(n));

        tab.assign(n, 0); //assigning a size of vector and fill it with 0
        arr_sum.assign(bucket, 0);
        delta_arr.assign(bucket, 0);

        while(c--)
        {
            int f, p, q;
            cin >> f >> p >> q;

            //cut if p or q are beyond the range
            p = max(0, p - 1);
            q = min(n - 1, q - 1);

            bool none = false;
            //if p is too far from right side or q from left, range is empty
            if(q < 0) none = true;
            if(p >= n) none = true;

            //update value
            if(f == 0)
            {
                ll v;
                cin >> v;

                if(none == false)
                {
                    //indices of extreme buckets in the range
                    int first = p / bucket;
                    int last = q / bucket;
                    //cout << first << " " << last << "\n*********\n";

                    bucket_touch(bucket, first);
                    bucket_touch(bucket, last);

                    if(last - first >= 2)
                    {
                        for(int i = first + 1; i <= last - 1; i++)
                        {
                            delta_arr[i] += v;
                            arr_sum[i] += bucket * v; //amount of numbers * what I have to add to each
                            //cout << arr_sum[i] << " ";
                        }

                        //first - adding to elements AFTER p
                        for(int i = p; i / bucket == first; i++)//work till I'm in this particular bucket
                        {
                            //if((i % bucket == 0 && i != p) || i >= n) break;
                            tab[i] += v;
                            arr_sum[first] += v;
                        }

                        //last - adding to elements BEFORE q
                        for(int i = q; i / bucket == last; i--) //there is no full bucket or 1 or 2 full
                        {
                            tab[i] += v;
                            arr_sum[last] += v;
                            //if(i % bucket == 0 || i == 0) break;
                        }

                        //cout << "1. " << arr_sum[first] << " " << arr_sum[last] << "\n";
                    }

                    else
                    {
                        for(int i = p; i <= q; i++)
                        {
                            tab[i] += v;
                            arr_sum[i / bucket] += v; //adding all values manually to arr_sum
                        }
                        //cout << "2. " << arr_sum[first] << " " << arr_sum[last] << "\n";
                    }
                }
            }

            //write sum of range
            else
            {
                if(none == true) cout << "0\n";
                else
                {
                    ll sum = 0;

                    int first = p / bucket;
                    int last = q / bucket;

                    bucket_touch(bucket, first);
                    bucket_touch(bucket, last);

                    if(last - first >= 2)
                    {
                        for(int i = first + 1; i <= last - 1; i++)
                        {
                            sum += arr_sum[i]; //amount of numbers * what I have to add to each
                        }

                        //first
                        for(int i = p; i / bucket == first; i++) //there is no full bucket or 1 or 2 full
                        {
                            //if(i % bucket == 0 && i != p) break; //I dont want to check the first element of the next bucket
                            sum += tab[i];
                        }

                        //last
                        for(int i = q; i / bucket == last; i--) //there is no full bucket or 1 or 2 full
                        {
                            sum += tab[i];
                            //if(i % bucket == 0) break; //I need to check first element in the bucket (last from right side)
                        }
                    }

                    else
                    {
                        for(int i = p; i <= q; i++)
                        {
                            sum += tab[i];
                        }
                    }

                    cout << sum << "\n";
                }
            }
        }
    }

    return 0;
}
