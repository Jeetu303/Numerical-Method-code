/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include<iostream>
#include<conio.h>

using namespace std;

void Lagrange_interpolation(){
    int i,j,n=3;
    double x[n]={100,200,300}, y[n] ={99.61,120.21,133.52}, xp=125, yp=0, p;
	  /* Implementing Lagrange Interpolation */
	 for(i=0;i<n;i++)
	 {
		  p=1;
		  for(j=0;j<n;j++)
		  {
			   if(i!=j)
			   {
			    	p = p* (xp - x[j])/(x[i] - x[j]);
			   }
		  }
		  yp = yp + p * y[i];
	 }
	 cout<< endl<<"Interpolated value at "<< xp<< " is "<< yp;
}
int main()
{
	Lagrange_interpolation();

	 return 0;
}



