#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int tab[21][21];
int dirty[11][11]; //index and coordinates of dirty places
bool visited[21][21];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int i, j;

struct Start{
    int x;
    int y;
};
Start v[11];


void BFS(int w, int l, int index, int amount) //index - starting index
{
    queue <int> q;
    int path[30][30];
    int x2, y2;

    for(i = 1; i <= l; i++)
    {
        for(j = 1; j <= w; j++)
        {
            path[i][j] = 0;
            visited[i][j] = false;
        }
    }

    visited[v[index].y][v[index].x] = true;
    q.push(v[index].y);
    q.push(v[index].x);

    while(!q.empty())
    {
        v[index].y = q.front();
        q.pop(); //erase it
        v[index].x = q.front();
        q.pop();

        //neighbours
        for(i = 0; i < 4; i++) //4 directions
        {
            x2 = v[index].x + dx[i];
            y2 = v[index].y + dy[i];
            if((tab[y2][x2] == 1 || tab[y2][x2] == 2)&& visited[y2][x2] == false)
            {
                visited[y2][x2] = true;
                q.push(y2);
                q.push(x2);
                path[y2][x2] = path[v[index].y][v[index].x] + 1;
                if(tab[y2][x2] == 2) //dirty place or robot
                {
                    for(j = 0; j < amount; j++) //which dirty place is it
                    {
                        if(v[j].x == x2 && v[j].y == y2 && dirty[index][j] > path[y2][x2])
                        {
                            dirty[index][j] = path[y2][x2];
                            dirty[j][index] = path[y2][x2];
                        }
                    }
                }
            }
        }
    }
}

int main ()
{
int w, l, amount, zm, result;
char n;
while(cin >> w >> l)
{
    if(w == 0 && l == 0) return 0;
    amount = 1;
    result = 0;
    for(i = 1; i <= l; i++)
    {
        for(j = 1; j <= w; j++)
        {
            cin >> n;
            if(n == '.') //paths
            {
                tab[i][j] = 1;
            }
            else if(n == 'o' || n == '*')
            {
                tab[i][j] = 2;
                if(n == 'o')
                {
                    v[0].y = i;
                    v[0].x = j;

                }
                if(n == '*') //destinations
                {
                    v[amount].y = i;
                    v[amount].x = j;
                    amount++;
                }
            }
            else //obstacle
            {
                tab[i][j] = 0;
            }
        }
    }

    for(i = 0; i < amount; i++)
    {
        for(j = 0; j < amount; j++)
        {
            dirty[i][j] = 10000;
        }
    }

    //cout << amount << "\n";
    for(zm = 0; zm < amount; zm++)
    {
        BFS(w, l, zm, amount);
        for(i = 0; i < amount; i++)
        {
            for(j = 0; j < amount; j++)
            {
                cout << dirty[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "----------------\n";
    }

    for(i = 0; i < amount - 1; i++)
    {
        int minn = 100000;
        for(j = i + 1; j < amount; j++)
        {
            if(dirty[j][i] < minn)
            {
                minn = dirty[j][i];
            }
        }
        result += minn;
    }

    if(result >= 10000) result = -1;
    cout << result << "\n";
}


return 0;
}

