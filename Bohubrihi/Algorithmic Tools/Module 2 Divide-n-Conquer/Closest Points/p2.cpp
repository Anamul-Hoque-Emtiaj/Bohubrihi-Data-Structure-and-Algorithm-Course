#include<bits/stdc++.h>
using namespace std;

#define ll long long int

class XY
{
public:
    double x,y;
};

bool cmpX(XY a, XY b)
{
    return a.x<b.x;
}

bool cmpY(XY a, XY b)
{
    return a.y<b.y;
}

double distance(XY a, XY b)
{
    return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
}

double naiveSys(XY arr[], ll n)
{
    double min = DBL_MAX;
    for(ll i=0; i<n-1; i++)
    {
        for(ll j=i+1; j<n; j++)
        {
            if(distance(arr[i],arr[j])<min)
                min = distance(arr[i],arr[j]);
            }
    }
    return min;
}

double stripClosest(XY strip[], int size, double d)
{
    double min = d;
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (distance(strip[i],strip[j]) < min)
                min = distance(strip[i], strip[j]);

    return min;
}

double closest_point(XY arrX[], XY arrY[], ll n)
{
    if(n<=3)
        return naiveSys(arrX, n);

    XY arrYL[n/2],arrYR[n-n/2];
    ll li=0,ri=0;
    for(ll i=0; i<n; i++)
    {
        if((arrY[i].x < arrX[n/2].x || (arrY[i].x == arrX[n/2].x && arrY[i].y < arrX[n/2].y))&&li<n/2)
        {
            arrYL[li++] = arrY[i];
        }
        else
            arrYR[ri++] = arrY[i];
    }
    double r1 = closest_point(arrX, arrYL, n/2);
    double r2 = closest_point(arrX+n/2, arrYR, n-(n/2));
    double rm = min(r1,r2);
    ll c=0;
    for(ll i=0; i<n; i++)
    {
        if(abs(arrY[i].x-arrX[n/2].x)<rm)
        {
            c++;
        }
    }
    XY arr3[c];
    c=0;
    for(ll i=0; i<n; i++)
    {
        if(abs(arrY[i].x-arrX[n/2].x)<=rm)
        {
            arr3[c++] = arrY[i];
        }
    }
    double r = stripClosest(arr3, c, rm);
    return min(r,rm);
}

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("i5.txt");
    if(inputFile.is_open())
    {
        ll n;
        inputFile>>n;
        XY arrX[n],arrY[n];
        for(ll i=0; i<n; i++)
        {
            inputFile>>arrX[i].x>>arrX[i].y;
            arrY[i].x = arrX[i].x;
            arrY[i].y = arrX[i].y;
        }

        sort(arrX,arrX+n,cmpX);
        sort(arrY,arrY+n, cmpY);
        double d = closest_point(arrX,arrY, n);
        outputFile.open("o52.txt");
        if(outputFile.is_open())
        {
            cout<<fixed<<setprecision(4)<<d<<endl;
            outputFile<<fixed<<setprecision(4)<<d<<endl;
        }
        else
            cout<<"output File cannot be openned\n";
    }
    else
        cout<<"input File cannot be openned\n";
}

