#include<iostream>
using namespace std;

int LastDigitOfFibonacciNumber(long long int n)
{
    int parents=1, childs=0,temp;

    for(int t=2;t<=n;t++)
    {
        temp = parents;
        parents =(parents + childs)%10;
        childs = temp;
    }
    return parents;
}
int main()
{
    cout<<"1. "<<LastDigitOfFibonacciNumber(7100241)<<endl;
    cout<<"2. "<<LastDigitOfFibonacciNumber(2016060)<<endl;
    cout<<"3. "<<LastDigitOfFibonacciNumber(7003951)<<endl;
    cout<<"4. "<<LastDigitOfFibonacciNumber(1834789)<<endl;
    cout<<"5. "<<LastDigitOfFibonacciNumber(1496815)<<endl;
}
