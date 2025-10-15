#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 10
#define MAX_EMAIL_LENGTH 50  // 49 chars + null terminator
#define REDUCED_EMAILS 6

// Function to read email addresses from user input
char** read_emails(int num_emails) {
    char** emails = (char**)malloc(num_emails * sizeof(char*));
    if (emails == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (int i = 0; i < num_emails; i++) {
        emails[i] = (char*)malloc(MAX_EMAIL_LENGTH * sizeof(char));
        if (emails[i] == NULL) {
            printf("Memory allocation failed for email %d!\n", i + 1);
            // Free previously allocated memory
            for (int j = 0; j < i; j++) {
                free(emails[j]);
            }
            free(emails);
            exit(1);
        }

        printf("Enter email address %d: ", i + 1);
        fgets(emails[i], MAX_EMAIL_LENGTH, stdin);
        // Remove newline character if present
        emails[i][strcspn(emails[i], "\n")] = '\0';
    }
    return emails;
}

// Function to display email addresses
void display_emails(char** emails, int num_emails) {
    printf("\nStored Email Addresses:\n");
    for (int i = 0; i < num_emails; i++) {
        printf("%d. %s\n", i + 1, emails[i]);
    }
}

// Function to shrink email array
char** shrink_email_array(char** emails, int old_size, int new_size) {
    char** new_emails = (char**)realloc(emails, new_size * sizeof(char*));
    if (new_emails == NULL) {
        printf("Memory reallocation failed!\n");
        // Keep original array if reallocation fails
        return emails;
    }
    return new_emails;
}

// Function to free allocated memory
void free_emails(char** emails, int num_emails) {
    for (int i = 0; i < num_emails; i++) {
        free(emails[i]);
    }
    free(emails);
}

int main() {
    // Allocate and read 10 email addresses
    printf("Enter %d student email addresses:\n", MAX_EMAILS);
    char** emails = read_emails(MAX_EMAILS);

    // Display original email list
    display_emails(emails, MAX_EMAILS);

    // Shrink array to 6 emails
    printf("\nShrinking cohort to %d students...\n", REDUCED_EMAILS);
    emails = shrink_email_array(emails, MAX_EMAILS, REDUCED_EMAILS);

    // Display updated email list
    display_emails(emails, REDUCED_EMAILS);

    // Free all allocated memory
    free_emails(emails, REDUCED_EMAILS);

    printf("\nMemory successfully freed.\n");
    return 0;
}
