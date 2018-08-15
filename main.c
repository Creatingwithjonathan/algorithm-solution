#include <stdio.h>
#include <stdlib.h>
/*Problem 2 http://www.techiedelight.com/check-subarray-with-0-sum-exists-not/ */
struct stack{
int current_size;
int* current_arr;
}li;
int main()
{
    int siz =0;
    int i =0;

    int target = 0;
    printf("Please enter the size of the array you would like: ");
    scanf("%d",&siz);
    int* arr = (int*)malloc(sizeof(int)*siz);
    while(i<siz){
        printf("Please enter the %d digit: ",(i+1));
        scanf("%d",&arr[i]);
        i++;
    }
     int outer = 0;
     int inner = 0;
     int num_of_cycles=1;
  
  for (inner=0;inner<siz;inner++){
      outer =inner;
        int sum1 = 0;
		struct stack*stack=(struct stack*)malloc(sizeof(struct stack));
		stack->current_size = -1;
		stack->current_arr=(int*)malloc(sizeof(int)*siz);
    for (outer=inner;outer<siz;outer++){
            int b = arr[outer];

            sum1= sum1+b;
            stack->current_size=1+(stack->current_size);
            stack->current_arr[stack->current_size]=b;
     
            if(sum1 != target &&(outer==siz-1)&&(inner==siz-1)){
                free(stack);
                outer= siz;
                inner=siz;
                }
            if(sum1 == target){
                    printf("\t\t\t\t new cycle [%d]\n",num_of_cycles);
                    printf("\b\tThe total is:%d the target is %d\n",sum1,target);
                while(stack->current_size!=-1){
                   printf("\tthe results are: %d\n",stack->current_arr[stack->current_size]);
                stack->current_size = (stack->current_size)-1;
                    }
                        num_of_cycles++;
                    }
            if(outer == (siz -1)){
               free(stack);
                outer= siz;
                printf("\n");
                }
        }
    }
    return 0;
}
