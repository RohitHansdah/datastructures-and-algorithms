#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007 
#define N 100000
using namespace std; 
bool vis[N];
vector <vector <int> > adj; 
void dfs(int node)
{
  if(vis[node])
    return;
  vis[node] = true; 
  cout<< node <<" ";
  for(auto neighbour: adj[node])
  {
     dfs(neighbour);
  }
}
 int main()
 {
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     int n, m; // n = # nodes, m = # edges
     cin >> n >> m;
     adj.resize(n+1);
     while(m--)
     {
          int x,y;
          cin >> x >> y;
          adj[x].push_back(y);
          adj[y].push_back(x);
     }
     // number of connected components
     cout<<"dfs search:";
     int cnt=0;
     for(int v=1;v<=n;v++)
     {
          if(!vis[v])
          {
              cnt++;
              dfs(v); 
          }
     }
     cout<<endl;
     cout<<"Number of connected components:"<<cnt;
     return 0;
 }
