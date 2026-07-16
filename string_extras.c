#include<stdio.h>
#include<string.h>
//find the salted password
// wap to convet all lower case vowel to uppercase in a string
void salt(char password[]);
char slicing(char str[],int n,int m);
void vowel_count(char str[]);
void check_character(char str[],char ch);
int main(){
    int choice;
    printf("enter the choice of fn\n ");
    printf("1.show salt passwd\n");
    printf("2.slicing the string\n");
    printf("3.vowel couunt in a string\n");
    printf("4.check_character in a string");
    scanf("%d",&choice);
    if(choice==1){
         char password[100];
    scanf("%s",&password);
    salt(password);
    }
    if(choice==2){
       char object[]="shivrajsharma";
       int a,b;
       printf("input the index of sliceing");
       scanf("%d",&a);
       printf("enter where the slice end");
       scanf("%d",&b);
       slicing(object,a,b);
      
    }
    if(choice==3){
        char dash[]="dhahfayrwufyusdu";
        vowel_count(dash);

    }
    if(choice==4){
        char str[]="my name is shiv i am from 10th standard";
        char ch;
        printf("enter the character you  want to check");
        scanf(" %c",&ch);
        check_character(str,ch);

    }

   




 




return 0;
}
void salt(char password[]){
    char new_passwd[200];
    char salt[]="1232";
    strcpy(new_passwd,password);
   printf("%s",strcat(new_passwd,salt));

}
char slicing(char str[],int n,int m){
   
    for(int i=n;i<=m;i++){
        printf("%c",str[i]);
    }

}
void vowel_count(char str[]){
    int n=strlen(str);
    int count=0;
    for(int i=0;i<n;i++){
        if(strchr("AEIOUaeiou",str[i])!=NULL){
            
            count++;

        }
    }
    printf("%d",count);
}
void check_character(char str[],char ch){
     int n=strlen(str);
     int found=0;
    for(int i=0;i<n;i++){
        if(str[i]==ch){
            found=1;
            break; 

        }
      

        }
       if(found==1){
        printf("character is present in a string");
       }
       else{
        printf("character does not found");
       }
    }





