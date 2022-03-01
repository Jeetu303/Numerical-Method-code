/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;
void SimpsonOneThird(){
    int n = 6;
   double h = 1;
   double f[n+1]={-2,-1,2,7,14,23,34};
   double sum ;
   for(int i = 0; i< n ;i+= 2){
       sum= sum + (h/3)*(f[i]+ 4*f[i+1] + f[i+2]);
   }
   std::cout <<"area is "<< sum<< std::endl;
}
int main()
{
   SimpsonOneThird();
    return 0;
}
