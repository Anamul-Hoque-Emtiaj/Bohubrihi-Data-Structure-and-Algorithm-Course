#include<bits/stdc++.h>
using namespace std;

#define ll long long int

 ll parent[100005],height[100005];
 ll maxi = 0;

 void make_set(ll i, ll r)
 {
     parent[i] = i;
     height[i] = r;
     if(r>maxi)
        maxi = r;
 }

 ll find(ll i)
 {
     while(i!=parent[i])
     {
         i = parent[i];
     }
     return i;
 }

 void make_union(ll des, ll sour)
 {
     ll p1 = find(des);
     ll p2 = find(sour);
     if(p1!=p2)
     {
         parent[p2] = p1;
         height[p1]+=height[p2];
         if(height[p1]>maxi)
            maxi = height[p1];
     }
 }

 void print(ll n)
 {
     for(ll i=0; i<n; i++)
        cout<<parent[i]<<" ";
     cout<<endl;
     for(ll i=0; i<n; i++)
        cout<<height[i]<<" ";
     cout<<endl<<endl;
 }

 int main()
 {
     ifstream inputFile;
     ofstream outputFile;
     inputFile.open("i5.txt");
     outputFile.open("o5.txt");
     ll n,m;
     inputFile>>n>>m;
     parent[0] = 0;
     height[0] = 0;
     ll a[n];
     for(ll i=0; i<n; i++)
     {
         inputFile>>a[i];
     }
     for(ll i=0; i<n; i++)
     {
         make_set(i+1,a[i]);
     }
     for(ll i=1; i<=m; i++)
     {
         ll d,s;
         inputFile>>d>>s;
         make_union(d,s);
         cout<<maxi<<endl;
         outputFile<<maxi<<" ";
     }
 }

