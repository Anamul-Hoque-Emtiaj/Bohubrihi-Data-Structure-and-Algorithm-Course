#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll *merged(ll *a, ll *b, ll n, ll m)
{
    ll *res = new ll[n+m];
    ll i=0,j=0,k=0;
    while(1)
    {
        if(a[i]<=b[j]&& i<n && j<m)
        {
           res[k++] = a[i++];
        }
        else if(a[i]>b[j] && i<n && j<m)
        {
            res[k++] = b[j++];
        }
        else if(i==n && j<m)
        {
            res[k++] = b[j++];
        }
        else if(i<n && j==m)
        {
            res[k++] = a[i++];
        }
        else
            break;
    }
    return res;
}

ll *mergedSort(ll arr[], ll l, ll h)
{
    if(l==h)
        return &arr[l];
    ll n = h-l+1;
    ll *r1 = mergedSort(arr,l, ((l+h)/2));
    ll  *r2 = mergedSort(arr, ((l+h)/2)+1, h);
    return merged(r1,r2,n-n/2,n/2);
}

int Majority_Element(ll a[], ll n)
{
   ll count = 1, cur = a[0],m=0;
   for(ll i=1; i<n; i++)
   {
       if(a[i]==cur)
        count++;
       else
       {
           if(count>m)
            m=count;
           cur=a[i];
           count = 1;
       }
   }
   if(m>n/2)
    return 1;
   else
    return 0;
}

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("i5.txt");
    outputFile.open("o5.txt");
    ll n;
    inputFile>>n;
    ll arr[n];
    for(ll i=0; i<n; i++)
        inputFile>>arr[i];
    ll *r = mergedSort(arr, 0, n-1);
    int t = Majority_Element(r,n);
    outputFile<<t<<endl;
    cout<<t<<endl;
}
