#include<bits/stdc++.h>
using namespace std;

#define ll long long int

class trees
{
public:
    ll key,c,s;
    trees **arr;
    trees()
    {
        c=0;
    }

    void ini(ll s)
    {
        arr = new trees*[s];
        this->s = s;
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
    inputFile.open("testIn.txt");
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
    root->ini(100005);
    list<trees*> v;
    v.push_back(root);

    while(!v.empty())
    {
        trees *t = v.front();
        for(i=0; i<n; i++)
        {
            if(a[i]==t->key)
            {
                trees *c1 = new trees();
                c1->key = i;
                c1->ini(t->s-t->c);
                t->addChild(c1);
                v.push_back(c1);
            }
        }
        v.pop_front();
    }
    ll r = height(root);
    cout<<r<<endl<<endl;

    print(root);
}
