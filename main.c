#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure of the element
struct Element
{
    char symbol[2];
    char name[50];
    int atomic_no;
    float atomic_wt;
};

// function declerations
void print_record(struct Element *e);
FILE *open_file(char *filename);

#define ELEMENTS_FILE ("elements.csv")

/**
 * Add an element record if it doesn't exist (by symbol).
 *
 * Symbol is case sensitive - 'H' <> 'h'
 * Element is not modified if it exists
 *
 * @param e     The element to add
 * @return      The position of the record, -1 on error
 */
int add_record(struct Element *e, FILE *fp)
{
    print_record(e);

    //FILE *fp = open_file(ELEMENTS_FILE);

    printf("Position of file pointer is : ");
    printf("%ld \n", ftell(fp));
    fseek(fp, 0, SEEK_END); // move to end of file
    printf("Position of file pointer is : ");
    printf("%ld \n", ftell(fp));
    fprintf(fp,"%s, %s, %d, %.6f\n", e->symbol, e->name, e-> atomic_no, e->atomic_wt);
    printf("Position of file pointer is : ");
    printf("%ld \n", ftell(fp));

    //fwrite(&e)

    fclose(fp);

    return true;
}

// Function to delete an element record matching symbol
bool delete_record(struct Element e)
{
}

// Function to modify an element record matching symbol
bool modify_record()
{
}

bool record_exists(struct Element e)
{



    return false;
}

// return file pointer
FILE *open_file(char *filename)
{
    FILE *fp = fopen(filename, "r+"); // must exist
    if (fp == NULL) {
        fp = fopen(filename, "w+"); // create empty
        if (fp == NULL) {
            printf("\nCannot open file...");
                return NULL; // error
        }
    }
    return fp;
}

void print_record(struct Element *e)
{
    printf("Element Record\n");
    printf("==============\n");
    printf("Symbol:    %s\n", e->symbol);
    printf("Name:      %s\n", e->name);
    printf("Atomic No: %d\n", e->atomic_no);
    printf("Atomic Wt: %.6f\n", e->atomic_wt);
}


// Function to return element record(s) matching all members of e
bool get_records(struct Element e, bool match_all)
{
}

bool test_add_record()
{
    struct Element e;
    strcpy(e.name, "Hydrogen");
    strcpy(e.symbol, "H");
    e.atomic_no = 1;
    e.atomic_wt = 1.008;
    //return add_record(&e);
}





/*
 * Function:  main
 * --------------------
 * Main for periodic table of the elements
 *
 *
 */
int main()
{

    FILE *fp = open_file(ELEMENTS_FILE);
    struct Element e;
    strcpy(e.name, "Hydrogen");
    strcpy(e.symbol, "H");
    e.atomic_no = 1;
    e.atomic_wt = 1.008;
    printf("%d\n", add_record(&e, fp));

    //printf("%d\n", test_add_record());
    getchar();
    return 0;
}
