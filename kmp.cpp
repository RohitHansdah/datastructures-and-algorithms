#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string t,p;
    cin>>t>>p;
    int n=t.length(),m=p.length(),i,j;
    vector<int>lps(m);
    i=1;
    j=0;
    lps[0]=0;
    while(i<m)
    {
        if(p[i]==p[j])
        {
            lps[i]=j+1;
            i++;
            j++;
        }
        else
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
    vector<int>ans;
    i=0;
    j=0;
    while(i<n)
    {
        if(t[i]==p[j])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            ans.push_back(i-j);
            j=lps[j-1];
        }
        else if(i<n && t[i]!=p[j])
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                i++;
            }
            
        }
        
    }
    for(int x:ans)
    {
        cout<<x<<" ";
    }
    return 0;
}