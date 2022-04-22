#include<stdio.h>
#include<string.h>

void options(), transform(), amount(), money(), keep(), entrance();
int option, pin = 222, count = 3, counter = 10, login, balance = 5000, x;
const char aka[][10] = {"Withdrawl", "Despite", "Balance"};

void options(){
    entrance();
    
    if (option == 1){
        x = 1;
        transform();
        
    } else if (option == 2){
        x = 2;
        transform();
        
    } else if (option == 3){
        printf("your balance is : %d", balance);
        
    } else {
        printf("Something went wrong. Please try again later");
    }
    
    if (x == 1 || x == 2 || option == 3){
        keep();
    }
    }

void entrance(){
     printf("Enter your pin: ");
     scanf("%d", &login);
    
    if (login == pin){
        for (int i = 0; i<3 ;i++){
            printf("%d.%s\n",i + 1, aka[i]);
        }
        printf("What would you like to do? ");
        scanf("%d", &option);

    } else {
        printf("Invalid pin! %d tries left before cooldown\n", count);
        count --;
        while (count == 0 && counter != -1){
            printf("\n\n\t%d", counter);
            counter--;
            sleep(1);
            system("clear");
        }
        printf("\n");
        options();
        }
    }

void transform(){
    amount();
    
    if (x == 1){
        balance = balance - option;
        printf("You have withdrawl %d$. Your new balance is %d$ (withdrawl)", 
        option, balance);
        
    } else if (x == 2){
        balance = balance + option;
        printf("You have despite %d$. Your new balance is %d$(despite)", 
        option, balance);
    }
}

void amount(){
    printf("\nPlese enter the amount: ");
    scanf("%d", &option);
    
}

void keep(){
    printf("\n\nDo you wish to perform another transaction? Press 1[yes], 0[no]");
    scanf("%d", &option);
    if (option == 1){
        options();
        
    } else {
        printf("thanks for using MAG ATM, have a nice day!");
    }
}

int main(){
  options();

}
