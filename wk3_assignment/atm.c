#include <stdio.h>

/**
 * check_balance - Prints the current account balance
 * @balance: The current balance
 *
 * Return: Nothing
 */
void check_balance(double balance)
{
	printf("Current balance: $%.2f\n", balance);
}

/**
 * deposit - Adds money to the account balance
 * @balance: Pointer to the current balance
 *
 * Return: Nothing
 */
void deposit(double *balance)
{
	double amount;

	printf("Enter amount to deposit: $");
	scanf("%lf", &amount);

	if (amount > 0)
	{
		*balance += amount;
		printf("Deposited $%.2f. New balance: $%.2f\n", amount, *balance);
	}
	else
	{
		printf("Invalid deposit amount.\n");
	}
}

/**
 * withdraw - Subtracts money from the account balance
 * @balance: Pointer to the current balance
 *
 * Return: Nothing
 */
void withdraw(double *balance)
{
	double amount;

	printf("Enter amount to withdraw: $");
	scanf("%lf", &amount);

	if (amount > 0 && amount <= *balance)
	{
		*balance -= amount;
		printf("Withdrew $%.2f. New balance: $%.2f\n", amount, *balance);
	}
	else if (amount > *balance)
	{
		printf("Insufficient funds.\n");
	}
	else
	{
		printf("Invalid withdrawal amount.\n");
	}
}

/**
 * display_menu - Displays the ATM options
 *
 * Return: Nothing
 */
void display_menu(void)
{
	printf("\n=== ATM Menu ===\n");
	printf("1. Check Balance\n");
	printf("2. Deposit\n");
	printf("3. Withdraw\n");
	printf("4. Exit\n");
	printf("Enter your choice (1-4): ");
}

/**
 * main - Entry point of the ATM program
 *
 * Return: Always 0
 */
int main(void)
{
	double balance = 1000.0;
	int choice;

	while (1)
	{
		display_menu();
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				check_balance(balance);
				break;
			case 2:
				deposit(&balance);
				break;
			case 3:
				withdraw(&balance);
				break;
			case 4:
				printf("Thank you for using the ATM. Goodbye!\n");
				return (0);
			default:
				printf("Invalid choice. Please try again.\n");
		}
	}
}
