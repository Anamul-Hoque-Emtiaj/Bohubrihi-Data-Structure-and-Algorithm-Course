#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll money_change(ll c[], ll n, ll m )
{
    ll a[n+1];
    a[0] = 0;
    for(ll i=1; i<=n; i++)
    {
        ll mini = 1000000000;
        for(ll j=0; j<m; j++)
        {
            if(i>=c[j])
            {
                ll t = 1 + a[i-c[j]];
                if(t<mini)
                    mini = t;
            }
        }
        a[i] = mini;
    }
    return a[n];
}

int main()
{
    ll c[] = {1,3,4};
    cout<<money_change(c,2,3)<<endl;
    cout<<money_change(c,34,3)<<endl;

    cout<<money_change(c,477,3)<<endl;
    cout<<money_change(c,939,3)<<endl;
    cout<<money_change(c,818,3)<<endl;
    cout<<money_change(c,781,3)<<endl;
    cout<<money_change(c,697,3)<<endl;
}
