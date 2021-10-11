//John Parkhurst
//9/22/21
#include <stdio.h>
#include <stdlib.h>

int calcDiv(int numA,int numB){
    /**
    @param: pointer to the desired answer integer array
    @return: void
    **/
    
    //Checks for the greatest common denominator 
    //
    int temp = 0;
    int ans = 0;
    //swaps so the biggest is always numB
    if(numA>numB){
        temp = numA;
        numA=numB;
        numB=temp;  
    }
    for(int t=1;t<=numA;t++){
        if((numA%t==0)&&(numB%t==0)){
            ans=t;
        }
    }
    return ans;
}
void printDiv(int num){
    //@param: num is number we want to find the divisor
    printf("The list of divisors of %d is:",num);
    for(int k=1;k<=num;k++){
        if(num%k==0){
            if(k==num){
                printf(" %d.\n",k);
            }else{
                printf(" %d,",k);
            }
        }
    }
    return;
}
int main (int argc, char *argv[]){
    if(argc == 1){
        printf("prog launched with no argument.\nProper usage: prog m [n]\n");
        exit(1);
    }else if(argc>3){
        printf("prog launched with too many arguments.\nProper usage: prog m [n]\n");
        exit(1);
    }
    //clearing then allocating an array based on size of arguments
	int* val = (int*) calloc(argc-1, sizeof(int));
	for(int i = 1; i<=argc-1;i++){
		int num,num1;
		//count tells u if it int or not
		int count = sscanf(argv[i],"%d",&num);
        if(count ==1){
            if(num>0){
                val[i-1]=num;
            }else{
                if(i==1){
                    printf("prog's first argument is not a strictly positive integer.\n");
                    free(val);
                    exit(1);
                }else{
                    printf("prog's second argument is not a strictly positive integer.\n");
                    free(val);
                    exit(1);
                }
            }
        }else{
            printf("prog's argument is not a strictly positive integer.\n");
            free(val);
            exit(1);
        }
	}
    if(argc==2){
        //For single value print out all the divisors
        printDiv(val[0]);
    }else if(argc==3){
        //For double calculate/print out the GCD
        int ans=calcDiv(val[0],val[1]);
        printf("The gcd of %d and %d is %d.\n",val[0],val[1],ans);
    }
    //Clear up memory from the heap
    free(val);
    return 0;
}