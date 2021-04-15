#ifndef READER_H
#define READER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <limits.h>

void init (char *);
void read (FILE *);

int getNextLine (FILE *, char **, int *);

extern struct {
    int count;
} args_;

//extern void findsubstring_(char [20], char [INT_MAX]);
extern void findsubstring_(char [], char [], int *lineToSearch_length, int *line_length);

#endif /* READER_H */