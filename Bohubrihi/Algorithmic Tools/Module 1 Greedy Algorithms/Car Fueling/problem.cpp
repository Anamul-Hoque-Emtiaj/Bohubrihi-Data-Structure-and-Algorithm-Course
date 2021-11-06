#include<bits/stdc++.h>
using namespace std;

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("i5.txt");
    outputFile.open("o5.txt");
    int d,m,n;
    inputFile>>d>>m>>n;
    int s[n+2];
    s[0]=0;
    for(int i=1; i<=n; i++)
    {
        inputFile>>s[i];
    }
    s[n+1] = d;
    int i=0,c=0,j;
    for(j=1;j<n+2;j++)
    {
        if(s[j]-s[i]>m)
        {
            if(j==i+1)
            {
                c=-1;
                break;
            }else
            {
                c++;
                i = j-1;
                j--;
            }
        }
    }
    outputFile<<c;
    cout<<c;
}
