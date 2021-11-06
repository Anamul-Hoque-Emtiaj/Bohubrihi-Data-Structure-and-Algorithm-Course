#include<iostream>
using namespace std;

int lastDigitOfSquareSum(long long int n)
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
            sum=(sum+(parents*parents))%10;
        }
    }

    parents=1, childs=0;
    for(t=2;t<=n%pisanoPeriod;t++)
    {
        temp = parents;
        parents =(parents + childs)%10;
        childs = temp;
        res = (res + (parents*parents))%10;
    }
    res = (res + (((n/pisanoPeriod)%10)*sum)%10)%10;
    return res;
}
int main()
{
    cout<<"1. "<<lastDigitOfSquareSum(65541020393978)<<endl;
    cout<<"2. "<<lastDigitOfSquareSum(9036544139724)<<endl;
    cout<<"3. "<<lastDigitOfSquareSum(61808802823427)<<endl;
    cout<<"4. "<<lastDigitOfSquareSum(68966017103619)<<endl;
    cout<<"5. "<<lastDigitOfSquareSum(45276060008167)<<endl;
}

