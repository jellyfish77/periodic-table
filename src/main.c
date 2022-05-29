#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"
#include "element.h"


// function declerations
void run_tests();
void test_add_element(struct Element *e, FILE *fp);

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
    test_add_element(&e, fp);

    e = set_element("Ti", "Titanium", 22, 47.867000);
    test_add_element(&e, fp);

    e = set_element("Ag", "Silver", 47, 107.870000);
    test_add_element(&e, fp);

    // load test
    /*
    int i;
    for (i = 1; i < 100; ++i)
    {
        char symbol[3];
        sprintf(symbol, "%d", i);
        e = set_element(symbol, "Unobtainium", 100, 200.123456);
        test_add_element(&e, fp);
    }
    */


    fclose(fp);
}

void test_add_element(struct Element *e, FILE *fp)
{
    print_record(e);
    printf("File size: %ld (bytes)\n", file_size(fp));
    printf("'%s' exists? %d\n", e->symbol, record_exists(e->symbol, fp));
    printf("Add record '%s': %d\n", e->symbol, add_record(e, fp));
    printf("File size: %ld (bytes)\n", file_size(fp));
    printf("'%s' exists? %d\n", e->symbol, record_exists(e->symbol, fp));
    printf("Add record '%s': %d\n", e->symbol, add_record(e, fp));
    printf("File size: %ld (bytes)\n", file_size(fp));
    printf("\n");
}
