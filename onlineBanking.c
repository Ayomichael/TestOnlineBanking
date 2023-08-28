#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct user
{
    char phone[50];
    char ac[50];
    char password[50];
    float balance;
};

int main()
{
    struct user usr, usr1;
    FILE *fp;
    char filename[50], phone[50], pword[50];
    int opt, choice;
    char cont = 'y';
    float amount;

    printf("\n what do you want to do?");
    printf("\n\n1. Register an account");
    printf("\n2. Login to account \n");

    printf("\nSelect: 1 or 2\n");
    scanf("%d", &opt);
    if (opt == 1)
    {
        system("clear");
        printf("Enter your account no:\t");
        scanf("%s", usr.ac);
        printf("Enter your Phone no:\t");
        scanf("%s", usr.phone);
        printf("Enter your new password:\t");
        scanf("%s", usr.password);
        usr.balance = 0;

        strcpy(filename, usr.phone);
        fp = fopen(strcat(filename, ".dat"), "w");
        fwrite(&usr, sizeof(struct user), 1, fp);
        if (&fwrite != 0)
        {
            printf("\n\nAccount successfully registered");
        }
        else
        {
            printf("\n\nSomething went wrong please try again");
        }
        fclose(fp);
    }
    if (opt == 2)
    {
        system("clear");
        printf("\nPhone No:\t");
        scanf("%s", phone);
        printf("password:\t");
        scanf("%s", pword);
        strcpy(filename, phone);
        fp = fopen(strcat(filename, ".dat"), "r");
        if (fp == NULL)
        {
            printf("\nAccount no. not registered");
        }
        else
        {
            fread(&usr, sizeof(struct user), 1, fp);
            fclose(fp);
            if (!strcmp(pword, usr.password))
            {
                printf("\n\tWelcome %s", usr.phone);
                while (cont == 'y')
                {
                    system("clear");
                    printf("\nPress 1 to check balance");
                    printf("\nPress 2 to deposit an amount");
                    printf("\nPress 3 to withdraw");
                    Printf("\nPress 4 to transfer the balance");
                    printf("\nPress 5 to change password\n");
                    printf("\n\nYour choice:\t");
                    scanf("%d", &choice);

                    switch (choice)
                    {
                    case 1:
                        printf("\nYour current balance is N.%.2f", usr.balance);
                        break;
                    case 2:
                        printf("\nEnter the amount:\t");
                        scanf("%f", amount);
                        usr.balance += amount;
                        fp = fopen(filename, "w");
                        fwrite(&usr, sizeof(struct user), 1, fp);
                        if (fwrite != NULL)
                            printf("\nsuccessfully deposited");
                        fclose(fp);
                        break;
                    case 3:
                        printf("\nEnter the amount:\t");
                        scanf("%f", amount);
                        usr.balance -= amount;
                        fp = fopen(filename, "w");
                        fwrite(&usr, sizeof(struct user), 1, fp);
                        if (fwrite != NULL)
                            printf("\nYou have withdrawn N.%.2f", amount);
                        fclose(fp);
                    case 4:
                        printf("\nPlease the phone number to transfer the balance");
                        scanf("%s", phone);
                        printf("\nPlease enter the amount to transfer:\t");
                        scanf("%f", &amount);
                        strcpy(filename, phone);

                        fp = fopen(strcat(filename, ".dat"), "r");
                        if (fp == NULL)
                            printf("\nAccount no. not registered");
                        else
                        {
                            fread(&usr1, sizeof(struct user), 1, fp);
                            fclose(fp);
                            if (amount > usr.balance)
                                printf("\nInsufficient balance");
                            else
                            {
                                fp = fopen(filename, "w");
                                usr1.balance += amount;
                                fwrite(&usr1, sizeof(struct user), 1, fp);
                                fclose(fp);
                                if (fwrite != NULL)
                                {
                                    printf("\nYou have successfully transfer N.%.2f to %s", amount, phone);
                                    strcpy(filename, usr.phone);
                                    fp = fopen(strcat(filename, ".dat"), "w");
                                    usr.balance -= amount;
                                    fwrite(&usr, sizeof(struct user), 1, fp);
                                    fclose(fp);
                                }
                            }
                        }
                        break;
                    case 5:
                        printf("\nPlease enter your new password");
                        scanf("%s", pword);
                        fp = fopen(filename, "w");
                        strcpy(usr.password, pword);
                        fwrite(&usr, sizeof(struct user), 1, fp);
                        if (fwrite != NULL)
                            printf("\nPassword changed succesfully");

                        break;
                    default:
                        printf("\nInvalid option");
                        printf("\n do you want to continue the transaction [y/n]");
                        scanf("%d", &cont);
                    }
                }
            }
            else
            {
                printf("\nInvalid password\n");
            }
        }
    }
    return 0;
}