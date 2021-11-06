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
    cout<<"1. "<<lastDigitOfSum(58623560663384)<<endl;
    cout<<"2. "<<lastDigitOfSum(36997431071850)<<endl;
    cout<<"3. "<<lastDigitOfSum(1446641485725)<<endl;
    cout<<"4. "<<lastDigitOfSum(34418254299542)<<endl;
    cout<<"5. "<<lastDigitOfSum(75400169681272)<<endl;
}
