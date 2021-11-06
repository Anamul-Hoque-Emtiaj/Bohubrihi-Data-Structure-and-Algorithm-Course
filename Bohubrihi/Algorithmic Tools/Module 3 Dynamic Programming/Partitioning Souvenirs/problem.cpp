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
    ll c=0;
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
            if(a[i][j]==w)
                c++;
        }
    }
    if(c>=3)
        return 1;
    else
        return 0;
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
    inputFile.open("testIn.txt");
    ll w,n;
    inputFile>>n;
    ll v[n],i,s=0;
    for(i=0; i<n; i++)
    {
        inputFile>>v[i];
        s+=v[i];
    }
    if(n<3)
        cout<<"0"<<endl;
    else if(s%3==0)
    {
        ll r = knapsack_without_repeatation(v,n,s/3);
        cout<<r<<endl;
    }
    else
        cout<<"0"<<endl;
}


