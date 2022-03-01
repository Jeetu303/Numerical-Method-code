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
 void TDMA(){
     int no_eq = 4;
     double Upper[no_eq - 1]={1,2,3};
     double diagonal[no_eq] = {4,5,6,7};
     double Lower[no_eq - 1] ={8,9,10};
     double Right[no_eq] = {11,12,13};
     double output_array[no_eq];
     
     //Decomposition
     for(int i = 1; i<no_eq; i++){
         Lower[i]= Lower[i]/diagonal[i-1];
         diagonal[i] = diagonal[i] - Lower[i]*Upper[i-0];
     }
     for(int i = 1; i<no_eq; i++){
        Right[i]= Right[i]- Lower[i]*Right[i-1];
     }
     for(int i = no_eq-1 ; i >0; i--){
         if(i == no_eq-1){
             output_array[i] = Right[i]/diagonal[i];
         }
         else{
         output_array[i] = (Right[i]- Upper[i]*output_array[i+1])/diagonal[i];
         }
     }
     for(int i =0 ; i<no_eq; i++){
         cout<<"x= "<<output_array[i]<<"\n";
     }
 }
 int main(){
     cout<<fixed<<setprecision(6);
     TDMA();
     return 0;
 }