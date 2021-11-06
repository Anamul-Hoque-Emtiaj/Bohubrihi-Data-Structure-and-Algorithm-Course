#include<bits/stdc++.h>
using namespace std;

#define ll long long int

class node
{
public:
    ll key;
    node *prev, *next;
};

class DoubleLinkList
{
public:
    node *head = NULL, *tail = NULL;
    ll s=0;

    ll size()
    {
        return s;
    }
    ll front()
    {
        if(s>0)
            return head->key;
        else
            return NULL;
    }
    ll back()
    {
        if(s>0)
            return tail->key;
        else
            return NULL;
    }
    bool empty()
    {
        if(s==0)
            return true;
        else
            return false;
    }
    void push_back(ll k)
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
    void pop_back()
    {
        if(s==1)
        {
            s = 0;
            head = NULL;
            tail = NULL;
        }
        else if(s>1)
        {
            tail = tail->prev;
            tail->next = NULL;
            s--;
        }
        else
        {
            cout<<"Empty List\n";
        }
    }
    void push_front(ll k)
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
            n->next = head;
            n->prev = NULL;
            head->prev = n;
            head = n;
            s++;
        }
    }
    void pop_front()
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
    ll find(ll k)
    {
        ll i = s,r=0;
        node *c = head;
        while(i--)
        {
            if(c->key==k)
            {
                r=1;
                break;
            }
            else
            {
                c = c->next;
            }
        }
        return r;
    }
    void erase(ll k)
    {
        ll i = s,f=0;
        node *c = head,*r;
        while(i--)
        {
            if(c->key==k)
            {
                f=1;
                r=c;
                break;
            }
            else
            {
                c = c->next;
            }
        }
        if(f==1)
        {
            r->next->prev = r->prev;
            r->prev->next = r->next;
            s--;
        }
        else
            cout<<"Not found\n";
    }
    void addAfter(node *n, ll k)
    {
        node *t = new node();
        t->key = k;
        t->prev = n;
        t->next = n->next;
        n->next->prev = t;
        n->next = t;
    }
    void addBefore(node *n, ll k)
    {
        node *t = new node();
        t->key = k;
        t->next = n;
        t->prev = n->prev;
        n->prev->next = t;
        n->prev = t;
    }
    void print()
    {
        node *c = head;
        cout<<"Size: "<<s<<endl;
        if(tail!=NULL)
            cout<<"front: "<<head->key<<" back: "<<tail->key<<endl;
        while(tail!=NULL)
        {
            cout<<c->key<<" ";
            if(c->key==tail->key)
                break;
            c = c->next;
        }
        cout<<endl;
    }
};

int main()
{
    DoubleLinkList *a = new DoubleLinkList();
    a->print();
    a->push_back(30);
    a->push_back(40);
    a->push_back(50);
    a->print();
    a->push_front(20);
    a->push_front(10);
    a->print();
    a->pop_back();
    a->pop_front();
    a->print();
    cout<<a->find(30)<<" "<<a->find(10)<<endl;
    a->erase(30);
    a->print();
    cout<<a->find(30)<<" "<<a->size()<<endl;
    delete a;
}
