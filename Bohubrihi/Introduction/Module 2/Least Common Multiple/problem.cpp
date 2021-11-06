#include<iostream>
using namespace std;

long long int GCD(long long int a, long long int b)
{
    if(b==0)
        return a;
    else
        return GCD(b,a%b);
}

long long int LCM(long long int a, long long int b)
{
    return ((a/GCD(a,b))*b);
}
int main()
{
    cout<<"1. "<<LCM(4226686,7136084)<<endl;
    cout<<"2. "<<LCM(1923169,2043574)<<endl;
    cout<<"3. "<<LCM(9771142,502320)<<endl;
    cout<<"4. "<<LCM(2294111,3471255)<<endl;
    cout<<"5. "<<LCM(4687247,9139875)<<endl;
}
