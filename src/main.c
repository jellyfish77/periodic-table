#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"


// function declerations
void run_tests();

#define ELEMENTS_FILE ("elements.csv")
#define SEPERATOR (',')


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

    static const struct Element emptyElement = {};

    FILE *fp = open_file(ELEMENTS_FILE);
    struct Element e;

    e = emptyElement; // empty struct
    strcpy(e.symbol, "H");
    strcpy(e.name, "Hydrogen");
    e.atomic_no = 1;
    e.atomic_wt = 1.008000;
    printf("Add record 'H': %d\n", add_record(&e, fp));
    printf("File size: %ld (bytes)\n", file_size(fp));
    printf("Record exists? %d\n", record_exists(e.symbol, fp));
    print_record(&e);

    strcpy(e.symbol, "Ti");
    strcpy(e.name, "Titanium");
    e.atomic_no = 22;
    e.atomic_wt = 47.867000;
    printf("\nTi exists? %d\n", record_exists(e.symbol, fp));
    printf("Add record 'Ti': %d\n", add_record(&e, fp));
    printf("File size: %ld (bytes)\n", file_size(fp));
    printf("Ti exists? %d\n", record_exists(e.symbol, fp));
    print_record(&e);

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