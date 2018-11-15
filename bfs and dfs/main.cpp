#include <bits/stdc++.h>
#define ll long long int
#define adi() ios::sync_with_stdio(false); cin.tie(0)
#define inf int(INT_MAX)
#define d 26
using namespace std;
list<int> *adj;
bool *visited;

void dfs(int src)
{
    visited[src]=true;
    cout<<src<<endl;
    for(auto i=adj[src].begin(); i!=adj[src].end(); i++)
    {
        if(!visited[*i])
        {
            dfs(*i);
        }
    }
}
void bfs(int src)
{
    queue<int> q;

    q.push(src);
    visited[src]=true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        cout<<u<<endl;
        for(auto i=adj[u].begin(); i!=adj[u].end(); i++)
        {
            int v = *i;
            if(visited[v]==false)
            {
                visited[v]=true;
                q.push(v);
            }

        }
    }
}
int main()
{
    int v;
    cin>>v;
    adj = new list<int> [v];
    visited = new bool[v];
    for(ll i=0; i<v; i++) visited[i]=false;

    int src, dest;
    int ch=1;
    while(ch!=0)
    {
        cout<<"src--> dest :: ";
        cin>>src>>dest;
        adj[src].push_back(dest);
        cout<<"coice  :: ";
        cin>>ch;
    }
    dfs(2);
    return 0;
}
