#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"
#include "element.h"


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

    //static const struct Element emptyElement = {};

    FILE *fp = open_file(ELEMENTS_FILE);
    struct Element e;
    //e = emptyElement; // empty struct

    e = set_element("H", "Hydrogen", 1, 1.00800);
    printf("Add record 'H': %d\n", add_record(&e, fp));
    printf("File size: %ld (bytes)\n", file_size(fp));
    printf("Record exists? %d\n", record_exists(e.symbol, fp));
    print_record(&e);

    e = set_element("Ti", "Titanium", 22, 47.867000);
    printf("\nTi exists? %d\n", record_exists(e.symbol, fp));
    printf("Add record 'Ti': %d\n", add_record(&e, fp));
    printf("File size: %ld (bytes)\n", file_size(fp));
    printf("Ti exists? %d\n", record_exists(e.symbol, fp));
    printf("Add record 'Ti': %d\n", add_record(&e, fp));
    printf("File size: %ld (bytes)\n", file_size(fp));

    e = set_element("Ag", "Silver", 47, 107.870000);
    printf("\n'%s' exists? %d\n", e.symbol, record_exists("Ag", fp));
    printf("Add record '%s': %d\n", e.symbol, add_record(&e, fp));
    printf("File size: %ld (bytes)\n", file_size(fp));
    printf("'%s' exists? %d\n", e.symbol, record_exists("Ag", fp));

    fclose(fp);
}