#include <iostream>
#include <vector>
using namespace std;

struct Node{
    vector <int> son;
};

Node tree[10001];
bool* visited; //array of visited nodes

void DFS(int v) //v - index of starting node, amount of nodes,
{
    int i;
    visited[v] = true;
    //cout << v << " ";
    vector <int>::iterator it_son;
    for(it_son = tree[v].son.begin(); it_son != tree[v].son.end(); it_son++)
    {
        if(visited[*it_son] == false && *it_son != 0)
        {
            DFS(*it_son);
        }
    }
}

int main ()
{
    /*drzewo - nieskierowany, spojny graf acykliczny
    warunki:
    - wierzcholki - krawedzie == 1
    - graf spojny - sprawdzam DFSem*/

int i, n, m, a, b;
bool zm;
//while(
      cin >> n >> m;//)
//{
    if(n - m != 1) cout << "NO\n";

    else
    {
        visited = new bool[n + 1];

        for(i = 0; i <= n; i++) //fill with zeros
        {
            visited[i] = false;
        }

        for(i = 0; i < m; i++)
        {
            cin >> a >> b;
            //undirected tree
            tree[a].son.push_back(b);
            tree[b].son.push_back(a);
        }
        DFS(1);

        zm = true;
        for(i = 1; i <= n; i++)
        {
            if(visited[i] == false) zm = false;

        }
        if(zm == false) cout << "NO\n";
        else cout << "YES\n";

        delete [] visited;

    }
//}


return 0;
}
