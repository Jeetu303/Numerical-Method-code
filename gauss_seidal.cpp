/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include<iomanip>
#include<cmath>
using namespace std;

void
GaussSeidal ()
{
  int no_eq = 3, n = 15;
  double residual_max ;
  double residual_no;
  double Assume_array_x[no_eq] = { 2, 2.5, 2.3 };
  double Coeff_array[no_eq][no_eq] = { {2, 3, 4}, {5, 6, 7}, {8, 9, 10} };
  double Right_array[no_eq] = { 12, 13, 14 };
  double error_limit = 0.05;
  double residual_array[no_eq];
  while (n > 0)
    {
      for (int i = 0; i < no_eq; i++)
	{
	  double x_koi = 0;
	  for (int j = 0; j < no_eq; j++)
	    {
	        if(i != j){
	      x_koi = x_koi + Coeff_array[i][j] * Assume_array_x[j];
	      residual_no = x_koi;
	        }
	        else{
	            residual_no = residual_no+ Coeff_array[i][j] * Assume_array_x[j];
	        }
	    };
	  Assume_array_x[i] = (Right_array[i] - x_koi) / Coeff_array[i][i];
	  cout << Assume_array_x[i] << " \n";
	  residual_array[i] = abs (Right_array[i] - residual_no );
	  if( i == 0){
	      residual_max = residual_array[i];
	  }
	  else if (residual_max > residual_array[i])
	    {
	      residual_max = residual_array[i];
	    }
	   else{
	        //
	    }
	}
	
      if (residual_max < error_limit)
	{
	    cout<<residual_max<<" "<<error_limit<<"break"<<"\n";
	  break;
	  
	}
      cout << "\n";
      n--;
    }


}

int
main ()
{
  cout << fixed << setprecision(8);
  GaussSeidal ();

  return 0;
}
