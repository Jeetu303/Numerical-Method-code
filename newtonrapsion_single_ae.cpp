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
#define Singlef(x) pow(x, 2)- 3*x + 2
#define diff_Singlef(x) 2*x - 3
using namespace std;

void NewtonRapson_Single_AE(){
    double iteration = 20, ini_x = 3, new_x, error = 0.0000005;
    new_x = ini_x;
    cout<< "ini_x= "<< ini_x<<"\n";
    for(int i  = 0 ; i< iteration ; i++){
         cout<<"iteration = "<<i<<" new_x = "<< new_x<< "   Singlef(nex_x)= "<< Singlef(new_x)<< "  diff_Singlef(nex_x)= "<<diff_Singlef(new_x)<<"\n";
        //  cout<<new_x<<endl<<Singlef(new_x)<<"  "<<diff_Singlef(new_x)<<"  "<<Singlef(new_x)/diff_Singlef(new_x)<<endl;
         double a =Singlef(new_x);
         double b = diff_Singlef(new_x);
        //  cout<< a/b<< endl;
         new_x = new_x - (a/b);
         cout<<new_x<<endl;
         if(abs(Singlef(new_x) < error)){
             break ;
         }
    }
}



int main()
{
    cout<<setprecision(6)<<fixed;
    NewtonRapson_Single_AE();
    return 0;
}

