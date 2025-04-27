// GymTracker.h

#ifndef GYMTRACKER_H
#define GYMTRACKER_H

// Preprocessor directives
#define MAX_ATTEMPTS 3         // Maximum login attempts allowed
#define MAX_LINE_LENGTH 256    // Maximum line length for reading the CSV file
#define MAX_USERS 100          // Maximum number of users

// Global Variables (Characters)
extern char name[50];           // Variable to store user name
extern char file_name[50];      // Buffer to store the name of the CSV file
extern char line[MAX_LINE_LENGTH];

// Structure Definition
typedef struct user {
    char name[50];
    float weight;
    float height;
    int age;
    float bench;
    float squat;
    float deadlift;
} User;

// Global Variables (Data)
extern User users[MAX_USERS];   // Array to store user data
extern int user_count;          // Number of users currently loaded
extern int invalid_attempts;    // Number of invalid login attempts

// Global Variables (Menu Choices)
extern int menu_choice;         // User menu choice
extern int height_choice;       // User height input
extern int weight_choice;       // User weight input
extern int age_choice;          // User age input
extern int bench_choice;        // User bench press input
extern int squat_choice;        // User squat input
extern int deadlift_choice;     // User deadlift input

// Function Declarations
void display_menu();                  // Display the main menu
void enter_name();                    // Enter user's name
void enter_weight();                  // Enter user's weight
void enter_height();                  // Enter user's height
void enter_age();                     // Enter user's age
void enter_bench();                   // Enter user's bench press record
void enter_squat();                   // Enter user's squat record
void enter_deadlift();                // Enter user's deadlift record
void check_account(char *name);        // Check if a user account exists
void delete_account();                // Delete a user account
void write_csv(const char *filename);   // Write user data to CSV file
void clear_input_buffer();             // Clear leftover input
void create_account();                // Create a new user account
void create_newaccount();             // (Possibly same as create_account? clarify)
void read_csv(const char *name, const char *area); // Read specific field from CSV
void load_csv(const char *filename);   // Load all users from CSV into memory

#endif // GYMTRACKER_H
