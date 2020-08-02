//dfs on 2D grid
#include <bits/stdc++.h>
#define ll long long 
using namespace std; 
ll  n,m;
bool vis[1000][1000];
ll dx[]={-1,0,1,0};
ll dy[]={0,1,0,-1};
bool isValid(ll x,ll y)
{
	if(x<1 || x>n || y<1 || y> m || vis[x][y])
	{
		return false;
	}
	return true;
}
void dfs(ll x, ll y)
{
	vis[x][y]=1;
	cout<<x<<" "<<y<<endl;
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
	dfs(1,1);
    return 0; 
}
