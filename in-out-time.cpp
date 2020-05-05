// in and out time
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define N 100001
using namespace std;
bool vis[N]={0};
ll in[N]={0};
ll out[N]={0};
vector<ll> adj[N];
ll m,n,u,v,timer=1;
void dfs(ll node) 
{
    vis[node] = true;
    in[node]=timer++;
    for(ll neighbour:adj[node]) 
    {
        if(!vis[neighbour])
        {
             dfs(neighbour);
        }
    }
    out[node]=timer++;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>m;
     while(m--)
     {
          cin>>u>>v;
          adj[u].push_back(v);
          adj[v].push_back(u);
     }
     dfs(1);
     for(ll i=1;i<=n;i++)
     {
          cout<<in[i]<<" ";
     }
     cout<<endl;
     for(ll i=1;i<=n;i++)
     {
          cout<<out[i]<<" ";
     }
    return 0;
}

