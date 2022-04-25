#include "functions.h"

//static const struct Element emptyElement = {};

struct Element set_element(char *symbol, char *name, int atomic_no, float atomic_wt)
{
    struct Element e = {};

    //e = emptyElement; // empty struct
    strcpy(e.symbol, symbol);
    strcpy(e.name, name);
    e.atomic_no = atomic_no;
    e.atomic_wt = atomic_wt;

    return e;
}