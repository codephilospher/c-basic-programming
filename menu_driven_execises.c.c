#include<stdio.h>
/*
 * Program: Menu Driven C Exercises
 * Description: A collection of basic C programs covering 
 * arrays, loops, functions, and pointers.
 * Author: Shiv raj sharma
 * Date: July 2026
 */


        void primeinrange(int start,int end);
        void printshape(char shape,int rows,int columns);
        void reverse(int array[],int n);
        void numcount(int array[],int n,int no);
        int arrayinput(int n,int num[]);
        void appendarray(int n,int num[]);
int main(){
    int choice;

    printf("enter the no of program you want to perform\n");
    printf("1.prime num in a range\n");
    printf("2.want to print the shape\n");
    printf("3.find maximum num\n");
    printf("4.reverse an aray\n");
    printf("5.english alphabet\n");
    printf("6.checkthenum\n");
    printf("7.largestno\n");
    printf("8.Appending in an array");
    scanf("%d",&choice);
    if(choice==8){
        int date[100]={10,20,34,5,6,4,6};
        int n=7;
        scanf("%d",&date[n]);
        n++;
        for(int i=0;i<n;i++){
              printf("%d ",date[i]);
        }
      
    }
    if(choice==7){
        int n;
       
        printf("num of input you want to enter");
        scanf("%d",&n);
         int num[n];
        arrayinput(n,num);
    }
    if(choice==6){
        int n,no;
        int num[]={1,4,5,6,5,4,2,3,4,2,4,};
        printf("totoal no in an aaraay");
        scanf("%d",&n);
        printf("input num which you want to count");
        scanf("%d",&no);
        numcount(num,n,no);

    }
    if(choice==1){
        int start,end;
        printf("enteer your range \n");
        printf("starting from=");
        scanf("%d",&start);
        printf("ending at=");
        scanf("%d",&end);
        primeinrange(start,end);
    }
    if(choice==2){
        char shape;
        int rows,columns;
        printf("enter the following details:-\n");
        printf("which character you want for the design=");
        scanf(" %c",&shape);
          printf("no of vertical columns=");
        scanf(" %d",&columns);
        printf("no of horizonatal rows=");
        scanf(" %d",&rows);
      
        printshape(shape,rows,columns);

    }
    if(choice==3){
        int a,b;
        int*ptr=&a;
        int *_ptr=&b;
        printf("enter your first no=");
        scanf("%d",ptr);
        printf("enter the second no");
        scanf("%d",_ptr);
        if(*ptr>*_ptr){
            printf("your no first is greater than second%d",*ptr);
            printf("your second no is%d",*_ptr);

        }
        else{
            printf("your second no is grater than first no%d",*_ptr);
        }
    }
    if(choice==4){
        int n;
        printf("enter the inputs you want to enter");
        scanf("%d",&n);
        int num[n];
        for(int i=0;i<n;i++){
            scanf("%d",&num[i]);
        }
        reverse(num,n);

    }
     if(choice==5){
        char ch='A';
       char *ptr=&ch;
       while(*ptr<='Z'){
        printf("%c\n",*ptr);
        (*ptr)++;
       }

    }
    return 0;
   
}
int arrayinput(int n,int num[]){
 
 
 for(int i=0;i<n;i++){
    scanf("%d",&num[i]);
    
 }
int largest=num[0];
for(int i=0;i<n;i++){
    if(num[i]>largest){
        largest=num[i];
    }
}
printf("your largest no is%d",largest);
}
void numcount(int array[],int n,int no){
      int count=0;
    for(int i=0;i<n;i++){
      
        if(array[i]==no){
            count++;
        }

    }
    printf("your no of occurence is%d",count);

}
void reverse(int array[],int n){
    for(int i=n-1;i>=0;i--){
        printf("%d",array[i]);
    }


}
void printshape(char shape,int rows,int columns){
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("%c",shape);
        }
        printf("\n");
    }
}
void primeinrange(int start,int end){
    int prime=1;
    
    for(int i=start;i<=end;i++){
        int prime=1;
        if(i<=1){
            prime=0;
        }
        for(int j=2;j<i;j++){
            if(i%j==0){
                prime=0;
                break;
            }
        }
        if(prime==1){
            printf("%d\n",i);
        }
    }
}


