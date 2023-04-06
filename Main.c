#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    int acc_no;
    char name[100];
    float balance;
};

void create_account(struct account acc);
void deposit(struct account acc);
void withdraw(struct account acc);
void display(struct account acc);

int main() {
    int choice;
    struct account acc;
    printf("Welcome to Bank Management System\n");
    printf("1. Create Account\n");
    printf("2. Deposit Amount\n");
    printf("3. Withdraw Amount\n");
    printf("4. Display Account Details\n");
    printf("5. Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_account(acc);
                break;
            case 2:
                deposit(acc);
                break;
            case 3:
                withdraw(acc);
                break;
            case 4:
                display(acc);
                break;
            case 5:
                printf("Thank you for using Bank Management System\n");
                break;
            default:
                printf("Invalid Choice! Please enter a valid choice.\n");
        }
    } while (choice != 5);
    return 0;
}

void create_account(struct account acc) {
    printf("Enter Account Number: ");
    scanf("%d", &acc.acc_no);
    printf("Enter Name: ");
    scanf("%s", &acc.name);
    printf("Enter Initial Balance: ");
    scanf("%f", &acc.balance);
    printf("Account Created Successfully\n");
}

void deposit(struct account acc) {
    float amount;
    printf("Enter Account Number: ");
    scanf("%d", &acc.acc_no);
    printf("Enter Amount to be Deposited: ");
    scanf("%f", &amount);
    acc.balance += amount;
    printf("Amount Deposited Successfully\n");
}

void withdraw(struct account acc) {
    float amount;
    printf("Enter Account Number: ");
    scanf("%d", &acc.acc_no);
    printf("Enter Amount to be Withdrawn: ");
    scanf("%f", &amount);
    if (amount > acc.balance) {
        printf("Insufficient Balance\n");
    } else {
        acc.balance -= amount;
        printf("Amount Withdrawn Successfully\n");
    }
}

void display(struct account acc) {
    printf("Account Number: %d\n", acc.acc_no);
    printf("Name: %s\n", acc.name);
    printf("Balance: %.2f\n", acc.balance);
}
