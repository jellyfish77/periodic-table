#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"


// function declerations
void print_record(struct Element *e);
FILE *open_file(char *filename);
bool record_exists(char *element_name, FILE *fp);
void run_tests();

#define ELEMENTS_FILE ("elements.csv")
#define SEPERATOR (',')

// Function to delete an element record matching symbol
bool delete_record(struct Element e)
{
}

// Function to modify an element record matching symbol
bool modify_record()
{
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

long file_size(FILE *fp)
{
    fseek(fp, 0, SEEK_END);
    return ftell(fp);
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


// Read all records from file into an array of Elements
bool get_records(FILE *fp)
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
    run_tests();

    //printf("%d\n", test_add_record());
    getchar();
    return 0;
}


void run_tests() {

    FILE *fp = open_file(ELEMENTS_FILE);
    struct Element e;
    strcpy(e.symbol, "H");
    strcpy(e.name, "Hydrogen");
    e.atomic_no = 1;
    e.atomic_wt = 1.008000;
    printf("Add record: %d\n", add_record(&e, fp));
    printf("File size: %ld (bytes)\n", file_size(fp));
    printf("Record exists? %d\n", record_exists(e.symbol, fp));


    static const struct Element emptyElement = {};
    // e = emptyElement;
    strcpy(e.symbol, "Ti");
    strcpy(e.name, "Titanium");
    e.atomic_no = 22;
    e.atomic_wt = 47.867000;
    printf("\nTi exists? %d\n", record_exists(e.symbol, fp));
    printf("Add record: %d\n", add_record(&e, fp));
    printf("File size: %ld (bytes)\n", file_size(fp));
    printf("Ti exists? %d\n", record_exists(e.symbol, fp));

    //e = emptyElement;
    strcpy(e.symbol, "Ti");
    strcpy(e.name, "Titanium");
    e.atomic_no = 22;
    e.atomic_wt = 47.867000;
    printf("\nTi exists? %d\n", record_exists(e.symbol, fp));
    printf("Add record: %d\n", add_record(&e, fp));
    printf("File size: %ld (bytes)\n", file_size(fp));
    printf("Ti exists? %d\n", record_exists(e.symbol, fp));

    printf("\nAg exists? %d\n", record_exists("Ag", fp));
    strcpy(e.symbol, "Ag");
    strcpy(e.name, "Silver");
    e.atomic_no = 47;
    e.atomic_wt = 107.870000;
    printf("Add record: %d\n", add_record(&e, fp));
    printf("File size: %ld (bytes)\n", file_size(fp));
    printf("Ag exists? %d\n", record_exists("Ag", fp));

    fclose(fp);
}