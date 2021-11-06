#include<bits/stdc++.h>
using namespace std;

#define ll long long int

struct index
{
    ll in,ti;
};

void swap(index *i1, index *i2)
{
    index t;
    t.in = i1->in;
    t.ti = i1->ti;

    i1->in = i2->in;
    i1->ti = i2->ti;

    i2->in = t.in;
    i2->ti = t.ti;
}

class myHeap
{
public:
    ll size;
    index **arr;
    myHeap(ll s)
    {
        size = 0;
        arr = new index*[s];
    }
    myHeap(const myHeap &m)
    {
        size = m.size;
        delete []arr;
        arr = new index*[m.size];
        for(ll i=0; i<m.size; i++)
        {
            arr[i] = new index();
            arr[i]->in = m.arr[i]->in;
            arr[i]->ti = m.arr[i]->ti;
        }
    }
    myHeap &operator=(myHeap &m)
    {
        size = m.size;
        delete []arr;
        arr = new index*[m.size];
        for(ll i=0; i<m.size; i++)
        {
            arr[i] = new index();
            arr[i]->in = m.arr[i]->in;
            arr[i]->ti = m.arr[i]->ti;
        }
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
            if(arr[p]->ti > arr[i]->ti || (arr[p]->ti == arr[i]->ti && arr[p]->in > arr[i]->in))
            {
                swap(arr[i],arr[p]);
                i = p;
            }
            else
                break;
        }
    }
    void siftDown(ll i)
    {
        while(2*i+1<size)
        {
            ll lc = leftChild(i);
            if(2*i+2==size)
            {
                if(arr[lc]->ti < arr[i]->ti || (arr[lc]->ti==arr[i]->ti && arr[lc]->in < arr[i]->in))
                {
                    swap(arr[i],arr[lc]);
                    break;
                }
                else
                    break;
            }
            ll rc = rightChild(i);
            if((arr[lc]->ti < arr[rc]->ti || (arr[lc]->ti == arr[rc]->ti && arr[lc]->in < arr[rc]->in) ) && (arr[i]->ti > arr[lc]->ti || (arr[i]->ti == arr[lc]->ti && arr[i]->in > arr[lc]->in)) )
            {
                swap(arr[i],arr[lc]);
                i = lc;
            }
            else if((arr[rc]->ti < arr[lc]->ti || (arr[rc]->ti == arr[lc]->ti && arr[rc]->in < arr[lc]->in) ) && (arr[i]->ti > arr[rc]->ti || (arr[i]->ti == arr[rc]->ti && arr[i]->in > arr[rc]->in)))
            {
                swap(arr[i],arr[rc]);
                i = rc;
            }
            else
                break;
        }
    }
    index extractMin()
    {
        index t;
        t.in = arr[0]->in;
        t.ti = arr[0]->ti;
        arr[0]->in = arr[size-1]->in;
        arr[0]->ti = arr[size-1]->ti;
        size--;
        siftDown(0);
        //cout<<"ex "<<t.in<<" "<<t.ti<<endl;
        return t;
    }
    void insert(ll i, ll v)
    {
        //cout<<"in "<<i<<" "<<v<<endl;
        arr[size] = new index();
        arr[size]->ti = v;
        arr[size]->in = i;
        size++;
        siftUp(size-1);
    }
};


int main()
{
    ifstream inputFile;
    inputFile.open("i4.txt");
    ofstream outputFile;
    outputFile.open("o4.txt");
    ll n,i,m;
    inputFile>>n>>m;
    ll *a = new ll[m];
    for(i=0; i<m; i++)
        inputFile>>a[i];

    myHeap *mi = new myHeap(n);
    index *res = new index[m];
    for(i=0; i<n; i++)
    {
        mi->insert(i, a[i]);
        res[i].ti = 0;
        res[i].in = i;
    }
    for(i=n; i<m; i++)
    {
        index t = mi->extractMin();
        res[i].in = t.in;
        res[i].ti = t.ti;

        ll p = t.ti + a[i];
        mi->insert(t.in, p);
    }
    for(i=0; i<m; i++)
    {
        cout<<res[i].in<<" "<<res[i].ti<<endl;
        outputFile<<res[i].in<<" "<<res[i].ti<<" ";
    }
}


