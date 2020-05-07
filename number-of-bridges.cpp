// number of bridges
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <math.h>
#define ll long long
#define N 100001
using namespace std;
ll n,m,u,v,timer=1;
bool vis[N]={false};
ll low[N]={0};
ll in[N]={0};
vector<ll>adj[N];
void dfs(ll node , ll parent)
{
     vis[node]=true;
     low[node]=timer;
     in[node]=timer;
     timer++;
     for(ll neighbour:adj[node])
     {
          if(neighbour==parent)
          {
               continue;
          }
          if(vis[neighbour])
          {
               //back edge
               low[node]=min(in[neighbour],low[node]);
          }
          else
          {
               // tree edge
               dfs(neighbour,node);
               if(low[neighbour]>in[node])
               {
                    cout<<node<<"->"<<neighbour<<endl;
               }
               low[node]=min(low[node],low[neighbour]);
          }
     }
}
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
  dfs(1,-1);
  return 0;
}
