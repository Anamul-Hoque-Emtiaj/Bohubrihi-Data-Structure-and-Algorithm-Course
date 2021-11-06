#include<bits/stdc++.h>

using namespace std;

class FractionalKnapsack
{
public:
    double v,w;
};

bool compare(FractionalKnapsack a, FractionalKnapsack b)
{
    return (a.v/a.w)>(b.v/b.w);
}

/*void print(long long int n, FractionalKnapsack *f)
{
    for(int i=0;i<n;i++)
        cout<<"V: "<<f[i].v<<" W: "<<f[i].w<<" v/w: "<<f[i].v/f[i].w<<endl;
}*/

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("i1.txt");
    outputFile.open("o1.txt");

    long long int n,W;
    inputFile>>n;
    inputFile>>W;
    FractionalKnapsack f[n];
    for(int i=0; i<n;i++)
    {
        inputFile>>f[i].v>>f[i].w;
    }
    //print(n,f);
    sort(f,f+n,compare);
    //cout<<"After sort"<<endl;
    //print(n,f);
    double totalValue=0;
    for(int i=0;i<n;i++)
    {
        if(W<=0)
            break;

        if(f[i].w<=W)
        {
            totalValue+=(f[i].v*1.00);
            W-=f[i].w;
        }
        else
        {
            totalValue+=((1.00*W/f[i].w)*f[i].v*1.00);
            W=0;
        }
    }

    outputFile<<fixed<<setprecision(4)<<totalValue;
    cout<<fixed<<setprecision(4)<<totalValue;
}
