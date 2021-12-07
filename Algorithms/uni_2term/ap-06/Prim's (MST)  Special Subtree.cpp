#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Graph{
    vector <pair<int, int>> neig;
};
Graph g[1'000'000];

void prims_algo(int start, int n)
{
    int min_path = 0;
    //weight and node; pri_q sorts by first element; adding "vector<pair<int, int>>, greater<pair<int, int>>" allows me to sort from the smalest element
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector <bool> visited(n + 1, false);

    pq.push(make_pair(0, start));
    //visited[start] = true;

    while(!pq.empty())
    {
        pair <int, int> current = pq.top();
        pq.pop();

        int weight = current.first;
        int node = current.second;
        cout << "*****************\n";
        cout << "wierzcholek: " << node << "\n";

        if(visited[node] == false)
        {
            visited[node] = true;
            min_path += weight;
            cout << "droga: " << min_path << "\n";

            cout << "synowie: \n";
            vector <pair<int, int>>::iterator it;
            for(it = g[node].neig.begin(); it != g[node].neig.end(); it++)
            {
                int n_weight = (*it).first; //neighbour weight
                int n_node = (*it).second;

                if(visited[n_node] == false)
                {
                    pq.push(make_pair(n_weight, n_node));
                    cout << "wierz syna: " << n_node << " " << "wartosc syna: " << n_weight << "\n";
                }
            }
        }
    }
    cout << "++++++++++++\nnajkrotsza: " << min_path << "\n";

    //return min_path;
}

int main()
{
    int n, m;
    cin >> n >> m;

    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].neig.push_back(make_pair(c, b));
        g[b].neig.push_back(make_pair(c, a));
    }
    int start;
    cin >> start;

    prims_algo(start, n);// << "\n";


    return 0;
}
