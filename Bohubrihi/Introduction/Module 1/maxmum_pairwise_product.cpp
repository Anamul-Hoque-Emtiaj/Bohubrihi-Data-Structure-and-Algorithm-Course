#include<bits/stdc++.h>

using namespace std;
#define ll long long int

int main()
{
    ll n,a[n],r,i,v,m1,m2;
    ofstream output;
    ifstream input;
    output.open("output1.txt");
    input.open("input1.txt");
    if(!input.is_open()) cout<<"File Doesnot Exist"<<endl;
    else
    {
        cout<<"File is opened"<<endl;
        input>>n;
        input>>m1;
        input>>m2;
        m1=max(m1,m2);
        m2=min(m1,m2);
        while(!input.eof())
        {
            input>>v;
            if(v>m1) m1=v;
            else if(m2<v) m2=v;
        }
        output<<m1*m2;
    }
    input.close();
    output.close();
}
