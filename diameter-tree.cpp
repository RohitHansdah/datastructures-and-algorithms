// diameter of a tree
#include <iostream>
#include <vector>
#define ll long long
#define mod 1000000007
#define N 100001
using namespace std;
bool vis[N]={0};
vector<ll> adj[N];
ll m,n,u,v,mxd=-1,mxnode=1;
void dfs(ll,ll);
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
     mxd=-1;
     dfs(1,0);
     mxd=-1;
     for(ll i=1;i<=n;i++)
     {
          vis[i]=0;
     }
     dfs(mxnode,0);
     cout<<mxd;
     return 0;
}
void dfs(ll node,ll d) 
{
    vis[node] = true;
    if(d>mxd)
    {
         mxd=d;
         mxnode=node;
    }
    for(ll neighbour:adj[node]) 
    {
        if(!vis[neighbour])
        {
             dfs(neighbour,d+1);
        }
    }
} 
