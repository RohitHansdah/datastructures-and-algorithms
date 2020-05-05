// check is tree
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define N 100000
using namespace std;
bool vis[N] = {false};
ll col[N]={0};
vector<ll> adj[N];
ll m,n,u,v;
bool dfs(ll node, ll color) 
{
    vis[node] = true;
    col[node] = color;
    for(ll neighbour:adj[node]) 
    {
        if(!vis[neighbour])
        {
             if(!dfs(neighbour,!color))
             {
                  return false;
             }
        }
        else
        {
             if(col[node]==col[neighbour])
             {
                  return false;
             }
        }
    }
    return true;
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
    if(dfs(1,1))
    {
         cout<<"YES";
    }
    else
    {
         cout<<"NO";
    }
    return 0;
}
