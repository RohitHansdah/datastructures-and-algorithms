//bfs on 2D grid
#include <bits/stdc++.h>
#define ll long long 
using namespace std; 
ll  n,m,dist[1000][1000];
bool vis[1000][1000];
ll dx[]={1,0,-1,0};
ll dy[]={0,1,0,-1};
bool isValid(ll x,ll y)
{
	if(x<1 || x>n || y<1 || y> m || vis[x][y])
	{
		return false;
	}
	return true;
}
void bfs(ll sx, ll sy)
{
	queue< pair<ll,ll> >q;
	vis[sx][sy]=1;
	q.push({sx,sy});
	dist[sx][sy]=0;
	while(!q.empty())
	{
		ll curx=q.front().first;
		ll cury=q.front().second;
		q.pop();
		for(ll i=0;i<4;i++)
		{
			if(isValid(curx+dx[i],cury+dy[i]))
			{
				q.push({curx+dx[i],cury+dy[i]});
				vis[curx+dx[i]][cury+dy[i]]=1;
				dist[curx+dx[i]][cury+dy[i]]=1+dist[curx][cury];
			}
		}
	}
}
int main() 
{ 
	cin>>n>>m;
	bfs(1,1);
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			cout<<dist[i][j]<<" ";
		}
		cout<<endl;
	}
    return 0; 
}
