// gymlib.h
#ifndef GYMLIB_H
#define GYMLIB_H

#define max_attempts 3          // Maximum attempts allowed
#define MAX_LINE_LENGTH 256     // Maximum line length for the CSV file
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

// GLOBAL VARIABLES (declared as extern)
extern char name[50];
extern char file_name[50];
extern char line[MAX_LINE_LENGTH];
extern struct user users[MAX_USERS];
extern int user_count;
extern int invalid_attempts;
extern int menu_choice;
extern int height_choice;
extern int weight_choice;
extern int age_choice;
extern int bench_choice;
extern int squat_choice;
extern int deadlift_choice;

// FUNCTION DECLARATIONS
void enter_name(void);
void check_account(char* name);
void create_account(void);
void clear_input_buffer(void);
void display_menu(void);
void enter_weight(void);
void enter_height(void);
void enter_age(void);
void enter_bench(void);
void enter_squat(void);
void enter_deadlift(void);
void delete_account(void);
void write_csv(const char* filename);
void read_csv(const char* name, const char* area);
void load_csv(const char* filename);

#endif // GYMLIB_H
