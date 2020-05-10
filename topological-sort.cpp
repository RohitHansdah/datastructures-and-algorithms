// topological sort(kahn's algorithm)
// only works for DAG(directed acyclic graph's)
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
using namespace std;
ll n,m,u,v;
vector<ll>adj[N];
ll in[N]={0};
vector<ll>res;
void kahn()
{
     queue<ll>q;
     for(ll i=1;i<=n;i++)
     {
          if(in[i]==0)
          {
              q.push(i); 
          }
     }
     while(!q.empty())
     {
          ll cur=q.front();
          res.push_back(cur);
          q.pop();
          for(ll neighbour:adj[cur])
          {
               --in[neighbour];
               if(in[neighbour]==0)
               {
                    q.push(neighbour);
               }
          }
     }
     for(ll node:res)
     {
          cout<<node<<" ";
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
         in[v]++;
    }
    kahn();
    return 0;
}
