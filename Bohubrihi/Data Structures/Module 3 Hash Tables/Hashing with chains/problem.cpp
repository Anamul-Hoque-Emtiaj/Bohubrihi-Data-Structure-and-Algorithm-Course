#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define P 1000000007
#define a 31
#define b 11
#define x  263

struct node
{
    string value;
    node *prev, *next;
};
/*ll intHash(ll n, ll M)
{
    return ((a*n+b)%P)%M;
}*/
ll myHash(string s, ll M)
{
    ll v = 0;
    for(ll i=s.size()-1; i>=0; i--)
    {
        ll t = int(s[i]);
        v = ((v*x + t)%P);
    }
    //v = intHash(v,M);
    v = v%M;
    //cout<<s<<" "<<v<<endl;
    return v;
}

class myContact
{
public:
    node **arr;
    ll M;
    myContact(ll M)
    {
        this->M = M;
        arr = new node*[M];
        for(ll i=0; i<M; i++)
            arr[i] = NULL;
    }
    ~myContact()
    {
        delete []arr;
    }
    string findContact(string s)
    {
        ll h = myHash(s,M);
        node *t = arr[h];
        while(t!=NULL)
        {
            if(t->value==s)
                return "yes";
            if(t->next==NULL)
                break;
            t = t->next;
        }
        return "no";
    }
    void add(string v)
    {
        string s = findContact(v);
        ll h = myHash(v,M);
        if(s=="no")
        {
            if(arr[h]==NULL)
            {
                node *n = new node();
                n->value = v;
                n->prev = NULL;
                n->next = NULL;
                arr[h] = n;
            }
            else
            {
                node *t = arr[h];
                while(1)
                {
                    if(t->next==NULL)
                        break;
                    t = t->next;
                }
                node *n = new node();
                n->value = v;
                n->prev = t;
                n->next = NULL;
                t->next = n;
            }
        }
    }
    void del(string k)
    {
        string s = findContact(k);
        ll h = myHash(k,M);
        if(s!="no")
        {
            node *t = arr[h];
            while(t->value!=k)
            {
                t = t->next;
            }
            if(t->prev==NULL)
            {
                if(t->next==NULL)
                    arr[h] = NULL;
                else
                {
                    t = t->next;
                    t->prev = NULL;
                    arr[h] = t;
                }
            }
            else if(t->next==NULL)
            {
                t->prev->next = NULL;
            }
            else
            {
                t->prev->next = t->next;
                t->next->prev = t->prev;
            }
        }
    }
    string check(ll i)
    {
        if(arr[i]!=NULL)
        {
            node *t = arr[i];
            string s = t->value;
            t = t->next;
            while(1)
            {
                if(t==NULL)
                    break;
                s = t->value + " " + s;
                t = t->next;
            }
            return s;
        }
        else
            return "";
    }
};

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("testIn.txt");
    outputFile.open("o.txt");
    ll n,M;
    inputFile>>M>>n;
    myContact *m = new myContact(M);
    while(n--)
    {
        string s;
        inputFile>>s;
        if(s=="add")
        {
            string v;
            inputFile>>v;
            m->add(v);
        }
        else if(s=="find")
        {
            string v;
            inputFile>>v;
            string r = m->findContact(v);
            cout<<r<<",";
            outputFile<<r<<",";
        }
        else if(s=="del")
        {
            string v;
            inputFile>>v;
            m->del(v);
        }
        else if(s=="check")
        {
            ll in;
            inputFile>>in;
            string r = m->check(in);
            cout<<r<<",";
            outputFile<<r<<",";
        }
    }
    delete m;
}

