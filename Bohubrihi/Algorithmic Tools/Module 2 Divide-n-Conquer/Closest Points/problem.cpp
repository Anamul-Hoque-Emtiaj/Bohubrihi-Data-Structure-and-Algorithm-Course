#include<bits/stdc++.h>
using namespace std;

#define ll long long int

struct Point
{
	double x, y;
};

int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a,  *p2 = (Point *)b;
    return (p1->x != p2->x) ? (p1->x - p2->x) : (p1->y - p2->y);
}

int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->y != p2->y) ? (p1->y - p2->y) : (p1->x - p2->x);
}

double dist(Point p1, Point p2)
{
	return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
				(p1.y - p2.y)*(p1.y - p2.y)
			);
}

double bruteForce(Point P[], ll n)
{
	double min = DBL_MAX;
	for (ll i = 0; i < n; ++i)
		for (ll j = i+1; j < n; ++j)
			if (dist(P[i], P[j]) < min)
				min = dist(P[i], P[j]);
	return min;
}

double min(double x, double y)
{
	return (x < y)? x : y;
}

double stripClosest(Point strip[], ll size, double d)
{
	double min = d;
	for (ll i = 0; i < size; ++i)
		for (ll j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
			if (dist(strip[i],strip[j]) < min)
				min = dist(strip[i], strip[j]);

	return min;
}

double closestUtil(Point Px[], Point Py[], ll n)
{
	if (n <= 3)
        return bruteForce(Px, n);

	ll mid = n/2;
	Point midPoint = Px[mid];

	Point Pyl[mid];
	Point Pyr[n-mid];
	ll li = 0, ri = 0;
	for (ll i = 0; i < n; i++)
	{
	if ((Py[i].x < midPoint.x || (Py[i].x == midPoint.x && Py[i].y < midPoint.y)) && li<mid)
		Pyl[li++] = Py[i];
	else
		Pyr[ri++] = Py[i];
	}

	double dl = closestUtil(Px, Pyl, mid);
	double dr = closestUtil(Px + mid, Pyr, n-mid);

	double d = min(dl, dr);

	Point strip[n];
	ll j = 0;
	for (ll i = 0; i < n; i++)
		if (abs(Py[i].x - midPoint.x) < d)
			strip[j] = Py[i], j++;

	return stripClosest(strip, j, d);
}

double closest(Point P[], ll n)
{
	Point Px[n];
	Point Py[n];
	for (ll i = 0; i < n; i++)
	{
		Px[i] = P[i];
		Py[i] = P[i];
	}

	qsort(Px, n, sizeof(Point), compareX);
    qsort(Py, n, sizeof(Point), compareY);
	return closestUtil(Px, Py, n);
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
        Point arr[n];
        for(ll i=0; i<n; i++)
        {
            inputFile>>arr[i].x>>arr[i].y;
        }
        double d = closest(arr, n);
        //double d = bruteForce(arr, n);
        outputFile.open("o21.txt");
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
