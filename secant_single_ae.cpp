/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>
// #define f(x)  pow(x,2)-2*x+1
// #define g(x)
// #define diff_f(x) 2*x-2
#define Singlef(x) pow(x, 2)+ 4*x + 4
#define diff_Singlef(x) 2*x + 4
using namespace std;

void Secant_Single_AE(){
    double iteration = 20, ini_x = 2, new_x, error = 0.00005, delta = 0.05;
    double x_i1 = ini_x - delta;
    new_x = ini_x;
    cout<<"ini_x= "<<ini_x<<" error= "<<error<<" delta= "<<delta<<"x_i1"<<x_i1<<"\n";
    for(int i  = 0 ; i < iteration ; i++){
        cout<<"iteration= "<<i<<" new_x= "<< new_x<<" Singlef(new_x)= "<<Singlef(new_x)<<"\n";
        if(abs(Singlef(new_x)< error)){
            break;
        }
        double a = Singlef(new_x);
        double b = Singlef(x_i1);
        double preserve = new_x;
        new_x = new_x - ((a*(new_x - x_i1))/(a-b)) ;
        x_i1 = preserve;
        
    }
}
int main()
{
    cout<<setprecision(6)<<fixed;
    
    Secant_Single_AE();
    return 0;
}