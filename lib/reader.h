#ifndef READER_H
#define READER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init (char *);
int read (FILE *);

int getNextLine (FILE *, unsigned char **, int *);

extern struct {
    int count;
} args_;

extern void findsubstring_(unsigned char *, unsigned char *, int *lineToSearch_length, int *line_length);

#endif /* READER_H */