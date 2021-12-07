#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int tab[21][21];
int dirty[11][21][21]; //index of dirty place and its coordinates
int i, j;

struct Start{
    int x;
    int y;
};
Start v[11];


void BFS(int w, int l, bool visited[21][21]) //start - starting index
{
    queue <int> q;
    int path[30][30];

    for(i = 1; i <= l; i++)
    {
        for(j = 1; j <= w; j++)
        {
            path[i][j] = 0;
        }
    }

    visited[v.y][v.x] = true;
    q.push(v.y);
    q.push(v.x);

    while(!q.empty())
    {
        v.y = q.front();
        q.pop(); //erase it
        v.x = q.front();
        q.pop();
        //cout << v.y << " " << v.x << "\n";

        //neighbours
        if(tab[v.y + 1][v.x] == 1 && visited[v.y + 1][v.x] == false)
        {
            visited[v.y + 1][v.x] = true;
            q.push(v.y + 1);
            q.push(v.x);
            path[v.y + 1][v.x] = path[v.y][v.x] + 1;
        }

        if(tab[v.y - 1][v.x] == 1 && visited[v.y - 1][v.x] == false)
        {
            visited[v.y - 1][v.x] = true;
            q.push(v.y - 1);
            q.push(v.x);
            path[v.y - 1][v.x] = path[v.y][v.x] + 1;
        }

        if(tab[v.y][v.x + 1] == 1 && visited[v.y][v.x + 1] == false)
        {
            visited[v.y][v.x + 1] = true;
            q.push(v.y);
            q.push(v.x + 1);
            path[v.y][v.x + 1] = path[v.y][v.x] + 1;
        }

        if(tab[v.y][v.x - 1] == 1 && visited[v.y][v.x - 1] == false)
        {
            visited[v.y][v.x - 1] = true;
            q.push(v.y);
            q.push(v.x - 1);
            path[v.y][v.x - 1] = path[v.y][v.x] + 1;
        }
    }

    for(i = 1; i <= l; i++)
    {
        for(j = 1; j <= w; j++)
        {
            cout << path[i][j] << " ";
        }
        cout << "\n";
    }

}

int main ()
{
int w, l;
char n;
bool visited[21][21];
while(cin >> w >> l)
{
    if(w == 0 && l == 0) return 0;

    for(i = 1; i <= l; i++)
    {
        for(j = 1; j <= w; j++)
        {
            visited[i][j] = false;

            cin >> n;
            if(n == 'o' || n == '*' || n == '.') //paths
            {
                tab[i][j] = 1;
                if(n == 'o')
                {
                    v.y = i;
                    v.x = j;
                    dirty[0][i][j] = 1;
                }
                if(n == '*' || n == 'o') //destinations
                {
                    //dirty[][i][j] = j; //coordinates of dirty places and robot
                }
            }
            else //obstacle
            {
                tab[i][j] = 0;
                visited[i][j] = true;
            }
        }
    }

    cout << "ok\n";
    BFS(w, l, visited);
}


return 0;
}
