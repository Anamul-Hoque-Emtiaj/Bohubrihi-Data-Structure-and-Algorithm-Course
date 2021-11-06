#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define P 10000019
#define M 10000
#define a 31
#define b 11

struct node
{
    ll key;
    string value;
    node *prev, *next;
};

ll myHash(ll n)
{
    //cout<<n<<" "<<((a*n+b)%P)%M<<endl;
    return ((a*n+b)%P)%M;
}

class myContact
{
public:
    node **arr;
    myContact()
    {
        arr = new node*[M];
        for(ll i=0; i<M; i++)
            arr[i] = NULL;
    }
    ~myContact()
    {
        delete []arr;
    }
    string findContact(ll k)
    {
        ll h = myHash(k);
        node *t = arr[h];
        while(t!=NULL)
        {
            if(t->key==k)
                return t->value;
            if(t->next==NULL)
                break;
            t = t->next;
        }
        return "not found";
    }
    void add(ll k, string v)
    {
        string s = findContact(k);
        ll h = myHash(k);
        if(s=="not found")
        {
            if(arr[h]==NULL)
            {
                node *n = new node();
                n->key = k;
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
                n->key = k;
                n->value = v;
                n->prev = t;
                n->next = NULL;
                t->next = n;
            }
        }
        else
        {
            node *t = arr[h];
            while(1)
            {
                if(t->key==k)
                {
                    t->value = v;
                    break;
                }
                t = t->next;
            }
        }
    }
    void del(ll k)
    {
        string s = findContact(k);
        ll h = myHash(k);
        if(s!="not found")
        {
            node *t = arr[h];
            while(t->key!=k)
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
};

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("i5.txt");
    outputFile.open("o5.txt");
    ll n;
    inputFile>>n;
    myContact *m = new myContact();
    while(n--)
    {
        string s;
        inputFile>>s;
        if(s=="add")
        {
            ll k;
            string v;
            inputFile>>k>>v;
            m->add(k,v);
        }
        else if(s=="find")
        {
            ll k;
            inputFile>>k;
            string r = m->findContact(k);
            cout<<r<<endl;
            outputFile<<r<<",";
        }
        else
        {
            ll k;
            inputFile>>k;
            m->del(k);
        }
    }
    delete m;
}
