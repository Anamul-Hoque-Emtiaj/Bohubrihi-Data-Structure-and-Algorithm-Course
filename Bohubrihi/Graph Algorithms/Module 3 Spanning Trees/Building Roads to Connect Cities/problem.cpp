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
};

double dist(edge *e)
{
    //fixed(7);
    //setprecision(7);
    return sqrt((e->s->x - e->d->x)*(e->s->x - e->d->x) + (e->s->y - e->d->y)*(e->s->y - e->d->y));
}

void swap(edge *a, edge *b)
{
    edge t;
    t.s = a->s;
    t.d = a->d;
    a->s = b->s;
    a->d = b->d;
    b->s = t.s;
    b->d = t.d;
}

class myHeap
{
public:
    ll size;
    edge **arr;
    myHeap(ll s)
    {
        size = 0;
        arr = new edge*[s];
    }
    ~myHeap()
    {
        delete []arr;
    }
    ll parent(ll i)
    {
        return (i-1)/2;
    }
    ll leftChild(ll i)
    {
        return 2*i+1;
    }
    ll rightChild(ll i)
    {
        return 2*i+2;
    }
    void siftUp(ll i)
    {
        while(i>0)
        {
            ll p = parent(i);
            if(dist(arr[p])<=dist(arr[i]))
                break;
            else
            {
                swap(arr[i],arr[p]);
                i = p;
            }
        }
    }
    void siftDown(ll i)
    {
        while(2*i+1<size)
        {
            ll lc = leftChild(i);
            if(2*i+2==size)
            {
                if(dist(arr[lc])< dist(arr[i]))
                {
                    swap(arr[lc],arr[i]);
                    break;
                }
                else
                    break;
            }
            ll rc = rightChild(i);
            if(dist(arr[i]) <= dist(arr[lc]) && dist(arr[i]) <= dist(arr[rc]))
                break;
            else
            {
                if(dist(arr[lc]) <= dist(arr[rc]))
                {
                    swap(arr[lc],arr[i]);
                    i = lc;
                }
                else
                {
                    swap(arr[rc],arr[i]);
                    i = rc;
                }
            }
        }
    }
    edge* extractMin()
    {
        edge *t = new edge();
        t->s = arr[0]->s;
        t->d = arr[0]->d;
        arr[0]->s = arr[size-1]->s;
        arr[0]->d = arr[size-1]->d;
        size--;
        siftDown(0);
        return t;
    }
    void insert(node *s, node *d)
    {
        arr[size] = new edge();
        arr[size]->s = s;
        arr[size]->d = d;
        size++;
        siftUp(size-1);
    }
};

class myGraph
{
public:
    ll n,size,*par;
    node **arr;
    bool *explore;
    myGraph(ll n)
    {
        this->n = n;
        size = 1;
        arr = new node*[n+1];
        explore = new bool[n+1];
        par = new ll[n+1];
    }
    void addNode(ll x, ll y)
    {
        arr[size]  = new node();
        arr[size]->x = x;
        arr[size]->y = y;
        arr[size]->in = size;
        size++;
    }
    double primes()
    {
        for(ll i=0; i<=n; i++)
        {
            explore[i] = false;
            par[i] = -1;
        }

        double d=0;
        myHeap *m = new myHeap(n*n);
        for(ll i=1; i<size-1; i++)
        {
            m->insert(arr[size-1],arr[i]);
        }
        explore[size-1] = true;
        while(m->size!=0)
        {
            edge *e = m->extractMin();
            if(explore[e->d->in]==false)
            {
                //cout<<e->s->in<<" "<<e->d->in<<endl;
                d+=dist(e);
                explore[e->d->in] = true;
                par[e->d->in] = e->s->in;
                for(ll i=1; i<size-1; i++)
                {
                    if(explore[i]==false)
                    {
                        m->insert(e->d, arr[i]);
                    }
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
    cout<<fixed<<setprecision(7)<<g->primes()<<endl;
}
