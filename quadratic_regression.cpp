/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include<iostream>
#include <iomanip>
#include <cmath>
#define S 50

using namespace std;
void quadratic_regression(){
    double sumX, sumY, sumXY,sum_squareX,sum_cubeX,sum_4X, sumX2Y;
    //  regression point 
    double reg_point = 125 ;
    int n = 15;
    double x[n] = {100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
    double y[n] = {99.61, 120.21,133.52,143.61,151.83,158.83,164.95,170.41,175.35,179.88,184.06,187.96,191.60,195.04,198.29};
    for(int i  = 0 ; i < n ; i++){
        sumX = sumX + x[i];
        sum_squareX = sum_squareX + pow(x[i], 2);
        sum_cubeX =  sum_cubeX + pow(x[i], 3);
        sum_4X = sum_4X + pow(x[i], 4);
        sumY = sumY + y[i];
        sumXY = sumXY + x[i]*y[i];
        sumX2Y = sumX2Y + pow(x[i],2)*y[i];
    }
    cout<< "sumX = "<< sumX<<endl;
    cout<< "sum_squareX = "<< sum_squareX<<endl;
    cout<< "sum_cubeX = "<< sum_cubeX<<endl;
    cout<< "sum_4X = "<< sum_4X<<endl;
    cout<< "sumY = "<< sumY<<endl;
    cout<< "sumXY = "<< sumXY<<endl;
    cout<< "sumX2Y= "<< sumX2Y<<endl;
    
}
void Guass_elimination_Partial(){
    int No_eq = 3 ;
    double reg_point = 1325;
    double Augmented[No_eq][No_eq+1] ={{15,12000,12400000,2455.15},{12000,12400000,14400000000,2139793},{12400000,14400000000,17831200000000,2293346500}};
    for(int j = 0; j<No_eq-1; j++){
        for(int i = j ; i< No_eq; i++){
            double  max_row;
            int row_no;
            if(i == j){
                max_row = Augmented[i][j];
                row_no = i;
            }
            else{
                if(max_row<Augmented[i][j]){
                    max_row = Augmented[i][j];
                    row_no = i;
                }
            }   
            if( i == No_eq - 1 && row_no == j){
                // printf("NO need to swap \n");
            }
            else if(i == No_eq - 1 && row_no != j){
                // printf("Swap needed \n");
               
                for(int s =0; s<No_eq+1; s++){
                    double c;
                    c = Augmented[j][s];
                    Augmented[j][s] = Augmented[row_no][s];
                    Augmented[row_no][s] = c;
                }
                // printf("Swap done \n");
            }
            else{
               //
            }
        }
        //farward elimination
        for(int k = j + 1 ; k < No_eq+1 ; k++){ 
            double multiplication = Augmented[k][j] / Augmented[j][j] ;
            // cout<<multiplication<<"\n";
            // for(int q =0; q< No_eq ; q++){
            //     for(int p = 0 ; p< No_eq+ 1; p++){
            //         cout<<Augmented[q][p]<<" ";
            //     }
            //     cout<<"\n";
            // }
            for(int r = j; r < No_eq + 1; r ++){
                Augmented[k][r] = Augmented[k][r] - Augmented[j][r] * multiplication ;
            } 
            // cout<<"cheking inside"<<"\n";
        }
        // cout<<"checking outside"<<"\n" ;
    }
    // printf("Farward elimination done \n");
    
    for(int q =0; q< No_eq ; q++){
        for(int p = 0 ; p< No_eq+ 1; p++){
        cout<<Augmented[q][p]<<" ";
        }
        cout<<"\n";
    } 
    // backward substitution
    double Answer[No_eq];
    for(int i = No_eq - 1 ; i >= 0 ; i--){
        double sum = 0;
        for(int j = i ; j < No_eq; j++){
            sum = sum + Augmented[i][j]*Answer[j];
        }
        Answer[i]=(Augmented[i][No_eq]-sum)/Augmented[i][i];
        cout<<"x"<< i<< " = "<<Answer[i]<< "\n";
    }
    cout<<"regressive quadratic polynomial is y = "<< Answer[0]<<" + ("<<Answer[1]<<"x) + ("<<Answer[2]<<"x^2)"<<endl;
    // regressed value reg_y
    double reg_y = 0 ;
    for(int i = 0 ; i < No_eq ; i++){
        reg_y = reg_y + Answer[i]*(pow(reg_point, i));
    }
    cout<< "regressed value at "<<reg_point<<" is "<<reg_y<<endl;
}
int main()
{
 cout<<fixed<<setprecision;
  quadratic_regression();
  Guass_elimination_Partial();
 return(0);
}

