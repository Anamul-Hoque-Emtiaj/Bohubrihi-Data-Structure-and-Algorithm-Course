#include<bits/stdc++.h>
using namespace std;

#define ll long long int

struct node
{
    ll key;
    node *parent, *leftChild, *rightChild;
};

struct val
{
    ll k,l,r;
};

node* find(node *r, ll x)
{
    if(r->key==x)
        return r;
    else if(r->key > x)
    {
        if(r->leftChild==NULL)
            return r;
        return find(r->leftChild,x);
    }
    else
    {
        if(r->rightChild==NULL)
            return r;
        return find(r->rightChild, x);
    }
}

node* leftDescendant(node* n)
{
    if(n->leftChild==NULL)
        return n;
    return leftDescendant(n->leftChild);
}

int main()
{
    ifstream inputFile;
    inputFile.open("i5.txt");
    ll n;
    inputFile>>n;
    node **arr = new node*[n];
    for(ll i=0; i<n; i++)
    {
        arr[i] = new node();
        arr[i]->key = NULL;
        arr[i]->parent = NULL;
        arr[i]->leftChild = NULL;
        arr[i]->rightChild = NULL;
    }
    val a[n];
    for(ll i=0; i<n; i++)
    {
        inputFile>>a[i].k>>a[i].l>>a[i].r;
    }
    bool f = true;
    arr[0]->key = a[0].k;
    for(ll i=0; i<n; i++)
    {
        if(a[i].l!=-1)
        {
            node *lc = find(arr[0],a[a[i].l].k);
            if(arr[i]->key==lc->key)
            {
                if(arr[i]->key > a[a[i].l].k)
                {
                    arr[a[i].l]->parent = arr[i];
                    arr[a[i].l]->key = a[a[i].l].k;
                    arr[i]->leftChild = arr[a[i].l];
                }
                else
                {
                    f = false;
                    break;
                }
            }
            else
            {
                lc = lc->rightChild;
                while(lc->leftChild!=NULL)
                {
                    lc = find(lc,a[a[i].l].k);
                }
                if(lc->key > a[a[i].l].k)
                {
                    arr[a[i].l]->parent = lc;
                    arr[a[i].l]->key = a[a[i].l].k;
                    lc->leftChild = arr[a[i].l];
                }
                else
                {
                    f = false;
                    break;
                }
            }
        }
        if(a[i].r!=-1)
        {
            node *rc = find(arr[0],a[a[i].r].k);
            if(arr[i]->key==rc->key)
            {
                if(arr[i]->key <= a[a[i].r].k)
                {
                    if(arr[i]->rightChild==NULL)
                    {
                        arr[a[i].r]->parent = arr[i];
                        arr[a[i].r]->key = a[a[i].r].k;
                        arr[i]->rightChild = arr[a[i].r];
                    }
                    else
                    {
                        f = false;
                        break;
                    }
                }
                else
                {
                    f = false;
                    break;
                }
            }
            else
            {
                rc = rc->rightChild;
                while(rc->rightChild!=NULL)
                    rc = find(rc,a[a[i].r].k);
                if(rc->key <= a[a[i].r].k)
                {
                    arr[a[i].r]->parent = rc;
                    arr[a[i].r]->key = a[a[i].r].k;
                    rc->rightChild = arr[a[i].r];
                }
                else
                {
                    f = false;
                    break;
                }
            }
        }
    }
    if(f)
        cout<<"CORRECT\n";
    else
        cout<<"INCORRECT\n";
}


