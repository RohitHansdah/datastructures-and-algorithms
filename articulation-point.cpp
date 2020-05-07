// articulation points
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <math.h>
#define ll long long
#define N 100001
using namespace std;
ll n,m,u,v,timer=0,cnt,x=0;;
bool vis[N]={false};
ll low[N]={0};
ll in[N]={0};
vector<ll>adj[N];
bool ap[N]={0};
void dfs(ll node , ll parent)
{
     cnt=0;
     vis[node]=true;
     low[node]=in[node]=timer++;
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
               ++cnt;
               dfs(neighbour,node);
               low[node]=min(low[node],low[neighbour]);
               if(in[node]<=low[neighbour] && parent!=-1)
               {
                    ap[node]=true;
               }
               if(parent=-1 && cnt>1)
               {
                    ap[node]=true;
               }
          }
     }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(ll i=0;i<m;i++)
  {
       cin>>u>>v;
       adj[u].push_back(v);
       adj[v].push_back(u);
  }
  dfs(1,-1);
  for(ll i=1;i<=n;i++)
  {
       if(ap[i])
       {
            cout<<i<<" ";
            x++;
       }
  }
  cout<<endl;
  cout<<x;
  return 0;
}
