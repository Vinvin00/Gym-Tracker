#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
#define max_attempts 3          // defining the maximum attempts possible (3)

//Global Variables (Characters)
char firstname[20] = "";             // variable to store the first name
char lastname[20] = "";              // variable to store the last name
char nickname[20] = "";              // variable to store the nickname 
char delete_secondchoice;       // variable to store yes or no option in the 'delete_name' function
char delete_firstname;          // varibale to store yes or no option in the 'delete_name' function
char delete_lastname;           // variable to store yes or no option in the 'delete_name' function
char delete_nickname;           // variable to store yes or no option in the 'delete_name' function


// Global Variables (Integers)
int invalid_attempts = 0;
int menu_choice;                // variable to store user menu choice
int delete_choice;              // variable to store user choice of which name to delete  
int greeting_formality;         // variable to store user formalitiy choice

//Functions 
void display_menu ();        // function to display menu overview 
void enter_names();          // function for menu option 1
void enter_nicknames();      // function for menu option 2
void decide_greeting ();     // function for menu option 3
void delete_name ();         // function for menu option 4
void print_easteregg();      // function to print surprise easter egg
void clear_input_buffer();   // function to clear the input buffer

// Main Function 
int main() {

 
    while (1) {
        display_menu ();      // funciton to display menu overview
       
        // user can choose from the menu in front of him, cases 1, 2, 3, 4 and 9 refer to functions, which are to be found below. 
        // Case 5 terminates the program whilst the 'default' case represents the invalid attempts, which are also shown to the user to keep track on. 
        switch (menu_choice){       
            case 1: 
                enter_names(); // 
                break;

            case 2: 
                enter_nicknames(); 
                break;

            case 3:
                decide_greeting();
                break;

            case 4: 
                delete_name();
                break;
            
            case 5:
                printf("-----------------------------\n");
                printf("\nYou chose option 5!\n\nIt's a shame you don't want to continue!\nGoodbye.\n\nThis program terminates here :( \n\n");
                return 0;

            case 9: // special surprise function (please don't be too harsh on my easter bunny, I tried my best :) ...)
                print_easteregg();
                break;

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
    }
}

// Function to print out the menu 
void display_menu(void){
    printf("\n-----------------------------\n"); // soley for visual purpose, to make it more visually appealing 
    printf("\nHello! Welcome to this Gym Tracker!\n\nPlease choose one of the following options from below:\n\n");
    printf("Option 1: Enter your name and lastname\n");
    printf("Option 2: Enter a nickname\n");
    printf("Option 3: Choose a greeting\n");
    printf("Option 4: Delete naming information\n");
    printf("Option 5: Exit the menu\n");
    printf("\n\n\n(Pssssst...Enter '9' for a little easter surprise...)\n");
    printf("\nPlease enter your choice: ");
    scanf(" %d", &menu_choice); // scans for the user input of the menu choice 
}

// Option One: Function to enter names 
void enter_names(void){ 
    printf("\n-----------------------------\n");
    printf("\nHello Welcome to this Gym Tracker! Please enter your name so we can see if you're already in out data bank\n\n\n");
    printf("If you want to skip your first name please press 's'.\n");
    printf("\nIf not, please put in your first name: \n");
    fgets(" %s", firstname); // scans for the user input of the first name or skip option 

    if (firstname[0] == 's' && firstname[1] == '\0') { // means that if the user input a 's' he decided to skip putting in his names
        firstname[0] = '\0'; // resets the first name (from 's' to nothing)
        printf("\nYou chose to skip entering your first name.\n");
    } else {
        printf("\nYou entered the first name: %s\n", firstname); // scans for the users first name input and display it here if user entered it 
    }
    clear_input_buffer();
    printf("\nNow, please put in your last name (or press 's' to skip):\n");
    fgets(" %s", lastname);  // scans for the user input of the last name or skip option 

    if (lastname[0] == 's' && lastname[1] == '\0') { // again, means that if the user input a 's' he decided to skip putting in his names
        lastname[0] = '\0'; // resets the last name (from 's' to nothing)
        printf("\nYou chose to skip entering your last name.\n");
    } else {
        printf("\nYou entered the last name: %s.\n\n", lastname); // scans for the users last name input and display it here if user entered it 
    }
    clear_input_buffer();
    printf("\nThank you, you're all done here!\nPress ENTER to return to the menu");
    clear_input_buffer();
}

// Option Two: Function to enter a nickname
void enter_nicknames(void){ 
    printf("\n-----------------------------\n");
    printf("\nYou chose Option 2: 'Enter a nickname'\n\n");     
    printf("If you want to skip your nickname please press 's'.\n");
    printf("\nIf not, please put in your desired nickname: \n");
    fgets(" %s", nickname); // scans for the user input of the nickname or skip option

    if (nickname[0] == 's' && nickname[1] == '\0') { // again, means that if the user input a 's' he decided to skip putting in his names
        nickname[0] = '\0';
        printf("\nYou chose to skip entering your nickname.\n");
    } else {
        printf("\nYou entered the nickname: %s.\n", nickname); // scans for the users nickname input and display it here if user entered it 
    }
    clear_input_buffer();
    printf("\nThank you, you're all done here!\nPress ENTER to return to the menu\n\n");
    clear_input_buffer();
}

// Function to clear the input buffer
void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
    
// Option Three: Funtiong to notify the user of the intention to greet them. Requests their preferred level of formality.      
void decide_greeting(void){ 
    printf("\n-----------------------------\n");
    printf("\nYou chose Option 3: 'Choose a greeting'\n\nPlease choose a level of formality of how you would like me to greet you:\n\n");
    printf("Option 1: Informal Greeting (using the nickname and casual language)\n");
    printf("Option 2: Medium Formal Greeting (using just the name)\n");
    printf("Option 3: Formal Greeting (using the name and surname)\n\n");
    printf("Please enter your desired option: \n");
    scanf(" %d", &greeting_formality); // scans for the user input of the greeting formality option
    clear_input_buffer();

    if (greeting_formality == 1){
        if (nickname[0] != '\0'){ // checks the condition that a nickname was previously entered
            printf("\nYou chose Option 1: Informal\n");
            printf("\nHey what's up, %s!\n\n", nickname); // inserts the nickname previously chosen by the user
            printf("Thank you for choosing 'Informal Greeting'!\nPress ENTER to return to the menu\n");
            clear_input_buffer();

        } else {
            printf("\n\nYou have not provided me with your nickname yet.\nPlease choose a nickname first and then return to this section to choose this greeting option!\n"); 
            clear_input_buffer();
        }
    } else if (greeting_formality == 2){  
        if (firstname[0] != '\0'){ // checks the condition that a first name was previously entered
            printf("\nYou chose Option 2: Medium Formal\n");
            printf("\nHey %s!\n\n", firstname); // inserts the first name previously chosen by the user
            printf("Thank you for choosing 'Medium Formal Greeting'!\nPress ENTER to return to the menu\n");
            clear_input_buffer();   
            
        } else {
            printf("\n\nYou have not provided me with your first name yet.\nPlease choose a name first and then return to this section to choose this greeting option!\n");  
            clear_input_buffer();
        }
    } else if (greeting_formality == 3){  
        if (firstname[0] != '\0'|| lastname[0] != '\0'){ // checks the condition that both first and last name were previously entered
            printf("\nYou chose Option 3: Formal\n");
            printf("\nHello %s %s.\n\n", firstname, lastname); // inserts the first and last name previously chosen by the user
            printf("Thank you for choosing 'Formal Greeting'!\nPress ENTER to return to the menu\n");
            clear_input_buffer();

        } else {
            printf("\n\nYou have not provided me with your first and last name yet.\nPlease choose a name first and then return to this section to choose this greeting option!\n"); 
            clear_input_buffer();        
        }
    } else {
        printf("\nYou chose none of the valid options provided.\n");
        printf("\nInvalid Option.\nPlease try again!\n");
        clear_input_buffer();
    }
}

// Option Four: Function to allow the user to delete their name, surname and/or nickname        
void delete_name(void){
    printf("-----------------------------\n");
    printf("\nYou chose Option 4: 'Delete Naming Information'\n\n");

    printf("\nPlease choose which name you would like to delete:\n\n");

    printf("Option 1: Name\n");
    printf("Option 2: Surname\n");
    printf("Option 3: Nickname\n");
    printf("Option 4: Do not delete any name and return back to the menu overview\n");
            
    printf("\nEnter your choice: \n");
    scanf(" %d", &delete_choice); // scans for the user choice of what to delete
    clear_input_buffer();
            
    switch (delete_choice){
        case 1: 
            printf("-----------------------------\n");
            printf("\nYou chose 'Option 1: Name'\n");
            if (firstname[0] != '\0') { // checks the condition that a first name was previously entered
                printf("\nYou previously entered your name '%s'\n", firstname); // inserts the first name previously chosen by the user
                printf("\nAre you sure you would like to delete it? (y/n)\n");
                scanf(" %c", &delete_firstname); // scans for the user choice of whether or not to delete the name
                clear_input_buffer();
                        
                if (delete_firstname == 'y' || delete_firstname == 'Y'){ // conditional for the case that the user want to delete the name
                    firstname[0] = '\0'; // deletes/resents the name
                    printf("\nYou have successfully deleted your name!\n");
                    clear_input_buffer();

                } else if (delete_firstname != 'y' || delete_firstname != 'Y'|| delete_firstname != 'n' || delete_firstname != 'N'){ // conditional for the case that the user did not put in a valid option
                    printf("\nYou did not choose one of the valid options. Please restart from the beginning.\n");
                    clear_input_buffer();
                    return;

                } else {
                    printf("\nGreat Choice! It is a beautiful name, why would you like to delete it anyways?\n");
                }
                
            } else {
                printf("\nYou have not provided me with your name yet.\nPlease return to the menu overview and choose a name first.\n");
                clear_input_buffer();
            }
            break;

        case 2: 
            printf("-----------------------------\n");
            printf("\nYou chose 'Option 2: Surname'\n");
            if (lastname[0] != '\0'){ // checks the condition that a last name was previously entered
                printf("\nYou previously entered your last name '%s'\n", lastname); // inserts the last name previously chosen by the user
                printf("\nAre you sure you would like to delete it? (y/n)\n");
                scanf(" %c", &delete_lastname); // scans for the user choice of whether or not to delete the name
                clear_input_buffer();
                        
                if (delete_lastname == 'y' || delete_lastname == 'Y'){ // conditional for the case that the user want to delete the name
                    lastname[0] = '\0'; // deletes/resents the name
                    printf("\nYou have successfully deleted your lastname!\n");
                    clear_input_buffer();

                } else if (delete_lastname != 'y' || delete_lastname != 'Y'|| delete_lastname != 'n' || delete_lastname != 'N'){ // conditional for the case that the user did not put in a valid option
                    printf("\nYou did not choose one of the valid options. Please restart from the beginning.\n");
                    clear_input_buffer();
                    return;

                } else {
                    printf("\nGreat Choice! It is a beautiful last name, why would you like to delete it anyways?\n");
                }
                
            } else {
                printf("\nYou have not provided me with your last name yet.\nPlease return to the menu overview and choose a last name first.\n");
                clear_input_buffer();
            }
            break;

        case 3:
            printf("-----------------------------\n");
            printf("\nYou chose 'Option 3: Nickname'\n");
            if (nickname[0] != '\0'){ // checks the condition that a nickname was previously entered
                printf("\nYou previously entered your nickname '%s'\n", nickname); // inserts the nickname previously chosen by the user
                printf("\nAre you sure you would like to delete it? (y/n)\n");
                scanf(" %c", &delete_nickname); // scans for the user choice of whether or not to delete the name
                clear_input_buffer();
                        
                if (delete_nickname == 'y' || delete_nickname == 'Y'){ // conditional for the case that the user want to delete the name
                    nickname[0] = '\0'; // deletes/resents the name
                    printf("\nYou have successfully deleted your nickname!\n");
                    clear_input_buffer();
                
                } else if (delete_nickname != 'y' || delete_nickname != 'Y'|| delete_nickname != 'n' || delete_nickname != 'N'){ // conditional for the case that the user did not put in a valid option
                    printf("\nYou did not choose one of the valid options. Please restart from the beginning.\n");
                    clear_input_buffer();
                    return;
                
                } else {
                    printf("\nGreat Choice! It is a beautiful nickname, why would you like to delete it anyways?\n");
                }

                
            } else {
                printf("\nYou have not provided me with your nickname yet.\nPlease return to the menu overview and choose a nickname first.\n");
                clear_input_buffer();
            }
            break;
 
        case 4: 
            printf("-----------------------------\n");
            printf("\nYou chose 'Option 4: Do not delete any name and return back to the menu overview'\n");
            printf("\nFeel free to come back if you change your mind!\nUntil then, I will redirct you back to the menu overview.\n");
            clear_input_buffer();
            display_menu();
            break;

        default:
            printf("\nYou did not choose one of the valid options. Please restart from the beginning and choose one of the following options:\n");
            clear_input_buffer();
            break;
    }
        
    printf("\nWould you like to delete anything else (y/n)?\n"); // checking if the user wants to delete anything else
    scanf(" %c", &delete_secondchoice); // scans for the users choice
    clear_input_buffer();
    if (delete_secondchoice == 'y' || delete_secondchoice == 'Y'){ // conditional for the case that the user want to delete another name
        printf("-----------------------------\n"); 
        printf("\nPlease start over and choose what other name you would like to delete:\n\n");
        delete_name();
        
    } else if (delete_secondchoice != 'y' || delete_secondchoice != 'Y'|| delete_secondchoice != 'n' || delete_secondchoice != 'N'){ // conditional for the case that the user did not put in a valid option
        printf("\nYou did not choose one of the valid options. Please restart from the beginning.\n");
        clear_input_buffer();
        
    } else {
        printf("\nYou chose not to delete any other names.\nPress ENTER to return to the menu.\n");
        clear_input_buffer();
    
    }
}

// Printing a little surprise easter egg when the number 9 is entered
void print_easteregg(){
    printf("\nBecause if there's an easter egg, the bunny can't be too far away... (yes, this is the attempt of an easter bunny!)\n\n");
    
    printf("      /\\/\\\n");
    printf("     /    \\\n");
    printf("    ( o.o )\n");
    printf("     ==\u2014==\n");  
    printf("      \\  /\n");
    printf("       --\n");
    
    printf("      _____  \n");
    printf("     /     \\ \n");
    printf("    |       | \n");
    printf("    |   9   | \n");
    printf("    |       | \n");
    printf("     \\_____/ \n");
    
    clear_input_buffer();
    printf("\n\nPress ENTER to get back to the menu overview.\n");
    clear_input_buffer();
}
}
