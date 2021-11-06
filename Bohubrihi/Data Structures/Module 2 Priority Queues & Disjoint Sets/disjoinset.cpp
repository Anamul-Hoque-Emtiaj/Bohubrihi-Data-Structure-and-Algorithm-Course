#include<bits/stdc++.h>
using namespace std;

#define ll long long int

 ll parent[100000],height[100000];

 void make_set(ll i)
 {
     parent[i] = i;
     height[i] = 0;
 }

 ll find(ll i)
 {
     while(i!=parent[i])
     {
         i = parent[i];
     }
     return i;
 }

 void make_union(ll x, ll y)
 {
     ll p1 = find(x);
     ll p2 = find(y);
     if(p1!=p2)
     {
         if(height[p1]==height[p2])
         {
             parent[p2] = p1;
             height[p1]+=1;
         }
         else if(height[p1]>height[p2])
            parent[p2] = p1;
         else
            parent[p1] = p2;
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
     ll n;
     cin>>n;
     for(ll i=0; i<n; i++)
        make_set(i);
     print(n);
     make_union(1,3);
     make_union(4,2);
     make_union(5,6);
     print(n);
     make_union(3,4);
     make_union(2,6);
     print(n);
 }
