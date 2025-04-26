#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_attempts 3          // defining the maximum attempts possible (3) => DO WE NEED THAT?
#define MAX_LINE_LENGTH 256     // defining the maximum line length for the csv file (256)
#define MAX_USERS 100  // Maximum number of users

//Global Variables (Characters)
char name[50] = "";             // variable to store the first name
char file_name[50];  // Buffer to store the name from the file
char line[MAX_LINE_LENGTH];

struct user {
    char name[50];
    float weight;
    float height;
    int age;
    float bench;
    float squat;
    float deadlift;
};

struct user users[MAX_USERS];  // Array to store user data
int user_count = 0;            // Number of users currently loaded


// Global Variables (Integers)
int invalid_attempts = 0;
int menu_choice;                // variable to store user menu choice
int height_choice;              // variable to store user height choice
int weight_choice;              // variable to store user weight choice
int age_choice;                 // variable to store user age choice
int bench_choice;               // variable to store user bench choice
int squat_choice;               // variable to store user squat choice
int deadlift_choice;            // variable to store user deadlift choice
//int check = 0; //             // variable to flag if the user is inside the

//Functions
void display_menu();        // function to display menu overview
void enter_name();         // function to enter name
void enter_weight();        // function for menu option 1
void enter_height();        // function for menu option 2
void enter_age();           // function for menu option 3
void enter_bench();         // function for menu option 4
void enter_squat();         // function for menu option 5
void enter_deadlift();      // function for menu option 6
void check_account(char* name);  // function to check if name exists
void delete_account();
void write_csv(const char *filename);
void clear_input_buffer();  // function to clear the input buffer
void create_account();      // function to create account
void create_newaccount();
void read_csv (const char *name, const char *area);
void load_csv(const char *filename);

// Main Function
int main() {
    load_csv("GymInfo.csv");
    enter_name();            // enter name to check if youre in the data base

    while (1) {
        display_menu();          // display menu

    switch (menu_choice) {
        case 1:
            enter_weight();
            break;

        case 2:
            enter_height();
            break;

        case 3:
            enter_age();
            break;

        case 4:
            enter_bench();
            break;

        case 5:
            enter_squat();
            break;

        case 6:
            enter_deadlift();
            break;

        case 7:
            delete_account();
            break;

        case 8:
            printf("-----------------------------\n");
            printf("\nYou chose option 8!\n\nIt's a shame you don't want to continue!\nGoodbye.\n\nThis program terminates here :( \n\n");
            return 0;

        default:
            invalid_attempts++;
            printf("\n-----------------------------\n");
            printf("\nThis is not a valid option.\n");
            printf("So far you have entered %d invalid option(s).\n", invalid_attempts);
            clear_input_buffer();

            if (invalid_attempts >= max_attempts) { // Checking whether its more than 3 attempts
                printf("\nYou don't seem too interested in speaking with me...\nGoodbye!\n\n");
                return 0;
            } else {
                printf("\nPlease press ENTER to try again!\n");
                clear_input_buffer();
                enter_name();
            }
        }
    }
    return 0; //WHY?
}




// FUNTION TO ENTER NAME TO SEE IF YOURE IN THE DATA BASE
void enter_name(void) {
    printf("\n-----------------------------\n");
    printf("\nHello You!\nWelcome to this Gym Tracker! \n\nPlease enter your name so we can see if you're already in our data bank!\n\n");
    printf("Name: ");
    fgets(name, sizeof(name), stdin); // scans for the user input of the first name
    name[strcspn(name, "\n")] = '\0'; // Remove the newline character from the input
    printf("\n-----------------------------\n");
    printf("\nYou entered the name: %s\n", name); // scans for the user's first name input and displays it here if the user entered it
    check_account(name);
}



// FUNCTION TO CHECK IF NAME IS IN THE DATABASE
void check_account(char* name) {
    FILE* file = fopen("GymInfo.csv", "r");  // Open the CSV file for reading
    if (file == NULL) {
        perror("Failed to open file"); // Print error message
        return;
    }

    char line[MAX_LINE_LENGTH];
    int found = 0;

    // Read each line from the CSV
    while (fgets(line, sizeof(line), file)) {

        // Extract the name from the current line (assumes names are the first field in the CSV)
        sscanf(line, "%49[^;]", file_name);  // Read up to the first semicolon (;)

        // Check if the entered name matches the name in the file
        if (strcmp(name, file_name) == 0) {
            found = 1;
            break;
        }
    }

    fclose(file);  // Close the file

    if (found) {
        printf("\n-----------------------------\n");
        printf("\nWelcome back, %s!\n", name);
        printf("You already have an account. Press ENTER to get started!");
        clear_input_buffer();
    } else {
        printf("\n-----------------------------\n");
        printf("It seems you don't have an account yet.\n");
        printf("Would you like to create an account?\n");
        printf("\nEnter 1 to create an account or 2 to exit: ");

        int choice;
        scanf("%d", &choice);
        clear_input_buffer();

        if (choice == 1) {
            printf("\nGreat! Let's create your account.\n");
            create_account();  // Call the function to create a new account
        } else if (choice == 2) {
            printf("\nThank you for visiting! Goodbye.\n");
            exit(0);  // Exit the program
        } else {
            printf("\nInvalid choice. Returning to the main menu.\n");
            display_menu();  // Redirect to the main menu
        }
    }
}

// FUNCTION TO CREATE NEW ACCOUNT
void create_account() {
    char name[50];
    printf("Please enter your first name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove the newline character from the input

    // Check if the name is empty
    if (strlen(name) == 0) {
        printf("Name cannot be empty. Please try again.\n");
        return;
    }

    printf("Please enter your weight: ");
    float weight;
    while (scanf("%f", &weight) != 1) {  // Validate input
        printf("Invalid input. Please enter a valid weight: ");
        clear_input_buffer();
    }
    clear_input_buffer();

    printf("Please enter your height: ");
    float height;
    while (scanf("%f", &height) != 1) {  // Validate input
        printf("Invalid input. Please enter a valid height: ");
        clear_input_buffer();
    }
    clear_input_buffer();

    printf("Please enter your age: ");
    int age;
    while (scanf("%d", &age) != 1) {  // Validate input
        printf("Invalid input. Please enter a valid age: ");
        clear_input_buffer();
    }
    clear_input_buffer();

    // Initialize bench, squat, and deadlift with placeholder values
    float bench = -1, squat = -1, deadlift = -1;  // Placeholder values for skipped inputs

    // Prompt for bench
    printf("Would you like to enter your bench press now? (1 for Yes, 2 for Skip): ");
    int choice;
    while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {  // Validate input
        printf("Invalid input. Please enter 1 for Yes or 2 for Skip: ");
        clear_input_buffer();
    }
    clear_input_buffer();
    if (choice == 1) {
        printf("Please enter your bench press (in kg): ");
        while (scanf("%f", &bench) != 1) {  // Validate input
            printf("Invalid input. Please enter a valid bench press value: ");
            clear_input_buffer();
        }
        clear_input_buffer();
    } else {
        printf("You chose to skip entering your bench press. You can add it later.\n");
    }

    // Prompt for squat
    printf("Would you like to enter your squat now? (1 for Yes, 2 for Skip): ");
    while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {  // Validate input
        printf("Invalid input. Please enter 1 for Yes or 2 for Skip: ");
        clear_input_buffer();
    }
    clear_input_buffer();
    if (choice == 1) {
        printf("Please enter your squat (in kg): ");
        while (scanf("%f", &squat) != 1) {  // Validate input
            printf("Invalid input. Please enter a valid squat value: ");
            clear_input_buffer();
        }
        clear_input_buffer();
    } else {
        printf("You chose to skip entering your squat. You can add it later.\n");
    }

    // Prompt for deadlift
    printf("Would you like to enter your deadlift now? (1 for Yes, 2 for Skip): ");
    while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {  // Validate input
        printf("Invalid input. Please enter 1 for Yes or 2 for Skip: ");
        clear_input_buffer();
    }
    clear_input_buffer();
    if (choice == 1) {
        printf("Please enter your deadlift (in kg): ");
        while (scanf("%f", &deadlift) != 1) {  // Validate input
            printf("Invalid input. Please enter a valid deadlift value: ");
            clear_input_buffer();
        }
        clear_input_buffer();
    } else {
        printf("You chose to skip entering your deadlift. You can add it later.\n");
    }

    // Write the data to the CSV file
    FILE *file = fopen("GymInfo.csv", "a");  // Open the file in append mode
    if (!file) {
        perror("Failed to open the CSV file for writing");
        return;
    }

    // Write all data to the CSV file, using -1 for skipped values
    fprintf(file, "%s;%.1f;%.1f;%d;%.1f;%.1f;%.1f\n", name, weight, height, age, bench, squat, deadlift);
    fclose(file);

    printf("\nYour account has been successfully created and stored in the CSV file!\n");
    printf("Please press ENTER to get back to the main menu!");
    clear_input_buffer();
}

// FUNCTION TO CLEAR INPUT BUFFER
void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// FUNCTION TO PRINT OUT THE MENU
void display_menu(void){
    printf("\n-----------------------------\n"); // soley for visual purpose, to make it more visually appealing
    printf("\nPlease choose one of the following options:\n\n");
    printf("Option 1: Enter your weight\n");
    printf("Option 2: Enter your height\n");
    printf("Option 3: Enter your age\n");
    printf("Option 4: Access your 'bench' tracker \n");
    printf("Option 5: Access your 'squat' tracker \n");
    printf("Option 6: Access your 'deadlift' tracker \n");
    printf("Option 7: Delete existing account\n");
    printf("Option 8: Exit the menu\n");
    printf("\nPlease enter your choice: ");
    scanf(" %d", &menu_choice); // scans for the user input of the menu choice
}

// OPTION 1 - FUNCTION TO ENTER WEIGHT
void enter_weight() {
    float new_weight;
    printf("\n-----------------------------\n");
    printf("\nYou chose Option 1: 'Enter Weight'\n\n");
    printf("Please choose from the following options: \n");
    printf("1 - View your current weight\n");
    printf("2 - Change your current weight\n");
    printf("3 - Return to the main menu\n");
    printf("\nPlease enter your desired option: \n");
    scanf(" %d", &weight_choice); // scans for the user input
    clear_input_buffer();

    switch (weight_choice) {
        case 1:
            printf("\nYou chose Option 1: 'View your current weight'\n");
            read_csv(name, "Weight");
            clear_input_buffer();
            break;

        case 2:
            printf("\nYou chose Option 2: 'Change your current weight'\n\n");
            printf("Please enter your new weight:\n");
            scanf("%f", &new_weight);
            clear_input_buffer();

            // Update the user's weight in the `users` array
            for (int i = 0; i < user_count; i++) {
                if (strcmp(users[i].name, name) == 0) {
                    users[i].weight = new_weight;
                    break;
                }
            }

            // Save the updated data to the CSV file
            write_csv("GymInfo.csv");

            printf("\n\nNice! Your new weight has been recorded!");
            printf("\nPress ENTER to get back to the menu overview.\n");
            clear_input_buffer();
            break;

        case 3:
            printf("\nYou chose Option 3: 'Return to the main menu'\n");
            printf("\nFeel free to come back if you change your mind!\nUntil then, press ENTER to get back to the menu overview.\n");
            clear_input_buffer();
            break;

        default:
            printf("\nYou did not choose one of the valid options. Please press ENTER to get back to the main overview\n");
            clear_input_buffer();
            break;
    }
}


// OPTION 2 - FUNCTION TO ENTER HEIGHT
void enter_height() {
    float new_height;
    printf("\n-----------------------------\n");
    printf("\nYou chose Option 2: 'Enter Height'\n\n");
    printf("Please choose from the following options: \n");
    printf("1 - View your current height\n");
    printf("2 - Change your current height\n");
    printf("3 - Return to the main menu\n");
    printf("\nPlease enter your desired option: \n");
    scanf(" %d", &height_choice);
    clear_input_buffer();

    switch (height_choice) {
        case 1:
            printf("\nYou chose Option 1: 'View your current height'\n");
            read_csv(name, "Height");
            clear_input_buffer();
            break;

        case 2:
            printf("\nYou chose Option 2: 'Change your current height'\n");
            printf("Please enter your new height! (in cm)\n");
            scanf("%f", &new_height);
            clear_input_buffer();

            // Update the user's height in the `users` array
            for (int i = 0; i < user_count; i++) {
                if (strcmp(users[i].name, name) == 0) {
                    users[i].height = new_height;
                    break;
                }
            }

            // Save the updated data to the CSV file
            write_csv("GymInfo.csv");

            printf("\nNice! Your new height has been recorded!");
            printf("\nPress ENTER to get back to the menu overview.\n");
            clear_input_buffer();
            break;

        case 3:
            printf("\nYou chose Option 3: 'Return to the main menu'\n");
            printf("\nFeel free to come back if you change your mind!\nUntil then, press ENTER to get back to the menu overview.\n");
            clear_input_buffer();
            break;

        default:
            printf("\nYou did not choose one of the valid options. Please press ENTER to get back to the main overview\n");
            clear_input_buffer();
            break;
    }
}

// OPTION 3 - FUNCTION TO ENTER AGE
void enter_age() {
    int new_age; // int because age can't be a decimal
    printf("\n-----------------------------\n");
    printf("\nYou chose Option 3: 'Enter Age'\n\n");
    printf("Please choose from the following options: \n");
    printf("1 - View your current age\n");
    printf("2 - Change your current age\n");
    printf("3 - Return to the main menu\n");
    printf("\nPlease enter your desired option: \n");
    scanf(" %d", &age_choice); // scans for the user input of the age
    clear_input_buffer();

    switch (age_choice) {
        case 1:
            printf("\nYou chose Option 1: 'View your current age'\n");
            read_csv(name, "Age");
            clear_input_buffer();
            break;

        case 2:
            printf("\nYou chose Option 2: 'Change your current age'\n");
            printf("Please enter your new age:\n");
            scanf("%d", &new_age);
            clear_input_buffer();

            // Update the user's age in the `users` array
            for (int i = 0; i < user_count; i++) {
                if (strcmp(users[i].name, name) == 0) {
                    users[i].age = new_age;
                    break;
                }
            }

            // Save the updated data to the CSV file
            write_csv("GymInfo.csv");

            printf("\nNice! Your new age has been recorded!");
            printf("\nPress ENTER to get back to the menu overview.\n");
            clear_input_buffer();
            break;

        case 3:
            printf("\nYou chose Option 3: 'Return to the main menu'\n");
            printf("\nFeel free to come back if you change your mind!\nUntil then, press ENTER to get back to the menu overview.\n");
            clear_input_buffer();
            break;

        default:
            printf("\nYou did not choose one of the valid options. Please press ENTER to get back to the main overview\n");
            clear_input_buffer();
            break;
    }
}

// OPTION 4 - FUNCTION TO ENTER BENCH
void enter_bench() {
    float new_bench;
    printf("\n-----------------------------\n");
    printf("\nYou chose Option 4: 'Enter Bench'\n\n");
    printf("Please choose from the following options: \n");
    printf("1 - View your current bench\n");
    printf("2 - Change your current bench\n");
    printf("3 - Return to the main menu\n");
    printf("\nPlease enter your desired option: \n");
    scanf(" %d", &bench_choice); // scans for the user input of 'bench'
    clear_input_buffer();

    switch (bench_choice) {
        case 1:
            printf("\nYou chose Option 1: 'View your current bench'\n");
            read_csv(name, "Bench");
            clear_input_buffer();
            break;

        case 2:
            printf("\nYou chose Option 2: 'Change your current bench'\n");
            printf("Please enter your new bench (in kg):\n");
            scanf("%f", &new_bench);
            clear_input_buffer();

            // Update the user's bench in the `users` array
            for (int i = 0; i < user_count; i++) {
                if (strcmp(users[i].name, name) == 0) {
                    users[i].bench = new_bench;
                    break;
                }
            }

            // Save the updated data to the CSV file
            write_csv("GymInfo.csv");

            printf("\nNice! Your new bench has been recorded!");
            printf("\nPress ENTER to get back to the menu overview.\n");
            clear_input_buffer();
            break;

        case 3:
            printf("\nYou chose Option 3: 'Return to the main menu'\n");
            printf("\nFeel free to come back if you change your mind!\nUntil then, press ENTER to get back to the menu overview.\n");
            clear_input_buffer();
            break;

        default:
            printf("\nYou did not choose one of the valid options. Please press ENTER to get back to the main overview\n");
            clear_input_buffer();
            break;
    }
}

// OPTION 5 - FUNCTION TO ENTER SQUAT
void enter_squat() {
    float new_squat;
    printf("\n-----------------------------\n");
    printf("\nYou chose Option 5: 'Enter Squat'\n\n");
    printf("Please choose from the following options: \n");
    printf("1 - View your current squat\n");
    printf("2 - Change your current squat\n");
    printf("3 - Return to the main menu\n");
    printf("\nPlease enter your desired option: \n");
    scanf(" %d", &squat_choice); // scans for the user input
    clear_input_buffer();

    switch (squat_choice) {
        case 1:
            printf("\nYou chose Option 1: 'View your current squat'\n");
            read_csv(name, "Squat");
            clear_input_buffer();
            break;

        case 2:
            printf("\nYou chose Option 2: 'Change your current squat'\n");
            printf("Please enter your new squat (in kg):\n");
            scanf("%f", &new_squat);
            clear_input_buffer();

            // Update the user's squat in the `users` array
            for (int i = 0; i < user_count; i++) {
                if (strcmp(users[i].name, name) == 0) {
                    users[i].squat = new_squat;
                    break;
                }
            }

            // Save the updated data to the CSV file
            write_csv("GymInfo.csv");

            printf("\nNice! Your new squat has been recorded!");
            printf("\nPress ENTER to get back to the menu overview.\n");
            clear_input_buffer();
            break;

        case 3:
            printf("\nYou chose Option 3: 'Return to the main menu'\n");
            printf("\nFeel free to come back if you change your mind!\nUntil then, press ENTER to get back to the menu overview.\n");
            clear_input_buffer();
            break;

        default:
            printf("\nYou did not choose one of the valid options. Please press ENTER to get back to the main overview\n");
            clear_input_buffer();
            break;
    }
}

// OPTION 6 - FUNCTION TO ENTER DEADLIFT
void enter_deadlift() {
    float new_dl;
    printf("\n-----------------------------\n");
    printf("\nYou chose Option 6: 'Enter Deadlift'\n\n");
    printf("Please choose from the following options: \n");
    printf("1 - View your current deadlift\n");
    printf("2 - Change your current deadlift\n");
    printf("3 - Return to the main menu\n");
    printf("\nPlease enter your desired option: \n");
    scanf(" %d", &deadlift_choice); // scans for the user input
    clear_input_buffer();

    switch (deadlift_choice) {
        case 1:
            printf("\nYou chose Option 1: 'View your current deadlift'\n");
            read_csv(name, "Deadlift");
            clear_input_buffer();
            break;

        case 2:
            printf("\nYou chose Option 2: 'Change your current deadlift'\n");
            printf("Please enter your new deadlift (in kg):\n");
            scanf("%f", &new_dl);
            clear_input_buffer();

            // Update the user's deadlift in the `users` array
            for (int i = 0; i < user_count; i++) {
                if (strcmp(users[i].name, name) == 0) {
                    users[i].deadlift = new_dl;
                    break;
                }
            }

            // Save the updated data to the CSV file
            write_csv("GymInfo.csv");

            printf("\nNice! Your new deadlift has been recorded!");
            printf("\nPress ENTER to get back to the menu overview.\n");
            clear_input_buffer();
            break;

        case 3:
            printf("\nYou chose Option 3: 'Return to the main menu'\n");
            printf("\nFeel free to come back if you change your mind!\nUntil then, press ENTER to get back to the menu overview.\n");
            clear_input_buffer();
            break;

        default:
            printf("\nYou did not choose one of the valid options. Please press ENTER to get back to the main overview\n");
            clear_input_buffer();
            break;
    }
}



//OPTION 7 - DELETE ACCOUNT
void delete_account() {
    char delete_name[50];
    printf("\n-----------------------------\n");
    printf("Enter the name of the account you want to delete: ");
    clear_input_buffer();
    fgets(delete_name, sizeof(delete_name), stdin);
    delete_name[strcspn(delete_name, "\n")] = '\0';  // Remove the newline character

    // Trim leading and trailing whitespace from the input name
    char *start = delete_name;
    while (*start == ' ') start++;  // Skip leading spaces
    char *end = start + strlen(start) - 1;
    while (end > start && (*end == ' ' || *end == '\n')) *end-- = '\0';  // Remove trailing spaces
    memmove(delete_name, start, end - start + 2);  // Shift the trimmed string to the beginning

    int found = 0;

    // Search for the user in the `users` array
    for (int i = 0; i < user_count; i++) {
        if (strcasecmp(users[i].name, delete_name) == 0) {  // Case-insensitive comparison
            found = 1;

            // Shift all subsequent users one position to the left
            for (int j = i; j < user_count - 1; j++) {
                users[j] = users[j + 1];
            }

            user_count--;  // Decrease the user count
            break;
        }
    }

    if (found) {
        // Save the updated data to the CSV file
        write_csv("GymInfo.csv");
        printf("\nThe account for '%s' has been successfully deleted.\n", delete_name);
    } else {
        printf("\nSorry, no account with the name '%s' was found.\n", delete_name);
        printf("Please press ENTER to get back to the main overview\n");
        clear_input_buffer();
    }
}



//FUNCTION TO WRITE IN CSV FILE
void write_csv(const char *filename) {
    FILE *file = fopen(filename, "w");  // Open the file for writing
    if (!file) {
        perror("Failed to open CSV file for writing");
        return;
    }

    // Write all users to the CSV file
    for (int i = 0; i < user_count; i++) {
        fprintf(file, "%s;%.1f;%.1f;%d;%.1f;%.1f;%.1f\n", users[i].name, users[i].weight, users[i].height,
                users[i].age, users[i].bench, users[i].squat, users[i].deadlift);
    }

    fclose(file);  // Close the file
}


// FUNCTION TO READ FROM THE CSV FILE
void read_csv(const char *name, const char *area) {
    FILE *file = fopen("GymInfo.csv", "r");  // Open the CSV file for reading
    if (!file) {
        perror("Failed to open CSV file");
        return;
    }

    char file_name[50];
    int found = 0;

    // Read each line from the CSV file
    while (fgets(line, sizeof(line), file)) {
        // Extract the name from the current line (assumes names are the first field in the CSV)
        sscanf(line, "%49[^;]", file_name);  // Read up to the first semicolon (;)

        // Check if the entered name matches the name in the file
        if (strcmp(name, file_name) == 0) {
            found = 1;

            // Parse the rest of the line into a temporary user struct
            struct user temp_user;
            sscanf(line, "%49[^;];%f;%f;%d;%f;%f;%f",
                   temp_user.name,
                   &temp_user.weight,
                   &temp_user.height,
                   &temp_user.age,
                   &temp_user.bench,
                   &temp_user.squat,
                   &temp_user.deadlift);

            // Check which area to display
            if (strcmp(area, "Weight") == 0)
                printf("Your current weight is: %.1f kg\n", temp_user.weight);
            else if (strcmp(area, "Height") == 0)
                printf("Your current height is: %.1f cm\n", temp_user.height);
            else if (strcmp(area, "Age") == 0)
                printf("Your age is: %d\n", temp_user.age);
            else if (strcmp(area, "Bench") == 0)
                printf("Your bench press is: %.1f kg\n", temp_user.bench);
            else if (strcmp(area, "Squat") == 0)
                printf("Your squat is: %.1f kg\n", temp_user.squat);
            else if (strcmp(area, "Deadlift") == 0)
                printf("Your deadlift is: %.1f kg\n", temp_user.deadlift);
            else
                printf("Unknown area: %s\n", area);

            break;  // Exit the loop once the user is found
        }
    }

    fclose(file);  // Close the file

    // If no user was found, display an error message
    if (!found) {
        printf("Sorry, no user with the name \"%s\" was found.\n", name);
        printf("\nWould you like to create a new account?\n");
        printf("\nEnter 1 to create an account or 2 to exit: ");

        int choice;
        scanf("%d", %choice);
        clear_input_buffer();

        if (choice == 1) {
            printf("\nGreat! Let's create your account.\n");
            create_account(); //Call the function to create a new account
        } else if (choice == 2) {
            printf("\nThank you for visiting! Goodbye.\n");
            exit(0); //exit the program
        } else {
            printf("\nInvalid choice. Returning to the main menu.\n");
            display_menu(); //Redirect to the main menu
        }
    }
}

// FUNCTION TO LOAD ALL USER DATA FROM CSV FILE INTO THE USERS ARRAY
void load_csv(const char *filename) {
    FILE *file = fopen(filename, "r");  // Open the CSV file for reading
    if (!file) {
        perror("Failed to open CSV file");
        return;
    }

    user_count = 0;

    // Clear the `users` array to avoid leftover data
    memset(users, 0, sizeof(users));

    // Read each line from the CSV file
    while (fgets(line, sizeof(line), file)) {
        if (user_count >= MAX_USERS) {
            printf("Maximum user limit reached. Cannot load more users.\n");
            break;
        }

        // Parse the line and populate the `users` array
        int fields_read = sscanf(line, "%49[^;];%f;%f;%d;%f;%f;%f",
                                 users[user_count].name,
                                 &users[user_count].weight,
                                 &users[user_count].height,
                                 &users[user_count].age,
                                 &users[user_count].bench,
                                 &users[user_count].squat,
                                 &users[user_count].deadlift);

        // Ensure all fields were successfully read
        if (fields_read == 7) {
            user_count++;
        } else {
            printf("Warning: Malformed line in CSV file: %s", line);
        }
    }

    fclose(file);  // Close the file
}
