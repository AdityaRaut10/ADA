#include <bits/stdc++.h>
#define ll long int
using namespace std;
#define inf (ll)INT_MAX
typedef pair<ll, ll> ipair;

class graph
{
public:
    ll v;
    list<ipair> *adj;
    graph(ll v)
    {
        this->v = v;
        adj = new list<ipair>[v];
    }
    void addEdge(ll u, ll v, ll w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    void shortestPath(ll src);
};
void graph::shortestPath(ll src)
{
    priority_queue<ipair, vector<ipair>, greater<ipair>> pq;//min heap // std would be a max heap
    //for distances we are going to create a new vector and initialize it to inf
    vector<ll> dist(v, inf);
    pq.push(make_pair(0, src));
    dist[src]=0;

    while(!pq.empty())
    {
        ll u = pq.top().second;
        pq.pop();

        for(auto i= adj[u].begin(); i!=adj[u].end(); i++)
        {
            // curr_v is neighbour of u with dist betwn them as weight
            ll curr_v = i->first;
            ll weight = i->second;

            if(dist[u]+weight< dist[curr_v])
            {
                dist[curr_v]=dist[u]+weight;
                pq.push(make_pair(dist[curr_v], curr_v));
            }
        }
    }
    cout<<"Vertex\tDistance From source\n";
        for(ll i=0; i<v; i++)
        {
            cout<<i<<"\t\t"<<dist[i]<<"\n";
        }
}

int main()
{
    int v =9, a,b,c;
    graph g(v);
    /*freopen("input.txt", "r", stdin);
    for(ll i=0; i<v; i++)
    {
        cin>>a>>b>>c;
        //fscanf(fp, "%d %d %d", &a, &b, &c);
        g.addEdge(a, b, c);
    }
    fclose(stdin);*/
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.shortestPath(0);
    return 0;
}
