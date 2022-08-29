#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <conio.h>


//This code represents a simple parking system
void enterace(), cuntdown(), timer(), stop();


int choise, flag = 0, counter = 0;
float hours, minutes, specific;


//the thread function that stop the timer
void stop(){

    printf("\nPress any key to stop the timer\n");
    char surf = getch();
    float payment = ((hours * 60) + minutes) / 12;

    system("cls");
    printf("\nTotally %g hours and %g minutes", hours, minutes);
    printf("\nYou have to pay %g$ for your stay.", payment);
    exit(1);

}

void cuntdown() {

    system("cls");
    printf("How many hours you wanna set: ");
    scanf("%g", &hours);

    printf("How many minutes you wanna set: ");
    scanf("%g", &minutes);

    //convert minutes to hours
    if (minutes > 60) {
        specific = minutes / 60;
        minutes = minutes - specific * 60;
        hours = hours + specific;
    }

    float payment = ((hours * 60) + minutes) / 12;
    // 60 devided by X = payment per hour
    system("cls");

    //print the time remained
    while (hours != -1) {
        printf("hours: %g, minutes: %g", hours, minutes);
        minutes--;

        if (minutes == -1) {
            hours--;
            minutes = 60;
        }

        Sleep(1000);
        system("cls");
    }

    printf("\nYou have to pay %g$ for your stay.", payment);
    exit(1);
}


void timer() {
    system("cls");

    pthread_t newthread;

    while (hours != -1) {
        pthread_create(&newthread, NULL, stop, NULL);

        printf("hours: %g, minutes: %g", hours, minutes);
        minutes++;

        if (minutes > 60) {
            specific = minutes / 60;
            minutes = minutes - specific * 60;
            hours = hours + specific;
        }

        Sleep(1000);
        system("cls");

    }
}


//the system nemu
void enterace() {
    printf("You have to buy parket ticket to park.\n");
    printf("(ticket is 5$ per hour)\n");

    printf("1. I want a timer\n");
    printf("2. I want to set specific time\n");

    printf("Your choise: ");
    scanf("%d", &choise);
}


int main() {
    enterace();
    if (choise == 1) {
        timer();
    } else {
        cuntdown();
    }

}
