#include <iostream>
#include <queue>
using namespace std;

struct Graph{
    int x;
    int y;
};
Graph g[40000]; //182*182==33124 ; n*m

int tab[200][200];
int min_path[200][200];
bool visited[200][200];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void BFS(int index, int n, int m)
{
    int y2, x2, y3, x3, i, j;
    int path[200][200];
    queue <int> q;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            visited[i][j] = false;
            path[i][j] = 0;
        }
    }

    visited[g[index].y][g[index].x] = true;
    q.push(g[index].y);
    q.push(g[index].x);

    while (!q.empty())
    {
        y2 = q.front();
        q.pop();
        x2 = q.front();
        q.pop();
        //cout << y2 << " " << x2 << "\n";
        //cout << "+++++++++++\n";
        for(i = 0; i < 4; i++) //neighbours
        {
            y3 = y2 + dy[i];
            x3 = x2 + dx[i];

            if(y3 < 0 || x3 < 0 || y3 > n || x3 > m) continue;

            else if(tab[y3][x3] == 0 && visited[y3][x3] == false)
            {
                //cout << y3 << " " << x3 << "\n";
                visited[y3][x3] = true;
                q.push(y3);
                q.push(x3);
                //cout << abs(y3 - g[index].y) << " " << abs(x3 - g[index].x) << "\n";
                //cout << "***********\n";
                path[y3][x3] = abs(y3 - g[index].y) + abs(x3 - g[index].x);

                /*if(min_path[y3][x3] >= path[y3][x3] && path[y3][x3] != 0)
                {
                    min_path[y3][x3] = path[y3][x3];
                }*/
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(min_path[i][j] > path[i][j] && path[i][j] != 0)
            {
                min_path[i][j] = path[i][j];
            }
        }
    }

    /*for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            cout << min_path[i][j] << " ";
        }
        cout << "\n";
    }*/

}

int main() {
    int i, j, t, n, m, amount;
    char a;
    cin >> t;
    while(t--)
    {
        amount = 0;
        cin >> n >> m;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                cin >> a;
                tab[i][j] = a - '0'; //char to int

                if(tab[i][j] == 1)//white pixel
                {
                    g[amount].y = i;
                    g[amount].x = j;
                    amount++;
                }
            }
        }

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                min_path[i][j] = 200;
            }
        }

        for(i = 0; i < amount; i++)
        {
            BFS(i, n, m);
            //cout << "-------------\n";
        }

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                if(min_path[i][j] == 200)
                {
                    min_path[i][j] = 0;
                }
                cout << min_path[i][j] << " ";
            }
            cout << "\n";
        }

    }

    return 0;
}
