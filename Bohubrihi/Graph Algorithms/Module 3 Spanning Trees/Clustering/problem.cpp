#include<bits/stdc++.h>
using namespace std;

#define ll long long int

struct node
{
    ll x,y,in;
};

struct edge
{
    node *s,*d;
    ll dis;
};

double dist(edge *e)
{
    return sqrt((e->s->x - e->d->x)*(e->s->x - e->d->x) + (e->s->y - e->d->y)*(e->s->y - e->d->y));
}

bool cmp(edge *a, edge *b)
{
    return dist(a)<dist(b);
}

class myGraph
{
public:
    ll n,size,*par,c,*height;
    node **arr;
    edge **edg;
    bool *explore;
    myGraph(ll n)
    {
        this->n = n;
        size = 0;
        c=0;
        arr = new node*[n];
        explore = new bool[n];
        par = new ll[n];
        height = new ll[n];
        edg = new edge*[n*n];
    }
    void addNode(ll x, ll y)
    {
        arr[size]  = new node();
        arr[size]->x = x;
        arr[size]->y = y;
        arr[size]->in = size;
        size++;
    }

    void filledEdge()
    {
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<n; j++)
            {
                if(i!=j)
                {
                    edg[c] = new edge();
                    edg[c]->s = arr[i];
                    edg[c]->d = arr[j];
                    edg[c]->dis = dist(edg[c]);
                    c++;
                }
            }
        }
    }

    void make_set(ll i)
    {
        par[i] = i;
        height[i] = 0;
    }

    ll find(ll i)
    {
        while(i!=par[i])
        {
            i = par[i];
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
                par[p2] = p1;
                height[p1]+=1;
            }
            else if(height[p1]>height[p2])
                par[p2] = p1;
            else
                par[p1] = p2;
        }
    }

    double clustering(ll k)
    {
        filledEdge();
        sort(edg,edg+c,cmp);
        for(ll i=0; i<n; i++)
            make_set(i);
        ll r = n;
        for(ll i=0; i<c; i++)
        {
            if(r==k)
                break;
            edge *e = edg[i];
            if(find(e->s->in)!=find(e->d->in))
            {
                r--;
                make_union(e->s->in, e->d->in);
            }
        }
        double d=1000000.00;
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<n; j++)
            {
                if(find(i)!=find(j))
                {
                    edge *e = new edge();
                    e->s = arr[i];
                    e->d = arr[j];
                    if(dist(e)<d)
                        d = dist(e);
                }
            }
        }
        return d;
    }
};

int main()
{
    ifstream inputFile;
    //ofstream outputFile;
    inputFile.open("i5.txt");
    //outputFile.open("o1.txt");
    ll n,m;
    inputFile>>n;
    m=n;
    myGraph *g = new myGraph(n);
    while(m--)
    {
        ll x,y;
        inputFile>>x>>y;
        g->addNode(x,y);
    }
    ll k;
    inputFile>>k;
    cout<<fixed<<setprecision(7)<<g->clustering(k)<<endl;
}

