#include <stdio.h>
#include <stdlib.h>

// function to add category in file
void AddCatagory() {
    char C_Name[20]; // category name
    int C_ID;        // category ID
    FILE *ptr1 = fopen("catagory.txt", "a");

    // taking input
    printf("enter category name and ID\n");
    scanf("%s %d", C_Name, &C_ID);

    if (ptr1 == NULL) {
        printf("error");
        exit(EXIT_FAILURE); // file does not exist
    } // end if

    fprintf(ptr1, "%s %d \n", C_Name, C_ID);
    printf("written in file catagory.txt\n");
    fclose(ptr1);
} // end AddCatagory

// function to add products
void AddProducts() {
    char P_Name[20]; // product name
    float P_Price;   // product price
    int P_ID;        // product ID
    FILE *ptr2 = fopen("product.txt", "a");

    // taking input
    printf("enter product name, price, and ID\n");
    scanf("%s %f %d", P_Name, &P_Price, &P_ID);

    if (ptr2 == NULL) {
        printf("error");
        exit(EXIT_FAILURE); // file does not exist
    } // end if

    fprintf(ptr2, "%s %f %d \n", P_Name, P_Price, P_ID);
    printf("written in file product.txt\n");
    fclose(ptr2);
} // end AddProduct

// function to generate the final result
void GenerateFinalResult() {
    FILE *ptr1 = fopen("catagory.txt", "r");
    FILE *ptr2 = fopen("product.txt", "r");
    FILE *ptr3 = fopen("final.txt", "w");

    if (ptr1 == NULL || ptr2 == NULL || ptr3 == NULL) {
        printf("error");
        exit(EXIT_FAILURE);
    }

    char C_Name[20]; // category name
    int C_ID;        // category ID
    char P_Name[20]; // product name
    float P_Price;   // product price
    int P_ID;        // product ID
    float price = 0;

    fseek(ptr1, 0, SEEK_SET);
    while (!feof(ptr1)) // till the end of the category file
    {
        fscanf(ptr1, "%s %d", C_Name, &C_ID);
        fprintf(ptr3, "%s", C_Name); // printing category name in final.txt file

        fseek(ptr2, 0, SEEK_SET);
        while (!feof(ptr2)) // till the end of the product file
        {
            fscanf(ptr2, "%s %f %d", P_Name, &P_Price, &P_ID);
            if (C_ID == P_ID) // if the product has the same ID as the category, it will be printed in final.txt file
            {
                price += P_Price;
                fprintf(ptr3, " %.2f\n", price);
            }
        }
    }

    fclose(ptr1);
    fclose(ptr2);
    fclose(ptr3);
} // end GenerateFinalResult

int main() {
    int n;
    printf("enter your choice(1-4): ");
    scanf("%d", &n);

    switch (n) {
    case 1:
        AddCatagory();
        break;
    case 2:
        AddProducts();
        break;
    case 3:
        GenerateFinalResult();
        break;
    case 4:
        exit(EXIT_SUCCESS);
        break;
    default:
        printf("error");
        break;
    } // end switch

    return 0;
} // end main
