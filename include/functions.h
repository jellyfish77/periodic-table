#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Structure of the element
struct Element
{
    char symbol[3];
    char name[50];
    int atomic_no;
    float atomic_wt;
};


int add_record(struct Element *e, FILE *fp);
bool record_exists(char *element_name, FILE *fp);
const char* get_field(char* line, int num);

#endif