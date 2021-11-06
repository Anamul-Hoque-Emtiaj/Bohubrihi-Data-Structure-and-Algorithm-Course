#include<iostream>
using namespace std;

long long int Fibonacci(int n)
{
    long long int a[n+1];
    a[0]=0;
    a[1]=1;
    for(int i=2;i<=n;i++)
    {
        a[i] = a[i-1] + a[i-2];
    }
    return a[n];
}
int main()
{
    cout<<"1. "<<Fibonacci(22)<<endl;
    cout<<"2. "<<Fibonacci(10)<<endl;
    cout<<"3. "<<Fibonacci(20)<<endl;
    cout<<"4. "<<Fibonacci(8)<<endl;
    cout<<"5. "<<Fibonacci(44)<<endl;
}
