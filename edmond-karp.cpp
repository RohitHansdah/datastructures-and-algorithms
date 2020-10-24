//Edmond-Karp algorithm
#include <bits/stdc++.h>
using namespace std;
int T,n,m,capacity[1001][1001],parent[1001],x,y,z;
vector<int>adj[1001];
int bfs(int s, int t)
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=-1;
    }
    parent[s]=-2;
    queue< pair <int , int  > >q;
    q.push({s,INT_MAX});
    while(!q.empty())
    {
        int cur=q.front().first;
        int flow=q.front().second;
        q.pop();
        for(int next:adj[cur])
        {
            if(parent[next]==-1 && capacity[cur][next])
            {
                parent[next]=cur;
                int new_flow=min(flow,capacity[cur][next]);
                if(next==t)
                {
                    return new_flow;
                }
                q.push({next,new_flow});
            }
        }
    }
    return 0;
}
int max_flow(int s , int t)
{
    int flow=0,new_flow;
    //finding augmented path
    while(new_flow=bfs(s,t))
    {
        flow+=new_flow;
        int cur=t;
        while(cur!=s)
        {
            int prev=parent[cur];
            capacity[prev][cur]-=new_flow;
            capacity[cur][prev]+=new_flow;
            cur=prev;
        }
    }
    return flow;
}
int main()
{
	cin>>T;
    while(T--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            adj[i].clear();
            for(int j=1;j<=n;j++)
            {
                capacity[i][j]=0;
            }
        }
        while(m--)
        {
            cin>>x>>y>>z;
            adj[x].push_back(y);
            adj[y].push_back(x);
            capacity[x][y]+=z;
            capacity[y][x]+=z;
        }
        cout<<max_flow(1,n)<<endl;
    }
	return 0;
}
