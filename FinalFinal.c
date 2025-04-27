#include "GymTracker.h"
#include <stdlib.h>
#include <string.h>
 
 
 // MAIN FUNCTION 
 int main() {
     load_csv("GymInfo.csv");
     enter_name();            // enter name to check if youre in the data base
     load_csv("GymInfo.csv");     
     enter_name();               
 
     while (1) {
         display_menu();          // display menu
         display_menu();          
 
     switch (menu_choice) {
         case 1:
 @@ -113,45 +111,38 @@ int main() {
             }
         }
     }
     return 0; //WHY?
     return 0; 
 }
 
 
 
 
 // FUNTION TO ENTER NAME TO SEE IF YOURE IN THE DATA BASE
 void enter_name(void) {
     printf("\n-----------------------------\n");
     printf("\nHello You!\nWelcome to this Gym Tracker! \n\nPlease enter your name so we can see if you're already in our data bank!\n\n");
     printf("Name: ");
     fgets(name, sizeof(name), stdin); // scans for the user input of the first name
     name[strcspn(name, "\n")] = '\0'; // Remove the newline character from the input
     fgets(name, sizeof(name), stdin);               // scans for the user input of the name
     name[strcspn(name, "\n")] = '\0';               // Remove the newline character from the input
     printf("\n-----------------------------\n");
     printf("\nYou entered the name: %s\n", name); // scans for the user's first name input and displays it here if the user entered it
     check_account(name);
     printf("\nYou entered the name: %s\n", name);   // scans for the user's name input and displays it here if the user entered it
     check_account(name);                            // checks if name is already in the data bank 
 }
 
 
 
 // FUNCTION TO CHECK IF NAME IS IN THE DATABASE
 void check_account(char* name) {
     FILE* file = fopen("GymInfo.csv", "r");  // Open the CSV file for reading
     FILE* file = fopen("GymInfo.csv", "r");         // Open the CSV file for reading
     if (file == NULL) {
         perror("Failed to open file"); // Print error message
         perror("Failed to open file");              // Print error message
         return;
     }
 
     char line[MAX_LINE_LENGTH];
     int found = 0;
 
     // Read each line from the CSV
     while (fgets(line, sizeof(line), file)) {
 
         // Extract the name from the current line (assumes names are the first field in the CSV)
         sscanf(line, "%49[^;]", file_name);  // Read up to the first semicolon (;)
     while (fgets(line, sizeof(line), file)) {       // Read each line from the CSV
  
         sscanf(line, "%49[^;]", file_name);         // Extract the name from the current line
 
         // Check if the entered name matches the name in the file
         if (strcmp(name, file_name) == 0) {
         if (strcmp(name, file_name) == 0) {         // Check if the entered name matches the name in the file
             found = 1;
             break;
         }
 @@ -176,68 +167,73 @@ void check_account(char* name) {
 
         if (choice == 1) {
             printf("\nGreat! Let's create your account.\n");
             create_account();  // Call the function to create a new account
             create_account();                       // Call the function to create a new account
         } else if (choice == 2) {
             printf("\nThank you for visiting! Goodbye.\n");
             exit(0);  // Exit the program
             exit(0);                                // Exit the program
         } else {
             printf("\nInvalid choice. Returning to the main menu.\n");
             display_menu();  // Redirect to the main menu
             display_menu();                         // Redirect to the main menu
         }
     }
 }
 
 
 // FUNCTION TO CREATE NEW ACCOUNT
 void create_account() {
 
     char name[50];
     printf("Please enter your first name: ");
     float weight;
     float height;
     int age;
 
     // Asks user to input name
     printf("Please enter your name: ");       
     fgets(name, sizeof(name), stdin);
     name[strcspn(name, "\n")] = '\0';  // Remove the newline character from the input
     name[strcspn(name, "\n")] = '\0';               // Remove the newline character from the input
 
     // Check if the name is empty
     if (strlen(name) == 0) {
     if (strlen(name) == 0) {                        // Check if the name is empty
         printf("Name cannot be empty. Please try again.\n");
         return;
     }
 
     printf("Please enter your weight: ");
     float weight;
     while (scanf("%f", &weight) != 1) {  // Validate input
     // Asks user to input weight
     printf("Please enter your weight: ");           
     while (scanf("%f", &weight) != 1) {             // Validate input
         printf("Invalid input. Please enter a valid weight: ");
         clear_input_buffer();
     }
     clear_input_buffer();
 
     printf("Please enter your height: ");
     float height;
     while (scanf("%f", &height) != 1) {  // Validate input
     // Asks user to input height
     printf("Please enter your height: ");           
     while (scanf("%f", &height) != 1) {             // Validate input
         printf("Invalid input. Please enter a valid height: ");
         clear_input_buffer();
     }
     clear_input_buffer();
 
     printf("Please enter your age: ");
     int age;
     while (scanf("%d", &age) != 1) {  // Validate input
     // Asks user to input age
     printf("Please enter your age: ");              
     while (scanf("%d", &age) != 1) {                // Validate input
         printf("Invalid input. Please enter a valid age: ");
         clear_input_buffer();
     }
     clear_input_buffer();
 
     // Initialize bench, squat, and deadlift with placeholder values
     float bench = -1, squat = -1, deadlift = -1;  // Placeholder values for skipped inputs
     float bench = -1, squat = -1, deadlift = -1;    // Initialize bench, squat, and deadlift with placeholder values, Placeholder values for skipped inputs
 
     // Prompt for bench
     printf("Would you like to enter your bench press now? (1 for Yes, 2 for Skip): ");
     printf("Would you like to enter your bench press now? (1 for Yes, 2 for Skip): ");  
     int choice;
     while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {  // Validate input
     while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {                 // Validate input
         printf("Invalid input. Please enter 1 for Yes or 2 for Skip: ");
         clear_input_buffer();
     }
     clear_input_buffer();
     if (choice == 1) {
         printf("Please enter your bench press (in kg): ");
         while (scanf("%f", &bench) != 1) {  // Validate input
         while (scanf("%f", &bench) != 1) {                                              // Validate input
             printf("Invalid input. Please enter a valid bench press value: ");
             clear_input_buffer();
         }
 @@ -247,15 +243,15 @@ void create_account() {
     }
 
     // Prompt for squat
     printf("Would you like to enter your squat now? (1 for Yes, 2 for Skip): ");
     while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {  // Validate input
     printf("Would you like to enter your squat now? (1 for Yes, 2 for Skip): ");        
     while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {                 // Validate input
         printf("Invalid input. Please enter 1 for Yes or 2 for Skip: ");
         clear_input_buffer();
     }
     clear_input_buffer();
     if (choice == 1) {
         printf("Please enter your squat (in kg): ");
         while (scanf("%f", &squat) != 1) {  // Validate input
         while (scanf("%f", &squat) != 1) {                                              // Validate input
             printf("Invalid input. Please enter a valid squat value: ");
             clear_input_buffer();
         }
 @@ -266,14 +262,14 @@ void create_account() {
 
     // Prompt for deadlift
     printf("Would you like to enter your deadlift now? (1 for Yes, 2 for Skip): ");
     while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {  // Validate input
     while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {                 // Validate input
         printf("Invalid input. Please enter 1 for Yes or 2 for Skip: ");
         clear_input_buffer();
     }
     clear_input_buffer();
     if (choice == 1) {
         printf("Please enter your deadlift (in kg): ");
         while (scanf("%f", &deadlift) != 1) {  // Validate input
         while (scanf("%f", &deadlift) != 1) {                                           // Validate input
             printf("Invalid input. Please enter a valid deadlift value: ");
             clear_input_buffer();
         }
 @@ -283,30 +279,32 @@ void create_account() {
     }
 
     // Write the data to the CSV file
     FILE *file = fopen("GymInfo.csv", "a");  // Open the file in append mode
     FILE *file = fopen("GymInfo.csv", "a");                                             // Open the file in append mode which is used when you want to add new data to the end of an existing file without modifying or deleting its current contents.
     if (!file) {
         perror("Failed to open the CSV file for writing");
         return;
     }
 
     // Write all data to the CSV file, using -1 for skipped values
     fprintf(file, "%s;%.1f;%.1f;%d;%.1f;%.1f;%.1f\n", name, weight, height, age, bench, squat, deadlift);
     fclose(file);
 
     fprintf(file, "%s;%.1f;%.1f;%d;%.1f;%.1f;%.1f\n", 
             name, weight, height, age, bench, squat, deadlift);                         // Write all data to the CSV file, using -1 for skipped values
     
             fclose(file);                                                               // close the file 
     printf("\nYour account has been successfully created and stored in the CSV file!\n");
     printf("Please press ENTER to get back to the main menu!");
     clear_input_buffer();
 }
 
 
 // FUNCTION TO CLEAR INPUT BUFFER
 void clear_input_buffer(void) {
     int c;
     while ((c = getchar()) != '\n' && c != EOF);
     while ((c = getchar()) != '\n' && c != EOF);        // Read and discard characters from the input buffer until a newline ('\n') or EOF is encountered
 }
 
 
 // FUNCTION TO PRINT OUT THE MENU
 void display_menu(void){
     printf("\n-----------------------------\n"); // soley for visual purpose, to make it more visually appealing
     printf("\n-----------------------------\n");        // soley for visual purpose, to make it more visually appealing
     printf("\nPlease choose one of the following options:\n\n");
     printf("Option 1: Enter your weight\n");
     printf("Option 2: Enter your height\n");
 @@ -317,9 +315,10 @@ void display_menu(void){
     printf("Option 7: Delete existing account\n");
     printf("Option 8: Exit the menu\n");
     printf("\nPlease enter your choice: ");
     scanf(" %d", &menu_choice); // scans for the user input of the menu choice
     scanf(" %d", &menu_choice);                         // scans for the user input of the menu choice
 }
 
 
 // OPTION 1 - FUNCTION TO ENTER WEIGHT
 void enter_weight() {
     float new_weight;
 @@ -330,7 +329,7 @@ void enter_weight() {
     printf("2 - Change your current weight\n");
     printf("3 - Return to the main menu\n");
     printf("\nPlease enter your desired option: \n");
     scanf(" %d", &weight_choice); // scans for the user input
     scanf(" %d", &weight_choice);                       // scans for the user input
     clear_input_buffer();
 
     switch (weight_choice) {
 @@ -346,11 +345,11 @@ void enter_weight() {
             scanf("%f", &new_weight);
             clear_input_buffer();
 
             // Update the user's weight in the `users` array
             for (int i = 0; i < user_count; i++) {
                 if (strcmp(users[i].name, name) == 0) {
                     users[i].weight = new_weight;
                     break;
            // Update the user's weight in the `users` array
             for (int i = 0; i < user_count; i++) {               // Loop through all users in the `users` array
                 if (strcmp(users[i].name, name) == 0) {          // Check if the current user's name matches the given name
                     users[i].weight = new_weight;                // Update the weight for the matched user
                     break;                                       // Exit the loop once the user is found and updated
                 }
             }
 
 @@ -378,53 +377,53 @@ void enter_weight() {
 
 // OPTION 2 - FUNCTION TO ENTER HEIGHT
 void enter_height() {
     float new_height;
     float new_height;                                               // Variable to store the new height entered by the user
     printf("\n-----------------------------\n");
     printf("\nYou chose Option 2: 'Enter Height'\n\n");
     printf("Please choose from the following options: \n");
     printf("1 - View your current height\n");
     printf("2 - Change your current height\n");
     printf("3 - Return to the main menu\n");
     printf("1 - View your current height\n");                       // Option to view the current height
     printf("2 - Change your current height\n");                     // Option to change the current height
     printf("3 - Return to the main menu\n");                        // Option to return to the main menu
     printf("\nPlease enter your desired option: \n");
     scanf(" %d", &height_choice);
     scanf(" %d", &height_choice);                                   // Read the user's choice for height-related actions
     clear_input_buffer();
 
     switch (height_choice) {
         case 1:
         case 1:                                                     // Option to view the current height
             printf("\nYou chose Option 1: 'View your current height'\n");
             read_csv(name, "Height");
             read_csv(name, "Height");                               // Call the function to read and display the user's height from the CSV file
             clear_input_buffer();
             break;
 
         case 2:
         case 2:                                                     // Option to change the current height
             printf("\nYou chose Option 2: 'Change your current height'\n");
             printf("Please enter your new height! (in cm)\n");
             scanf("%f", &new_height);
             scanf("%f", &new_height);                               // Read the new height entered by the user
             clear_input_buffer();
 
             // Update the user's height in the `users` array
             for (int i = 0; i < user_count; i++) {
                 if (strcmp(users[i].name, name) == 0) {
                     users[i].height = new_height;
                     break;
             for (int i = 0; i < user_count; i++) {                  // Loop through all users in the `users` array
                 if (strcmp(users[i].name, name) == 0) {             // Check if the current user's name matches the given name
                     users[i].height = new_height;                   // Update the height for the matched user
                     break;                                          // Exit the loop once the user is found and updated
                 }
             }
 
             // Save the updated data to the CSV file
             write_csv("GymInfo.csv");
             write_csv("GymInfo.csv");                               // Write the updated `users` array back to the CSV file
 
             printf("\nNice! Your new height has been recorded!");
             printf("\nNice! Your new height has been recorded!");   // Confirmation message
             printf("\nPress ENTER to get back to the menu overview.\n");
             clear_input_buffer();
             break;
 
         case 3:
         case 3:  // Option to return to the main menu
             printf("\nYou chose Option 3: 'Return to the main menu'\n");
             printf("\nFeel free to come back if you change your mind!\nUntil then, press ENTER to get back to the menu overview.\n");
             clear_input_buffer();
             break;
 
         default:
         default:  // Handle invalid input
             printf("\nYou did not choose one of the valid options. Please press ENTER to get back to the main overview\n");
             clear_input_buffer();
             break;
 @@ -433,53 +432,53 @@ void enter_height() {
 
 // OPTION 3 - FUNCTION TO ENTER AGE
 void enter_age() {
     int new_age; // int because age can't be a decimal
     int new_age;                                                    // Variable to store the new age (int because age can't be a decimal)
     printf("\n-----------------------------\n");
     printf("\nYou chose Option 3: 'Enter Age'\n\n");
     printf("Please choose from the following options: \n");
     printf("1 - View your current age\n");
     printf("2 - Change your current age\n");
     printf("3 - Return to the main menu\n");
     printf("1 - View your current age\n");                          // Option to view the current age
     printf("2 - Change your current age\n");                        // Option to change the current age
     printf("3 - Return to the main menu\n");                        // Option to return to the main menu
     printf("\nPlease enter your desired option: \n");
     scanf(" %d", &age_choice); // scans for the user input of the age
     scanf(" %d", &age_choice);                                      // Read the user's choice for age-related actions
     clear_input_buffer();
 
     switch (age_choice) {
         case 1:
         case 1:                                                     // Option to view the current age
             printf("\nYou chose Option 1: 'View your current age'\n");
             read_csv(name, "Age");
             read_csv(name, "Age");                                  // Call the function to read and display the user's age from the CSV file
             clear_input_buffer();
             break;
 
         case 2:
         case 2:                                                     // Option to change the current age
             printf("\nYou chose Option 2: 'Change your current age'\n");
             printf("Please enter your new age:\n");
             scanf("%d", &new_age);
             scanf("%d", &new_age);                                  // Read the new age entered by the user
             clear_input_buffer();
 
             // Update the user's age in the `users` array
             for (int i = 0; i < user_count; i++) {
                 if (strcmp(users[i].name, name) == 0) {
                     users[i].age = new_age;
                     break;
             for (int i = 0; i < user_count; i++) {                  // Loop through all users in the `users` array
                 if (strcmp(users[i].name, name) == 0) {             // Check if the current user's name matches the given name
                     users[i].age = new_age;                         // Update the age for the matched user
                     break;                                          // Exit the loop once the user is found and updated
                 }
             }
 
             // Save the updated data to the CSV file
             write_csv("GymInfo.csv");
             write_csv("GymInfo.csv");                               // Write the updated `users` array back to the CSV file
 
             printf("\nNice! Your new age has been recorded!");
             printf("\nNice! Your new age has been recorded!");      // Confirmation message
             printf("\nPress ENTER to get back to the menu overview.\n");
             clear_input_buffer();
             break;
 
         case 3:
         case 3: // Option to return to the main menu
             printf("\nYou chose Option 3: 'Return to the main menu'\n");
             printf("\nFeel free to come back if you change your mind!\nUntil then, press ENTER to get back to the menu overview.\n");
             clear_input_buffer();
             break;
 
         default:
         default: // Handle invalid input
             printf("\nYou did not choose one of the valid options. Please press ENTER to get back to the main overview\n");
             clear_input_buffer();
             break;
 @@ -488,53 +487,53 @@ void enter_age() {
 
 // OPTION 4 - FUNCTION TO ENTER BENCH
 void enter_bench() {
     float new_bench;
     float new_bench;                                                // Variable to store the new bench press value
     printf("\n-----------------------------\n");
     printf("\nYou chose Option 4: 'Enter Bench'\n\n");
     printf("Please choose from the following options: \n");
     printf("1 - View your current bench\n");
     printf("2 - Change your current bench\n");
     printf("3 - Return to the main menu\n");
     printf("1 - View your current bench\n");                        // Option to view the current bench press
     printf("2 - Change your current bench\n");                      // Option to change the current bench press
     printf("3 - Return to the main menu\n");                        // Option to return to the main menu
     printf("\nPlease enter your desired option: \n");
     scanf(" %d", &bench_choice); // scans for the user input of 'bench'
     scanf(" %d", &bench_choice);                                    // Read the user's choice for bench-related actions
     clear_input_buffer();
 
     switch (bench_choice) {
         case 1:
         case 1:                                                     // Option to view the current bench press
             printf("\nYou chose Option 1: 'View your current bench'\n");
             read_csv(name, "Bench");
             read_csv(name, "Bench");                                // Call the function to read and display the user's bench press from the CSV file
             clear_input_buffer();
             break;
 
         case 2:
         case 2:                                                     // Option to change the current bench press
             printf("\nYou chose Option 2: 'Change your current bench'\n");
             printf("Please enter your new bench (in kg):\n");
             scanf("%f", &new_bench);
             scanf("%f", &new_bench);                                // Read the new bench press value entered by the user
             clear_input_buffer();
 
             // Update the user's bench in the `users` array
             for (int i = 0; i < user_count; i++) {
                 if (strcmp(users[i].name, name) == 0) {
                     users[i].bench = new_bench;
                     break;
             // Update the user's bench press in the `users` array
             for (int i = 0; i < user_count; i++) {                  // Loop through all users in the `users` array
                 if (strcmp(users[i].name, name) == 0) {             // Check if the current user's name matches the given name
                     users[i].bench = new_bench;                     // Update the bench press for the matched user
                     break;                                          // Exit the loop once the user is found and updated
                 }
             }
 
             // Save the updated data to the CSV file
             write_csv("GymInfo.csv");
             write_csv("GymInfo.csv");                               // Write the updated `users` array back to the CSV file
 
             printf("\nNice! Your new bench has been recorded!");
             printf("\nNice! Your new bench has been recorded!");    // Confirmation message
             printf("\nPress ENTER to get back to the menu overview.\n");
             clear_input_buffer();
             break;
 
         case 3:
         case 3: // Option to return to the main menu
             printf("\nYou chose Option 3: 'Return to the main menu'\n");
             printf("\nFeel free to come back if you change your mind!\nUntil then, press ENTER to get back to the menu overview.\n");
             clear_input_buffer();
             break;
 
         default:
         default: // Handle invalid input
             printf("\nYou did not choose one of the valid options. Please press ENTER to get back to the main overview\n");
             clear_input_buffer();
             break;
 @@ -543,53 +542,53 @@ void enter_bench() {
 
 // OPTION 5 - FUNCTION TO ENTER SQUAT
 void enter_squat() {
     float new_squat;
     float new_squat;                                                // Variable to store the new squat value
     printf("\n-----------------------------\n");
     printf("\nYou chose Option 5: 'Enter Squat'\n\n");
     printf("Please choose from the following options: \n");
     printf("1 - View your current squat\n");
     printf("2 - Change your current squat\n");
     printf("3 - Return to the main menu\n");
     printf("1 - View your current squat\n");                        // Option to view the current squat
     printf("2 - Change your current squat\n");                      // Option to change the current squat
     printf("3 - Return to the main menu\n");                        // Option to return to the main menu
     printf("\nPlease enter your desired option: \n");
     scanf(" %d", &squat_choice); // scans for the user input
     scanf(" %d", &squat_choice);                                    // Read the user's choice for squat-related actions
     clear_input_buffer();
 
     switch (squat_choice) {
         case 1:
         case 1:                                                     // Option to view the current squat
             printf("\nYou chose Option 1: 'View your current squat'\n");
             read_csv(name, "Squat");
             read_csv(name, "Squat");                                // Call the function to read and display the user's squat from the CSV file
             clear_input_buffer();
             break;
 
         case 2:
         case 2:                                                     // Option to change the current squat
             printf("\nYou chose Option 2: 'Change your current squat'\n");
             printf("Please enter your new squat (in kg):\n");
             scanf("%f", &new_squat);
             scanf("%f", &new_squat);                                // Read the new squat value entered by the user
             clear_input_buffer();
 
             // Update the user's squat in the `users` array
             for (int i = 0; i < user_count; i++) {
                 if (strcmp(users[i].name, name) == 0) {
                     users[i].squat = new_squat;
                     break;
             for (int i = 0; i < user_count; i++) {                  // Loop through all users in the `users` array
                 if (strcmp(users[i].name, name) == 0) {             // Check if the current user's name matches the given name
                     users[i].squat = new_squat;                     // Update the squat for the matched user
                     break;                                          // Exit the loop once the user is found and updated
                 }
             }
 
             // Save the updated data to the CSV file
             write_csv("GymInfo.csv");
             write_csv("GymInfo.csv");                               // Write the updated `users` array back to the CSV file
 
             printf("\nNice! Your new squat has been recorded!");
             printf("\nNice! Your new squat has been recorded!");    // Confirmation message
             printf("\nPress ENTER to get back to the menu overview.\n");
             clear_input_buffer();
             break;
 
         case 3:
         case 3: // Option to return to the main menu
             printf("\nYou chose Option 3: 'Return to the main menu'\n");
             printf("\nFeel free to come back if you change your mind!\nUntil then, press ENTER to get back to the menu overview.\n");
             clear_input_buffer();
             break;
 
         default:
         default: // Handle invalid input
             printf("\nYou did not choose one of the valid options. Please press ENTER to get back to the main overview\n");
             clear_input_buffer();
             break;
 @@ -598,90 +597,89 @@ void enter_squat() {
 
 // OPTION 6 - FUNCTION TO ENTER DEADLIFT
 void enter_deadlift() {
     float new_dl;
     float new_dl;                                                   // Variable to store the new deadlift value
     printf("\n-----------------------------\n");
     printf("\nYou chose Option 6: 'Enter Deadlift'\n\n");
     printf("Please choose from the following options: \n");
     printf("1 - View your current deadlift\n");
     printf("2 - Change your current deadlift\n");
     printf("3 - Return to the main menu\n");
     printf("1 - View your current deadlift\n");                     // Option to view the current deadlift
     printf("2 - Change your current deadlift\n");                   // Option to change the current deadlift
     printf("3 - Return to the main menu\n");                        // Option to return to the main menu
     printf("\nPlease enter your desired option: \n");
     scanf(" %d", &deadlift_choice); // scans for the user input
     scanf(" %d", &deadlift_choice);                                 // Read the user's choice for deadlift-related actions
     clear_input_buffer();
 
     switch (deadlift_choice) {
         case 1:
         case 1:                                                     // Option to view the current deadlift
             printf("\nYou chose Option 1: 'View your current deadlift'\n");
             read_csv(name, "Deadlift");
             read_csv(name, "Deadlift");                             // Call the function to read and display the user's deadlift from the CSV file
             clear_input_buffer();
             break;
 
         case 2:
         case 2:                                                     // Option to change the current deadlift
             printf("\nYou chose Option 2: 'Change your current deadlift'\n");
             printf("Please enter your new deadlift (in kg):\n");
             scanf("%f", &new_dl);
             scanf("%f", &new_dl);                                   // Read the new deadlift value entered by the user
             clear_input_buffer();
 
             // Update the user's deadlift in the `users` array
             for (int i = 0; i < user_count; i++) {
                 if (strcmp(users[i].name, name) == 0) {
                     users[i].deadlift = new_dl;
                     break;
             for (int i = 0; i < user_count; i++) {                  // Loop through all users in the `users` array
                 if (strcmp(users[i].name, name) == 0) {             // Check if the current user's name matches the given name
                     users[i].deadlift = new_dl;                     // Update the deadlift for the matched user
                     break;                                          // Exit the loop once the user is found and updated
                 }
             }
 
             // Save the updated data to the CSV file
             write_csv("GymInfo.csv");
             write_csv("GymInfo.csv");                               // Write the updated `users` array back to the CSV file
 
             printf("\nNice! Your new deadlift has been recorded!");
             printf("\nNice! Your new deadlift has been recorded!"); // Confirmation message
             printf("\nPress ENTER to get back to the menu overview.\n");
             clear_input_buffer();
             break;
 
         case 3:
         case 3: // Option to return to the main menu
             printf("\nYou chose Option 3: 'Return to the main menu'\n");
             printf("\nFeel free to come back if you change your mind!\nUntil then, press ENTER to get back to the menu overview.\n");
             clear_input_buffer();
             break;
 
         default:
         default: // Handle invalid input
             printf("\nYou did not choose one of the valid options. Please press ENTER to get back to the main overview\n");
             clear_input_buffer();
             break;
     }
 }
 
 
 
 //OPTION 7 - DELETE ACCOUNT
 // OPTION 7 - DELETE ACCOUNT
 void delete_account() {
     char delete_name[50];
     char delete_name[50];                                                   // Variable to store the name of the account to delete
     printf("\n-----------------------------\n");
     printf("Enter the name of the account you want to delete: ");
     clear_input_buffer();
     fgets(delete_name, sizeof(delete_name), stdin);
     delete_name[strcspn(delete_name, "\n")] = '\0';  // Remove the newline character
     fgets(delete_name, sizeof(delete_name), stdin);                         // Read the name entered by the user
     delete_name[strcspn(delete_name, "\n")] = '\0';                         // Remove the newline character
 
     // Trim leading and trailing whitespace from the input name
     char *start = delete_name;
     while (*start == ' ') start++;  // Skip leading spaces
     while (*start == ' ') start++;                                          // Skip leading spaces
     char *end = start + strlen(start) - 1;
     while (end > start && (*end == ' ' || *end == '\n')) *end-- = '\0';  // Remove trailing spaces
     memmove(delete_name, start, end - start + 2);  // Shift the trimmed string to the beginning
     while (end > start && (*end == ' ' || *end == '\n')) *end-- = '\0';     // Remove trailing spaces
     memmove(delete_name, start, end - start + 2);                           // Shift the trimmed string to the beginning
 
     int found = 0;
     int found = 0;                                                          // Flag to check if the account was found
 
     // Search for the user in the `users` array
     for (int i = 0; i < user_count; i++) {
         if (strcasecmp(users[i].name, delete_name) == 0) {  // Case-insensitive comparison
         if (strcasecmp(users[i].name, delete_name) == 0) {                  // Case-insensitive comparison
             found = 1;
 
             // Shift all subsequent users one position to the left
             for (int j = i; j < user_count - 1; j++) {
                 users[j] = users[j + 1];
             }
 
             user_count--;  // Decrease the user count
             user_count--;                                                   // Decrease the user count
             break;
         }
     }
 @@ -698,43 +696,46 @@ void delete_account() {
 }
 
 
 
 //FUNCTION TO WRITE IN CSV FILE
 // FUNCTION TO WRITE IN CSV FILE
 void write_csv(const char *filename) {
     FILE *file = fopen(filename, "w");  // Open the file for writing
     FILE *file = fopen(filename, "w");                                      // Open the file for writing
     if (!file) {
         perror("Failed to open CSV file for writing");
         perror("Failed to open CSV file for writing");                      // Print error message if the file cannot be opened
         return;
     }
 
     // Write all users to the CSV file
     for (int i = 0; i < user_count; i++) {
         fprintf(file, "%s;%.1f;%.1f;%d;%.1f;%.1f;%.1f\n", users[i].name, users[i].weight, users[i].height,
                 users[i].age, users[i].bench, users[i].squat, users[i].deadlift);
         fprintf(file, "%s;%.1f;%.1f;%d;%.1f;%.1f;%.1f\n", 
                 users[i].name, 
                 users[i].weight, 
                 users[i].height,
                 users[i].age, 
                 users[i].bench, 
                 users[i].squat, 
                 users[i].deadlift);                                         // Write user data in CSV format
     }
 
     fclose(file);  // Close the file
     fclose(file);                                                           // Close the file
 }
 
 
 // FUNCTION TO READ FROM THE CSV FILE
 void read_csv(const char *name, const char *area) {
     FILE *file = fopen("GymInfo.csv", "r");  // Open the CSV file for reading
     FILE *file = fopen("GymInfo.csv", "r");                                 // Open the CSV file for reading
     if (!file) {
         perror("Failed to open CSV file");
         perror("Failed to open CSV file");                                  // Print error message if the file cannot be opened
         return;
     }
 
     char file_name[50];
     int found = 0;
     char file_name[50];                                                     // Buffer to store the name from the file
     int found = 0;                                                          // Flag to check if the user was found
 
     // Read each line from the CSV file
     while (fgets(line, sizeof(line), file)) {
         // Extract the name from the current line (assumes names are the first field in the CSV)
         sscanf(line, "%49[^;]", file_name);  // Read up to the first semicolon (;)
     while (fgets(line, sizeof(line), file)) {                                                              
         sscanf(line, "%49[^;]", file_name);                                 // Extract the name from the current line (assumes names are the first field in the CSV) and read up to the first semicolon (;)
 
         // Check if the entered name matches the name in the file
         if (strcmp(name, file_name) == 0) {
         if (strcmp(name, file_name) == 0) {                                 // Check if the entered name matches the name in the file
             found = 1;
 
             // Parse the rest of the line into a temporary user struct
 @@ -764,11 +765,11 @@ void read_csv(const char *name, const char *area) {
             else
                 printf("Unknown area: %s\n", area);
 
             break;  // Exit the loop once the user is found
             break;                                                          // Exit the loop once the user is found
         }
     }
 
     fclose(file);  // Close the file
     fclose(file);                                                           // Close the file
 
     // If no user was found, display an error message
     if (!found) {
 @@ -782,33 +783,33 @@ void read_csv(const char *name, const char *area) {
 
         if (choice == 1) {
             printf("\nGreat! Let's create your account.\n");
             create_account(); //Call the function to create a new account
             create_account();                                               // Call the function to create a new account
         } else if (choice == 2) {
             printf("\nThank you for visiting! Goodbye.\n");
             exit(0); //exit the program
             exit(0);                                                        // Exit the program
         } else {
             printf("\nInvalid choice. Returning to the main menu.\n");
             display_menu(); //Redirect to the main menu
             display_menu();                                                 // Redirect to the main menu
         }
     }
 }
 
 // FUNCTION TO LOAD ALL USER DATA FROM CSV FILE INTO THE USERS ARRAY
 void load_csv(const char *filename) {
     FILE *file = fopen(filename, "r");  // Open the CSV file for reading
     FILE *file = fopen(filename, "r");                                      // Open the CSV file for reading
     if (!file) {
         perror("Failed to open CSV file");
         perror("Failed to open CSV file");                                  // Print error message if the file cannot be opened
         return;
     }
 
     user_count = 0;
     user_count = 0;                                                         // Reset the user count
 
     // Clear the `users` array to avoid leftover data
     memset(users, 0, sizeof(users));
 
     // Read each line from the CSV file
     while (fgets(line, sizeof(line), file)) {
         if (user_count >= MAX_USERS) {
         if (user_count >= MAX_USERS) {                                      // Check if the maximum user limit is reached
             printf("Maximum user limit reached. Cannot load more users.\n");
             break;
         }
 @@ -831,5 +832,6 @@ void load_csv(const char *filename) {
         }
     }
 
     fclose(file);  // Close the file
     fclose(file);                                                           // Close the file
 }
