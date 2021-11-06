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
    ll n,ccc=0;
    node **arr;
    bool *visit;
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
    }
    void addEdge(ll i1, ll i2)
    {
        if(arr[i1]==NULL)
        {
            node *n = new node();
            n->value = i2;
            n->next = NULL;
            arr[i1] = n;
            //cout<<arr[i1]->value<<endl;
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
            //cout<<i1<<" "<<arr[i1]->value<<" "<<i2<<endl;
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
        node *t = arr[in];
        while(t!=NULL)
        {
            if(!visit[t->value])
                explore(t->value);
            t = t->next;
        }
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
    //ofstream outputFile;
    //outputFile.open("o5.txt");
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
    g->dfs();
    cout<<g->ccc<<endl;
}

