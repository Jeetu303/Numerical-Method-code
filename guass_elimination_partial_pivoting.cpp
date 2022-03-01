/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

void Guass_elimination_Partial(){
    int No_eq = 3 ;
    double Augmented[No_eq][No_eq+1] ={{10,-7,0,7},{-3,2.099,6,3.901},{5,-1,5,6}};
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
                printf("NO need to swap \n");
            }
            else if(i == No_eq - 1 && row_no != j){
                printf("Swap needed \n");
               
                for(int s =0; s<No_eq+1; s++){
                    double c;
                    c = Augmented[j][s];
                    Augmented[j][s] = Augmented[row_no][s];
                    Augmented[row_no][s] = c;
                }
                printf("Swap done \n");
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
    printf("Farward elimination done \n");
    
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
}
int main (){
    cout<<fixed<<setprecision(8);
    Guass_elimination_Partial();
}