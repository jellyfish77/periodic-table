#include "functions.h"

/**
 * Add an element record if it doesn't exist (by symbol).
 *
 * Symbol is case sensitive - 'H' <> 'h'
 * Element is not modified if it exists
 *
 * @param e     The element to add
 * @return      The position of the record, -1 on error
 */
// TODO: return pos
int add_record(struct Element *e, FILE *fp)
{
    if(record_exists(e->symbol, fp))
    {
        return true;
    }
    //print_record(e);
    //FILE *fp = open_file(ELEMENTS_FILE);
    //printf("Position of file pointer is : ");
    //printf("%ld \n", ftell(fp));
    fseek(fp, 0, SEEK_END); // move to end of file
    //printf("Position of file pointer is : ");
    //printf("%ld \n", ftell(fp));
    return fprintf(fp,"%s,%s,%d,%.6f\n", e->symbol, e->name, e-> atomic_no, e->atomic_wt);
    //printf("Position of file pointer is : ");
    //printf("%ld \n", ftell(fp));
    //fwrite(&e)
    //return true;
}

bool record_exists(char *element_name, FILE *fp)
{
    rewind(fp); // move to start of file
    bool result = false;

    char line[1024];
    while (fgets(line, 1024, fp))
    {
        char* tmp = strdup(line);
        //printf("Matching symbol: %s against: %s\n", get_field(tmp, 1), element_name);
        if (strcmp(get_field(tmp, 1), element_name) == 0)
        {
            result = true;
        }
        // NOTE strtok clobbers tmp
        free(tmp);
    }

    return result;
}

// Return an element from file matching specified symbol
// TODO: implement
struct Element * get_record(char *element_symbol, FILE *fp)
{


}

/**
 * @brief Return field from specified column in csv string
 *
 * @param line      The scv string (i.e. line)
 * @param column    The column (field position) to return
 * @return          The field or NULL if not found
 */
const char* get_field(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}


// Delete an element record from file matching symbol
// TODO: implement
bool delete_record(char *element_symbol, FILE *fp)
{
}

// Modify an Element record in file matching symbol from supplied Element
// TODO: implement
bool modify_record(struct Element *e, FILE *fp)
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
// TODO: implement
// https://stackoverflow.com/questions/47028165/how-do-i-return-an-array-of-struct-from-a-function
struct Element * get_records(FILE *fp)
{
}


// Sort array of elements into order (by atomic number)
// TODO: implement
struct Element * sort_records(struct Element *e)
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