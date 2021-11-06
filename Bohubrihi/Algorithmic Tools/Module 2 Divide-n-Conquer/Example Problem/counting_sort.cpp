#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,t;
    cin>>n;
    int a[n],m=0,s[n];
    for(i=0; i<n; i++)
    {
        cin>>t;
        a[i]=t;
        if(t>m)
            m= t;
        s[i] = -1;
    }
    int c[m+1],p[m+1];
    for(i=0; i<=m; i++)
    {
        c[i]=0;
        p[i]=0;
    }
    for(i=0; i<n; i++)
    {
        c[a[i]]++;
    }
    p[0] = 0;
    for(i=1; i<=m; i++)
    {
        p[i] = p[i-1] + c[i-1];
    }
    for(i=0;i<n;i++)
    {
        s[p[a[i]]++] = a[i];
    }
    for(i=0; i<n; i++)
        cout<<s[i]<<" ";
}
