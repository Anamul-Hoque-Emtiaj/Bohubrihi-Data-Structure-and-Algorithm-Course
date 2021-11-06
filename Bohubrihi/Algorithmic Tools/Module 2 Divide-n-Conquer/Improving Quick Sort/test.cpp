#include<iostream>
using namespace std;

void test(int a[], int n)
{
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    test(a+3, n-3);
}
