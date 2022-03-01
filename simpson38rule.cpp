/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
void simpson38Method(){
    int n = 10, count = 0;
    double h = 1;
    double f[n] = {-1,2,23,86,215,434,767,1238,1871,2690,3719};
    // cout<< f[n];
    double sum ;
    for(int i = 0 ; i < n ; i += 3){
        sum= sum + ((h*3)/8)*(f[i]+ 3*f[i+1] + 3*f[i+2]+f[i+3]);
        count += 1;
    }
    cout<< "area is " <<sum<<"\n" ;
    // cout<< count <<"\n";
}
int main(){
    cout<<fixed<<setprecision(6);
    simpson38Method();
    return(0);
}