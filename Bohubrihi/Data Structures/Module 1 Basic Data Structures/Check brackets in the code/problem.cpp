#include<bits/stdc++.h>
using namespace std;

#define ll long long int

class node
{
public:
    ll key;
    node *prev, *next;
};

class myStack
{
public:
    node *head = NULL, *tail = NULL;
    ll s=0;

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
            tail = tail->prev;
            tail->next = NULL;
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
    myStack *a = new myStack();
    ifstream inputFile;
    inputFile.open("i5.txt");
    string s;
    inputFile>>s;
    ll c = 0,i;
    for(i=0; i<s.size(); i++)
    {
        if(s[i]=='(')
        {
            a->push(1);
        }
        else if(s[i]=='{')
        {
            a->push(2);
        }
        else if(s[i]=='[')
        {
            a->push(3);
        }
        else if(s[i]==')')
        {
            ll t = a->back();
            if(t==1)
                a->pop();
            else
            {
                c=i+1;
                break;
            }
        }
        else if(s[i]=='}')
        {
            ll t = a->back();
            if(t==2)
                a->pop();
            else
            {
                c=i+1;
                break;
            }
        }
        else if(s[i]==']')
        {
            ll t = a->back();
            if(t==3)
                a->pop();
            else
            {
                c=i+1;
                break;
            }
        }
    }
    if(c==0)
    {
        if(a->empty())
        {
            cout<<"Success"<<endl;
        }
        else
            cout<<i<<endl;
    }
    else
        cout<<c<<endl;
    delete a;
}
