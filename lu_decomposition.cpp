/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<iostream>
#include <iomanip>
#include<cmath>
using namespace std;


void LUDecoposition(){
    int no_eq = 3;
    double Coeff_array[no_eq][no_eq] = {{10,-7,0},{-3,2.099,6},{5,-1,5}};
    double Right[no_eq] = {7,3.901,6};
    double Lower[no_eq][no_eq],Upper[no_eq][no_eq], D_array[no_eq], out_array[no_eq];
   for(int i = 0 ; i <no_eq ; i++){
       for(int r = i ; r <no_eq ;r++){
           double sumL =0;
           for(int s = 0 ; s <i ; s++){
               sumL += Lower[r][s]*Upper[s][i];
           }
           Lower[r][i] = Coeff_array[r][i]- sumL;
       }
       for(int j = i+1 ; j <no_eq ;j++){
           double sumU =0;
           for(int k = 0 ; k <i ; k++){
               sumU += Lower[i][k]*Upper[k][j];
           }
           Upper[i][j] = (Coeff_array[i][j]- sumU)/Lower[i][i];
       }
       Upper[i][i] = 1 ;
   }
//   // lower matrix printing
//   for(int i = 0; i<no_eq; i++){
//       for(int j = 0 ; j< no_eq; j++){
//           cout<<Lower[i][j]<<"  ";
//       }
//       cout<<"\n";
//   }
//   // Upper matrix printing 
//   for(int i = 0; i<no_eq; i++){
//       for(int j = 0 ; j< no_eq; j++){
//           cout<<Lower[i][j]<<"  ";
//       }
//       cout<<"\n";
//   }
    
    // calculating D matrix
    // farward sweep
    for(int i = 0 ; i< no_eq ; i++){
        double sumd = 0;
        for(int j =0 ; j<i; j++){
            sumd += Lower[i][j]*D_array[j];
        }
        D_array[i] = (Right[i] - sumd)/Lower[i][i] ;
    }
    // output calculation
    for(int i = no_eq -1 ; i> 0 ; i--){
        double sumx = 0;
        for(int j =i+ 1 ; j<no_eq; j++){
            sumx += Upper[i][j]*out_array[j];
        }
        out_array[i]  = D_array[i] - sumx ;
    }
    
    //printing out_array
    for(int i = 0 ; i<no_eq ; i++){
        cout<<"x= "<<out_array[i]<<"\n";
    }
}
int main()
{
    cout<<fixed<<setprecision(6);
    LUDecoposition();

    return 0;
}


