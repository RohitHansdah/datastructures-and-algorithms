// subtree size
#include <iostream>
#include <vector>
#define ll long long
#define mod 1000000007
#define N 100001
using namespace std;
bool vis[N]={0};
ll subtree[N]={0};
vector<ll> adj[N];
ll m,n,u,v;
ll dfs(ll);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     cin>>n>>m;
     while(m--)
     {
          cin>>u>>v;
          adj[u].push_back(v);
          adj[v].push_back(u);
     }
     dfs(1);
     for(ll i=1;i<=n;i++)
     {
          cout<<subtree[i]<<" ";
     }
     return 0;
}
ll dfs(ll node) 
{
    vis[node] = true;
    ll cur=1;
    for(ll neighbour:adj[node]) 
    {
        if(!vis[neighbour])
        {
             cur=cur+dfs(neighbour);
        }
    }
    subtree[node]=cur;
    return cur;
} 
