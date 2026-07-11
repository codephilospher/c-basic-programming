#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * @file student_records.c
 * @brief Elegant HackerRank-style challenge solution implementing structs, enums,
 * arrays, and functions for a high-performance Student Record Analytics System.
 *
 * This system models real-world grading evaluation mechanics by leveraging 
 * advanced C concepts such as enum reflection, custom array-of-structures query 
 * pipelines, and strict memory safety.
 */

#define MAX_NAME_LEN 64
#define MAX_SUBJECTS 5
#define MAX_STUDENTS 100

/**
 * @brief Enum representing subject categories for categorization and analytics.
 */
typedef enum {
    CAT_MATHEMATICS = 0,
    CAT_SCIENCE,
    CAT_LITERATURE,
    CAT_HISTORY,
    CAT_COUNT /* Utility sentinel value for boundaries */
} SubjectCategory;

/**
 * @brief Structure representing a Subject taken by a student.
 */
typedef struct {
    char name[MAX_NAME_LEN];
    SubjectCategory category;
    double score;
} Subject;

/**
 * @brief Structure representing a Student containing profile and grading metrics.
 */
typedef struct {
    unsigned int id;
    char name[MAX_NAME_LEN];
    Subject enrolled_subjects[MAX_SUBJECTS];
    int subject_count;
    double calculated_gpa;
} Student;

/* ========================================================================= */
/*                           FUNCTION DECLARATIONS                           */
/* ========================================================================= */

const char* get_category_name(SubjectCategory category);
bool register_subject(Student* student, const char* name, SubjectCategory cat, double score);
void update_student_gpa(Student* student);
void print_student_report(const Student* student);
const Student* find_top_performer(const Student students[], int student_count);
int filter_students_by_category_score(const Student students[], int student_count, 
                                      SubjectCategory target_cat, double threshold_score, 
                                      const Student* filtered_results[]);
void sort_students_by_gpa(Student students[], int student_count);

/* ========================================================================= */
/*                               MAIN DRIVER                                 */
/* ========================================================================= */

int main(void) {
    printf("=== STUDENT RECORD ANALYTICS SYSTEM INITIALIZED ===\n\n");

    /* Initialize mock array of students (HackerRank style input mockup) */
    Student database[MAX_STUDENTS] = {
        { .id = 101, .name = "Alice Vance", .subject_count = 0, .calculated_gpa = 0.0 },
        { .id = 102, .name = "Bob Miller", .subject_count = 0, .calculated_gpa = 0.0 },
        { .id = 103, .name = "Charlie Cox", .subject_count = 0, .calculated_gpa = 0.0 },
        { .id = 104, .name = "Diana Prince", .subject_count = 0, .calculated_gpa = 0.0 }
    };
    int total_students = 4;

    /* Populate Alice's records */
    register_subject(&database[0], "Calculus I", CAT_MATHEMATICS, 94.5);
    register_subject(&database[0], "Physics II", CAT_SCIENCE, 89.0);
    register_subject(&database[0], "World History", CAT_HISTORY, 78.5);

    /* Populate Bob's records */
    register_subject(&database[1], "Linear Algebra", CAT_MATHEMATICS, 82.0);
    register_subject(&database[1], "Chemistry I", CAT_SCIENCE, 95.5);
    register_subject(&database[1], "English Lit", CAT_LITERATURE, 91.0);

    /* Populate Charlie's records */
    register_subject(&database[2], "Discrete Maths", CAT_MATHEMATICS, 71.0);
    register_subject(&database[2], "Modern History", CAT_HISTORY, 88.0);

    /* Populate Diana's records */
    register_subject(&database[3], "Calculus II", CAT_MATHEMATICS, 99.0);
    register_subject(&database[3], "Astrophysics", CAT_SCIENCE, 98.5);
    register_subject(&database[3], "Creative Writing", CAT_LITERATURE, 95.0);

    /* Calculate and cache GPAs */
    for (int i = 0; i < total_students; i++) {
        update_student_gpa(&database[i]);
    }

    /* Print all student reports */
    printf("--- ALL STUDENT TRANSCRIPTS ---\n");
    for (int i = 0; i < total_students; i++) {
        print_student_report(&database[i]);
    }

    /* 1. Identify and display the top performing student */
    printf("\n--- GLOBAL ANALYTICS ---\n");
    const Student* top_student = find_top_performer(database, total_students);
    if (top_student != NULL) {
        printf("Top Performer overall: %s (ID: %u) with GPA: %.2f\n\n", 
               top_student->name, top_student->id, top_student->calculated_gpa);
    }

    /* 2. Filter students by performance in specific Subject Category */
    SubjectCategory search_category = CAT_MATHEMATICS;
    double cut_off_score = 90.0;
    const Student* math_achievers[MAX_STUDENTS];
    
    printf("Searching for high achievers (Score > %.1f) in: %s\n", 
           cut_off_score, get_category_name(search_category));
           
    int match_count = filter_students_by_category_score(database, total_students, 
                                                        search_category, cut_off_score, 
                                                        math_achievers);
    
    for (int i = 0; i < match_count; i++) {
        printf(" -> Achiever Found: %s\n", math_achievers[i]->name);
    }

    /* 3. Sort database array in-place by GPA and demonstrate order */
    printf("\n--- SORTING DATABASE BY GPA (DESCENDING) ---\n");
    sort_students_by_gpa(database, total_students);
    for (int i = 0; i < total_students; i++) {
        printf("Rank %d: %-15s | GPA: %.2f\n", i + 1, database[i].name, database[i].calculated_gpa);
    }

    printf("\n=== PROCESS COMPLETED SUCCESSFULLY ===\n");
    return 0;
}

/* ========================================================================= */
/*                         FUNCTION IMPLEMENTATIONS                          */
/* ========================================================================= */

/**
 * @brief Converts enum category to its string representation (Reflection pattern).
 * 
 * @param category Enum value representing SubjectCategory.
 * @return String representation of the category.
 */
const char* get_category_name(SubjectCategory category) {
    switch (category) {
        case CAT_MATHEMATICS: return "Mathematics";
        case CAT_SCIENCE:     return "Science";
        case CAT_LITERATURE:  return "Literature";
        case CAT_HISTORY:     return "History";
        default:              return "Unknown Category";
    }
}

/**
 * @brief Safely registers a subject score to a Student's subject array.
 * 
 * @param student Pointer to target Student struct.
 * @param name String representing name of subject.
 * @param cat Enum category of subject.
 * @param score Double value of grade achieved.
 * @return true if assignment succeeded, false if limit was exceeded or input invalid.
 */
bool register_subject(Student* student, const char* name, SubjectCategory cat, double score) {
    if (student == NULL || name == NULL || score < 0.0 || score > 100.0) {
        return false;
    }
    
    if (student->subject_count >= MAX_SUBJECTS) {
        fprintf(stderr, "Error: Max subjects limit reached for %s\n", student->name);
        return false;
    }

    /* Extract and store inside structure index */
    int index = student->subject_count;
    strncpy(student->enrolled_subjects[index].name, name, MAX_NAME_LEN - 1);
    student->enrolled_subjects[index].name[MAX_NAME_LEN - 1] = '\0'; /* Ensure null-termination */
    student->enrolled_subjects[index].category = cat;
    student->enrolled_subjects[index].score = score;
    
    student->subject_count++;
    return true;
}

/**
 * @brief Computes, updates and caches the GPA of a Student based on enrolled course marks.
 * 
 * @param student Pointer to target Student structure.
 */
void update_student_gpa(Student* student) {
    if (student == NULL || student->subject_count == 0) {
        if (student != NULL) student->calculated_gpa = 0.0;
        return;
    }

    double cumulative_scores = 0.0;
    for (int i = 0; i < student->subject_count; ++i) {
        cumulative_scores += student->enrolled_subjects[i].score;
    }
    
    /* Simple GPA Conversion Scale mapping: Score average out of 25 to match standard 4.0 Scale */
    student->calculated_gpa = (cumulative_scores / student->subject_count) / 25.0;
}

/**
 * @brief Outputs formatted report card transcript directly to the console.
 * 
 * @param student Constant pointer to Student structure to render.
 */
void print_student_report(const Student* student) {
    if (student == NULL) return;

    printf("==================================================\n");
    printf("STUDENT ID : %u\n", student->id);
    printf("STUDENT NAME: %s\n", student->name);
    printf("GPA         : %.2f / 4.00\n", student->calculated_gpa);
    printf("--------------------------------------------------\n");
    printf("%-20s | %-15s | %-5s\n", "Subject Name", "Category", "Score");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < student->subject_count; ++i) {
        printf("%-20s | %-15s | %5.1f\n", 
               student->enrolled_subjects[i].name, 
               get_category_name(student->enrolled_subjects[i].category), 
               student->enrolled_subjects[i].score);
    }
    printf("==================================================\n\n");
}

/**
 * @brief Analytical utility function locating the top performer on array.
 * 
 * @param students Constant input array of Students.
 * @param student_count Length of student array.
 * @return Constant pointer to the top Student in the database.
 */
const Student* find_top_performer(const Student students[], int student_count) {
    if (students == NULL || student_count <= 0) {
        return NULL;
    }

    const Student* top_student = &students[0];
    for (int i = 1; i < student_count; i++) {
        if (students[i].calculated_gpa > top_student->calculated_gpa) {
            top_student = &students[i];
        }
    }
    return top_student;
}

/**
 * @brief High-efficiency pointer filtering function matching criteria elements.
 * Passes out filtered entries matching threshold standards via reference array.
 * 
 * @param students Input read-only list of Students.
 * @param student_count Total students available.
 * @param target_cat Target Category to search for.
 * @param threshold_score Cut-off point parameter.
 * @param filtered_results Pointer array output stream destination.
 * @return Total match entries written to output array.
 */
int filter_students_by_category_score(const Student students[], int student_count, 
                                      SubjectCategory target_cat, double threshold_score, 
                                      const Student* filtered_results[]) {
    if (students == NULL || filtered_results == NULL || student_count <= 0) {
        return 0;
    }

    int match_count = 0;
    for (int i = 0; i < student_count; i++) {
        for (int j = 0; j < students[i].subject_count; j++) {
            if (students[i].enrolled_subjects[j].category == target_cat && 
                students[i].enrolled_subjects[j].score >= threshold_score) {
                
                filtered_results[match_count] = &students[i];
                match_count++;
                break; /* Ensure student is listed only once in results even if multiple matches exist */
            }
        }
    }
    return match_count;
}

/**
 * @brief Bubble sort algorithm executing in-place ordering of students 
 * on their Calculated GPA (Descending Order).
 * 
 * @param students Input array to modify.
 * @param student_count Length of array.
 */
void sort_students_by_gpa(Student students[], int student_count) {
    if (students == NULL || student_count <= 1) {
        return;
    }

    for (int i = 0; i < student_count - 1; i++) {
        for (int j = 0; j < student_count - i - 1; j++) {
            if (students[j].calculated_gpa < students[j+1].calculated_gpa) {
                /* Swap structures in array */
                Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
}