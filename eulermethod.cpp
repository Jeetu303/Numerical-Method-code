/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<iomanip>
#include<cmath>
#define f(x,y) ((pow(x,2)-pow(y,2))/(2*x*y))
using namespace std;

void EulerMethod(){
    int limit = 10, n;
    double h = 1, ini_x =1,  ini_y = 1;
    double sum =0,k1, x = ini_x, y = ini_y;
    n = limit/h;
    int count =0;
    for(int i = 0 ; i <n-1; i++){
        k1 = (pow (x, 2) - pow (y, 2)) / (2 * x * y);
        y = y + k1*h;
        x = x + h;
        count++;
        cout<< k1<<endl;
    }
    std::cout << "area= "<<y << std::endl;
    // cout<<count;
}
int main(){
    EulerMethod();
    return 0;
}


