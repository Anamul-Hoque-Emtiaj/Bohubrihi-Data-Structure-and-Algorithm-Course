#include<bits/stdc++.h>
using namespace std;

#define ll long long int

class trees
{
public:
    ll key,c,h;
    trees **arr;
    trees()
    {
        c=0;
        arr = new trees*[100000];
    }

    ~trees()
    {
        delete []arr;
    }

    void addChild(trees *t)
    {
        arr[c++] = t;
    }
};

ll height(trees *t)
{
    if(t->c==0)
    {
        return 1;
    }
    ll maxi = 0;
    for(ll i=0; i<t->c; i++)
    {
        ll v = height(t->arr[i]);
        if(v>maxi)
            maxi = v;
    }
    return maxi+1;
}

void print(trees *t)
{
    for(ll i=0; i<t->c; i++)
        print(t->arr[i]);
    cout<<t->key<<endl;
    for(ll i=0; i<t->c; i++)
        cout<<t->arr[i]->key<<" ";
    cout<<endl;
}

int main()
{
    ifstream inputFile;
    inputFile.open("i2.txt");
    ll n;
    inputFile>>n;
    ll a[n],i,in;
    for(i=0; i<n; i++)
    {
        inputFile>>a[i];
        if(a[i]==-1)
            in = i;
    }
    trees *root = new trees();
    root->key = in;
    trees **arr = new trees*[n];
    arr[in] = root;
    for(i=0; i<n; i++)
    {
        if(a[i]!=-1)
        {
            arr[i] = new trees();
            arr[i]->key = i;
        }
    }

    for(ll i=0; i<n; i++)
    {
        if(a[i]!=-1)
        {
            arr[a[i]]->addChild(arr[i]);
        }
    }

    cout<<height(arr[in])<<endl;
    //print(arr[in]);

    delete []arr;
}

