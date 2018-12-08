#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct linked
{
    char country[30];
    int count;
    struct linked *next;
} country_element;
typedef country_element *elemptr;
int main()
{
    char country_name[30];
    int didadd;

    FILE *fp;
    fp = fopen("countries.dat", "r");

    elemptr first = (elemptr)malloc(sizeof(country_element));
    elemptr current = first;
    first->count = 1;
    first->next = NULL;
    fscanf(fp, "%s", &country_name);
    strcpy(first->country, country_name);          //Initializes first->country to the name of the first country in the file
    while (fscanf(fp, "%s", &country_name) != EOF) //loops until EOF
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
    while (current->next != NULL)
    {
        printf("%s %d\n", current->country, current->count);
        current = current->next;
    }
    printf("%s %d\n", current->country, current->count);
    fclose(fp);
}