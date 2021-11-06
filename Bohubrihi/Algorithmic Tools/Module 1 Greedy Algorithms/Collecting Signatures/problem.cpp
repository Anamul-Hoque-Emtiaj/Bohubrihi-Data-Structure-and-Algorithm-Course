#include<bits/stdc++.h>
using namespace std;

#define ll long long int

class Available
{
public:
    ll from,to;
};

bool compare(Available a, Available b)
{
    return a.to<b.to;
}

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("i5.txt");
    outputFile.open("o5.txt");
    int n,i;
    inputFile>>n;
    Available a[n];
    for(i=0;i<n;i++)
    {
        inputFile>>a[i].from>>a[i].to;
    }
    sort(a,a+n,compare);
    int j=0,c=1;
    vector<ll> v;
    v.push_back(a[j].to);

    for(i=1; i<n; i++)
    {
        if(a[i].from>a[j].to)
        {
            c++;
            j=i;
            v.push_back(a[j].to);
        }

    }
    cout<<c<<" ";
    outputFile<<c<<" ";
    reverse(v.begin(),v.end());
    while(!v.empty())
    {
        ll t = v.back();
        cout<<t<<" ";
        outputFile<<t<<" ";
        v.pop_back();
    }
}

