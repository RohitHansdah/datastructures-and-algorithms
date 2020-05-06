// bfs
#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define mod 1000000007
#define N 100001
using namespace std;
bool vis[N]={0};
ll dist[N]={0};
ll subtree[N]={0};
vector<ll> adj[N];
ll t,n,m,u,v;
void bfs(ll);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  cin>>t;
  while(t--)
  {
     cin>>n>>m;
     for(ll i=1;i<=n;i++)
     {
          adj[i].clear();
          vis[i]=0;
          dist[i]=0;
     }
     while(m--)
     {
          cin>>u>>v;
          adj[u].push_back(v);
          adj[v].push_back(u);
     }
     bfs(1);
     cout<<endl;
     for(ll i=1;i<=n;i++)
     {
          cout<<dist[i]<<" ";
     }
     cout<<endl;
  }
     return 0;
}
void bfs(ll src) 
{
    vis[src] = true;
    dist[src]=0;
    queue<ll>q;
    q.push(src);
    while(!q.empty())
    {
         ll cur=q.front();
         cout<<cur<<" ";
         q.pop();
         for(ll neighbour:adj[cur])
         {
              if(!vis[neighbour])
              {
                   q.push(neighbour);
                   vis[neighbour]=true;
                   dist[neighbour]=dist[cur]+1;
              }
         }
    }
} 
