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

int
take_user_input(char const *prompt)
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

struct lohistat
get_lohi(int *array, size_t arrayLen)
{
    struct lohistat stat = {0, 0};

    for (int i = 0; i < arrayLen; ++i)
    {
        for (int i = 0; i < arrayLen; ++i)
            if (array[i] < array[stat.low])
                stat.low = i;

            else if (array[i] > array[stat.high])
                stat.high = i;
    }

    return stat;
}

double
compute_average(int v[USERINPUT_MAX])
{
    int sum;

    for (int i = 0; i < USERINPUT_COUNT && VALUES[i] != USERINPUT_SENTINEL; ++i)
        sum = sum + i;

    return sum / USERINPUT_COUNT;
}

// In this assignment normalization means each element in the original user-inputted array
// minus the mean average
int *compute_normalization(int v[USERINPUT_COUNT], float avg)
{
    int normalized[USERINPUT_COUNT + 1];

    for (int i = 0; i < USERINPUT_COUNT && v[i] != USERINPUT_SENTINEL; ++i)
        normalized[i] = v[i - avg];

    return normalized; 
}

int
main(int argc, char **argv)
{
    static char const *promptstr = "VECRQ? ";
    int USERINPUTS[USERINPUT_MAX + 1];


    return 0;
}
