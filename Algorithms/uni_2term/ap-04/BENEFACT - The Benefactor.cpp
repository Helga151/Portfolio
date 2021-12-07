#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Graph{
    vector <pair<int, int>> neighbours; //node and length
};

Graph g[50000];
bool visited[50000];
long long path[100'000'000];
long long max_path;

int BFS(int index, int p, long long& max_path)
{
    int i, current_vertex, current_distance, neig_vertex, neig_distance, max_index = 0;
    queue <pair<int, int>> q;
    vector <pair<int, int>>::iterator it_g;
    q.push({index, 0});

    for(i = 1; i <= p; i++)
    {
        path[i] = 0;
        visited[i] = false;
    }

    visited[index] = true;

    while(!q.empty())
    {
        auto current_pair = q.front();
        current_vertex = current_pair.first;
        current_distance = current_pair.second;
        q.pop();

        for(it_g = g[current_vertex].neighbours.begin(); it_g != g[current_vertex].neighbours.end(); it_g++)
        {
            neig_vertex = it_g -> first;
            neig_distance = it_g -> second;
            if(visited[neig_vertex] == false && neig_vertex != 0)
            {
                visited[neig_vertex] = true;
                q.push({neig_vertex, current_distance + neig_distance});
                path[neig_vertex] = current_distance + neig_distance;
            }
        }
    }

    for(i = 1; i <= p; i++)
    {
        if(path[i] > max_path)
        {
            max_path = path[i];
            max_index = i;
        }
    }
    return max_index;

    /*for(i = 1; i <= p; i++)
    {
        cout << i << ": " << path[i] << "\n";
    }*/

}

int main ()
{
    int t, p, a, b, l, i;
    cin >> t;
    while(t--)
    {
        cin >> p;
        for(i = 1; i <= p; i++)
        {
            g[i].neighbours.clear();
        }

        for(i = 1; i < p; i++)
        {
            cin >> a >> b >> l;
            g[a].neighbours.push_back({b, l});
            g[b].neighbours.push_back({a, l});
        }

        int bfs1 = BFS(1, p, max_path);
        int bfs2 = BFS(bfs1, p, max_path);

        /*for(i = 1; i <= p; i++)
        {
            cout << i <<".\n-----------\n";
            BFS(i, p, max_path);

        }*/

        //cout << bfs1 << " " << bfs2 << "\n";
        cout << max_path << "\n";
    }

return 0;
}
