#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Graph{
   vector<pair<int, pair<int, int>>> edges;//wt, u, v
};
Graph g;

int parent[4000];
int sizee[4000];

int find_(int a)
{
    if(a == parent[a]) return a;
    return parent[a] = find_(parent[a]);
}

void union_(int a, int b)
{
    a = find_(a);
    b = find_(b);

    if(a != b)
    {
        if(sizee[a] < sizee[b]) swap(a,b);
        parent[b] = a;
        sizee[a] += sizee[b];
    }
}

int kruskal()
{
    int min_wt = 0;
    vector<pair<int, pair<int, int>>>::iterator it;

    for(it = g.edges.begin(); it != g.edges.end(); it++)
    {
        int u = it -> second.first;
        int v = it -> second.second;
        //cout << u << " " << v << "\n";

        int put_u = find_(u);
        int put_v = find_(v);
        //cout << put_u << " " << put_v << "\n***********\n";

        if(put_u != put_v)
        {
            min_wt += it -> first; //update min weight
            union_(put_u, put_v);
        }
    }
    return min_wt;
}


int main()
{
    int g_nodes, g_edges;
    cin >> g_nodes >> g_edges;

    for(int i = 1; i <= g_nodes; i++)
    {
        parent[i] = i;
        sizee[i] = 1;
    }

    int zm = g_edges;
    while(zm--)
    {
        int g_from, g_to, g_weight;
        cin >> g_from >> g_to >> g_weight;

        g.edges.push_back(make_pair(g_weight, make_pair(g_from, g_to)));
    }
    sort(g.edges.begin(), g.edges.end());

    cout << kruskal();

    return 0;
}
