// Floyd Warshall algorithm
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
#define N 10001
using namespace std;
ll n,m,u,v,w;
ll graph[N][N];
void floyd();
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
         for(ll j=1;j<=n;j++)
         {
              if(i==j)
              {
                   graph[i][j]=0;
              }
              else
              {
                   graph[i][j]=INT_MAX;
              }
         }
    }
    while(m--)
    {
         cin>>u>>v>>w;
         graph[u][v]=w;
    }
    floyd();
    return 0;
}
void floyd()
{
     for(ll k=1;k<=n;k++)
     {
          for(ll i=1;i<=n;i++)
          {
               for(ll j=1;j<=n;j++)
               {
                    graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
               }
          }
     }
     for(ll i=1;i<=n;i++)
     {
          for(ll j=1;j<=n;j++)
          {
               cout<<graph[i][j]<<" ";
          }
          cout<<endl;
     }
}