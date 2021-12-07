#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int* gender;

struct Graph{
    vector <int> neighbours;
};
Graph g[2001];

bool BFS(int index)
{
    int temp;
    queue <int> q;
    vector <int>::iterator it_neig;

    q.push(index);
    gender[index] = 1; //change to female

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        for(it_neig = g[temp].neighbours.begin(); it_neig != g[temp].neighbours.end(); it_neig++)
        {
            if(*it_neig != 0 && gender[*it_neig] == -1)
            {
                q.push(*it_neig);
                if(gender[temp] == 1) gender[*it_neig] = 0; //change to male
                else if(gender[temp] == 0) gender[*it_neig] = 1;
                //cout << "indeks: " << *it_neig << " plec: " << gender[*it_neig] << "\n";
            }

            else if(gender[*it_neig] == gender[temp])
            {
                //cout << "homo:\n";
                //cout << "indeks: " << *it_neig << " plec: " << gender[*it_neig] << "\n";
                return false;
            }
        }
    }
    return true;
}

bool CheckAll(int bugs)
{
    int i;
    for(i = 1; i <= bugs; i++)
    {
        if(gender[i] == -1 && BFS(i) == false) return false;
    }
    return true;
}

int main()
{
    //if there is an odd-numbered cycle or non bipartite graph, homo bugs have been found (Bipartite Graph - graf dwudzielny)
    //wiki: Aby przekonać się, czy dany graf jest dwudzielny, wystarczy użyć algorytmu przeszukiwania grafu (BFS lub DFS)
    // i kolorować wierzchołki (początkowo o kolorze neutralnym) na dwa kolory tak,
    // aby przechodzony wierzchołek miał kolor przeciwny względem poprzednika.
    // Jeśli natrafimy na dwa wierzchołki o tym samym kolorze połączone krawędzią, to graf nie jest dwudzielny.
    // W przeciwnym wypadku graf jest dwudzielny, podział zbioru wierzchołków na rozłączne podzbiory wyznaczają ich kolory.
    int n, bugs, interactions, i, j, a, b;
    bool zm;
    cin >> n;
    for(j = 1; j <= n; j++)
    {
        cin >> bugs >> interactions ;

        zm = true;
        gender = new int[bugs + 1];

        for(i = 0; i <= bugs; i++)
        {
            gender[i] = -1; //trans
            g[i].neighbours.clear();
        }

        for(i = 0; i < interactions; i++)
        {
            cin >> a >> b;
            if(a == b)
            {
                zm = false;//connection with itself add break?
            }
            g[a].neighbours.push_back(b);
            g[b].neighbours.push_back(a);
        }

        cout << "Scenario #" << j << ":\n";

        if(zm == false)
        {
            cout << "Suspicious bugs found!\n";
        }

        else
        {
            zm = CheckAll(bugs);

            if(zm == true) cout << "No suspicious bugs found!\n";
            else cout << "Suspicious bugs found!\n";
        }

        delete [] gender;
    }

    return 0;
}
