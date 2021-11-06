#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("i5.txt");
    outputFile.open("o5.txt");
    ll n,c=0,t=1;
    inputFile>>n;
    vector<ll>v;
    while(n>0)
    {
        if(t>n)
        {
            ll temp = v.back();
            temp +=n;
            v.pop_back();
            v.push_back(temp);
            n=0;
        }
        else
        {
            v.push_back(t);
            n-=t;
            c++;
            t++;
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


