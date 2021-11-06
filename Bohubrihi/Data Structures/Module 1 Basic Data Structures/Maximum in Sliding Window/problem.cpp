#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("i5.txt");
    outputFile.open("o5.txt");
    ll n,m;
    inputFile>>n;
    ll a[n],i;
    for(i=0; i<n; i++)
    {
        inputFile>>a[i];
    }
    inputFile>>m;
    ll r[n-m+1],maxi=0,c=0;
    for(i=1; i<m; i++)
    {
        if(a[i]>=a[maxi])
        {
            maxi = i;
        }

    }
    r[c++] = a[maxi];
    for(i=m; i<n; i++)
    {
        if(maxi==i-m)
        {
            maxi = i-m+1;
            for(ll j=i-m+2; j<=m; j++)
            {
                if(a[j]>=a[maxi])
                {
                    maxi = j;
                }
            }
        }
        else
        {
            if(a[i]>=a[maxi])
                maxi = i;
        }
        r[c++] = a[maxi];
    }
    for(i=0; i<n-m+1; i++)
    {
        cout<<r[i]<<" ";
        outputFile<<r[i]<<" ";
    }
}
