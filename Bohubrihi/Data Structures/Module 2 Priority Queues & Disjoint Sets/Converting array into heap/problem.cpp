#include<bits/stdc++.h>
using namespace std;

#define ll long long int

struct index
{
    ll i1,i2;
};
ll c=0;
index r[400000];

class myHeap
{
public:
    ll size, *arr;
    myHeap(ll s)
    {
        size = 0;
        arr = new ll[s];
    }
    ~myHeap()
    {
        delete []arr;
    }
    ll parent(ll i)
    {
        return (i-1)/2;
    }
    ll leftChild(ll i)
    {
        return 2*i+1;
    }
    ll rightChild(ll i)
    {
        return 2*i+2;
    }
    void siftUp(ll i)
    {
        while(i>0)
        {
            ll p = parent(i);
            if(arr[p]<=arr[i])
                break;
            else
            {
                ll t = arr[i];
                arr[i] = arr[p];
                arr[p] = t;
                i = p;
            }
        }
    }
    void siftDown(ll i)
    {
        while(2*i+1<size)
        {
            ll lc = leftChild(i);
            if(2*i+2==size)
            {
                if(arr[lc]<arr[i])
                {
                    ll t = arr[lc];
                    arr[lc] = arr[i];
                    arr[i] = t;
                    r[c].i1 = i;
                    r[c].i2 = lc;
                    c++;
                    break;
                }
                else
                    break;
            }
            ll rc = rightChild(i);
            if(arr[i]<=arr[lc] && arr[i]<=arr[rc])
                break;
            else
            {
                if(arr[lc]<=arr[rc])
                {
                    ll t = arr[lc];
                    arr[lc] = arr[i];
                    arr[i] = t;
                    i = lc;
                }
                else
                {
                    ll t = arr[rc];
                    arr[rc] = arr[i];
                    arr[i] = t;
                    i = rc;
                }
            }
        }
    }
    ll getMin()
    {
        return arr[0];
    }
    ll extractMin()
    {
        ll t = arr[0];
        arr[0] = arr[size-1];
        size--;
        siftDown(0);
        return t;
    }
    void insert(ll p)
    {
        arr[size++] = p;
        siftUp(size-1);
    }
    void changePriority(ll i, ll p)
    {
        ll t = arr[i];
        arr[i] = p;
        if(p>t)
        {
            siftDown(i);
        }
        else
            siftUp(i);
    }
    void remove(ll i)
    {
        changePriority(i,-1);
        extractMin();
    }
    void customSiftDown(ll i)
    {
        while(2*i+1<size)
        {
            ll lc = leftChild(i);
            if(2*i+2==size)
            {
                if(arr[lc]<arr[i])
                {
                    ll t = arr[lc];
                    arr[lc] = arr[i];
                    arr[i] = t;
                    r[c].i1 = i;
                    r[c].i2 = lc;
                    c++;
                    break;
                }
                else
                    break;
            }

            ll rc = rightChild(i);
            if(arr[i]<=arr[lc] && arr[i]<=arr[rc])
                break;
            else
            {
                if(arr[lc]<=arr[rc])
                {
                    ll t = arr[lc];
                    arr[lc] = arr[i];
                    arr[i] = t;
                    r[c].i1 = i;
                    r[c].i2 = lc;
                    c++;
                    i = lc;
                }
                else
                {
                    ll t = arr[rc];
                    arr[rc] = arr[i];
                    arr[i] = t;
                    r[c].i1 = i;
                    r[c].i2 = rc;
                    c++;
                    i = rc;
                }
            }
        }
    }
    void buildHeap(ll a[], ll s)
    {
        for(ll i=0; i<s; i++)
            arr[i] = a[i];
        size = s;
        for(ll i=(s/2)-1; i>=0; i--)
        {
            customSiftDown(i);
        }
    }
    void heapSort(ll a[], ll s)
    {
        buildHeap(a,s);
        for(ll i=0; i<s; i++)
        {
            ll t = extractMin();
            a[i] = t;
        }
    }
};


int main()
{
    ifstream inputFile;
    inputFile.open("i5.txt");
    ofstream outputFile;
    outputFile.open("o5.txt");
    ll n,i;
    inputFile>>n;
    ll *a = new ll[n];
    for(i=0; i<n; i++)
        inputFile>>a[i];
    /*for(i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;*/
    myHeap *m = new myHeap(n);
    //m->heapSort(a,n);
    m->buildHeap(a,n);
    /*for(i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;*/
    cout<<c<<endl;
    outputFile<<c<<" ";
    for(i=0; i<c; i++)
    {
        cout<<r[i].i1<<" "<<r[i].i2<<endl;
        outputFile<<r[i].i1<<" "<<r[i].i2<<" ";
    }
}

