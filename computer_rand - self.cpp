/* C++ program for estimation of Pi using Monte
Carlo Simulation */
#include <bits/stdc++.h>
#include<iostream>
// Defines precision for x and y values. More the
// interval, more the number of significant digits
#define N 100
using namespace std;



int main()
{
	int i;
	long n=N*N;
	double rand_x, rand_y, origin_dist, pi;
	long x[n],y[n],a1,a2,c1,c2;
	x[0]=1;
	y[0]=1;
	int circle_points = 0, square_points = 0;
	//srand(time(NULL));
a1=3;
a2=5;
c1=7;
c2=11;
	// Total Random numbers generated = possible x
	// values * possible y values
	for (i = 1; i < n; i++) {
            x[i]=(a1*x[i-1]+c1)%(N+1);

            y[i]=(a2*y[i-1]+c2)%(N+1);


		// Randomly generated x and y values
		rand_x = double(x[i])/N;
		rand_y = double(y[i])/N;

		// Distance between (x, y) from the origin
		origin_dist = rand_x * rand_x + rand_y * rand_y;

		// Checking if (x, y) lies inside the define
		// circle with R=1
		if (origin_dist <= 1)
			circle_points++;

		// Total number of points generated
		square_points++;

		// estimated pi after this iteration
		pi = double(4 * circle_points) / square_points;

		// For visual understanding (Optional)
		///cout << rand_x << " " << rand_y << " " << circle_points
			///<< " " << square_points << " - " << pi << endl << endl;


	}

	// Final Estimated Value
	cout << "\nFinal Estimation of Pi = " << pi;

	return 0;
}

