#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll r[1001][1001];

ll longest_common_subsequence(ll a[], ll b[], ll n, ll m)
{
    if(n<0 || m<0)
        return 0;
    if(r[n][m]!=-1)
        return r[n][m];
    ll in, de, sub;
    if(a[n]==b[m])
    {
        sub = 1 + longest_common_subsequence(a,b,n-1,m-1);
        r[n][m] = sub;
    }
    else
    {
       in = longest_common_subsequence(a,b,n,m-1);
       de = longest_common_subsequence(a,b,n-1,m);
       r[n][m] = max(in, de);
    }

    return r[n][m];
}

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("i5.txt");
    outputFile.open("o5.txt");
    ll n,m,i,j;
    inputFile>>n;
    ll a[n];
    for(i=0; i<n; i++)
    {
        inputFile>>a[i];
    }
    inputFile>>m;
    ll b[m];
    for(i=0; i<m; i++)
    {
        inputFile>>b[i];
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            r[i][j] = -1;
    }

    ll d = longest_common_subsequence(a,b,n-1,m-1);
    cout<<d<<endl;
    outputFile<<d<<endl;
    /*for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            cout<<r[i][j]<<" ";
        cout<<endl;
    }*/
}
