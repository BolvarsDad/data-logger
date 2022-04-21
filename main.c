#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>

#define USERINPUT_MAX 10
#define USERINPUT_SENTINEL 0

struct
lohistat
{
    int low;
    int high;
};

uint64_t
strtou64(char const *buffer, size_t bufsz)
{
    uint64_t out;

    for (size_t i = 0; i < bufsz && isdigit(buffer[i]); ++i)
        out = 10 * out + (buffer[i] - '0');

    return out;
}

uint64_t
take_user_input(void)
{
    char buffer[USERINPUT_MAX];
    size_t buflen;
    char ch;

    while ((ch = getchar()) != EOF && ch != '\n')
        if (buflen < USERINPUT_MAX)
            buffer[buflen++] = ch;

    if (ch == EOF)
        putchar('\n');

    return strtou64(buffer, buflen); 
}

// this is faster than sorting (O(n) vs (O(n log n)))
struct lohistat
compute_lohi(int *array, size_t arrayLen)
{
    struct lohistat stat = {0, 0};

    for (size_t i = 0; i < arrayLen; ++i)
    {
        if (array[i] < array[stat.low])
            stat.low = i;

        else if (array[i] > array[stat.high])
            stat.high = i;
    }

    return stat;
}

double
compute_average(int *array, size_t arrayLen)
{
    int sum;

    for (int i = 0; i < arrayLen; ++i)
        sum = sum + array[i];

    return sum / arrayLen;
}

// In this assignment normalization means each element in the original user-inputted array
// minus the mean average
int const *
compute_normalization(int *array, float avg)
{
    static int narray[USERINPUT_MAX];

    for (int i = 0; i < USERINPUT_MAX; ++i)
        narray[i] = array[i] - avg;

    return narray; 
}

int
main(int argc, char **argv)
{
    static char const *promptstr = "VECRQ? ";
    int array[USERINPUT_MAX] = {1, 2, 3, 4, 5};
    int const *res = compute_normalization(array, 3.0);
    struct lohistat stat = get_lohi(array, 6);
    
    printf("lowest %d highest %d", array[stat.low], array[stat.high]);

    for (int i = 0; i < 5; ++i)
        printf("norm >> " + "%d ", res[i]);

    return 0;
}
