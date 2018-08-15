#include <stdio.h>
#include <stdlib.h>
/* question 1 http://www.techiedelight.com/find-pair-with-given-sum-array/ 
	Done by:Jonathan Darling
	Date:8/15 */
int main()
{   int siz_input=0;
    int i =0;
    int t = 0;
    int target_value= 0;
    printf("Please enter the size of the input");
    scanf("%d",&siz_input);
    int *arr = (int*)malloc(sizeof(int)*siz_input);
    while(i<siz_input){
        printf("Please enter the %d value",i);
        scanf("%d",&arr[i]);
        i++;
    }
    printf("Please enter the target value to find the sum for \n");
    scanf("%d",&target_value);
    int num_of_success = 0;
    for(i=0;i<siz_input;i++){
        for(t=i;t<siz_input;t++){
        int a = arr[i];
        int b = arr[t];
        int c = a+b;

            if(c == target_value&& a!=b){
                printf("The value of %d and %d sum up to %d\n",a,b,target_value);

            }
        }
    }
    if (num_of_success == 0){printf("Sorry there were no two numbers that sum up to the target of %d",target_value);}
    return 0;
}
