#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll a[1001][1001];
vector<char> v1;
vector<char> v2;

ll edit_distance(string s1, string s2, ll n, ll m)
{
    if(a[n][m]!=-1)
        return a[n][m];
    ll sub, in, de;
    in = 1 + edit_distance(s1,s2,n,m-1);
    de = 1 + edit_distance(s1,s2,n-1,m);
    if(s1[n-1]==s2[m-1])
    {
        sub = edit_distance(s1,s2,n-1,m-1);
    }
    else
    {

        sub = 1 + edit_distance(s1,s2,n-1,m-1);
    }
    a[n][m] = min(in, min(de,sub));
    return a[n][m];
}

void reconstruct(string s1, string s2, ll n, ll m)
{
    ll i=n, j=m;
    while(i!=0&&j!=0)
    {
        if(s1[i-1]==s2[j-1])
        {
            ll t = min(a[i-1][j-1],min(a[i][j-1],a[i-1][j]));
            if(t==a[i-1][j-1])
            {
                v1.push_back(s1[i-1]);
                v2.push_back(s2[j-1]);
                i--;
                j--;
            }
            else if(t==a[i][j-1])
            {
                v1.push_back('-');
                v2.push_back(s2[j-1]);
                j--;
            }
            else
            {
                v1.push_back(s1[i-1]);
                v2.push_back('-');
                i--;
            }
        }
        else
        {
            ll t = min(1 + a[i-1][j-1],min(1 + a[i][j-1],1 + a[i-1][j]));
            if(t==1 + a[i-1][j-1])
            {
                v1.push_back(s1[i-1]);
                v2.push_back(s2[j-1]);
                i--;
                j--;
            }
            else if(t==1 + a[i][j-1])
            {
                v1.push_back('-');
                v2.push_back(s2[j-1]);
                j--;
            }
            else
            {
                v1.push_back(s1[i-1]);
                v2.push_back('-');
                i--;
            }
        }
    }
    if(i==0)
    {
        while(j!=0)
        {
            v1.push_back('-');
            v2.push_back(s2[j-1]);
            j--;
        }
    }
    if(j==0)
    {
        while(i!=0)
        {
            v1.push_back(s1[i-1]);
            v2.push_back('-');
            i--;
        }
    }
}

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("i5.txt");
    outputFile.open("o5.txt");
    string s1,s2;
    inputFile>>s1>>s2;
    ll n = s1.size();
    ll m = s2.size();
    for(ll i=0; i<=n; i++)
    {
        for(ll j=0; j<=m; j++)
        {
            if(i==0)
            {
                a[i][j] = j;
            }
            else if(j==0)
            {
                a[i][j] = i;
            }
            else
                a[i][j] = -1;
        }
    }
    ll d = edit_distance(s1,s2,n,m);
    /*cout<<s1<<endl;
    cout<<s2<<endl;
    outputFile<<d<<endl;
    for(ll i=0; i<=n; i++)
    {
        for(ll j=0; j<=m; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    reconstruct(s1,s2,n,m);
    while(!v1.empty())
    {
        char t = v1.back();
        cout<< t<<" ";
        v1.pop_back();
    }
    cout<<endl;
    while(!v2.empty())
    {
        char t = v2.back();
        cout<< t<<" ";
        v2.pop_back();
    }*/
    cout<<endl<<d<<endl;
}
