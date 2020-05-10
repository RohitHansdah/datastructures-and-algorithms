// Bellman Ford algorithm
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
#define N 10000001
#define MAX 1000001
using namespace std;
ll n,m,u,v,w;
vector<ll>adj[N];
ll cost[N]={0};
ll cycle[N]={0};
void bell()
{
     //relax each edge v-1 times 
     for(ll i=0;i<n-1;i++)
     {
          for(ll j=0;j<2*m;j=j+2)
          {
               cost[adj[j][1]]=min(cost[adj[j][0]]+adj[j][2],cost[adj[j][1]]);
               cost[adj[j+1][1]]=min(cost[adj[j+1][0]]+adj[j+1][2],cost[adj[j+1][1]]);
          }
     }
     for(ll i=1;i<=n;i++)
     {
          cout<<cost[i]<<endl;
          cycle[i]=cost[i];
     }
     for(ll i=0;i<2*m;i=i+2)
     {
          cost[adj[i][1]]=min(cost[adj[i][0]]+adj[i][2],cost[adj[i][1]]);
          cost[adj[i+1][1]]=min(cost[adj[i+1][0]]+adj[i+1][2],cost[adj[i+1][1]]);
     }
     bool check=false;
     for(ll i=1;i<=n;i++)
     {
          if(cost[i]!=cycle[i])
          {
               check=true;
               break;
          }
     }
     if(check)
     {
          cout<<"negative cycle is present";
     }
     else
     {
          cout<<"negative cycle is not present";
     }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(ll i=2;i<=n;i++)
    {
         cost[i]=MAX;
    }
    for(ll i=0;i<2*m;i=i+2)
    {
         cin>>u>>v>>w;
         adj[i].push_back(u);
         adj[i].push_back(v);
         adj[i].push_back(w);
         adj[i+1].push_back(v);
         adj[i+1].push_back(u);
         adj[i+1].push_back(w);
    }
    bell();
    return 0;
}
