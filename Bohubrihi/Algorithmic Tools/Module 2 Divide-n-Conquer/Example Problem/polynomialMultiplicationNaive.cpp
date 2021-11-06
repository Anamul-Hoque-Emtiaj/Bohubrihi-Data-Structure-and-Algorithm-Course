#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ll n;
    cin>>n;
    ll a[n],b[n];
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(ll i=0; i<n; i++)
    {
        cin>>b[i];
    }
    ll c[n][n];
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<n; j++)
        {
            c[i][j] =a[i]*b[j];
        }
    }
    ll x = 2*n-1;
    ll result[x];
    for(ll i=0; i<x; i++)
        result[i]=0;
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<n; j++)
        {
            result[i+j]+=c[i][j];
        }
    }
    for(ll i=0; i<x; i++)
        cout<<result[i]<<" ";
}
