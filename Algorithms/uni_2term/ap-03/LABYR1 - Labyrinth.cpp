#include <iostream>
#include <queue>
using namespace std;

bool visited[1001][1001];
bool labyrinth[1001][1001];
int path[1001][1001];
int max_path;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

struct graph{
    int x;
    int y;
};
graph g[1000001];

int BFS(int index, int r, int c, int amount, int& max_path)
{
    queue <int> q;
    int i, j, k, x2, y2, x3, y3, max_index = 0;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            path[i][j] = 0;
            visited[i][j] = false;
        }
    }

    visited[g[index].y][g[index].x] = true;
    q.push(g[index].y);
    q.push(g[index].x);

    while(!q.empty())
    {
        y2 = q.front();
        q.pop();
        x2 = q.front();
        q.pop();

        for(i = 0; i < 4; i++)
        {
            x3 = x2 + dx[i];
            y3 = y2 + dy[i];
            if (labyrinth[y3][x3] == true && visited[y3][x3] == false) //unvisited free place
            {
                visited[y3][x3] = true;
                q.push(y3);
                q.push(x3);
                path[y3][x3] = path[y2][x2] + 1;
            }
        }
    }

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(path[i][j] > max_path)
            {
                max_path = path[i][j];
                for(k = 0; k < amount; k++) //index of the farthest free place
                {
                    if(g[k].x == j && g[k].y == i)
                    {
                        max_index = k;
                    }
                }
            }
        }
    }
    return max_index;
    /*for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            cout << path[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "--------------\n";*/
}

int main() {
    int n, c, r, i, j, amount;
    char a;
    cin >> n;
    while(n--)
    {
        cin >> c >> r;
        amount = max_path = 0;
        for(i = 0; i < r; i++)
        {
            for(j = 0; j < c; j++)
            {
                cin >> a;
                if(a == '#') labyrinth[i][j] = false; //cannot enter
                else
                {
                    labyrinth[i][j] = true; //can enter
                    g[amount].x = j;
                    g[amount].y = i;
                    amount++;
                }
            }
        }

        int bfs1 = BFS(0, r, c, amount, max_path);
        int bfs2 = BFS(bfs1, r, c, amount, max_path);
        //cout << bfs1 << " " << bfs2 << " " << "\n";
        cout << "Maximum rope length is " << max_path << ".\n";

    }

    return 0;
}
