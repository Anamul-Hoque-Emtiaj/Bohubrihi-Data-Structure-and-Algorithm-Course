#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void partition(ll a[], ll l, ll h, ll &m1, ll &m2)
{
    ll pvt = h;
    ll j=pvt,k=pvt;
    bool jSet=false;
    bool kSet = false;
    for(ll i=l; i<h; i++)
    {
        if(a[i]>=a[pvt]&&!jSet)
        {
            j=i;
            jSet = true;
        }
        if(a[i]>a[pvt]&&!kSet)
        {
            k=i;
            kSet = true;
        }
        if(a[i]==a[pvt]&&kSet)
        {
            ll t = a[i];
            a[i] = a[k];
            a[k] = t;
            k++;
        }
        else if((a[i]<a[pvt])&&jSet)
        {
            if(kSet)
            {
                ll t = a[i];
                a[i] = a[k];
                a[k] = t;

                t = a[j];
                a[j] = a[k];
                a[k] = t;
                k++;
                j++;
            }
            else
            {
                ll t = a[i];
                a[i] = a[j];
                a[j] = t;
                j++;
            }
        }
    }
    ll t = a[pvt];
    a[pvt] = a[k];
    a[k] = t;
    k++;
    m1 = j;
    m2 = k;
}

void quick_sort(ll a[], ll l, ll h)
{
    if(l<h)
    {
        ll m1,m2;
        partition(a,l,h,m1,m2);
        quick_sort(a,l,m1-1);
        quick_sort(a,m2,h);
    }
}

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("i5.txt");
    if(inputFile.is_open())
    {
        ll n;
        inputFile>>n;
        ll arr[n];
        for(ll i=0; i<n; i++)
            inputFile>>arr[i];

        quick_sort(arr, 0, n-1);

        outputFile.open("o5.txt");
        if(outputFile.is_open())
        {
            for(ll i=0; i<n; i++)
            {
                cout<<arr[i]<<" ";
                outputFile<<arr[i]<<" ";
            }
        }
        else
            cout<<"output File cannot be openned\n";
    }
    else
        cout<<"input File cannot be openned\n";
}
