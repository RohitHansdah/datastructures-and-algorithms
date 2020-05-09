// prim's algorithm
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
ll n,m,u,v,w,cost=0,mn,pos,cur;
vector<ll> adj[N];
ll key[N]={0};
ll par[N]={0};
bool vis[N]={false};
map<string,ll>weight;
ll min_vertex()
{
     mn=INT_MAX;
     pos=1;
     for(ll i=1;i<=n;i++)
     {
          if(!vis[i])
          {
               if(key[i]<mn)
               {
                    mn=key[i];
                    pos=i;
               }
          }
     }
     return pos;
}
void mst()
{
   for(ll i=1;i<=n;i++)
   {
     cur=min_vertex();
     for(ll neighbour:adj[cur])
     {
          if(!vis[neighbour] && key[neighbour]>weight[to_string(cur)+"-"+to_string(neighbour)])
          {
               key[neighbour]=weight[to_string(cur)+"-"+to_string(neighbour)];
               par[neighbour]=cur;
          }
     }
     vis[cur]=1;
   }
   for(ll i=1;i<=n;i++)
   {
        cost=cost+key[i];
   }
   cout<<"cost:"<<cost<<endl;
   for(ll i=2;i<=n;i++)
   {
        cout<<par[i]<<"->"<<i<<":"<<key[i]<<endl;
   }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    par[1]=-1;
    for(ll i=2;i<=n;i++)
    {
         key[i]=INT_MAX;
    }
    for(ll i=0;i<m;i++)
    {
         cin>>u>>v>>w;
         adj[u].push_back(v);
         adj[v].push_back(u);
         string index;
         index=to_string(u)+"-"+to_string(v);
         weight[index]=w;
         index=to_string(v)+"-"+to_string(u);
         weight[index]=w;
    }
    mst();
    return 0;
}
