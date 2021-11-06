#include<iostream>
using namespace std;

int moneyChange(int n)
{
    return ((n/10)+((n%10)/5)+((n%10)%5));
}

int main()
{
    cout<<"1. "<<moneyChange(439)<<endl;
    cout<<"2. "<<moneyChange(835)<<endl;
    cout<<"3. "<<moneyChange(787)<<endl;
    cout<<"4. "<<moneyChange(204)<<endl;
    cout<<"5. "<<moneyChange(895)<<endl;
}
