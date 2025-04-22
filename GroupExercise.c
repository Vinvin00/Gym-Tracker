#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#incluse 'GymInfo.cvs' // including csv file 

int main(){
#define max_attempts 3          // defining the maximum attempts possible (3) => DO WE NEED THAT? 

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
void enter_names();         // function to enter name
void enter_weight();        // function for menu option 1
void enter_height();        // function for menu option 2
void enter_age();           // function for menu option 3
void enter_bench();         // function for menu option 4
void enter_squat();         // function for menu option 5
void enter_deadlift();      // function for menu option 6
void clear_input_buffer();  // function to clear the input buffer
void check_account();       // function to check if name exists 

// Main Function 
int main() {
while (1) {
    enter_name();            // enter name to check if youre in the data base
    display_menu();          // display menu 

    switch (menu_choice){
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
                printf("\nThis is not a valid option.\n");
                printf("So far you have entered %d invalid option(s).\n", invalid_attempts);
                
                if (invalid_attempts >= max_attempts) { // Checking whether its more than 3 attempts
                    printf("\nYou don't seem too interested in speaking with me...\nGoodbye!\n\n");
                    return 0;
                
                } else {
                    printf("\nPlease press ENTER to try again!\n");
                    clear_input_buffer();
                }      
        }
    

// FUNCTION TO PRINT OUT THE MENU
void display_menu(void){
    printf("\n-----------------------------\n"); // soley for visual purpose, to make it more visually appealing 
    printf("\nHello! Welcome to this Gym Tracker!\n\nPlease choose one of the following options from below:\n\n");
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

// FUNTION TO ENTER NAME TO SEE IF YOURE IN THE DATA BASE
void enter_names(void){ 
    printf("\n-----------------------------\n");
    printf("\nHello Welcome to this Gym Tracker! Please enter your name so we can see if you're already in out data bank\n\n\n");
    fgets(" %s", firstname); // scans for the user input of the first name or skip option 

    printf("\nYou entered the name: %s\n", firstname); // scans for the users first name input and display it here if user entered it 

    clear_input_buffer();
    printf("\nThank you, we're now going to see if you already have an account!) 
    check_account; 
    clear_input_buffer();
}

// FUNCTION TO CHECK IF NAME IS IN THE DATABASE
void check_account(const char* name,) {
    FILE* file = fopen("GymInfo.csv", "r");  // Open the CSV file for reading
    if (file == NULL) {
        perror("Failed to open file"); 
        return;
    }

    char line[MAX_LINE_LENGTH];
    int found = 0;

    // Read each line from the CSV
    while (fgets(line, sizeof(line), file)) {
        char file_name[50];  // Adjust size as necessary

        // Split the line into first name and last name
        sscanf(line, "%49[^,], name);  // Assume comma-separated

        // Check if the names match
        if (strcmp(firstname, file_firstname) == 0 && strcmp(lastname, file_lastname) == 0) {
            found = 1;
            break;
        }
    }

    fclose(file);  // Close the file

    if (found) {
        printf("Welcome back, %s %s! You already have an account.\n", firstname, lastname);
    } else {
        printf("It seems you don't have an account yet.\n");
    }
}


// FUNCTION TO CLEAR INPUT BUFFER
void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


// FUNCTION TO ENTER WEIGHT
void enter_weight(){
    printf("Hello! You chose Option 1: 'Enter Weight'\n");
    printf("Please choose from the following opitons: \n");
    printf("1 - View your current weight\n"); 
    printf("2 - Change your current weight\n"); 
    printf("3 - Return to the main menu\n");
    printf("Please enter your desired option: \n");
    scanf(" %d", &weight_choice); // scans for the user input 
    clear_input_buffer();

 switch (weight_choice){
     case 1:
        printf("Hello! You chose Option 1: 'View your current weight'\n");
        // code to view current weight
        clear_input_buffer();
        
     case 2: {
        int new_weight;
        printf("Hello! You chose Option 2: 'Change your current weight'\n");
        printf("Please enter your new weight!\n");
        scanf("%d", &new_weight);
        clear_input_buffer();
        writecsv("GymInfo.csv", "Weight", new_weight);
        printf("Nice! Your new weight has been recorded!");
        break; 
     }
     case 3: 
        printf("Hello! You chose Option 3: 'Return to the main menu'\n");
        printf("\nFeel free to come back if you change your mind!\nUntil then, I will redirct you back to the menu overview.\n");
        clear_input_buffer();
        display_menu();
        break;
    
     default:
            printf("\nYou did not choose one of the valid options. Please restart from the beginning and choose one of the following options:\n");
            clear_input_buffer();
            break;
    }


// FUNCTION TO ENTER HEIGHT
void enter_height(){
    printf("Hello! You chose Option 1: 'Enter Height'\n");
    printf("Please choose from the following options: \n");
    printf("1 - View your current height\n"); 
    printf("2 - Change your current height\n"); 
    printf("3 - Return to the main menu\n");
    printf("Please enter your desired option: \n");
    scanf(" %d", &height_choice); 
    clear_input_buffer();

 switch (height_choice){
     case 1:
        printf("Hello! You chose Option 1: 'View your current height'\n");
        // code to view current height
        clear_input_buffer();
        
     case 2: {
        int new_height; 
        printf("Hello! You chose Option 2: 'Change your current height'\n");
        printf("Please enter your new height!\n");
        scanf("%d", &new_height);
        clear_input_buffer();
        writecsv("GymInfo.csv", "Height", new_height);
        printf("Nice! Your new height has been recorded!");
        break; 
     }
        
     case 3: 
        printf("Hello! You chose Option 3: 'Return to the main menu'\n");
        printf("\nFeel free to come back if you change your mind!\nUntil then, I will redirct you back to the menu overview.\n");
        clear_input_buffer();
        display_menu();
        break;
    
     default:
            printf("\nYou did not choose one of the valid options. Please restart from the beginning and choose one of the following options:\n");
            clear_input_buffer();
            break;
    }

// FUNCTION TO ENTER AGE 
void enter_age(){
    printf("Hello! You chose Option 1: 'Enter Age'\n");
    printf("Please choose from the following options: \n");
    printf("1 - View your current age\n"); 
    printf("2 - Change your current age\n"); 
    printf("3 - Return to the main menu\n");
    printf("Please enter your desired option: \n");
    scanf(" %d", &age_choice); // scans for the user input of the age
    clear_input_buffer();

 switch (age_choice){
     case 1:
        printf("Hello! You chose Option 1: 'View your current age'\n");
        // code to view current age
        clear_input_buffer();
        
     case 2: {
        int new_age; 
        printf("Hello! You chose Option 2: 'Change your current age'\n");
        printf("Please enter your new age!\n");
        scanf("%d", &new_age);
        clear_input_buffer();
        writecsv("GymInfo.csv", "Age", new_age);
        printf("Nice! Your new age has been recorded!");
        break;
     }
        
     case 3: 
        printf("Hello! You chose Option 3: 'Return to the main menu'\n");
        printf("\nFeel free to come back if you change your mind!\nUntil then, I will redirct you back to the menu overview.\n");
        clear_input_buffer();
        display_menu();
        break;
    
     default:
            printf("\nYou did not choose one of the valid options. Please restart from the beginning and choose one of the following options:\n");
            clear_input_buffer();
            break;
    }

// FUNCTION TO ENTER BENCH 
void enter_bench(){
    printf("Hello! You chose Option 1: 'Enter Bench'\n");
    printf("Please choose from the following opitons: \n");
    printf("1 - View your current bench\n"); 
    printf("2 - Change your current bench\n"); 
    printf("3 - Return to the main menu\n");
    printf("Please enter your desired option: \n");
    scanf(" %d", &bench_choice); // scans for the user input of 'bench'
    clear_input_buffer();

 switch (bench_choice){
     case 1:
        printf("Hello! You chose Option 1: 'View your current bench'\n");
        // code to view current bench
        clear_input_buffer();
        
     case 2:{
        int new_bench; 
        printf("Hello! You chose Option 2: 'Change your current bench'\n");
        printf("Please enter your new bench!\n");
        scanf("%d", &new_bench);
        clear_input_buffer();
        writecsv("GymInfo.csv", "Bench", new_bench);
        printf("Nice! Your new bench has been recorded!");
        break;
     }
        
     case 3: 
        printf("Hello! You chose Option 3: 'Return to the main menu'\n");
        printf("\nFeel free to come back if you change your mind!\nUntil then, I will redirct you back to the menu overview.\n");
        clear_input_buffer();
        display_menu();
        break;
    
     default:
            printf("\nYou did not choose one of the valid options. Please restart from the beginning and choose one of the following options:\n");
            clear_input_buffer();
            break;
    }

// FUNCTION TO ENTER SQUAT 
void enter_squat(){
    printf("Hello! You chose Option 1: 'Enter Squat'\n");
    printf("Please choose from the following options: \n");
    printf("1 - View your current squat\n"); 
    printf("2 - Change your current squat\n"); 
    printf("3 - Return to the main menu\n");
    printf("Please enter your desired option: \n");
    scanf(" %d", &squat_choice); // scans for the user input 
    clear_input_buffer();

 switch (squat_choice){
     case 1:
        printf("Hello! You chose Option 1: 'View your current squat'\n");
        // code to view current squat
        clear_input_buffer();
        
     case 2:{
        int new_squat; 
        printf("Hello! You chose Option 2: 'Change your current squat'\n");
        printf("Please enter your new squat!\n");
        scanf("%d", &new_squat);
        clear_input_buffer();
        writecsv("GymInfo.csv", "Squat", new_squat);
        printf("Nice! Your new squat has been recorded!");
        break;
     }
        
     case 3: 
        printf("Hello! You chose Option 3: 'Return to the main menu'\n");
        printf("\nFeel free to come back if you change your mind!\nUntil then, I will redirct you back to the menu overview.\n");
        clear_input_buffer();
        display_menu();
        break;
    
     default:
            printf("\nYou did not choose one of the valid options. Please restart from the beginning and choose one of the following options:\n");
            clear_input_buffer();
            break;
    }


// FUNCTION TO ENTER DEADLIFT  
void enter_deadlift(){
    printf("Hello! You chose Option 1: 'Enter Deadlift'\n");
    printf("Please choose from the following options: \n");
    printf("1 - View your current deadlift\n"); 
    printf("2 - Change your current deadlift\n"); 
    printf("3 - Return to the main menu\n");
    printf("Please enter your desired option: \n");
    scanf(" %d", &deadlift_choice); // scans for the user input
    clear_input_buffer();

 switch (deadlift_choice){
     case 1:
        printf("Hello! You chose Option 1: 'View your current deadlift'\n");
        // code to view current deadlift
        clear_input_buffer();
        
     case 2:{
        int new_dl; 
        printf("Hello! You chose Option 2: 'Change your current deadlift'\n");
        printf("Please enter your new deadlift!\n");
        scanf("%d", &new_dl);
        clear_input_buffer();
        writecsv("GymInfo.csv", "Deadlift", new_dl);
        printf("Nice! Your new deadlift has been recorded!");
        break;
     }
        
     case 3: 
        printf("Hello! You chose Option 3: 'Return to the main menu'\n");
        printf("\nFeel free to come back if you change your mind!\nUntil then, I will redirct you back to the menu overview.\n");
        clear_input_buffer();
        display_menu();
        break;
    
     default:
            printf("\nYou did not choose one of the valid options. Please restart from the beginning and choose one of the following options:\n");
            clear_input_buffer();
            break;
    }


//FUNCTION TO WRITE IN CSV FILE
void write_csv(const char *filename, const char *area, int value) {
    FILE *file = fopen(filename, "w");  //OPENS AND WRITES IN THE CSV FILE, OVERWRITES AND REPLACES ENTRY

    if (!file) {
        perror("I'm sorry we couldn't open the CSV file :("); //ERROR MESSAGE TO DISPLAY IF FILE DID NOT OPEN CORRECTLY
        return;
    }

    fprintf(file, "%s;%s;%d\n", name, area, value);  // PRINTS INTO FILE 
    fclose(file); //CLOSES FILE
}


















