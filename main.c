#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define COUNTER_MAX 10
#define EXIT_VALUE 0

struct
Simulation
{
    int   *arguments;
    int    argc;
    int    argv;
}   simdata;

// Default values
static struct Simulation const default_sim = {0, 0};

void        sim_init        (struct Simulation *simp);
int         sim_view        (struct Simulation *simp);
int         sim_enter       (struct Simulation *simp, char const *prompt);
void        sim_compute     (struct Simulation *simp);
void        sim_step        (struct Simulation *simp);
void        sim_reset       (struct Simulation *simp);
void        sim_quit        (struct Simulation *simp);

enum
ERR_CODES 
{
        ERR_INVALID_INPUT,
        ERR_COUNTER_MAX_REACHED,
        ERR_MAX_VALUE
};

void
sim_init(struct Simulation *simp)
{
    memcpy(simp, &default_sim, sizeof default_sim);
}

void
sim_step(struct Simulation *simp)
{
}

int
sim_view(struct Simulation *simp)
{
    return 0;
}

// currently just boiletplate from the lunar descent program
int
sim_enter(struct Simulation *simp, char const *prompt)
{
    char buffer[COUNTER_MAX];
    size_t buflen = 0;
    int ch;

    fputs(prompt, stdout);

    while ((ch = getchar()) != EOF && ch != '\n')
        if (buflen < 32)
            buffer[++buflen] = ch;

    if (ch == EOF)
        putchar('\n');

    return 0;
}


void
sim_compute(struct Simulation *simp)
{
}

void
sim_reset(struct Simulation *simp)
{
}

void
sim_quit(struct Simulation *simp)
{
}

int
main(int argc, char **argv)
{
    struct Simulation sim;
    sim_init(&sim);

    return 0;
}
