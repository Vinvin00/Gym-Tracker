// FUNCTION TO CREATE NEW ACCOUNT
void create_account() {

    char name[50];
    float weight;
    float height;
    int age;

    // Asks user to input name
    printf("Please enter your name: ");       
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';               // Remove the newline character from the input

    if (strlen(name) == 0) {                        // Check if the name is empty
        printf("Name cannot be empty. Please try again.\n");
        return;
    }

// FUNTION TO ENTER NAME TO SEE IF YOURE IN THE DATA BASE
void enter_name(void) {
    printf("\n-----------------------------\n");
    printf("\nHello You!\nWelcome to this Gym Tracker! \n\nPlease enter your name so we can see if you're already in our data bank!\n\n");
    printf("Name: ");
    fgets(name, sizeof(name), stdin);               // scans for the user input of the name
    name[strcspn(name, "\n")] = '\0';               // Remove the newline character from the input
    printf("\n-----------------------------\n");
    printf("\nYou entered the name: %s\n", name);   // scans for the user's name input and displays it here if the user entered it
    check_account(name);                            // checks if name is already in the data bank 
}


// FUNCTION TO CHECK IF NAME IS IN THE DATABASE
void check_account(char* name) {
    FILE* file = fopen("GymInfo.csv", "r");         // Open the CSV file for reading
    if (file == NULL) {
        perror("Failed to open file");              // Print error message
        return;
    }

    int found = 0;

    while (fgets(line, sizeof(line), file)) {       // Read each line from the CSV
 
        sscanf(line, "%49[^;]", file_name);         // Extract the name from the current line

        if (strcmp(name, file_name) == 0) {         // Check if the entered name matches the name in the file
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
            create_account();                       // Call the function to create a new account
        } else if (choice == 2) {
            printf("\nThank you for visiting! Goodbye.\n");
            exit(0);                                // Exit the program
        } else {
            printf("\nInvalid choice. Returning to the main menu.\n");
            display_menu();                         // Redirect to the main menu
        }
    }
}

// FUNCTION TO CLEAR INPUT BUFFER
void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);        // Read and discard characters from the input buffer until a newline ('\n') or EOF is encountered
}


// FUNCTION TO PRINT OUT THE MENU
void display_menu(void){
    printf("\n-----------------------------\n");        // soley for visual purpose, to make it more visually appealing
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
    scanf(" %d", &menu_choice);                         // scans for the user input of the menu choice
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
    scanf(" %d", &weight_choice);                       // scans for the user input
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
            for (int i = 0; i < user_count; i++) {               // Loop through all users in the `users` array
                if (strcmp(users[i].name, name) == 0) {          // Check if the current user's name matches the given name
                    users[i].weight = new_weight;                // Update the weight for the matched user
                    break;                                       // Exit the loop once the user is found and updated
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
    float new_height;                                               // Variable to store the new height entered by the user
    printf("\n-----------------------------\n");
    printf("\nYou chose Option 2: 'Enter Height'\n\n");
    printf("Please choose from the following options: \n");
    printf("1 - View your current height\n");                       // Option to view the current height
    printf("2 - Change your current height\n");                     // Option to change the current height
    printf("3 - Return to the main menu\n");                        // Option to return to the main menu
    printf("\nPlease enter your desired option: \n");
    scanf(" %d", &height_choice);                                   // Read the user's choice for height-related actions
    clear_input_buffer();

    switch (height_choice) {
        case 1:                                                     // Option to view the current height
            printf("\nYou chose Option 1: 'View your current height'\n");
            read_csv(name, "Height");                               // Call the function to read and display the user's height from the CSV file
            clear_input_buffer();
            break;

        case 2:                                                     // Option to change the current height
            printf("\nYou chose Option 2: 'Change your current height'\n");
            printf("Please enter your new height! (in cm)\n");
            scanf("%f", &new_height);                               // Read the new height entered by the user
            clear_input_buffer();

            // Update the user's height in the `users` array
            for (int i = 0; i < user_count; i++) {                  // Loop through all users in the `users` array
                if (strcmp(users[i].name, name) == 0) {             // Check if the current user's name matches the given name
                    users[i].height = new_height;                   // Update the height for the matched user
                    break;                                          // Exit the loop once the user is found and updated
                }
            }

            // Save the updated data to the CSV file
            write_csv("GymInfo.csv");                               // Write the updated `users` array back to the CSV file

            printf("\nNice! Your new height has been recorded!");   // Confirmation message
            printf("\nPress ENTER to get back to the menu overview.\n");
            clear_input_buffer();
            break;

        case 3:  // Option to return to the main menu
            printf("\nYou chose Option 3: 'Return to the main menu'\n");
            printf("\nFeel free to come back if you change your mind!\nUntil then, press ENTER to get back to the menu overview.\n");
            clear_input_buffer();
            break;

        default:  // Handle invalid input
            printf("\nYou did not choose one of the valid options. Please press ENTER to get back to the main overview\n");
            clear_input_buffer();
            break;
    }
}

// OPTION 3 - FUNCTION TO ENTER AGE
void enter_age() {
    int new_age;                                                    // Variable to store the new age (int because age can't be a decimal)
    printf("\n-----------------------------\n");
    printf("\nYou chose Option 3: 'Enter Age'\n\n");
    printf("Please choose from the following options: \n");
    printf("1 - View your current age\n");                          // Option to view the current age
    printf("2 - Change your current age\n");                        // Option to change the current age
    printf("3 - Return to the main menu\n");                        // Option to return to the main menu
    printf("\nPlease enter your desired option: \n");
    scanf(" %d", &age_choice);                                      // Read the user's choice for age-related actions
    clear_input_buffer();

    switch (age_choice) {
        case 1:                                                     // Option to view the current age
            printf("\nYou chose Option 1: 'View your current age'\n");
            read_csv(name, "Age");                                  // Call the function to read and display the user's age from the CSV file
            clear_input_buffer();
            break;

        case 2:                                                     // Option to change the current age
            printf("\nYou chose Option 2: 'Change your current age'\n");
            printf("Please enter your new age:\n");
            scanf("%d", &new_age);                                  // Read the new age entered by the user
            clear_input_buffer();

            // Update the user's age in the `users` array
            for (int i = 0; i < user_count; i++) {                  // Loop through all users in the `users` array
                if (strcmp(users[i].name, name) == 0) {             // Check if the current user's name matches the given name
                    users[i].age = new_age;                         // Update the age for the matched user
                    break;                                          // Exit the loop once the user is found and updated
                }
            }

            // Save the updated data to the CSV file
            write_csv("GymInfo.csv");                               // Write the updated `users` array back to the CSV file

            printf("\nNice! Your new age has been recorded!");      // Confirmation message
            printf("\nPress ENTER to get back to the menu overview.\n");
            clear_input_buffer();
            break;

        case 3: // Option to return to the main menu
            printf("\nYou chose Option 3: 'Return to the main menu'\n");
            printf("\nFeel free to come back if you change your mind!\nUntil then, press ENTER to get back to the menu overview.\n");
            clear_input_buffer();
            break;

        default: // Handle invalid input
            printf("\nYou did not choose one of the valid options. Please press ENTER to get back to the main overview\n");
            clear_input_buffer();
            break;
    }
}

// OPTION 4 - FUNCTION TO ENTER BENCH
void enter_bench() {
    float new_bench;                                                // Variable to store the new bench press value
    printf("\n-----------------------------\n");
    printf("\nYou chose Option 4: 'Enter Bench'\n\n");
    printf("Please choose from the following options: \n");
    printf("1 - View your current bench\n");                        // Option to view the current bench press
    printf("2 - Change your current bench\n");                      // Option to change the current bench press
    printf("3 - Return to the main menu\n");                        // Option to return to the main menu
    printf("\nPlease enter your desired option: \n");
    scanf(" %d", &bench_choice);                                    // Read the user's choice for bench-related actions
    clear_input_buffer();

    switch (bench_choice) {
        case 1:                                                     // Option to view the current bench press
            printf("\nYou chose Option 1: 'View your current bench'\n");
            read_csv(name, "Bench");                                // Call the function to read and display the user's bench press from the CSV file
            clear_input_buffer();
            break;

        case 2:                                                     // Option to change the current bench press
            printf("\nYou chose Option 2: 'Change your current bench'\n");
            printf("Please enter your new bench (in kg):\n");
            scanf("%f", &new_bench);                                // Read the new bench press value entered by the user
            clear_input_buffer();

            // Update the user's bench press in the `users` array
            for (int i = 0; i < user_count; i++) {                  // Loop through all users in the `users` array
                if (strcmp(users[i].name, name) == 0) {             // Check if the current user's name matches the given name
                    users[i].bench = new_bench;                     // Update the bench press for the matched user
                    break;                                          // Exit the loop once the user is found and updated
                }
            }

            // Save the updated data to the CSV file
            write_csv("GymInfo.csv");                               // Write the updated `users` array back to the CSV file

            printf("\nNice! Your new bench has been recorded!");    // Confirmation message
            printf("\nPress ENTER to get back to the menu overview.\n");
            clear_input_buffer();
            break;

        case 3: // Option to return to the main menu
            printf("\nYou chose Option 3: 'Return to the main menu'\n");
            printf("\nFeel free to come back if you change your mind!\nUntil then, press ENTER to get back to the menu overview.\n");
            clear_input_buffer();
            break;

        default: // Handle invalid input
            printf("\nYou did not choose one of the valid options. Please press ENTER to get back to the main overview\n");
            clear_input_buffer();
            break;
    }
}

// OPTION 5 - FUNCTION TO ENTER SQUAT
void enter_squat() {
    float new_squat;                                                // Variable to store the new squat value
    printf("\n-----------------------------\n");
    printf("\nYou chose Option 5: 'Enter Squat'\n\n");
    printf("Please choose from the following options: \n");
    printf("1 - View your current squat\n");                        // Option to view the current squat
    printf("2 - Change your current squat\n");                      // Option to change the current squat
    printf("3 - Return to the main menu\n");                        // Option to return to the main menu
    printf("\nPlease enter your desired option: \n");
    scanf(" %d", &squat_choice);                                    // Read the user's choice for squat-related actions
    clear_input_buffer();

    switch (squat_choice) {
        case 1:                                                     // Option to view the current squat
            printf("\nYou chose Option 1: 'View your current squat'\n");
            read_csv(name, "Squat");                                // Call the function to read and display the user's squat from the CSV file
            clear_input_buffer();
            break;

        case 2:                                                     // Option to change the current squat
            printf("\nYou chose Option 2: 'Change your current squat'\n");
            printf("Please enter your new squat (in kg):\n");
            scanf("%f", &new_squat);                                // Read the new squat value entered by the user
            clear_input_buffer();

            // Update the user's squat in the `users` array
            for (int i = 0; i < user_count; i++) {                  // Loop through all users in the `users` array
                if (strcmp(users[i].name, name) == 0) {             // Check if the current user's name matches the given name
                    users[i].squat = new_squat;                     // Update the squat for the matched user
                    break;                                          // Exit the loop once the user is found and updated
                }
            }

            // Save the updated data to the CSV file
            write_csv("GymInfo.csv");                               // Write the updated `users` array back to the CSV file

            printf("\nNice! Your new squat has been recorded!");    // Confirmation message
            printf("\nPress ENTER to get back to the menu overview.\n");
            clear_input_buffer();
            break;

        case 3: // Option to return to the main menu
            printf("\nYou chose Option 3: 'Return to the main menu'\n");
            printf("\nFeel free to come back if you change your mind!\nUntil then, press ENTER to get back to the menu overview.\n");
            clear_input_buffer();
            break;

        default: // Handle invalid input
            printf("\nYou did not choose one of the valid options. Please press ENTER to get back to the main overview\n");
            clear_input_buffer();
            break;
    }
}

// OPTION 6 - FUNCTION TO ENTER DEADLIFT
void enter_deadlift() {
    float new_dl;                                                   // Variable to store the new deadlift value
    printf("\n-----------------------------\n");
    printf("\nYou chose Option 6: 'Enter Deadlift'\n\n");
    printf("Please choose from the following options: \n");
    printf("1 - View your current deadlift\n");                     // Option to view the current deadlift
    printf("2 - Change your current deadlift\n");                   // Option to change the current deadlift
    printf("3 - Return to the main menu\n");                        // Option to return to the main menu
    printf("\nPlease enter your desired option: \n");
    scanf(" %d", &deadlift_choice);                                 // Read the user's choice for deadlift-related actions
    clear_input_buffer();

    switch (deadlift_choice) {
        case 1:                                                     // Option to view the current deadlift
            printf("\nYou chose Option 1: 'View your current deadlift'\n");
            read_csv(name, "Deadlift");                             // Call the function to read and display the user's deadlift from the CSV file
            clear_input_buffer();
            break;

        case 2:                                                     // Option to change the current deadlift
            printf("\nYou chose Option 2: 'Change your current deadlift'\n");
            printf("Please enter your new deadlift (in kg):\n");
            scanf("%f", &new_dl);                                   // Read the new deadlift value entered by the user
            clear_input_buffer();

            // Update the user's deadlift in the `users` array
            for (int i = 0; i < user_count; i++) {                  // Loop through all users in the `users` array
                if (strcmp(users[i].name, name) == 0) {             // Check if the current user's name matches the given name
                    users[i].deadlift = new_dl;                     // Update the deadlift for the matched user
                    break;                                          // Exit the loop once the user is found and updated
                }
            }

            // Save the updated data to the CSV file
            write_csv("GymInfo.csv");                               // Write the updated `users` array back to the CSV file

            printf("\nNice! Your new deadlift has been recorded!"); // Confirmation message
            printf("\nPress ENTER to get back to the menu overview.\n");
            clear_input_buffer();
            break;

        case 3: // Option to return to the main menu
            printf("\nYou chose Option 3: 'Return to the main menu'\n");
            printf("\nFeel free to come back if you change your mind!\nUntil then, press ENTER to get back to the menu overview.\n");
            clear_input_buffer();
            break;

        default: // Handle invalid input
            printf("\nYou did not choose one of the valid options. Please press ENTER to get back to the main overview\n");
            clear_input_buffer();
            break;
    }
}


// OPTION 7 - DELETE ACCOUNT
void delete_account() {
    char delete_name[50];                                                   // Variable to store the name of the account to delete
    printf("\n-----------------------------\n");
    printf("Enter the name of the account you want to delete: ");
    clear_input_buffer();
    fgets(delete_name, sizeof(delete_name), stdin);                         // Read the name entered by the user
    delete_name[strcspn(delete_name, "\n")] = '\0';                         // Remove the newline character

    // Trim leading and trailing whitespace from the input name
    char *start = delete_name;
    while (*start == ' ') start++;                                          // Skip leading spaces
    char *end = start + strlen(start) - 1;
    while (end > start && (*end == ' ' || *end == '\n')) *end-- = '\0';     // Remove trailing spaces
    memmove(delete_name, start, end - start + 2);                           // Shift the trimmed string to the beginning

    int found = 0;                                                          // Flag to check if the account was found

    // Search for the user in the `users` array
    for (int i = 0; i < user_count; i++) {
        if (strcasecmp(users[i].name, delete_name) == 0) {                  // Case-insensitive comparison
            found = 1;

            // Shift all subsequent users one position to the left
            for (int j = i; j < user_count - 1; j++) {
                users[j] = users[j + 1];
            }

            user_count--;                                                   // Decrease the user count
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


// FUNCTION TO WRITE IN CSV FILE
void write_csv(const char *filename) {
    FILE *file = fopen(filename, "w");                                      // Open the file for writing
    if (!file) {
        perror("Failed to open CSV file for writing");                      // Print error message if the file cannot be opened
        return;
    }

    // Write all users to the CSV file
    for (int i = 0; i < user_count; i++) {
        fprintf(file, "%s;%.1f;%.1f;%d;%.1f;%.1f;%.1f\n", 
                users[i].name, 
                users[i].weight, 
                users[i].height,
                users[i].age, 
                users[i].bench, 
                users[i].squat, 
                users[i].deadlift);                                         // Write user data in CSV format
    }

    fclose(file);                                                           // Close the file
}


// FUNCTION TO READ FROM THE CSV FILE
void read_csv(const char *name, const char *area) {
    FILE *file = fopen("GymInfo.csv", "r");                                 // Open the CSV file for reading
    if (!file) {
        perror("Failed to open CSV file");                                  // Print error message if the file cannot be opened
        return;
    }

    char file_name[50];                                                     // Buffer to store the name from the file
    int found = 0;                                                          // Flag to check if the user was found

    // Read each line from the CSV file
    while (fgets(line, sizeof(line), file)) {                                                              
        sscanf(line, "%49[^;]", file_name);                                 // Extract the name from the current line (assumes names are the first field in the CSV) and read up to the first semicolon (;)

        if (strcmp(name, file_name) == 0) {                                 // Check if the entered name matches the name in the file
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

            break;                                                          // Exit the loop once the user is found
        }
    }

    fclose(file);                                                           // Close the file

    // If no user was found, display an error message
    if (!found) {
        printf("Sorry, no user with the name \"%s\" was found.\n", name);
        printf("\nWould you like to create a new account?\n");
        printf("\nEnter 1 to create an account or 2 to exit: ");

        int choice;
        scanf("%d", &choice);
        clear_input_buffer();

        if (choice == 1) {
            printf("\nGreat! Let's create your account.\n");
            create_account();                                               // Call the function to create a new account
        } else if (choice == 2) {
            printf("\nThank you for visiting! Goodbye.\n");
            exit(0);                                                        // Exit the program
        } else {
            printf("\nInvalid choice. Returning to the main menu.\n");
            display_menu();                                                 // Redirect to the main menu
        }
    }
}
