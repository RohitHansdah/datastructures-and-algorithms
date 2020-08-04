#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string t;
    cin>>t;
    int n=t.length(),c=0,r=0;
    n=2*n+1;
    int p[n]={0};
    p[0]=0;
    p[1]=1;
    for(int i=2;i<n;i++)
    {
        int mir=2*c-i;
        if(i<r)
        {
            p[i]=min(r-i,p[mir]);
        }
        while( ((i + p[i]) < n && (i - p[i]) > 0) &&  ( ((i + p[i] + 1) % 2 == 0) ||  
            (t[(i + p[i] + 1)/2] == t[(i - p[i] - 1)/2] )))
        {
            p[i]++;
        }
        if(i+p[i]>r)
        {
            c=i;
            r=i+p[i];
        }
    }
    for(int y:p)
    {
        cout<<y<<" ";
    }
    return 0;
}