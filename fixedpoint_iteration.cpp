/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<iomanip>
#include <cstdlib>
#include<cmath>
#define f(x) pow(x, 2)-3*x+2
#define g(x) (2+(pow(x,2)))/3
// for convergence modeof(diff of g(x))< 1
using namespace std;

int fixedpointmethod(){
    int max_iteration = 20, indicator=0;
   double ini_guess = 0, tole_error = 0.000005, x_in ;
   
    // cin>>ini_guess;
    // cin>>tole_error;
    // cin>>max_iteration;
     cout<<"ini_guess= "<<ini_guess<<"\n";
    cout<<"tole_error= "<<tole_error<<"\n";
    cout<<"max_iteration= "<<max_iteration<<"\n";
    for(int i = 0; i < max_iteration;  i++){
        if( i ==0){
            x_in = ini_guess;
        }
        cout<<"iteration-"<<i<<" x="<<x_in<<" f(x)="<<f(x_in)<<"\n" ;
        if( abs(f(x_in))< tole_error){
            cout<<"Root is "<< x_in;
            indicator = 1;
            break;
        }
         x_in = g(x_in);
        
        // if(indicator == 0 && i == max_iteration-1){
        //     cout<<"Not convergent.";
        // }
        
    }
    return(0);
}
 int main(){
     cout<<setprecision(6)<<fixed;
    fixedpointmethod();
    return 0;
 }
 
 



