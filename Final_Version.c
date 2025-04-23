#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_attempts 3          // defining the maximum attempts possible (3) => DO WE NEED THAT? 
#define MAX_LINE_LENGTH 256     // defining the maximum line length for the csv file (256)

//Global Variables (Characters)
char name[50] = "";             // variable to store the first name

// Global Variables (Integers)
int invalid_attempts = 0;
int menu_choice;                // variable to store user menu choice
int height_choice;              // variable to store user height choice
int weight_choice;              // variable to store user weight choice
int age_choice;                 // variable to store user age choice
int bench_choice;               // variable to store user bench choice
int squat_choice;               // variable to store user squat choice
int deadlift_choice;            // variable to store user deadlift choice

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
void write_csv(const char *filename, const char *area, int value);
void clear_input_buffer();  // function to clear the input buffer
void create_account();      // function to create account 
void read_csv (const char *filename, const char *area);
 
// Main Function 
int main() {

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
            printf("-----------------------------\n");
            printf("\nYou chose option 7!\n\nIt's a shame you don't want to continue!\nGoodbye.\n\nThis program terminates here :( \n\n");
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
void enter_name(void){ 
    printf("\n-----------------------------\n");
    printf("\nHello You!\nWelcome to this Gym Tracker! \n\nPlease enter your name so we can see if you're already in out data bank!\n\n");
    printf("Name: ");
    fgets(name, sizeof(name), stdin); // scans for the user input of the first name 
    printf("\n-----------------------------\n");
    printf("\nYou entered the name: %s\n", name); // scans for the users first name input and display it here if user entered it 
    check_account(name); 
    clear_input_buffer();
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
        char file_name[50];  // Buffer to store the name from the file

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
        printf("Welcome back, %s!\n", name);
        printf("You already have an account. Press ENTER to get started!\n");
        clear_input_buffer();
    } else {
        printf("\n-----------------------------\n");
        printf("It seems you don't have an account yet.\n");
        printf("Would you like to create an account?\n");
        printf("Enter 1 to create an account or 2 to exit: ");

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
    printf("Please enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove the newline character from the input

    printf("Please enter your weight: ");
    float weight;
    scanf("%f", &weight);
    clear_input_buffer();

    printf("Please enter your height: ");
    float height;
    scanf("%f", &height);
    clear_input_buffer();

    printf("Please enter your age: ");
    int age;
    scanf("%d", &age);
    clear_input_buffer();

    // Initialize bench, squat, and deadlift with placeholder values
    float bench = -1, squat = -1, deadlift = -1; // method to visualise that the user has not entered any data yet

    // Prompt for bench
    printf("Would you like to enter your bench press now? (1 for Yes, 2 for Skip): ");
    int choice;
    scanf("%d", &choice);
    clear_input_buffer();
    if (choice == 1) {
        printf("Please enter your bench press (in kg): ");
        scanf("%f", &bench);
        clear_input_buffer();
    } else {
        printf("You chose to skip entering your bench press. You can add it later.\n");
    }

    // Prompt for squat
    printf("Would you like to enter your squat now? (1 for Yes, 2 for Skip): ");
    scanf("%d", &choice);
    clear_input_buffer();
    if (choice == 1) {
        printf("Please enter your squat (in kg): ");
        scanf("%f", &squat);
        clear_input_buffer();
    } else {
        printf("You chose to skip entering your squat. You can add it later.\n");
    }

    // Prompt for deadlift
    printf("Would you like to enter your deadlift now? (1 for Yes, 2 for Skip): ");
    scanf("%d", &choice);
    clear_input_buffer();
    if (choice == 1) {
        printf("Please enter your deadlift (in kg): ");
        scanf("%f", &deadlift);
        clear_input_buffer();
    } else {
        printf("You chose to skip entering your deadlift. You can add it later.\n");
    }

    // Write the data to the CSV file
    FILE *file = fopen("GymInfo.csv", "a");  // Open the file in append mode
    if (!file) {
        perror("I'm sorry we couldn't open the CSV file :(");
        return;
    }

    // Write all data to the CSV file, using -1 for skipped values
    fprintf(file, "%s;%f;%f;%d;%f;%f;%f\n", name, weight, height, age, bench, squat, deadlift);
    fclose(file);

    printf("\nYour account has been successfully created!\n");
    printf("Please press ENTER to get back to the main menu!");
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
    printf("Option 7: Exit the menu\n");
    printf("\nPlease enter your choice: ");
    scanf(" %d", &menu_choice); // scans for the user input of the menu choice 
}

// OPTION 1 - FUNCTION TO ENTER WEIGHT
void enter_weight(){
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


 switch (weight_choice){
     case 1:
        printf("\nYou chose Option 1: 'View your current weight'\n");
        read_csv("GymInfo.csv", "Weight");
        clear_input_buffer();
        break; 
        
     case 2: 
        printf("\nYou chose Option 2: 'Change your current weight'\n\n");
        printf("Please enter your new weight:\n");
        scanf("%f", &new_weight);
        clear_input_buffer();
        write_csv("GymInfo.csv", "Weight", new_weight); //writecsv is undeclared => write_csv? 
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
void enter_height(){
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

    switch (height_choice){
        case 1:
            printf("\nYou chose Option 1: 'View your current height'\n");
            read_csv("GymInfo.csv", "Height");
            clear_input_buffer();
            break; 
            
        case 2:  
            printf("\nYou chose Option 2: 'Change your current height'\n");
            printf("Please enter your new height! (in cm)\n");
            scanf("%f", &new_height);
            clear_input_buffer();
            write_csv("GymInfo.csv", "Height", new_height);
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
void enter_age(){
    int new_age; //int because age cant be a decimal 
    printf("\n-----------------------------\n");
    printf("\nYou chose Option 3: 'Enter Age'\n\n");
    printf("Please choose from the following options: \n");
    printf("1 - View your current age\n"); 
    printf("2 - Change your current age\n"); 
    printf("3 - Return to the main menu\n");
    printf("\nPlease enter your desired option: \n");
    scanf(" %d", &age_choice); // scans for the user input of the age
    clear_input_buffer();

 switch (age_choice){
     case 1:
        printf("\nYou chose Option 1: 'View your current age'\n");
        read_csv("GymInfo.csv", "Age");
        clear_input_buffer();
        break;
        
     case 2: 
        printf("\nYou chose Option 2: 'Change your current age'\n");
        printf("Please enter your new age:\n");
        scanf("%d", &new_age);
        clear_input_buffer();
        write_csv("GymInfo.csv", "Age", new_age);
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
void enter_bench(){
    float new_bench;
    printf("\n-----------------------------\n");
    printf("\nYou chose Option 4: 'Enter Bench'\n\n");
    printf("Please choose from the following opitons: \n");
    printf("1 - View your current bench\n"); 
    printf("2 - Change your current bench\n"); 
    printf("3 - Return to the main menu\n");
    printf("\nPlease enter your desired option: \n");
    scanf(" %d", &bench_choice); // scans for the user input of 'bench'
    clear_input_buffer();

    switch (bench_choice){
        case 1:
            printf("\nYou chose Option 1: 'View your current bench'\n");
            read_csv("GymInfo.csv", "Bench");
            clear_input_buffer();
            break; 
            
        case 2: 
            printf("\nYou chose Option 2: 'Change your current bench'\n");
            printf("Please enter your new bench!\n");
            scanf("%f", &new_bench);
            clear_input_buffer();
            write_csv("GymInfo.csv", "Bench", new_bench);
            printf("\nNice! Your new bench has been recorded!");
            printf("\nPress ENTER to get back to the menu overview.\n");
            clear_input_buffer();
            break;
        
        case 3: 
            printf("\nYou chose Option 3: 'Return to the main menu'\n");
            printf("\nFeel free to come back if you change your mind!\nUntil then, press ENTER to get back to the menu overview.\n");
            break;

        default:
            printf("\nYou did not choose one of the valid options. Please press ENTER to get back to the main overview\n");
            clear_input_buffer();
            break;
        }
}

// OPTION 5 - FUNCTION TO ENTER SQUAT 
void enter_squat(){
    float new_squat;
    printf("\n-----------------------------\n");
    printf("\nYou chose Option 5: 'Enter Squat'\n\n");
    printf("Please choose from the following opitons: \n");
    printf("1 - View your current squat\n"); 
    printf("2 - Change your current squat\n"); 
    printf("3 - Return to the main menu\n");
    printf("\nPlease enter your desired option: \n");
    scanf(" %d", &squat_choice); // scans for the user input 
    clear_input_buffer();

 switch (squat_choice){
     case 1:
        printf("You chose Option 1: 'View your current squat'\n");
        read_csv("GymInfo.csv", "Squat");
        clear_input_buffer();
        break;
        
     case 2: 
        printf("You chose Option 2: 'Change your current squat'\n");
        printf("Please enter your new squat!\n");
        scanf("%f", &new_squat);
        clear_input_buffer();
        write_csv("GymInfo.csv", "Squat", new_squat);
        printf("Nice! Your new squat has been recorded!");
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
void enter_deadlift(){
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

    switch (deadlift_choice){
        case 1:
            printf("\nYou chose Option 1: 'View your current deadlift'\n");
            read_csv("GymInfo.csv", "Deadlift");
            clear_input_buffer();
            break;
            
        case 2: 
            printf("\nYou chose Option 2: 'Change your current deadlift'\n");
            printf("Please enter your new deadlift!\n");
            scanf("%f", &new_dl);
            clear_input_buffer();
            write_csv("GymInfo.csv", "Deadlift", new_dl);
            printf("Nice! Your new deadlift has been recorded!");
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


//FUNCTION TO WRITE IN CSV FILE
void write_csv(const char *filename, const char *area, int value) {
    FILE *file = fopen(filename, "a");  //OPENS AND WRITES IN THE CSV FILE, OVERWRITES AND REPLACES ENTRY

    if (!file) {
        perror("I'm sorry we couldn't open the CSV file :("); //ERROR MESSAGE TO DISPLAY IF FILE DID NOT OPEN CORRECTLY
        return;
    }

    fprintf(file, "%s;%s;%d\n", name, area, value);  // PRINTS INTO FILE 
    fclose(file); //CLOSES FILE 
    }

//Function to read in the CSV file
void read_csv (const char *filename, const char *area) {
    FILE *file = fopen(filename, "r");
    if (!file){
       perror ("I am sorry I could not open the CSV file.);
       return;
       }
    char line[MAX_LINE_LENGTH];
    while (fgets (line, sizeof(line), file)){
       char file_name[50];
       float weight, height, bench, squat, deadlift;
       int age;

       int fields = sscanf (line, "%49[^;]; %f; %f; %d; %f; %f; %f", file_name, &weight, &height, &age, &bench, &squat, &deadlift);

        if (fields == 7 && strcmp(file_name, name) == 0) {
            fclose(file);

            if (strcmp(area, "Weight") == 0)
                printf("Your current weight is: %.1f kg\n", weight);
            else if (strcmp(area, "Height") == 0)
                printf("Your current height is: %.1f cm\n", height);
            else if (strcmp(area, "Age") == 0)
                printf("Your current age is: %d years\n", age);
            else if (strcmp(area, "Bench") == 0)
                printf("Your current bench is: %.1f kg\n", bench);
            else if (strcmp(area, "Squat") == 0)
                printf("Your current squat is: %.1f kg\n", squat);
            else if (strcmp(area, "Deadlift") == 0)
                printf("Your current deadlift is: %.1f kg\n", deadlift);
            else
                printf("Unknown field: %s\n", area);

            return;
        }
    }

    fclose(file);
    printf("We were not able to find your record inside our databae.\n);
     }
                            
     
        
