/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream> 
#include <iomanip>
#include<cmath>
using namespace std;

void Newton_backward_interpolation(){
    // Number of values given
	int n = 3;
	double x[n] = { 100, 200, 300 };
		// Value to interpolate at
	double value = 275;
	// y[][] is used for difference table with y[][0] used for input
	double y[n][n];
	y[0][0] = 99.61;
	y[1][0] = 120.21;
	y[2][0] = 133.52;
// 	y[3][0] = 143.61;
  // Calculating the backward difference table
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--)
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
    }
 
    // Displaying the backward difference table
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)
            cout << "  " << y[i][j]<< "\t";
        cout << endl;
    }
 
 
    // Initializing u and sum
    double sum = y[n - 1][0];
    double u = (value - x[n - 1]) / (x[1] - x[0]);
    for (int i = 1; i < n; i++) {
        
        double temp = u;
        for (int i = 1; i < n; i++){
            temp = temp * (u + i);
        }
        // calculating factorial
	    int fact = 1;
	    for (int j = 2; j <= i; j++){
		    fact *= j;
	    }
        sum = sum + (temp * y[n - 1][i]) /fact;
    }
     cout << "\n Value at " << value << " is "<< sum << endl;
}

int main(){
    cout<<fixed<<setprecision(6);
    Newton_backward_interpolation();
    return 0;
}
