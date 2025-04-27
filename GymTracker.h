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


