#include<bits/stdc++.h>
using namespace std;

#define ll long long int

struct edge
{
    ll value,weight;
    edge *next;
};

struct node
{
    ll index, dist;
};

void swap(node *a, node *b)
{
    node t;
    t.index = a->index;
    t.dist = a->dist;
    a->index = b->index;
    a->dist = b->dist;
    b->index = t.index;
    b->dist = t.dist;
}

class myHeap
{
public:
    ll size;
    node **arr;
    myHeap(ll s)
    {
        size = 0;
        arr = new node*[s];
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
            if(arr[p]->dist<=arr[i]->dist)
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
                if(arr[lc]->dist<arr[i]->dist)
                {
                    swap(arr[lc],arr[i]);
                    break;
                }
                else
                    break;
            }
            ll rc = rightChild(i);
            if(arr[i]->dist <= arr[lc]->dist && arr[i]->dist <= arr[rc]->dist)
                break;
            else
            {
                if(arr[lc]->dist<=arr[rc]->dist)
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
    node* extractMin()
    {
        node *t = new node();
        t->index = arr[0]->index;
        t->dist = arr[0]->dist;
        arr[0]->index = arr[size-1]->index;
        arr[0]->dist = arr[size-1]->dist;
        size--;
        siftDown(0);
        return t;
    }
    void insert(node *p)
    {
        arr[size] = new node();
        arr[size]->index = p->index;
        arr[size]->dist = p->dist;
        size++;
        //cout<<"in: "<<p->index<<" "<<p->dist<<endl;
        siftUp(size-1);
    }
    void changePriority(ll ind, ll p)
    {
        ll t,in;
        for(ll i=0; i<size; i++)
        {
            if(arr[i]->index==ind)
            {
                t = arr[i]->dist;
                arr[i]->dist = p;
                in=i;
                break;
            }
        }
        if(p>t)
        {
            siftDown(in);
        }
        else
            siftUp(in);
    }
    void remove(ll i)
    {
        changePriority(i,-1);
        extractMin();
    }
};

class myGraph
{
public:
    ll n,*level,*par,*dist;
    edge **arr;

    myGraph(ll n)
    {
        this->n = n;
        arr = new edge*[n+1];
        par = new ll[n+1];
        level = new ll[n+1];
        dist = new ll[n+1];
        for(ll i=0; i<=n; i++)
        {
            arr[i] = new edge();
            arr[i] = NULL;
        }
    }
    void addEdge(ll i1, ll i2, ll w)
    {
        if(arr[i1]==NULL)
        {
            edge *n = new edge();
            n->value = i2;
            n->next = NULL;
            n->weight = w;
            arr[i1] = n;
        }
        else
        {
            edge *t = arr[i1];
            while(t!=NULL)
            {
                if(t->next!=NULL)
                    t = t->next;
                else
                    break;
            }
            edge *n = new edge();
            n->value = i2;
            n->weight = w;
            n->next = NULL;
            t->next = n;
        }
    }

    ll dijkstra(ll s, ll d)
    {
        for(ll i=0; i<=n; i++)
        {
            dist[i] = 1000000;
            par[i] = -1;
        }
        dist[s] = 0;
        myHeap *m = new myHeap(n);
        node *tmp = new node();
        tmp->index = s;
        tmp->dist = 0;
        m->insert(tmp);
        while(m->size!=0)
        {
            node *f = m->extractMin();
            //cout<<"ex: "<<f->index<<" "<<f->weight<<endl;
            edge *t = arr[f->index];
            while(t!=NULL)
            {
                if(dist[t->value]==1000000)
                {
                    dist[t->value] = dist[f->index] + t->weight;
                    par[t->value] = f->index;
                    node *tmp1 = new node();
                    tmp1->index = t->value;
                    tmp1->dist = dist[t->value];
                    m->insert(tmp1);
                }
                else if(dist[t->value] > (dist[f->index] + t->weight))
                {
                    dist[t->value] = dist[f->index] + t->weight;
                    par[t->value] = f->index;
                    m->changePriority(t->value,dist[t->value]);
                    //cout<<"cng: "<<t->value<<" "<<dist[t->value]<<endl;
                }
                t = t->next;
            }
        }
        if(dist[d]==1000000)
            return -1;
        else
            return dist[d];
    }

    void belmanford(ll a)
    {
        for(ll i=0; i<=n; i++)
        {
            dist[i] = 1000000;
            par[i] = -1;
        }

        dist[a] = 0;
        for(ll j=1; j<=n; j++)
        {
            for(ll i=1; i<=n; i++)
            {
                if(arr[i]!=NULL)
                {
                    edge *t = arr[i];
                    while(t!=NULL)
                    {
                        if(dist[t->value] > (dist[i] + t->weight))
                        {
                            dist[t->value] = dist[i] + t->weight;
                            par[t->value] = i;
                        }
                        t = t->next;
                    }
                }
            }
        }
    }

    ll negetiveCycle()
    {
        ll a;
        for(ll i=1; i<=n; i++)
        {
            if(arr[i]!=NULL)
            {
                a = i;
                break;
            }
        }
        belmanford(a);

        ll c=0;
        for(ll i=1; i<=n; i++)
        {
            if(c==1)
                break;
            if(arr[i]!=NULL)
            {
                edge *t = arr[i];
                while(t!=NULL)
                {
                    if(dist[t->value] > (dist[i] + t->weight))
                    {
                        c=1;
                        break;
                    }
                    t = t->next;
                }
            }
        }
        return c;
    }

    void bfs(ll s)
    {
        for(ll i=0; i<=n; i++)
        {
            level[i] = 1000000;
            par[i] = -1;
        }
        level[s] = 0;
        queue<ll> myQ;
        myQ.push(s);
        while(!myQ.empty())
        {
            ll f = myQ.front();
            myQ.pop();
            edge *t = arr[f];
            while(t!=NULL)
            {
                if(level[t->value]==1000000)
                {
                    level[t->value] = level[f] + 1;
                    par[t->value] = f;
                    myQ.push(t->value);
                }
                t = t->next;
            }
        }
    }

    ll minimumEdge(ll s, ll d)
    {
        bfs(s);
        ll t = level[d],r=-1;
        if(t==1000000)
            return r;
        else
            return t;
    }

    ll bipartite()
    {
        bfs(n);
        ll f=1;
        for(ll i=1; i<=n; i++)
        {
            if(f==0)
                break;
            edge *t = arr[i];
            while(t!=NULL)
            {
                if(level[i]==level[t->value])
                {
                    f=0;
                    break;
                }
                t = t->next;
            }
        }
        return f;
    }

    void print()
    {
        for(ll i=1; i<=n; i++)
        {
            cout<<i<<": ";
            edge *t = arr[i];
            while(t!=NULL)
            {
                cout<<t->value<<" ";
                t = t->next;
            }
            cout<<endl;
        }
    }
};

int main()
{
    ifstream inputFile;
    inputFile.open("i5.txt");
    ll n,m;
    inputFile>>n>>m;
    myGraph *g = new myGraph(n);
    while(m--)
    {
        ll s,d,w;
        inputFile>>s>>d>>w;
        g->addEdge(s,d,w);
    }
    //g->print();
    cout<<g->negetiveCycle()<<endl;
}






