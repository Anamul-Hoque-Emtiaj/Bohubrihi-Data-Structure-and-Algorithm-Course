#include<bits/stdc++.h>
using namespace std;

#define ll long long int

struct packet
{
    ll appearTime, processTime;
};

class node
{
public:
    ll key;
    node *prev, *next;
};

class myQueue
{
public:
    node *head = NULL, *tail = NULL;
    ll s=0;

    ll front()
    {
        if(s>0)
            return head->key;
        else
            return NULL;
    }
    void push(ll k)
    {
        if(s==0)
        {
            node *n = new node();
            n->key = k;
            n->prev = NULL;
            n->next = NULL;
            head = n;
            tail = n;
            s++;
        }
        else
        {
            node *n = new node();
            n->key = k;
            n->prev = tail;
            n->next = NULL;
            tail->next = n;
            tail = n;
            s++;
        }

    }
    void pop()
    {
        if(s==1)
        {
            s = 0;
            head = NULL;
            tail = NULL;
        }
        else if(s>1)
        {
            head = head->next;
            head->prev = NULL;
            s--;
        }
        else
        {
            cout<<"Empty List\n";
        }
    }
};

int main()
{
    ifstream inputFile;
    inputFile.open("i4.txt");
    ofstream outputFile;
    outputFile.open("o4.txt");
    ll n,s,i;
    inputFile>>s>>n;
    packet a[n];
    for(i=0; i<n; i++)
    {
        inputFile>>a[i].appearTime>>a[i].processTime;

    }
    myQueue *q = new myQueue();
    ll arr[n],f,res[n];
    f = a[0].appearTime + a[0].processTime;
    arr[0] = f;
    q->push(f);
    res[0] = a[0].appearTime;
    for(i=1; i<n; i++)
    {
        if(f>=a[i].appearTime)
        {
            arr[i] = f + a[i].processTime;
            f+= a[i].processTime;
        }
        else
        {
            arr[i] = a[i].appearTime + a[i].processTime;
            f = a[i].appearTime + a[i].processTime;
        }
        cout<<"t: "<<i<<" "<<arr[i]<<endl;
    }

    for(i=1; i<s; i++)
    {
        q->push(arr[i]);
        res[i] = arr[i-1]>a[i].appearTime? arr[i-1] : a[i].appearTime;
    }

    for(i=s; i<n; i++)
    {
        ll t = q->front();
        if(t>a[i].appearTime)
        {
            res[i]  = -1;
        }
        else
        {
            q->pop();
            q->push(arr[i]);
            res[i] = arr[i-1] > a[i].appearTime? arr[i-1] : a[i].appearTime;
        }
    }
    for(i=0; i<n; i++)
    {
        cout<<res[i]<<" ";
        outputFile<<res[i]<<" ";
    }
    cout<<endl;
    delete a;
}
