/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<iostream>
#include <cmath>
#include<iomanip>
#define f(x,y) ((pow(x,2)-pow(y,2))/(2*x*y))
using namespace std;

void
RK4 ()
{
  double omega1 = 1 / 6, omega2 = 2 / 6, omega3 = 2 / 6, omega4 = 1 / 6, h = 1, ini_x = 1, ini_y = 1;
  double k1, k2, k3, k4;
  int limit = 10, n = limit / h;
  int count =0;
  double sum = 0, x = ini_x, y = ini_y;
  for (int i = 1; i < n ; i++)
    {
    //   k1 = f (x, y);
    //   k2 = f (x+h/2, y+(h / 2)*k1);
    //   k3 = f (x + h / 2, y + (h / 2) * k2);
    //   k4 = f (x + h, y + h * k3);
    //   cout << "k1= " << k1 << " k2= " << k2 << " k3= " << k3 << " k4= " << k4<< endl;
   /* double random1 = pow(x,2);
    double random12 = pow(y,2);
    double random123 = 2*x*y ;
    cout<<"k1  "<<"random1= "<<random1<<" random12= "<<random12<<" random123= "<<random123<<endl;
    k1 = (random1 - random12)/random123;
    random1 = pow(x+h/2,2);
    random12 = pow(y+ k1*(h/2), 2);
    random123 = 2*(x+h/2)*(y+k1*(h/2));
     cout<<"k2  "<<"random1= "<<random1<<" random12= "<<random12<<" random123= "<<random123<<endl;
    k2 = (random1 - random12)/random123;
    random1 = pow(x+h/2,2);
    random12 = pow(y+k2*(h/2),2);
    random123 = 2*(x+h/2)*(y+k2*(h/2));
    cout<<"k3  "<<"random1= "<<random1<<" random12= "<<random12<<" random123= "<<random123<<endl;
    k3 = (random1 - random12)/random123;
    random1 = pow(x+h,2);
    random12 = pow(y+k3*(h),2);
    random123 = 2*(x+h)*(y+k3*(h));
    cout<<"k4  "<<"random1= "<<random1<<" random12= "<<random12<<" random123= "<<random123<<endl;
    k4 = (random1 - random12)/random123; */
         k1 = (pow (x, 2) - pow (y, 2)) / (2 * x * y);
         k2 = (pow (x + h / 2, 2) - pow (y + (h*k1)/ 2, 2)) / (2 * (x + h / 2) * (y + (h*k1)/ 2));
         k3 = (pow (x + h / 2, 2) - pow (y + (h*k2)/ 2, 2)) / (2 * (x + h / 2) * (y + (h*k2)/ 2));
         k4 = (pow (x + h, 2) - pow (y + (h*k3), 2)) / (2 * (x + h) * (y + (h*k3)));
         cout <<"k1= "<<k1<<" k2= "<<k2<<" k3= "<<k3<<" k4= "<<k4<<endl;
        sum = sum + (h / 6) *(k1 + k2 * 2 + k3 * 2 + k4);
        // cout<<sum<<endl;
      x = x + h;
      y = sum;
      count++;
    }
  std::cout << "Area = " << sum << std::endl;
//   cout<<count;
}

int
main ()
{
//   cout << fixed << setprecision (8);
  RK4 ();
  return 0;
}


