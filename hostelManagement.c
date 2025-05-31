#include <stdio.h>
#include <string.h>

char breakfast[100];
char lunch[100];
char dinner[100];

void messproviderlogin();
void studentlogin();
void addmenu();
void viewmenu();
void submitfeedback();
void viewfeedback();
void weeklyreport();  

int main() {
    int choice;

    while (1) {
        printf("\n====== Mess Management System ======\n");
        printf("Enter 1 for Mess Provider Login\n");
        printf("Enter 2 for Student Login\n");
        printf("Enter 0 to Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            messproviderlogin();
        } else if (choice == 2) {
            studentlogin();
        } else if (choice == 0) {
            printf("Exiting system. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

  
void messproviderlogin() {
    char username[50], password[50];
    char correct_username[] = "gcoey";
    char correct_password[] = "pass123";

    printf("\n--- Mess Provider Login ---\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    if (strcmp(username, correct_username) == 0
     && strcmp(password, correct_password) == 0 ) {
        printf("Login successful!\n");

        int option;
        while (1) {
            printf("\n--- Mess Provider Menu ---\n");
            printf("1. Add Today's Menu\n");
            printf("2. View Feedback\n");
            printf("3. View Weekly Rating Report\n");
            printf("4. Logout\n");
            printf("Enter your choice: ");
            scanf("%d", &option);

            if (option == 1)
                addmenu();
            else if (option == 2)
                viewfeedback();
            else if (option == 3)
                weeklyreport();  
            else if (option == 4)
                break;
            else
                printf("Invalid option. Try again.\n");
        }
    } }

void addmenu() {
    printf("\nEnter today's Breakfast: ");
    scanf(" %[^\n]", breakfast);
    printf("Enter today's Lunch: ");
    scanf(" %[^\n]", lunch);
    printf("Enter today's Dinner: ");
    scanf(" %[^\n]", dinner);

    FILE *fp = fopen("menu.txt", "w");
    if (fp != NULL) {
        fprintf(fp, "%s\n%s\n%s\n", breakfast, lunch, dinner);
        fclose(fp);
        printf("Menu saved successfully!\n");
    } else {
        printf("Error saving menu.\n");
    }
}


void studentlogin() {
    char name[50];
    printf("\nEnter your name: ");
    scanf("%s", name);

    int option;
    while (1) {
        printf("\n--- Student Menu ---\n");
        printf("1. View Today's Menu\n");
        printf("2. Submit Feedback\n");
        printf("3. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        if (option == 1)
            viewmenu();
        else if (option == 2)
            submitfeedback();
        else if (option == 3)
            break;
        else
            printf("Invalid option. Try again.\n");
    }
}


void viewmenu() {
    FILE *fp = fopen("menu.txt", "r");
    if (fp != NULL) {
        fgets(breakfast, sizeof(breakfast), fp);
        fgets(lunch, sizeof(lunch), fp);
        fgets(dinner, sizeof(dinner), fp);
        fclose(fp);

        printf("\n--- Today's Menu ---\n");
        printf("Breakfast: %s", breakfast);
        printf("Lunch: %s", lunch);
        printf("Dinner: %s", dinner);
    } else {
        printf("No menu added yet.\n");
    }
}


void submitfeedback() {
    int rating;
    char complaint[200];

    printf("\n--- Submit Feedback ---\n");
    printf("Rate the mess service:\n");
    printf("1. Very Good\n");
    printf("2. Good\n");
    printf("3. Bad\n");
    printf("4. Very Bad\n");
    printf("Enter your rating (1-4): ");
    scanf("%d", &rating);

    printf("Any complaint? (type 'none' if no complaint): ");
    scanf(" %[^\n]", complaint);

    FILE *fp = fopen("feedback.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "%d,%s\n", rating, complaint);  
        fclose(fp);
        printf("Feedback submitted successfully!\n");
    } else {
        printf("Error saving feedback.\n");
    }
}


void viewfeedback() {
    char line[256];
    FILE *fp = fopen("feedback.txt", "r");

    printf("\n--- Feedback Received ---\n");

    if (fp != NULL) {
        while (fgets(line, sizeof(line), fp)) {
            printf("%s", line);
        }
        fclose(fp);
    } else {
        printf("No feedback available yet.\n");
    }
}


void weeklyreport() {
    FILE *fp = fopen("feedback.txt", "r");
    if (fp == NULL) {
        printf("No feedback available to generate report.\n");
        return;
    }

    int rating;
    char complaint[200];
    int very_good = 0, good = 0, bad = 0, very_bad = 0, total = 0;

    while (fscanf(fp, "%d,%[^\n]\n", &rating, complaint) != EOF) {
        switch (rating) {
            case 1: very_good++; break;
            case 2: good++; break;
            case 3: bad++; break;
            case 4: very_bad++; break;
            default: break;
        }
        total++;
    }

    fclose(fp);

    printf("\n--- Weekly Rating Report ---\n");
    printf("Total Feedbacks: %d\n", total);
    printf("Very Good: %d\n", very_good);
    printf("Good: %d\n", good);
    printf("Bad: %d\n", bad);
    printf("Very Bad: %d\n", very_bad);
}
