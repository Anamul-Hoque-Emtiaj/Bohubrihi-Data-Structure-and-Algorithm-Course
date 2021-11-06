#include<bits/stdc++.h>
using namespace std;

#define ll long long int

//buttom to top
ll *primitive_calculator(ll n)
{
    ll *a = new ll[n+1];
    a[0] = -1;
    a[1] = 0;
    for(ll i=2; i<=n; i++)
    {
        ll r1 = 100000000, r2 = 100000000, r3 = 100000000;
        if(i>1)
            r1 = 1 + a[i-1];
        if(i%2==0)
            r2 = 1 + a[i/2];
        if(i%3==0)
            r3 = 1 + a[i/3];
        a[i] = min(r1, min(r2, r3));
    }

    return a;
}

//top to bottom
ll primitive_calculator2(ll a[], ll n)
{
    if(a[n]!=-1)
        return a[n];
    ll r1 = 1000000;
    ll r2 = 1000000;
    ll r3 = 1000000;
    if(n>1)
        r1 = 1 + primitive_calculator2(a, n-1);
    if(n%2==0)
        r2 = 1 + primitive_calculator2(a, n/2);
    if(n%3==0)
        r3 = 1 + primitive_calculator2(a, n/3);
    a[n] = min(r1, min(r2, r3));
    return a[n];
}

vector<ll> reconstruct(ll a[], ll n)
{
    vector<ll> c;
    c.push_back(n);
    ll t = n;
    for(ll i=1; i<a[n]; i++)
    {
        if(t%3==0 && a[t] == a[t/3]+1)
        {
            c.push_back(t/3);
            t = t/3;
        }
        else if(t%2==0 && a[t] == a[t/2]+1)
        {
            c.push_back(t/2);
            t = t/2;
        }
        else if(t>1 && a[t] ==a[t-1]+1)
        {
            c.push_back(t-1);
            t--;
        }
    }
    if(n!=1)
        c.push_back(1);
    return c;
}


int main()
{
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("i5.txt");
    outputFile.open("o5.txt");
    ll n;
    inputFile>>n;
    cout<<n<<endl;
    ll *a = primitive_calculator(n);
    vector<ll> v = reconstruct(a,n);
    cout<<a[n]<<" ";
    outputFile<<a[n]<<" ";
    while(!v.empty())
    {
        ll t = v.back();
        cout<< t<<" ";
        outputFile<< t<<" ";
        v.pop_back();
    }
    outputFile<<endl;
}
