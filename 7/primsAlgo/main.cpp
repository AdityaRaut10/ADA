#include <bits/stdc++.h>
#define ll int
#define m INT_MAX
using namespace std;
typedef pair<int, int> ip;
class graph
{
public:
    ll v;
    list<ip> *adj;
    graph(ll k)
    {
        this->v = k;
        adj = new list<ip>[v];
    }
    void addpath(ll u, ll z, ll w)
    {
        adj[u].push_back(make_pair(z, w));
        adj[z].push_back(make_pair(u, w));
    }
    void mst(void);
};
void graph::mst()
{
    ll s=0;
    priority_queue<ip, vector<ip> , greater<ip> > pq;
    vector<ll> val;
    vector<bool> visited;
    vector<ll> par;
    for(ll j=0; j<v; j++)
    {

        val.push_back(m);
        visited.push_back(false);
        par.push_back(-1);
    }

    val[s]=0;

    pq.push(make_pair(0, s));

    while(!pq.empty())
    {
        ll u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for(auto i=adj[u].begin(); i!=adj[u].end(); i++)
        {
            ll v = i->first;
            ll w = i->second;

            if(visited[v]==false && val[v]> w)
            {
                val[v]= w;
                par[v]=u;
                pq.push(make_pair(val[v], v));
            }
        }

    }
   // FILE *fp;
   // fp = fopen("output.txt", "w");
        //freopen("output.txt", "w", stdout);
        for(ll j=1; j<v; j++)
        {
           // freopen("output.txt", "w", stdout);
            //cout<<par[j]<<" <-- "<<val[j]<<" --> "<<j<<"\n";
            cout<<par[j]<<" "<<j<<"\n";
          //  fprintf(fp, "%d %d %d\n",par[j], j, val[j]);
        }
      //  fclose(stdout);
}

int main()
{
    ll v=6;
    graph g(v);
    ll a, b, c;
 /*   FILE *fp;
    fp = fopen("input.txt", "r");
    //freopen("input.txt", "r", stdin);
    for(ll i=0; i<v; i++)
    {
        //cin>>a>>b>>c;
        fscanf(fp, "%d %d %d", &a, &b, &c);
        g.addpath(a, b, c);
    }
    fclose(fp);
*/
    g.addpath(0, 3, 5);
    g.addpath(0, 1, 7);
    g.addpath(0, 5, 9);
    g.addpath(1, 4, 12);
    g.addpath(2, 5, 13);
    g.addpath(2, 3, 2);
    g.addpath(3, 4, 4);

    g.mst();
    return 0;
}
