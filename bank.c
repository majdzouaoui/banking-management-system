#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
char name[20];
int acc_nm, amount, count = 0, transfer_amt, amt_withdrawed, amt_dep, choice;
void menu();
void deposit_money();
void withdraw_money();
void transfer_money();
void account_detail();
void transfer_detail();
void last_detail();

int main()
{
    printf("give your name");
    gets(name);

    printf("give you account number");
    scanf("%d", &acc_nm);
    menu();

    printf("put your choise");
    scanf("%d", &choice);
    while (1)
    {
        switch (choice)
        {
        case 1:
            deposit_money();
            break;
        case 2:
            withdraw_money();
            break;
        case 3:
            transfer_money();
            break;
        case 4:
            account_detail();
            break;
        case 5:
            transfer_detail();
            break;
        case 6:
            transfer_detail();
            exit(0);
            break;
            ;
        default:
            printf("invalide choise");
            break;
        }
    }

    return 0;
}

void menu()
{
    printf("menu\n");
    printf("1-deposit money\n");
    printf("2-withdraw money\n");
    printf("3-transfer money\n");
    printf("4-account details\n");
    printf("5-transfer details\n");
    printf("6-exit\n");
}
void deposit_money()
{
    time_t tm;
    time(&tm);
    FILE *f = fopen("account.txt", "a");
    printf("put the amount to deposit\n");
    scanf("%d", &amt_dep);
    amount += amt_dep;
    printf("money deposited\n");
        printf("your balance is %d \n", amount);
    count++;
    fprintf(f, "you have deposited : %d \n", amt_dep);
    fprintf(f, "date : %s \n", ctime(&tm));
    fclose(f);
    printf("press any key to continue \n");
    getch();
}
void withdraw_money()
{
    time_t tm;
    time(&tm);
    FILE *f = fopen("account.txt", "a");
    printf("put the amount to withdraw\n");
    scanf("%d", &amt_withdrawed);
    amount -= amt_withdrawed;
    printf("money withrawed\n");
    printf("your balance is %d \n", amount);
    count++;
    fprintf(f, "you have withdrawed : %d \n", amt_withdrawed);
    fprintf(f, "date : %s \n", ctime(&tm));
    fclose(f);
    printf("press any key to continue \n");
    getch();
}
void transfer_money()
{
    time_t tm;
    time(&tm);
    int acc_nm2;
    FILE *f = fopen("account.txt", "r");
    printf("put the amount to transfer\n");
    scanf("%d", &transfer_amt);
    printf("put the account to transfer to \n");
    scanf("%d", &acc_nm2);
    if (transfer_amt > amount)
    {
        printf("you don't have sufficient money");
    }
    else
    {
        amount -= transfer_amt;
        printf("money transered\n");
        printf("your balance is %d \n", amount);
        count++;
        fprintf(f, "you have transfered : %d from your account %d to account %d \n", transfer_amt, acc_nm, acc_nm2);
        fprintf(f, "date : %s \n", ctime(&tm));
    }
    fclose(f);
    printf("press any key to continue \n");
    getch();
}
void account_detail()
{
    FILE *f = fopen("account.txt", "a");
    printf("  *account detail*  \n");
    printf("name : %s\n", name);
    printf("account number : %d\n", acc_nm);
    printf("your current ammount : %d\n", amount);
    fclose(f);
    printf("press any key to continue \n");
    getch();
}
void transfer_detail()
{
    FILE *f = fopen("account.txt", "a");
    char c = getc(f);
    if (c == EOF)
        printf("no recent transactions \n");
    else
    {
        while (!(c == EOF))
        {
            printf("%c", c);
            c = getc(f);
        }
    }
    fclose(f);
    printf("press any key to continue \n");
    getch();
}
void last_detail()
{
    FILE *f = fopen("account.txt", "a");
    printf("  *account detail*  \n");
    printf("name : %s\n", name);
    printf("account number : %d\n" ,acc_nm);
    printf("your current ammount : %d\n", amount);
    fclose(f);
    printf("press any key to continue \n");
    getch();
} 