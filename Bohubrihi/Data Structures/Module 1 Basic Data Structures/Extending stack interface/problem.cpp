#include<bits/stdc++.h>
using namespace std;

#define ll long long int

class myStack
{
public:
    ll *a = new ll[400009];
    ll size=0;
    ll maxi;
    ll max()
    {
        return a[maxi];
    }
    void push(ll v)
    {
        if(size==0)
        {
            a[size] = v;
            maxi = 0;
            size++;
        }
        else
        {
            if(a[maxi]<v)
                maxi = size;
            a[size] = v;
            size++;
        }
    }
    void pop()
    {
        if(maxi==size-1)
        {
            maxi = 0;
            for(ll i=1; i<size-1; i++)
            {
                if(a[i]>a[maxi])
                    maxi = i;
            }
            a[size-1] = NULL;
            size--;
        }
        else
        {
            a[size-1] = NULL;
            size--;
        }
    }
    void print()
    {
        cout<<"size: "<<size<<endl;
        for(ll i=0; i<size; i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
};

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("i5.txt");
    outputFile.open("o5.txt");
    ll n,i;
    inputFile>>n;
    myStack r;
    for(i=1; i<=n; i++)
    {
        string s;
        inputFile>>s;
        if(s=="push")
        {
            ll v;
            inputFile>>v;
            r.push(v);
        }
        else if(s=="pop")
        {
            r.pop();
        }
        else if(s=="max")
        {
            ll t = r.max();
            cout<<t<<endl;
            outputFile<<t<<" ";
        }
    }
}
