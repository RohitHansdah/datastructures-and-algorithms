//dfs on 2D grid
#include <bits/stdc++.h>
#define ll long long 
using namespace std; 
ll  n,m,cnt,a[1000][1000];
bool vis[1000][1000];
ll dx[]={-1,0,1,0};
ll dy[]={0,1,0,-1};
bool isValid(ll x,ll y)
{
	if(x<1 || x>n || y<1 || y> m || vis[x][y] || a[x][y]==0)
	{
		return false;
	}
	return true;
}
void dfs(ll x, ll y)
{
	vis[x][y]=1;
	for(ll i=0;i<4;i++)
	{
		if(isValid(x+dx[i],y+dy[i]))
		{
			dfs(x+dx[i],y+dy[i]);
		}
	}
}
int main() 
{ 
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			if(vis[i][j]==0 && a[i][j]==1)
			{
				dfs(i,j);
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
    return 0; 
}
