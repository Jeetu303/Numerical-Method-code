/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream> 
#include <iomanip>
#include<cmath>
using namespace std;

void Newton_forward_interpolation(){
    // Number of values given
	int n = 3;
	double x[] = { 200, 300, 400 };
		// Value to interpolate at
	double value = 275;
	// y[][] is used for difference table with y[][0] used for input
	double y[n][n];
	y[0][0] = 120.21;
	y[1][0] = 133.52;
	y[2][0] = 143.61;
// 	y[3][0] = ;
	// Calculating the forward difference table
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++)
			y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
	}
	// Displaying the forward difference table
/*	for (int i = 0; i < n; i++) {
		cout <<"  "<< x[i]
			<< "\t";
		for (int j = 0; j < n - i; j++)
			cout <<"  "<< y[i][j]
				<< "\t";
		cout << endl;
	} */
	// initializing u and sum
	double sum = y[0][0];
	double s = (value - x[0]) / (x[1] - x[0]);
	for (int i = 1; i < n; i++) {
	    //calculating s 
	    double temp = s;
	    for (int j = 1; j < i; j++){
		    temp = temp * (s - j);
	    }
	    // calculating factorial
	    int fact = 1;
	    for (int j = 2; j <= i; j++){
		    fact *= j;
	    }
		sum = sum + (temp * y[0][i])/fact;
	}

	cout << "\n Value at " << value << " is "<< sum << endl;
}

int main(){
    cout<<fixed<<setprecision(6);
    Newton_forward_interpolation();
    return 0;
}



