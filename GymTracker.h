// gymtracker.h

#ifndef GYMTRACKER_H
#define GYMTRACKER_H

// Preprocessor directives

#define MAX_ATTEMPTS 3         // Maximum number of login attempts
#define MAX_LINE_LENGTH 256    // Maximum line length for the CSV file
#define MAX_USERS 100          // Maximum number of users

// Structure
typedef struct {
    char name[50];
    float weight;
    float height;
    int age;
    float bench;
    float squat;
    float deadlift;
} User;

// Global variable declarations
extern char name[50];
extern char file_name[50];
extern char line[MAX_LINE_LENGTH];
extern User users[MAX_USERS];
extern int user_count;
extern int invalid_attempts;
extern int menu_choice;
extern int height_choice;
extern int weight_choice;
extern int age_choice;
extern int bench_choice;
extern int squat_choice;
extern int deadlift_choice;

// Function declarations (add your real functions here)
void loadUsersFromFile(const char *filename);
void saveUsersToFile(const char *filename);
void addUser(User new_user);
void printAllUsers(void);



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


#endif // GYMTRACKER_H
