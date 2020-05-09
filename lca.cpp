// lca
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#include <climits>
# include <string>
#define ll long long
#define N 100001
using namespace std;
ll n,m,u,v,x,y;
vector<ll> adj[N];
ll par[N]={0};
ll level[N]={0};
void dfs(ll node , ll parent)
{
     par[node]=parent;
     if(parent==-1)
     {
          level[node]=0;
     }
     else
     {
          level[node]=level[parent]+1;
     }
     for(ll neighbour:adj[node])
     {
          if(neighbour==parent)
          {
               continue;
          }
          dfs(neighbour,node);
     }
}
ll lca(ll a , ll b)
{
     if(level[b]<level[a])
     {
          swap(a,b);
     }
     ll d=level[b]-level[a];
     while(d--)
     {
          b=par[b];
     }
     if(a==b)
     {
          return a;
     }
     while(a!=b)
     {
          a=par[a];
          b=par[b];
     }
     return a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    m=n-1;
    while(m--)
    {
         cin>>u>>v;
         adj[u].push_back(v);
         adj[v].push_back(u);
    }
    cin>>x>>y;
    dfs(1,-1);
    cout<<lca(x,y);
    return 0;
}
