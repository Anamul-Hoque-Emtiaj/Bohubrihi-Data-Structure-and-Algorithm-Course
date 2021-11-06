#include<bits/stdc++.h>
using namespace std;

#define ll long long int

struct node
{
    ll value;
    node *next;
};

class myGraph
{
public:
    ll n,*level,*par;
    node **arr;

    myGraph(ll n)
    {
        this->n = n;
        arr = new node*[n+1];
        par = new ll[n+1];
        level = new ll[n+1];
        for(ll i=0; i<=n; i++)
        {
            arr[i] = new node();
            arr[i] = NULL;
        }
    }
    void addEdge(ll i1, ll i2)
    {
        if(arr[i1]==NULL)
        {
            node *n = new node();
            n->value = i2;
            n->next = NULL;
            arr[i1] = n;
        }
        else
        {
            node *t = arr[i1];
            while(t!=NULL)
            {
                if(t->next!=NULL)
                    t = t->next;
                else
                    break;
            }
            node *n = new node();
            n->value = i2;
            n->next = NULL;
            t->next = n;
        }
    }
    void addUndirectedEdge(ll i1, ll i2)
    {
        addEdge(i1,i2);
        addEdge(i2,i1);
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
            node *t = arr[f];
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
            node *t = arr[i];
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
            node *t = arr[i];
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
        ll in1,in2;
        inputFile>>in1>>in2;
        g->addUndirectedEdge(in1,in2);
    }
    //g->print();
    cout<<g->bipartite()<<endl;
}




