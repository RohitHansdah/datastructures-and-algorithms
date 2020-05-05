//dfs on tree
#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007 
#define N 100000
using namespace std; 
int level[N]={0};
int par[N]={0};
vector <vector <int> > adj; 
void dfs(int node, int parent)
{
  par[node]=parent;
  if(parent==-1)
  {
       level[node]=0;
  }
  else
  {
       level[node]=level[parent]+1;
  }
  cout<<"node:"<<node<<"->"<<"parent:"<<parent<<"  level:"<<level[node]<<endl;
  for(auto neighbour: adj[node])
  {
     if(neighbour==parent)
     {
          continue;
     }
     dfs(neighbour,node);
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
     // level of each node and parent array
     dfs(1,-1);
     cout<<"level : ";
     for(int i=1;i<=n;i++)
     {
          cout<<level[i]<<" ";
     }
     cout<<endl;
     cout<<"parent : ";
     for(int i=1;i<=n;i++)
     {
          cout<<par[i]<<" ";
     }
     return 0;
 }
