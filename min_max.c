#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mex.h"

typedef struct linked
{
    char country[30];
    int count;
    struct linked *next;
} country_element;

typedef country_element *elemptr;

 void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
 {
     main();
     return;
 }

int main()
{
    char country_name[256];
    int didadd;
    elemptr max1 = (elemptr)malloc(sizeof(country_element));
    elemptr max2 = (elemptr)malloc(sizeof(country_element));
    elemptr max3 = (elemptr)malloc(sizeof(country_element));

    FILE *fr;
    fr = fopen("countries.dat", "r");

    elemptr first = (elemptr)malloc(sizeof(country_element));
    elemptr current = first;
    first->count = 1;
    first->next = NULL;
    fscanf(fr, "%s", &country_name);
    strcpy(first->country, country_name);          //Initializes first->country to the name of the first country in the file
    while (fscanf(fr, "%s", &country_name) != EOF) //loops until EOF
    {
        didadd = 0;
        elemptr current = first;
        if (strcmp(country_name, current->country) == 0)
        {
            current->count += 1;
        }
        else
        {
            while (current->next != NULL) //Loop until the end of the linked list
            {
                current = current->next;
                if (strcmp(country_name, current->country) == 0)
                {
                    current->count += 1; //If the country name is the same as another in the linked list, add one to its count
                    didadd = 1;          //keeps track that at some point the country was found on the list
                }
            }
            if (didadd == 0) //appends new element to the end of the linked list if the country wasn't found in the linked list
            {
                current->next = (elemptr)malloc(sizeof(country_element));
                current = current->next;
                strcpy(current->country, country_name);
                current->count = 1;
                current->next = NULL;
            }
        }
    }
    current = first; //sets current to point to the first element
    max1->count = 0;
    max2->count = 0;
    max3->count = 0;
    FILE *fw;
    fw = fopen("country_data", "w");
    while (current->next != NULL)
    {
        while(strcmp(current->country, "Private") == 0) {
            current = current->next;        //skips all the "Private" ips
        }
        if (max1->count < current->count)
        {
            max3 = max2;
            max2 = max1;
            max1 = current;
        }
        else if (max2->count < current->count)
        {
            max3 = max2;
            max2 = current;
        }
        else if (max3->count < current->count)
        {
            max3 = current;
        }

        current = current->next;
    }
    fprintf(fw, "%s %d\n%s %d\n%s %d\n", max1->country, max1->count, max2->country, max2->count, max3->country, max3->count);
    fclose(fr);
    fclose(fw);
    printf("Max1: %s %d\n", max1->country, max1->count);
    printf("Max2: %s %d\n", max2->country, max2->count);
    printf("Max3: %s %d\n", max3->country, max3->count);

    return 0;
}