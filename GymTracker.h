// GymTracker.h

#ifndef GYMTRACKER_H
#define GYMTRACKER_H

// Preprocessor directives
#define MAX_USERS 50
#define MAX_LINE_LENGTH 128

// Structure
typedef struct {
    char name[30];  // Name (up to 29 characters + null terminator)
    int age;
    float height;   // Height in centimeters
    float weight;   // Weight in kilograms
    int bench;      // Bench press record (kg)
    int squat;      // Squat record (kg)
    int deadlift;   // Deadlift record (kg)
} GymUser;

// Function declarations
void trimNewline(char *str);
int readInteger(const char *prompt);
float readFloat(const char *prompt);

void createNewEntry(GymUser *user);                         // Create a new user entry
void saveUserToFile(const char *filename, GymUser user);     // Save a user entry to file
int loadUsersFromFile(const char *filename, GymUser users[], int maxEntries); // Load users from file
void searchUserByName(GymUser users[], int count, const char *name);          // Search for user by name

#endif // GYMTRACKER_H
