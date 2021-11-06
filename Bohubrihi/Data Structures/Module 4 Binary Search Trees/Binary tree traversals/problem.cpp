#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ifstream inputFile;
ofstream outputFile;

struct node
{
    ll key;
    node *parent, *leftChild, *rightChild;
};

void inOrder(node *root)
{
    if(root!=NULL)
    {
        inOrder(root->leftChild);
        cout<<root->key<<" ";
        outputFile<<root->key<<" ";
        inOrder(root->rightChild);
    }
}

void preOrder(node *root)
{
    if(root!=NULL)
    {
        cout<<root->key<<" ";
        outputFile<<root->key<<" ";
        preOrder(root->leftChild);
        preOrder(root->rightChild);
    }
}

void postOrder(node *root)
{
    if(root!=NULL)
    {
        postOrder(root->leftChild);
        postOrder(root->rightChild);
        cout<<root->key<<" ";
        outputFile<<root->key<<" ";
    }
}

int main()
{
    inputFile.open("i5.txt");
    outputFile.open("o5.txt");
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
    ll k,l,r;
    for(ll i=0; i<n; i++)
    {
        inputFile>>k>>l>>r;
        arr[i]->key = k;
        if(l!=-1)
        {
            arr[i]->leftChild = arr[l];
            arr[l]->parent = arr[i];
        }
        if(r!=-1)
        {
            arr[i]->rightChild = arr[r];
            arr[r]->parent = arr[i];
        }
    }
    inOrder(arr[0]);
    cout<<endl;
    outputFile<<",";
    preOrder(arr[0]);
    cout<<endl;
    outputFile<<",";
    postOrder(arr[0]);
    cout<<endl;
}
