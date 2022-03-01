/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include<iostream>
#include <iomanip>

#define S 50

using namespace std;
void Linear_regression(){
    int n = 4;
     double x[S] = {1,2,3,4}, y[S]={10,11,12,13}, sumX=0, sumX2=0, sumY=0, sumXY=0, a, b;
     /* Calculating Required Sum */
 for(int i=1;i<=n;i++)
 {
  sumX = sumX + x[i];
  sumX2 = sumX2 + x[i]*x[i];
  sumY = sumY + y[i];
  sumXY = sumXY + x[i]*y[i];
 }
 /* Calculating a and b */
 b = ((n+ 1)*sumXY-sumX*sumY)/((n+1)*sumX2-sumX*sumX);
 a = (sumY - b*sumX)/(n+ 1);

 /* Displaying value of a and b */
 cout<<"Calculated value of a is "<< a << "and b is "<< b << endl;
 cout<<"Equation of best fit is: y = "<< a <<" + "<< b<<"x";

}
int main()
{
 cout<<fixed<<setprecision;
  Linear_regression();


 
 return(0);
}


