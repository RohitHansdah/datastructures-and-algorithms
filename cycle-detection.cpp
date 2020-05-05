// cycle detection
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define N 100000
using namespace std;
bool vis[N];
vector<ll> adj[N];
ll m,n,u,v;
bool dfs(ll node, ll parent) 
{
    vis[node] = true;
    for(ll neighbour:adj[node]) 
    {
        if(!vis[neighbour])
        {
             if(dfs(neighbour,node))
             {
                  return true;
             }
        }
        else
        {
             if(neighbour!=parent)
             {
                  return true;
             }
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n>>m;
    while(m--)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(dfs(1,-1))
    {
         cout<<"YES";
    }
    else
    {
         cout<<"NO";
    }
    return 0;
}

