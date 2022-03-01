/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;
void
GuassElimination ()
{
  int n = 2;
  double array_Coeff[n][n + 1] = {{0.00001,2,4},{1,-1,1}}, array_out[n];
//   for (int i = 0; i < n; i++)
//     {
//       for (int j = 0; j <= n; j++)
// 	{
// 	  cin >> array_Coeff[i][j];
// 	};
//     };
  // Forward elimination 
  for (int i = 0; i < n; i++)
    {
      for (int j = i+1; j < n ; j++)
	{
	  double numerator, denominator;
	  numerator = array_Coeff[j][i];
	  denominator = array_Coeff[i][i];
	  for (int k = 0; k < n + 1; k++)
	    {
	      array_Coeff[j][k] = array_Coeff[j][k] - array_Coeff[i][k] * (numerator / denominator);

	    }
	}
    }
       // Print the array_Coeff
//   for (int i = 0; i < n; i++)
//     {
//       for (int j = 0; j <= n; j++)
// 	{
// 	  cout << array_Coeff[i][j] << "  ";
// 	};
//       cout << endl;
//     };
             // Backward substitution
  array_out[n] = array_Coeff[n][n]/array_Coeff[n-1][n-1];
  for(int i =n-1; i>=0; i--){
      array_out[i]= array_Coeff[i][n];
      for(int j = i+1; j<n+1; j++){
          array_out[i] = array_out[i]- array_Coeff[i][j]*array_out[j];
      }
    //   cout<<array_out[i]<<"  see\n";
    //   cout<<array_Coeff[i][i]<<"see \n";
      array_out[i]=array_out[i]/array_Coeff[i][i];
  }
             //   print the solution
for(int i =0; i<n; i++){
    cout<<"x"<<i<<"= "<<array_out[i]<<"\n";
}

}

int
main ()
{
    cout<<fixed<<setprecision;
  GuassElimination ();
  return 0;
}

