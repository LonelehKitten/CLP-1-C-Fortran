#ifndef READER_H
#define READER_H

#include <stdio.h>
#include <stdlib.h>

void init (char *);
void read (FILE *);

int getNextLine (FILE *, char **);

extern struct {
    int count;
} args_;

extern void findsubstring_(char *, char *);

#endif /* READER_H */