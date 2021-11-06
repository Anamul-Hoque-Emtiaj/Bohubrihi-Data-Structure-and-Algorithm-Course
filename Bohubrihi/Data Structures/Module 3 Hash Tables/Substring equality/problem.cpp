#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define PRIME 1000000019
#define M 10000
#define a 31
#define b 11
#define x 347

ll intHash(ll n)
{
    return ((a*n+b)%PRIME)%M;
}

ll myHash(string s)
{
    ll v = 0,f=1;
    for(ll i=s.size()-1; i>=0; i--)
    {
        ll t = int(s[i]);
        v+=(t*f)%PRIME;
        v%=PRIME;
        f = (f*x)%PRIME;
    }
    return intHash(v);
}


bool areEqual(string s1, string s2)
{
    if(s1.size()!=s2.size())
        return false;

    for(ll i=0; i<s1.size(); i++)
    {
        if(s1[i]!=s2[i])
            return false;
    }
    return true;
}

void precomputation(string t, ll p, ll arr[])
{
    //have to modify this func with 2d array.. row no indicate starting index of substring and col no indicate size of substring
    arr[t.size()-p] = myHash(t.substr(t.size()-p, p));
    ll y = 1;
    for(ll i=1; i<=p; i++)
        y = (y*x)%PRIME;
    for(ll i=t.size()-p-1; i>=0; i--)
    {
        ll temp = (arr[i+1]*x + int(t[i])-((int(t[i+p])*y)%PRIME))%PRIME;
        if(temp<0)
            temp+=PRIME;
        arr[i] = intHash(temp);
    }
}


int main()
{
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("i5.txt");
    outputFile.open("o5.txt");
    string s;
    inputFile>>s;
    ll n;
    inputFile>>n;
    while(n--)
    {
        ll i1,i2,l;
        inputFile>>i1>>i2>>l;
        ll r1 = myHash(s.substr(i1,l));
        ll r2 = myHash(s.substr(i2,l));
        if(r1==r2)
        {
            cout<<"Yes"<<endl;
            outputFile<<"Yes ";
        }
        else
        {
            cout<<"No"<<endl;
            outputFile<<"No ";
        }
    }
}



