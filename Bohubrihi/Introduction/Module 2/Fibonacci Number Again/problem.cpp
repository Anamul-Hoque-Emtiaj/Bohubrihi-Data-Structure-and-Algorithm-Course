#include<iostream>
using namespace std;

long long int Pisano(long long int m)
{
    long long int parents=1, childs=0,temp,res,t;

    for(t=2;t<=m*m;t++)
    {
        temp = parents;
        parents =(parents + childs)%m;
        childs = temp;
        if(parents==1&&childs==0)
        {
            res = t-1;
            break;
        }
    }
    return res;
}

long long int FibonacciNumber(long long int n, long long int m)
{
    long long int pisanoPeriod = Pisano(m);
    n = n% pisanoPeriod;

    long long int parents=1, childs=0,temp,t;
    for(t=2;t<=n;t++)
    {
        temp = parents;
        parents =(parents + childs)%m;
        childs = temp;
    }
    return parents;
}
int main()
{
    cout<<"1. "<<FibonacciNumber(22220501673129,737)<<endl;
    cout<<"2. "<<FibonacciNumber(64710033115016,310)<<endl;
    cout<<"3. "<<FibonacciNumber(83246275944499,97)<<endl;
    cout<<"4. "<<FibonacciNumber(17345839960879,555)<<endl;
    cout<<"5. "<<FibonacciNumber(81729821751752,361)<<endl;
}

