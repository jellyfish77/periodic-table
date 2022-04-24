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
    fprintf(fp,"%s,%s,%d,%.6f\n", e->symbol, e->name, e-> atomic_no, e->atomic_wt);
    //printf("Position of file pointer is : ");
    //printf("%ld \n", ftell(fp));
    //fwrite(&e)
    return true;
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
