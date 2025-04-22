// THE CODE HAS NOT BEEN TESTED
// THIS IS JUST FRAME WORK FOR OUR OWN CODE
//IT IS SUPPOSED TO PROVIDE IDEAS FOR WHAT TO CODE




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 50
#define MAX_LINE_LENGTH 128

// Define the GymUser structure with reasonable sizes.
typedef struct {
    char name[30];   // Reduced size for name
    int age;
    float height;    // in centimeters
    float weight;    // in kilograms
    int bench;       // bench press record (kg)
    int squat;       // squat record (kg)
    int deadlift;    // deadlift record (kg)
} GymUser;

// Helper function to remove trailing newline from a string.
void trimNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}

// Reads an integer from a string safely.
int readInteger(const char *prompt) {
    char input[16];
    printf("%s", prompt);
    fgets(input, sizeof(input), stdin);
    trimNewline(input);
    return atoi(input);
}

// Reads a float from a string safely.
float readFloat(const char *prompt) {
    char input[16];
    printf("%s", prompt);
    fgets(input, sizeof(input), stdin);
    trimNewline(input);
    return atof(input);
}

// Function to input a new gym entry.
void createNewEntry(GymUser *user) {
    char input[30];

    printf("Enter name: ");
    fgets(user->name, sizeof(user->name), stdin);
    trimNewline(user->name);

    user->age = readInteger("Enter age: ");

    user->height = readFloat("Enter height (in cm): ");

    user->weight = readFloat("Enter weight (in kg): ");

    user->bench = readInteger("Enter bench press record (kg): ");

    user->squat = readInteger("Enter squat record (kg): ");

    user->deadlift = readInteger("Enter deadlift record (kg): ");
}

// Function to append a gym entry to the CSV file.
void saveUserToFile(const char* filename, GymUser user) {
    FILE *fp = fopen(filename, "a");  // Open for appending.
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    // Write entry in CSV format.
    fprintf(fp, "%s,%d,%.2f,%.2f,%d,%d,%d\n",
            user.name, user.age, user.height, user.weight,
            user.bench, user.squat, user.deadlift);
    fclose(fp);
    printf("Entry saved successfully.\n");
}

// Function to load gym users from the CSV file into an array.
// Returns the number of users loaded.
int loadUsersFromFile(const char* filename, GymUser users[], int maxEntries) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return 0;
    }
    char line[MAX_LINE_LENGTH];
    int count = 0;

    // Read and skip header line.
    if (fgets(line, sizeof(line), fp) == NULL) {
        fclose(fp);
        return 0;
    }
    
    while (fgets(line, sizeof(line), fp) && count < maxEntries) {
        trimNewline(line);
        // Tokenize line, expected order: Name,Age,Height,Weight,Bench,Squat,Deadlift.
        char *token = strtok(line, ",");
        if (token == NULL) continue;
        strncpy(users[count].name, token, sizeof(users[count].name));
        
        token = strtok(NULL, ",");
        users[count].age = token ? atoi(token) : 0;
        
        token = strtok(NULL, ",");
        users[count].height = token ? atof(token) : 0.0;
        
        token = strtok(NULL, ",");
        users[count].weight = token ? atof(token) : 0.0;
        
        token = strtok(NULL, ",");
        users[count].bench = token ? atoi(token) : 0;
        
        token = strtok(NULL, ",");
        users[count].squat = token ? atoi(token) : 0;
        
        token = strtok(NULL, ",");
        users[count].deadlift = token ? atoi(token) : 0;
        
        count++;
    }
    fclose(fp);
    return count;
}

// Function to search for an entry by name (case insensitive).
void searchUserByName(GymUser users[], int count, const char* name) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        char lowerUser[30], lowerName[30];
    }
}
