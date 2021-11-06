#include<bits/stdc++.h>
using namespace std;

#define ll long long int

struct node
{
    ll value;
    node *next;
};

struct visiting
{
    ll in,value;
};

bool cmp(visiting &a, visiting &b)
{
    return a.value>b.value;
}

class myGraph
{
public:
    ll n,ccc=0,c=1;
    node **arr;
    bool *visit;
    visiting *previsit, *postvisit;
    myGraph(ll n)
    {
        this->n = n;
        arr = new node*[n+1];
        for(ll i=0; i<=n; i++)
        {
            arr[i] = new node();
            arr[i] = NULL;
        }
        visit = new bool[n+1];
        previsit = new visiting[n+1];
        postvisit = new visiting[n+1];
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
    bool checkNeighber(ll i1, ll i2)
    {
        node *t = arr[i1];
        while(t!=NULL)
        {
            if(t->value==i2)
            {
                return true;
            }
            t = t->next;
        }
        return false;
    }
    void explore(ll in)
    {
        visit[in] = true;
        previsit[in].in = in;
        previsit[in].value = c;
        c++;
        node *t = arr[in];
        while(t!=NULL)
        {
            if(!visit[t->value])
                explore(t->value);
            t = t->next;
        }
        postvisit[in].value = c;
        postvisit[in].in = in;
        c++;
    }
    bool checkPath(ll i1, ll i2)
    {
        for(ll i=0; i<=n; i++)
            visit[i] = false;
        explore(i1);
        return visit[i2];
    }
    void dfs()
    {
        for(ll i=0; i<=n; i++)
            visit[i] = false;
        for(ll i=1; i<=n; i++)
        {
            if(!visit[i])
            {
                explore(i);
                ccc++;
            }
        }
    }
    void topologicalSort()
    {
        dfs();
        sort(postvisit+1, postvisit+n+1,cmp);
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
    ofstream outputFile;
    outputFile.open("o5.txt");
    ll n,m;
    inputFile>>n>>m;
    myGraph *g = new myGraph(n);
    while(m--)
    {
        ll in1,in2;
        inputFile>>in1>>in2;
        g->addEdge(in1,in2);
    }
    //g->print();
    g->topologicalSort();
    for(ll i=1; i<=n; i++)
    {
        visiting t = g->postvisit[i];
        cout<<t.in<<" "<<t.value<<endl;
        outputFile<<t.in<<" ";
    }
}

