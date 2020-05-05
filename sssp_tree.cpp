// sssp tree dfs
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define N 100000
using namespace std;
bool vis[N] = {false};
ll dist[N]={0};
vector<ll> adj[N];
ll m,n,u,v,q,girl,mn=INT_MAX,propose;
void dfs(ll node, ll d) 
{
    vis[node] = true;
    dist[node]=d;
    for(ll child:adj[node]) 
    {
        if(!vis[child])
        {
             dfs(child,dist[node]+1);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    m=n-1;
    while(m--)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    cin>>q;
    while(q--)
    {
         cin>>girl;
         if(mn>dist[girl])
         {
              mn=dist[girl];
              propose=girl;
         }
    }
    cout<<propose;
    return 0;
}
