#include <iostream>
#include <vector>
using namespace std;

bool* visited; //array of visited nodes

void DFS(int v, int n, int** tree) //v - index of starting node, amount of nodes,
{
    int i;
    visited[v] = true;
    //cout << v << " ";
    for(i = 1; i <= n; i++)
    {
        if(tree[v][i] == 1 && visited[i] == false)
        {
            DFS(i, n, tree);
        }
    }
}

int main ()
{
        /*drzewo - nieskierowany, spojny graf acykliczny
        warunki:
        - wierzcholki - krawedzie == 1
        - graf spojny - sprawdzam DFSem*/

//graf przechowam w macierzy odwiedzin
int i, j, n, m, a, b;
bool zm;
while(cin >> n >> m)
{
    if(n - m != 1) cout << "NO\n";

    else
    {
        int** tree = new int*[n + 1];
        visited = new bool[n + 1];

        for(i = 1; i <= n; i++)
        {
            tree[i] = new int[n + 1];
        }

        for(i = 1; i <= n; i++) //fill with zeros
        {
            visited[i] = false;
            for(j = 1; j <= n; j++)
            {
                tree[i][j] = 0;
            }
        }

        for(i = 1; i <= m; i++)
        {
            cin >> a >> b;
            //undirected tree
            tree[a][b] = 1;
            tree[b][a] = 1;
        }

        DFS(1, n, tree);

        zm = true;
        for(i = 1; i <= n; i++)
        {
            if(visited[i] == false) zm = false;
        }
        if(zm == false) cout << "NO\n";
        else cout << "YES\n";


        for(i = 1; i <= n; i++)
        {
            delete tree[i];
        }
        delete [] tree;
        delete [] visited;

    }
}


return 0;
}
