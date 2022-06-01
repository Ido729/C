#include <stdio.h>
#include <string.h>

void creation(), contact_list(), keep();
char full_name[50], Email[500], ch, decision[24];
int phone, i, num, option;


void menu(){
    const char options [][90] = {"Add contact","contact list"};
    
    printf("\nWelcome to our virtual contact book!\n");
    for (int i = 0; i<2 ;i++){
        printf("%d.%s\n",i + 1, options[i]);
}
    printf("Please chose: ");
    scanf("%d", &option);

    if (option == 1){
        creation();
    } else {
        contact_list();   
    }
    }


void creation(){

   printf("Enter the amount of people that you wished to add their contact: ");
   scanf("%d", &num);

   FILE *fptr;
   fptr = fopen("C:\\contact list.txt", "a");
   ch = fgetc(fptr);
    
   if(fptr == NULL)
   {
       printf("Error!");
       exit(1);
   }

   for(i = 0; i < num; ++i)
   {
      printf("\nFor contact %d \nEnter full name: ", i+1);
      scanf("%s", full_name);

      printf("Enter your Phone number: ");
      scanf("%d", &phone);

      printf("Enter your Email: ");
      scanf("%s", Email);

      fprintf(fptr,"Full Name: %s \nPhone Number : %d \nEmail : %s\n\n", full_name, phone, Email);
   }
    fclose(fptr);
    keep();
}


void contact_list(){
    printf("\nBelow is the contact list.\n\n ");

    FILE *fptr;
    fptr = fopen("C:\\contact list.txt", "r");
    ch = fgetc(fptr);

    while (ch != EOF)
    {
    printf("%c", ch);
    ch = fgetc(fptr);
    }
    fclose(fptr);
    keep();
}

void keep(){
    printf("would you like to go back to the menu? [yes/no] : ");
    scanf("%s", decision);

    if (strcmp(decision, "yes") == 0){
        system("clear");
        menu();
    } else{
        exit(1);
    }
}

int main(){
    menu();
    }
