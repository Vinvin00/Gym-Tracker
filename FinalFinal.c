#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_attempts 3          // Defining the maximum attempts possible (3) => DO WE NEED THAT?
#define MAX_LINE_LENGTH 256     // Defining the maximum line length for the csv file (256)
#define MAX_USERS 100           // Maximum number of users

// STRUCTURE
struct user {
    char name[50];
    float weight;
    float height;
    int age;
    float bench;
    float squat;
    float deadlift;
};

// GLOBAL VARIABLES
char name[50] = "";             // variable to store the name
char file_name[50];             // Buffer to store the name from the file
char line[MAX_LINE_LENGTH];
struct user users[MAX_USERS];   // Array to store user data
int user_count = 0;             // Number of users currently loaded
int invalid_attempts = 0;
int menu_choice;                // variable to store user menu choice
int height_choice;              // variable to store user height choice
int weight_choice;              // variable to store user weight choice
int age_choice;                 // variable to store user age choice
int bench_choice;               // variable to store user bench choice
int squat_choice;               // variable to store user squat choice
int deadlift_choice;            // variable to store user deadlift choice


// FUNCTION DECLARATION
void display_menu();            // function to display menu overview
void enter_name();              // function to enter name
void enter_weight();            // function for menu option 1
void enter_height();            // function for menu option 2
void enter_age();               // function for menu option 3
void enter_bench();             // function for menu option 4
void enter_squat();             // function for menu option 5
void enter_deadlift();          // function for menu option 6
void check_account(char* name); // function to check if name exists
void delete_account();          // function to delete account
void clear_input_buffer();      // function to clear the input buffer
void create_account();          // function to create account

void write_csv(const char *filename);               // Writes user data to a CSV file, where 'filename' is The name of the CSV file.
void read_csv(const char *name, const char *area);  // Reads specific user data from a CSV file, where 'name' is the user's name and 'area' the data field to retrieve (e.g., Weight, Height).
void load_csv(const char *filename);                // Loads all user data from a CSV file into memory, where 'filename' is The name of the CSV file


// MAIN FUNCTION 
int main() {
    load_csv("GymInfo.csv");     
    enter_name();               

    while (1) {
        display_menu();          

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
    return 0; 
}






    // Asks user to input weight
    printf("Please enter your weight: ");           
    while (scanf("%f", &weight) != 1) {             // Validate input
        printf("Invalid input. Please enter a valid weight: ");
        clear_input_buffer();
    }
    clear_input_buffer();

    // Asks user to input height
    printf("Please enter your height: ");           
    while (scanf("%f", &height) != 1) {             // Validate input
        printf("Invalid input. Please enter a valid height: ");
        clear_input_buffer();
    }
    clear_input_buffer();

    // Asks user to input age
    printf("Please enter your age: ");              
    while (scanf("%d", &age) != 1) {                // Validate input
        printf("Invalid input. Please enter a valid age: ");
        clear_input_buffer();
    }
    clear_input_buffer();

    float bench = -1, squat = -1, deadlift = -1;    // Initialize bench, squat, and deadlift with placeholder values, Placeholder values for skipped inputs

    // Prompt for bench
    printf("Would you like to enter your bench press now? (1 for Yes, 2 for Skip): ");  
    int choice;
    while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {                 // Validate input
        printf("Invalid input. Please enter 1 for Yes or 2 for Skip: ");
        clear_input_buffer();
    }
    clear_input_buffer();
    if (choice == 1) {
        printf("Please enter your bench press (in kg): ");
        while (scanf("%f", &bench) != 1) {                                              // Validate input
            printf("Invalid input. Please enter a valid bench press value: ");
            clear_input_buffer();
        }
        clear_input_buffer();
    } else {
        printf("You chose to skip entering your bench press. You can add it later.\n");
    }

    // Prompt for squat
    printf("Would you like to enter your squat now? (1 for Yes, 2 for Skip): ");        
    while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {                 // Validate input
        printf("Invalid input. Please enter 1 for Yes or 2 for Skip: ");
        clear_input_buffer();
    }
    clear_input_buffer();
    if (choice == 1) {
        printf("Please enter your squat (in kg): ");
        while (scanf("%f", &squat) != 1) {                                              // Validate input
            printf("Invalid input. Please enter a valid squat value: ");
            clear_input_buffer();
        }
        clear_input_buffer();
    } else {
        printf("You chose to skip entering your squat. You can add it later.\n");
    }

    // Prompt for deadlift
    printf("Would you like to enter your deadlift now? (1 for Yes, 2 for Skip): ");
    while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {                 // Validate input
        printf("Invalid input. Please enter 1 for Yes or 2 for Skip: ");
        clear_input_buffer();
    }
    clear_input_buffer();
    if (choice == 1) {
        printf("Please enter your deadlift (in kg): ");
        while (scanf("%f", &deadlift) != 1) {                                           // Validate input
            printf("Invalid input. Please enter a valid deadlift value: ");
            clear_input_buffer();
        }
        clear_input_buffer();
    } else {
        printf("You chose to skip entering your deadlift. You can add it later.\n");
    }

    // Write the data to the CSV file
    FILE *file = fopen("GymInfo.csv", "a");                                             // Open the file in append mode which is used when you want to add new data to the end of an existing file without modifying or deleting its current contents.
    if (!file) {
        perror("Failed to open the CSV file for writing");
        return;
    }

    fprintf(file, "%s;%.1f;%.1f;%d;%.1f;%.1f;%.1f\n", 
            name, weight, height, age, bench, squat, deadlift);                         // Write all data to the CSV file, using -1 for skipped values
    
            fclose(file);                                                               // close the file 
    printf("\nYour account has been successfully created and stored in the CSV file!\n");
    printf("Please press ENTER to get back to the main menu!");
    clear_input_buffer();
}




// FUNCTION TO LOAD ALL USER DATA FROM CSV FILE INTO THE USERS ARRAY
void load_csv(const char *filename) {
    FILE *file = fopen(filename, "r");                                      // Open the CSV file for reading
    if (!file) {
        perror("Failed to open CSV file");                                  // Print error message if the file cannot be opened
        return;
    }

    user_count = 0;                                                         // Reset the user count

    // Clear the `users` array to avoid leftover data
    memset(users, 0, sizeof(users));

    // Read each line from the CSV file
    while (fgets(line, sizeof(line), file)) {
        if (user_count >= MAX_USERS) {                                      // Check if the maximum user limit is reached
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

    fclose(file);                                                           // Close the file
}

