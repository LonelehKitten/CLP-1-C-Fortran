#ifndef READER_H
#define READER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init (char *);
int read (FILE *);

int getNextLine (FILE *, unsigned char **, int *);


/**
 *  ALLRIGHT - no problems
 *  FOPENERR - file doens't exist
 *  INVFIRSTERR - invalid first line format
 *  MUST2ERR - file contains less than 2 lines
**/
enum {
    // no problems
    ALLRIGHT = 0,
    // file doens't exist
    FOPENERR = -1,
    // invalid first line format
    INVFIRSTERR = -2,
    // file contains less than 2 lines
    MUST2ERR = -3
} status;

extern struct {
    int count;
} args_;

extern void findsubstring_(unsigned char *, unsigned char *, int *lineToSearch_length, int *line_length);

#endif /* READER_H */