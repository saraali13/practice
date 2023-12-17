#include <stdio.h>

struct Employee {
    char name[50];
    int employeeID;
};

struct Department {
    char name[50];
    struct Employee employees[10];
};

struct Company {
    char companyName[50];
    struct Department departments[3];
};

int main() {
    struct Company company = {"TechCorp", {{"HR", {{"Alice", 1}, {"Bob", 2}, {"Charlie", 3}}}, {"Engineering", {{"David", 4}, {"Eva", 5}}}}};

    printf("Company Information:\n");
    printf("Company Name: %s\n", company.companyName);

    printf("Departments:\n");
    for (int i = 0; i < 2; i++) {
        printf("Department %s:\n", company.departments[i].name);
        for (int j = 0; j < 3; j++) {
            printf("Employee %d: %s (ID: %d)\n", j + 1, company.departments[i].employees[j].name, company.departments[i].employees[j].employeeID);
        }
    }

    return 0;
}
