#include <iostream>
#include <vector>
#include <algorithm>


#include "SearchAlgorithms.hpp"
#include "GeneratorInstance.hpp"
#include "../headers/CPUTimer.hpp"

using namespace std;


void test_D1(int N, int ld, int min_value, int interval){
    vector<int> A(N);
    CPUTimer timer;
    if(ld == 1){
        printf("Linear Increasing Distribution\n");
        LinearIncreasingDistribution(A.begin(), A.end(), min_value, interval);
    }
    else if(ld == 2){
        printf("Linear Decreasing Distribution\n");
        LinearDecreasingDistribution(A.begin(), A.end(), min_value, interval);
    }
    else if(ld == 3){
        printf("Linear Normal Distribution\n");
        LinearNormalDistribution(A.begin(), A.end(), min_value, interval);
    }
    else
        return;

    int query;
    printf("How many queries in the range: ");
    scanf(" %d", &query);
    while(query > 0){
        getchar();
        bool found;
        int key;
        printf("Search key value: ");
        scanf(" %d", &key);

        /* ------------------------------------------- */

       printf("----------------------------------------------------------------------\n\n");
       printf("Key: %d\n", key);
       printf("N = %d\n", N);

        

        timer.reset();
        found = false;
        timer.start();
        found = linear_search(A.begin(), A.end(), key);
        timer.stop();
        printf("Linear search: ");
        if(found == true){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        printf("timer: %.10lf\n", timer.getCronoTotalSecs());
        
        /* ------------------------------------------- */

        timer.reset();
        found = false;
        timer.start();
        found = jump_search(A.begin(), A.end(), key);
        timer.stop();
        printf("Jump search: ");
        if(found == true){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        printf("timer: %.10lf\n", timer.getCronoTotalSecs());
        
        /* ------------------------------------------- */

        timer.reset();
        found = false;
        timer.start();
        found = binary_search(A.begin(), A.end(), key);
        timer.stop();
        printf("Binary search: ");
        if(found == true){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
         printf("timer: %.10lf\n", timer.getCronoTotalSecs());
       
        /* ------------------------------------------- */
        
        timer.reset();
        found = false;
        timer.start();
        found = interpolation_search(A.begin(), A.end(), key);
        timer.stop();
        printf("Interpolation search: ");
        if(found == true){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        printf("timer: %.10lf\n", timer.getCronoTotalSecs());
        
        /* ------------------------------------------- */

        timer.reset();
        found = false;
        timer.start();
        found = exponential_search(A.begin(), A.end(), key);
        timer.stop();
        printf("Exponential search: ");
        if(found == true){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        printf("timer: %.10lf\n", timer.getCronoTotalSecs());
        
        /* ------------------------------------------- */
        
        timer.reset();
        found = false;
        timer.start();
        found = fibonaccian_search(A.begin(), A.end(), key);
        timer.stop();
        printf("Fibonaccian search: ");
        if(found == true){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        printf("timer: %.10lf\n", timer.getCronoTotalSecs());
        printf("----------------------------------------------------------------------\n\n");
        query--;
    }
    printf("\n");
}


void test_D2(int M, int N, int ld, int min_value, int interval){



    vector<vector<int> > A(M, vector<int>(N));
    
    CPUTimer timer;
    
    if(ld == 1){
        printf("Linear Increasing Distribution\n");
        LinearIncreasingDistribution_2D(A.begin(), A.end(), min_value, interval);
    }
    else if( ld == 2){
        printf("Linear Decreasing Distribution\n");
        LinearDecreasingDistribution_2D(A.begin(), A.end(), min_value, interval);
    }
    else if( ld==3){
        printf("Linear Normal Distribution\n");
        LinearNormalDistribution_2D(A.begin(), A.end(), min_value, interval);
    }
    else
        return;
    int query;
    printf("How many queries in the range: ");
    scanf(" %d", &query);
    while(query>0){
        bool found;
        int key;
        printf("Search key value: ");
        scanf(" %d", &key);

        /* ------------------------------------------- */

        printf("----------------------------------------------------------------------\n\n");
        printf("Key: %d\n", key);
        printf("M x N = %d x %d\n", M, N);
        timer.reset();
        found = false;
        timer.start();
        found = saddleback_search(A.begin(), A.end(), key);
        timer.stop();
        printf("Saddleback search: ");

        if(found == true){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        printf("timer: %.10lf\n", timer.getCronoTotalSecs());

        timer.reset();
        found = false;
        timer.start();
        found = shen_search(A.begin(), A.end(), key);
        timer.stop();

        printf("Shen search: ");
        if(found == true){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        printf("timer: %.10lf\n", timer.getCronoTotalSecs());
        printf("----------------------------------------------------------------------\n\n");
        query--;
    }
    printf("\n");
}

void test_D3(int M, int N, int P, int ld, int min_value, int interval){


    vector<vector<vector<int> > > A(M, vector<vector<int> >(N, vector<int>(P)));
    CPUTimer timer;

    if( ld == 1){
        printf("Linear Increasing Distribution\n");
        LinearIncreasingDistribution_3D(A.begin(), A.end(), min_value, interval);
    }
    else if(ld == 2){
        printf("Linear Decreasing Distribution\n");
        LinearDecreasingDistribution_3D(A.begin(), A.end(), min_value, interval);
    }
    else if(ld == 3){
        printf("Linear Normal Distribution\n");
        LinearNormalDistribution_3D(A.begin(), A.end(), min_value, interval);
    }
    else
        return;

    int query;
    printf("How many queries in the range: ");
    scanf("%d", &query);
    while(query > 0){
        bool found;
        int key;
        printf("Search key value: ");
        scanf(" %d", &key);

        /* ------------------------------------------- */
        
        printf("----------------------------------------------------------------------\n\n");
        printf("Key: %d\n", key);
        printf("M x N x P = %d x %d x %d\n", M, N, P);
        if( M == N && M == P){
            timer.reset();
            found = false;
            timer.start();
            found = linialsaks_search(A.begin(), A.end(), key);
            timer.stop();
           
            printf("LinialSaks search: ");
            if(found == true){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
            printf("timer: %.10lf\n", timer.getCronoTotalSecs());
        }
        
        /* ------------------------------------------- */
        
        timer.reset();
        found = false;
        timer.start();
        found = MAHL_e(A.begin(), A.end(), key);
        timer.stop();
        printf("Shen3D search: ");
        if(found == true){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        printf("timer: %.10lf\n", timer.getCronoTotalSecs());

        printf("----------------------------------------------------------------------\n\n");
        query--;
    }
    printf("\n");
}

/*!
 * \brief Function main.
 */
int main(){
    int option;
    do{
        printf("Test search algorithms for:\n1 - one-dimensional\n2 - two-dimensional\n3 - three-dimensional\nAnother value to leave:\n");

        scanf(" %d", &option);
        switch(option){
            case 1:{
                int N, ld, min_value, interval;
                printf("What kind of distribution?\n1 - LID\n2 - LDD \n3 - LND\n");
                scanf(" %d", &ld);
                printf("What is the size of the array? ");
                scanf(" %d", &N);
                printf("Start of break: ");
                
                scanf(" %d", &min_value);
                printf("End of break: ");
               

                scanf(" %d", &interval);
                test_D1(N, ld, min_value, interval);
                break;
            }
            case 2:{
                int M, N, ld, min_value, interval;
                printf("What kind of distribution?\n1 - LID\n2 - LDD \n3 - LND\n");
                scanf(" %d", &ld);
                printf("What is the size of the array? \n");
                printf("M: ");
                scanf(" %d", &M);
                printf("N: ");
                scanf(" %d", &N);
                printf("Start of break: ");
                scanf(" %d", &min_value);
                printf("End of break: ");
                scanf(" %d", &interval);
                test_D2(M, N, ld, min_value, interval);
                break;
            }
            case 3:{
                int  M, N, P, ld, min_value, interval;
                 printf("What kind of distribution?\n1 - LID\n2 - LDD \n3 - LND\n");
                scanf(" %d", &ld);
                printf("What is the size of the array? \n");
                printf("M: ");
                scanf("%d", &M);
                printf("N: ");
                scanf("%d", &N);
                printf("P: ");
                scanf(" %d", &P);
                printf("Start of break: ");
                scanf("%d", &min_value);
                printf("End of break: ");
                scanf("%d", &interval);
                test_D3(M, N, P, ld, min_value, interval);
                break;
            }
            default:
                break;
        }
    }while(option > 0 && option  < 4);
    return 0;
}
