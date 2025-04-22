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
    

// Function to print out the menu 
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

// ENTER NAME TO SEE IF YOURE IN THE DATA BASE
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

// Function to clear the input buffer
void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


// Function to enter weight 
void enter_weight(){
    printf("Hello! You chose Option 1: 'Enter Weight'\n");
    printf("Please choose from the following opitons:v\n");
    printf("1 - View your current weight\n"); 
    printf("2 - Change your current weight\n"); 
    printf("3 - Return to the main menu\n");
    printf("Please enter your desired option: \n");
    scanf(" %d", &weight_choice); // scans for the user input of the greeting formality option
    clear_input_buffer();

 if (weight_choice == 1){
            // code to view current weight
            clear_input_buffer();
        }
    
    } else if (weight_choice == 2){  
         // code to change current weight
            clear_input_buffer();
        }

    } else if (weight_choice == 3){  
         // code to return to main menu
            clear_input_buffer();
        }

    } else {
        printf("\nYou chose none of the valid options provided.\n");
        printf("\nInvalid Option.\nPlease try again!\n");
        clear_input_buffer();
    }
}
























