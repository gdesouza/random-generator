#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/// Begin and end are *inclusive*; => [begin, end]
uint32_t getRandInterval(uint32_t begin, uint32_t end) 
{
       double scaled = (double)rand()/RAND_MAX;

       return (end - begin +1)*scaled + begin;
}

void main(int argc, char** argv)
{
    int min, max;

    // if only 1 argument is given, the range will be between
    // 0 and the number given.
    if (argc==2) {
        min=0;
        max=atoi(argv[1]);
    }

    // if 2 arguments are given, the range will between them
    if (argc==3) {
        min=atoi(argv[1]);
        max=atoi(argv[2]);
    }

    /* Intializes random number generator */
    time_t t;
    srand((unsigned) time(&t));

    uint32_t r = getRandInterval(min, max);
    printf("%d\n", r);
}
