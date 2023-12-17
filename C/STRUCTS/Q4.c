#include <stdio.h>

struct Course {
    char courseName[50];
    int courseCode;
};

struct Student {
    char name[50];
    int studentID;
    struct Course courses[3];
};

struct University {
    char universityName[50];
    struct Student students[5];
};

int main() {
    struct University university = {"TechUniversity", {{"Alice", 1, {{"Math", 101}, {"Physics", 102}, {"Computer Science", 103}}}, {"Bob", 2, {{"Chemistry", 201}, {"Biology", 202}, {"English", 203}}}}};

    printf("University Information:\n");
    printf("University Name: %s\n", university.universityName);

    printf("Students:\n");
    for (int i = 0; i < 2; i++) {
        printf("Student %d: %s (ID: %d)\n", i + 1, university.students[i].name, university.students[i].studentID);
        printf("Courses:\n");
        for (int j = 0; j < 3; j++) {
            printf("Course %d: %s (Code: %d)\n", j + 1, university.students[i].courses[j].courseName, university.students[i].courses[j].courseCode);
        }
    }

    return 0;
}
