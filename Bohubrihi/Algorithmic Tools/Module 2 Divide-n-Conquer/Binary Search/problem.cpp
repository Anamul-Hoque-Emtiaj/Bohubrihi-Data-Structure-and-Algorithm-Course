#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll binarySearch(ll l, ll h, ll a[], ll k)
{
    ll r = -1;
    ll m = (l+h)/2;
    if(l>h)
        return -1;

    if(a[m]==k)
    {
        return m;
    }
    else if(a[m]>k)
    {
        return binarySearch(l,m-1,a,k);
    }
    else
    {
        return binarySearch(m+1,h,a,k);
    }
}

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("i5.txt");
    outputFile.open("o5.txt");
    ll n,i,k;
    inputFile>>n;
    ll a[n];
    for(i=0; i<n; i++)
        inputFile>>a[i];
    inputFile>>k;
    ll b[k];
    for(i=0; i<k; i++)
        inputFile>>b[i];
    for(i=0; i<k; i++)
    {
        ll r = binarySearch(0,n-1,a,b[i]);
        outputFile<<r<<" ";
        cout<<r<<" ";
    }
}
