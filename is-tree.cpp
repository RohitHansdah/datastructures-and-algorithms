// check is tree
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define N 100000
using namespace std;
bool vis[N] = {false};
vector<ll> adj[N];
ll m,n,x,u,v,cnt=0;
void dfs(ll node) 
{
    vis[node] = true;
    for(ll child:adj[node]) 
    {
        if(!vis[child])
        {
             dfs(child);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n>>m;
    x=m;
    while(x--)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(ll v=1;v<=n;v++)
    {
         if(!vis[v])
         {
              cnt++;
              dfs(v);
         }
    }
    if(cnt==1 && m==n-1)
    {
         cout<<"YES";
    }
    else
    {
         cout<<"NO";
    }
    return 0;
}
