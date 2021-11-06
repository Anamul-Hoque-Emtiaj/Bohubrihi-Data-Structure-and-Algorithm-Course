#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll a[10005][305];
vector<ll> v1;

ll knapsack_without_repeatation(ll v[], ll n, ll w)
{
    for(ll i=0; i<=n; i++)
        a[0][i] = 0;
    for(ll i=0; i<=w; i++)
        a[i][0] = 0;
    for(ll i=1; i<=w; i++)
    {
        for(ll j=1; j<=n; j++)
        {
            ll t = a[i][j-1];
            if(v[j-1]<=i)
            {
                if(t<a[i-v[j-1]][j-1] + v[j-1])
                    t = a[i-v[j-1]][j-1] + v[j-1];
            }
            a[i][j] = t;
        }
    }
    return a[w][n];
}

void reconstruct(ll v[], ll n, ll w)
{
    while(1)
    {
        if(n == 0 || w == 0)
            break;
        if(a[w][n]==a[w-1][n])
        {
            w--;
        }
        else if(a[w][n]==a[w][n-1])
        {
            n--;
        }
        else
        {
            v1.push_back(v[n-1]);
            w -= v[n-1];
            n--;
        }
    }
}

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("testIn.txt");
    outputFile.open("o5.txt");
    ll w,n;
    inputFile>>w>>n;
    ll v[n],i;
    for(i=0; i<n; i++)
        inputFile>>v[i];
    ll r = knapsack_without_repeatation(v,n,w);
    cout<<r<<endl;
    reconstruct(v,n,w);
    for(i=0; i<=w; i++)
    {
        for(ll j=0; j<=n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    while(!v1.empty())
    {
        cout<<v1.back()<<" ";
        v1.pop_back();
    }
}

