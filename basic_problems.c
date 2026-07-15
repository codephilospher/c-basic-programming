/*THis code show basic problems which i solve suring my c journey*/



#include<stdio.h>
// Wap to check whether input is upper or not
//WAP to check the given no is natural or not
//WAP to print the sum of first n natural no also print them in reverse
// keep taking input from user until user does not input an odd no
//wap to find area of square cirlce and rectangle
void checker(char array[],int n);
void number(int num);
void reverse_sum(int n);
void table(int n);
void oddend(int num[],int n);
void factorial(int n);
float squarearea(int side);
float circlearea(int radius);
float rectanglearea(int lenght,int breadth);
//most basic complete 
int main(){
  int side,radius,length,breadth,area;
printf("enter which area you want to measure");
printf(" 1.Area of square");
printf("2.Area of rectangle");
printf(" 3,area of circle"); 
printf("enter the no of area you want to calculate");
 scanf("%c",&area);
 switch(area){
  case 1:
  printf("enter side of square");
  printf("side=");
  scanf("%d",&side);
  squarearea(side);
  break;
  case 2:
  printf("enter length and breadth of rectangle");
  printf("length=");
  scanf("%d\n",&length);
  printf("breadth");
  scanf("%d",&breadth);
  rectaanglearea(length,breadth);
  break;
  case 3:
  printf("enter the radius of circle");
  printf("Radius=");
  scanf("%d",&radius);
  circlearea(radius);
  break;
  default:
  printf("enter valid choice");
 }
return 0 ;
}
//switch code
float squarearea(int side){
  return side*side;
}
float circlearea(int radius){
  float pi=3.14;
  return pi*radius*radius;
}
float Rectanglearea(int length,int breadth){
    return length*breadth;
}



//most basic complete
void factorial(int n){
  int fact=1;
  for(int i=1;i<=n;i++){
    fact=fact*i;
   }
   printf("your factorial is %d",fact);

}
void oddend(int num[],int n){
  for(int i=0;i<n;i++){
    printf("enter the no you want to enteer except odd");
    scanf("%d",&num[i]);
    if((num[i]%2)!=0){
      printf("you enter an odd no %d",num[i]);
      break;
    }
  }
}


void table(int n){
  for(int i=1;i<=10;i++){
  printf("your table is %d\n",n*i);
}
}

void reverse_sum(int n){
  int sum=0;
  for(int i=n;i>=1;i--){
    sum=sum+i;
    printf("your reverse order %d\n",i);
  }
  printf("sum of your no %d",sum);

  
  
}
void number(int num){
  if(num>0){
    printf("your no is natural");
  }
  else{
    printf("number is not natural");
  }
}
void checker(char array[],int n){//words{a,b,c},3
  int count=0;
  for(int i=0;i<n;i++){//2,3
    if(array[i]>='A' && array[i]<='Z'){
      printf("this character is upper:%c\n",array[i]);//a,b
      count++;//2
    }
  }
printf("total upper case character %d",count);
}