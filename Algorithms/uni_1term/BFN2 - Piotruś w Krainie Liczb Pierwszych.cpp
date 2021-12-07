#include <iostream>
using namespace std;
void sito(int *tab, long long U)
{
    int i;
  	for (i = 2; i * i <= U; i++)
	{
    	if(!((tab[i>>5]>>(i&63))&1))
    	for (int j = i*i ; j<=U; j+=i)
      		tab[j>>5] |= (1<<(j&63)); //ustawienie odpowiedniego bitu na 1
    }
}

int main()
{
    int t, i;
    int L, U, n = 214748364;
    int* tab = new int [n];
    cin >> t;
    while (t--)
    {
        cin >> L >> U;
        sito(tab, U);
        for(i=L;i<=U;i++)
    	if(!((tab[i>>5]>>(i&63))&1))
        {
            cout<<i<<"\n";
        }

  	cout<<endl;
    }
return 0;
}
