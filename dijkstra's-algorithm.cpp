// dijkstra's algorithm
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
ll n,m,u,v,w;
vector<ll> adj[N];
ll par[N]={0};
ll key[N]={0};
bool vis[N]={0};
map<string , ll >weight;
ll min_vertex()
{
     ll mn=INT_MAX,pos=1;
     for(ll i=1;i<=n;i++)
     {
          if(mn>key[i] && !vis[i])
          {
               mn=key[i];
               pos=i;
          }
     }
     return pos;
}
void dijkstra()
{
   for(ll i=1;i<=n;i++)
   {
     ll cur=min_vertex();
     for(ll neighbour:adj[cur])
     {
          if(!vis[neighbour] && key[neighbour]>key[cur]+weight[to_string(cur)+"-"+to_string(neighbour)])
          {
               key[neighbour]=key[cur]+weight[to_string(cur)+"-"+to_string(neighbour)];
               par[neighbour]=cur;
          }
     }
     vis[cur]=1;
   }
   for(ll i=1;i<=n;i++)
   {
        cout<<key[i]<<" "<<endl;
   }
   cout<<endl;
   for(ll i=1;i<=n;i++)
   {
        cout<<par[i]<<" "<<endl;
   }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(ll i=2;i<=n;i++)
    {
         key[i]=INT_MAX;
    }
    for(ll i=1; i<=m;i++)
    {
         cin>>u>>v>>w;
         adj[u].push_back(v);
         adj[v].push_back(u);
         weight[to_string(u)+"-"+to_string(v)]=w;
         weight[to_string(v)+"-"+to_string(u)]=w;
    }
    dijkstra();
    return 0;
}
