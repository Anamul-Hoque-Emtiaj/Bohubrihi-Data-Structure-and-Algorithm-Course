#include<iostream>
using namespace std;

int lastDigitOfSum(long long int n)
{
    long long int parents=1, childs=0,temp,pisanoPeriod,t,sum=1,res=1;

    for(t=2;t<=100;t++)
    {
        temp = parents;
        parents =(parents + childs)%10;
        childs = temp;
        if(parents==1&&childs==0)
        {
            pisanoPeriod = t-1;
            break;
        }else
        {
            sum=(sum+parents)%10;
        }
    }

    parents=1, childs=0;
    for(t=2;t<=n%pisanoPeriod;t++)
    {
        temp = parents;
        parents =(parents + childs)%10;
        childs = temp;
        res = (res + parents)%10;
    }
    res = (res + (((n/pisanoPeriod)%10)*sum)%10)%10;
    return res;
}
int main()
{
    cout<<"1. "<<(lastDigitOfSum(43545805830929)-lastDigitOfSum(32921020667365-1))%10<<endl;
    cout<<"2. "<<(lastDigitOfSum(47250136067626)-lastDigitOfSum(44713561530585-1))%10<<endl;
    cout<<"3. "<<(lastDigitOfSum(79764368961087)-lastDigitOfSum(37214113337197-1))%10<<endl;
    cout<<"4. "<<(lastDigitOfSum(44366658788379)-lastDigitOfSum(30205001379829-1))%10<<endl;
    cout<<"5. "<<(lastDigitOfSum(98085652783069)-lastDigitOfSum(84209819929853-1))%10<<endl;
}

