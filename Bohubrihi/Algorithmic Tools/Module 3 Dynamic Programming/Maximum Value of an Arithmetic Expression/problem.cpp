#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll Max[50][50],Min[50][50];

ll max_value(ll  v[], ll n, char o[])
{
    for(ll i=0; i<n; i++)
    {
        Max[i][i] = v[i];
        Min[i][i] = v[i];
    }
    ll i=0;
    ll j=1;
    while(1)
    {
        ll mini = LONG_MAX;
        ll maxi = LONG_MIN;
        for(ll k=i; k<j; k++)
        {
            ll t1,t2,t3,t4;
            if(o[k]=='+')
            {
                t1 = Max[i][k] + Max[k+1][j];
                t2 = Min[i][k] + Min[k+1][j];
                t3 = Max[i][k] + Min[k+1][j];
                t4 = Min[i][k] + Max[k+1][j];
            }
            else if(o[k]=='-')
            {
                t1 = Max[i][k] - Max[k+1][j];
                t2 = Min[i][k] - Min[k+1][j];
                t3 = Max[i][k] - Min[k+1][j];
                t4 = Min[i][k] - Max[k+1][j];
            }
            else
            {
                t1 = Max[i][k] * Max[k+1][j];
                t2 = Min[i][k] * Min[k+1][j];
                t3 = Max[i][k] * Min[k+1][j];
                t4 = Min[i][k] * Max[k+1][j];
            }
            maxi = max(maxi,max(t1,max(t2,max(t3,t4))));
            mini = min(mini,min(t1,min(t2,min(t3,t4))));
        }
        Max[i][j] = maxi;
        Min[i][j] = mini;
        if(j==n-1)
        {
            if(i==0)
                break;
            else
            {
               j = j-i+1;
               i=0;
            }
        }
        else
        {
            i++;
            j++;
        }
    }
    return Max[0][n-1];
}

int main()
{
    ifstream inputFile;
    inputFile.open("testIn.txt");
    string s;
    inputFile>>s;
    ll n = s.size();
    ll v[n-n/2], vi=0,oi=0;
    char o[n/2];
    for(ll i=0; i<s.size(); i++)
    {
        if(i%2==0)
        {
            v[vi++] = s[i] - '0';
        }
        else
            o[oi++] = s[i];
    }
    ll r = max_value(v, n-n/2, o);
    cout<<r<<endl;
    for(ll i=0; i<n-n/2; i++)
    {
        for(ll j=0; j<n-n/2; j++)
            cout<<Max[i][j]<<" ";
        cout<<endl;
    }
    for(ll i=0; i<n-n/2; i++)
    {
        for(ll j=0; j<n-n/2; j++)
            cout<<Min[i][j]<<" ";
        cout<<endl;
    }
}
