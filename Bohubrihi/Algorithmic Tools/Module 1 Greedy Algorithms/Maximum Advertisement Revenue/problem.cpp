#include<bits/stdc++.h>
using namespace std;

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("i5.txt");
    outputFile.open("o5.txt");
    int n,i;
    inputFile>>n;
    long long int a[n],b[n];
    for(i=0;i<n;i++)
    {
        inputFile>>a[i];
    }
    for(i=0;i<n;i++)
    {
        inputFile>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    long long int result=0;
    for(i=0;i<n;i++)
    {
        result=result + (a[i]*b[i]);
    }
    cout<<result;
    outputFile<<result;
}

