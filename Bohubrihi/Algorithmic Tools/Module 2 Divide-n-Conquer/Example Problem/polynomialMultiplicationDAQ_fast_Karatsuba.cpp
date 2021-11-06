#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll *polynomialMultiplication(ll a[], ll b[], ll n)
{
    ll *res = new ll[2*n-1];
    for(ll i=0; i<2*n-1; i++)
    {
        res[i]=0;
    }

    if(n==1)
    {
        res[0] = a[0]*b[0];
        return res;
    }

    ll a1[n-n/2],a0[n-n/2],b1[n-n/2],b0[n-n/2],an[n-n/2], bn[n-n/2];
    if(n%2==0)
    {
        for(ll i=0; i<n/2; i++)
        {
            a1[i] = a[i];
            a0[i] = a[i+n/2];
            b1[i] = b[i];
            b0[i] = b[i+n/2];
            an[i] = a[i] + a[i+n/2];
            bn[i] = b[i] + b[i+n/2];
        }
    }
    else
    {
        for(ll i=0; i<n/2; i++)
        {
            a1[i] = a[i];
            a0[i] = a[i+n/2];
            b1[i] = b[i];
            b0[i] = b[i+n/2];
            an[i] = a[i] + a[i+n/2];
            bn[i] = b[i] + b[i+n/2];
        }
        a0[n/2] = a[n-1];
        b0[n/2] = b[n-1];
        a1[n/2] = 0;
        b1[n/2] = 0;
        an[n/2] = a[n-1];
        bn[n/2] = b[n-1];
    }
    ll *r11 = polynomialMultiplication(a1,b1,n-n/2);
    ll *r00 = polynomialMultiplication(a0,b0,n-n/2);
    ll *rm = polynomialMultiplication(an,bn,n-n/2);
    if(n%2==0)
    {
        for(ll i=0; i<n-1; i++)
        {
            res[i] += r11[i];
            res[i+n] +=r00[i];
        }
        for(ll i=0; i<n-1; i++)
        {
            res[(n/2)+i]+= (rm[i]-r00[i]-r11[i]);
        }

    }
    else
    {
        for(ll i=0; i<n; i++)
        {
            res[i] += r11[i];
            res[i+n-1] +=r00[i];
        }
        for(ll i=0; i<n; i++)
        {
            res[(n/2)+i]+= (rm[i]-r00[i]-r11[i]);
        }
    }

    return res;
}

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

    ll *res = polynomialMultiplication(a,b,n);
    cout<<endl;
    for(ll i=0; i<2*n-1; i++)
        cout<<res[i]<<" ";
}
