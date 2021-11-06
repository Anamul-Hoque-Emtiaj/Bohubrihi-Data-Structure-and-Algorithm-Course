#include<bits/stdc++.h>
using namespace std;

bool isSwap(string s1, string s2)
{
    //return true when s1<s2
    string s3 = s1 + s2;
    string s4 = s2 + s1;
    if(s3>=s4)
        return false;
    else
        return true;
}

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("i5.txt");
    outputFile.open("o5.txt");
    int n,i,j;
    inputFile>>n;
    string s[n], res;
    for(i=0; i<n;i++)
    {
        inputFile>>s[i];
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(isSwap(s[i],s[j]))
            {
                string t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
        }
    }
    for(i=0; i<n;i++)
        res+=s[i];
    cout<<res;
    outputFile<<res;
}
