#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gymlib.h"

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
