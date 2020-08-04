#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string s,t,p;
    cin>>t>>p;
    s=p+'@'+t;
    int n=s.length(),m=p.length(),l=0,r=0;
    vector<int>z(n);
    z[0]=0;
    for(int i=1;i<n;i++)
    {
        if(i>r)
        {
            r=l=i;
            while(r<n && s[r]==s[r-l])
            {
                r++;
            }
            z[i]=r-l;
            r--;
        }
        else
        {
            int k=i-l;
            if(z[k]<r-i+1)
            {
                z[i]=z[k];
            }
            else
            {
                l=i;
                while(r<n && s[r]==s[r-l])
                {
                    r++;
                }
                z[i]=r-l;
                r--;
            }
            
        }
        
    }
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        if(z[i]==m)
        {
            ans.push_back(i-m-1);
        }
    }
    for(int x:ans)
    {
        cout<<x<<" ";
    }
    return 0;
}