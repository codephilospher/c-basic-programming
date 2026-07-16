#include <stdio.h>
#include <string.h>
#define shiv 256
void vowel_converter(char str[]);
void vowel_convertor(char str[]);
void frequency(char str[]);
void space_remover(char str[]);

int main() {
    // Define a buffer to store the input (allocating space for 100 characters)
    char name[100];

    printf("Please enter your full name: ");

    // fgets(destination_buffer, maximum_size, input_stream)
    // 'sizeof(name)' ensures we never read more than 99 characters + '\0'
    if (fgets(name, sizeof(name), stdin) != NULL) {
        
        // Optional but Recommended: Remove the trailing newline character (\n)
        // fgets keeps the '\n' when you press Enter. This line swaps it for a null-terminator.
        name[strcspn(name, "\n")] = '\0';

        // Display the cleaned input
        printf("Welcome to the program, %s!\n", name);
    } else {
        printf("Error reading input.\n");
    }
    char str[]="my name is shiv hello everyone";
    frequency(str);
        int choice;
    printf("No of function you want to done\n");
    printf("1.changing lower case vowel to uppwercase\n");
    printf("2.To remove space");
    scanf(" %d",&choice);
    getchar();
    if(choice==1){
        char str[100];
       
        if(fgets(str,sizeof(str),stdin) != NULL){
            str[strcspn(str,"\n")] = '\0';
            
             printf(" your string is %s!\n",str);
            vowel_converter(str);
        }
       
    

    }
     if(choice==2){
            char str[100]="my name is shiv";
            space_remover( str);


        }

    return 0;
}

void vowel_converter(char str[]){
    int n=strlen(str);
    for(int i=0;i<n;i++){
        if(str[i]=='a'){
            str[i]='A';
        }
        else if(str[i]=='e'){
            str[i]='E';
        }
        else if(str[i]=='i'){
            str[i]='I';

        }
        else if(str[i]=='o'){
            str[i]='O';
        }
        else if(str[i]=='u'){
            str[i]='U';
        }
    }
    puts(str);

}
void vowel_convertor(char str[]){
    int n = strlen(str);
    for(int i = 0; i < n; i++){
        switch(str[i]) {
            case 'a': str[i] = 'A'; break;
            case 'e': str[i] = 'E'; break;
            case 'i': str[i] = 'I'; break;
            case 'o': str[i] = 'O'; break;
            case 'u': str[i] = 'U'; break;
            default: break; // Do nothing for other characters
        }
    }
    puts(str);
}
//SEcond way of doing this
void frequency(char str[]){
    int code[256]={0};
    for(int i=0;str[i]!='\0';i++){
        char character=str[i];
        if(character!=' '){
        code[character]++;
        }
    }
    int max_count=0;
    char freq_ch=' ';
      for(int i=0;str[i]!='\0';i++){
        char character=str[i];
        if(character!=' '){

             if(code[character]>max_count){
            max_count=code[character];
            freq_ch=character;
             }
          }

      }
      printf("your most frequency character is%c,%d times",freq_ch,max_count);
    
}
void space_remover(char str[]){
    char str_[200];
    int j=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]!=' '){
            str[j]=str[i];
            j++;
    }
}
 str[j]='\0';
  printf("your new string is%s",str);
}
