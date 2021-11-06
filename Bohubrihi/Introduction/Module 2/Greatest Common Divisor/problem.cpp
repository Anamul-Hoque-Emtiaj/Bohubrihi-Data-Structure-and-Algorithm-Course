#include<iostream>
using namespace std;

long long int GCD(long long int a, long long int b)
{
    if(b==0)
        return a;
    else
        return GCD(b,a%b);
}
int main()
{
    cout<<"1. "<<GCD(1004765186,939964279)<<endl;
    cout<<"2. "<<GCD(969570892,1578700845)<<endl;
    cout<<"3. "<<GCD(868603614,1308644746)<<endl;
    cout<<"4. "<<GCD(675542985,1711845572)<<endl;
    cout<<"5. "<<GCD(1894694428,670904111)<<endl;
}
