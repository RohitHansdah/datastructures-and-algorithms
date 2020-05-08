// kruskal's algorithm
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#define ll long long
#define N 100001
using namespace std;
ll n,m,u,v,w,cost=0;
struct edge
{
     ll u;
     ll v;
     ll w;
};
bool compare(edge a , edge b)
{
     if(a.w<b.w)
     {
          return true;
     }
     else
     {
          return false;
     }
}
edge adj[N];
ll par[N];
ll find(ll vertex)
{
     if(par[vertex]==-1)
     {
          return vertex;
     }
     else
     {
          return par[vertex]=find(par[vertex]);
     }
}
void merge(ll x , ll y)
{
     par[x]=y;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(ll i=0;i<=n;i++)
    {
         par[i]=-1;
    }
    for(ll i=0;i<m;i++)
    {
         cin>>adj[i].u>>adj[i].v>>adj[i].w;
    }
    sort(adj,adj+m,compare);
    for(ll i=0;i<m;i++)
    {
         if(find(adj[i].u)!=find(adj[i].v))
         {
              cost=cost+adj[i].w;
              merge(find(adj[i].u),find(adj[i].v));
         }
    }
    cout<<cost;
    return 0;
}
