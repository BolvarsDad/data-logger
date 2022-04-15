#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX 10
#define EXIT_VAL 0

struct
Simulation
{
    int   *arguments;
    int    argc;
};

// Default values
static struct Simulation const default_sim = {NULL, 0};
struct Simulation simdata;

void        sim_init        (struct Simulation *simp);
int         sim_view        (struct Simulation *simp);
int         sim_enter       (struct Simulation *simp, char const *prompt);
void        sim_compute     (struct Simulation *simp);
void        sim_reset       (struct Simulation *simp);
int         sim_quit        (struct Simulation *simp);

void
sim_init(struct Simulation *simp)
{
    memcpy(simp, &default_sim, sizeof default_sim);
}

int
sim_view(struct Simulation *simp)
{
    return 0;
}

int
sim_enter(struct Simulation *simp, char const *prompt)
{
    char        buffer[MAX] = {};
    size_t      buflen = 0;
    char       *token;
    int         ch;
    size_t      num_of_elements = sizeof(buffer)/sizeof(buffer[0]);

    token = strtok(buffer, ",");
    
    fputs(prompt, stdout);

    while ((ch = getchar()) != EOF && ch != '\n')
        if (buflen < MAX)
            buffer[buflen++] = ch;

    return 0;
}

void
sim_compute(struct Simulation *simp)
{
    int compute_median;
    int compute_min;
    int compute_max;
}

void
sim_sanitize(struct Simulation *simp)
{

}

// using memset is the fastest way I could think of to reset the array heap using the standard library
// memset->string.h
void
sim_reset(struct Simulation *simp)
{
    int *args = simp->arguments;
    memset(args, 0, simp->argc*sizeof(args[0]));
}

char const *
sim_get_quitreason(struct Simulation const *simp)
{
    if (simp->argc > MAX)
        return "Max arguments reached.\n";

    if (simp->arguments = 0)
        return "Exit value entered.\n";

    if (feof(stdin))
        return "User quit.\n";

    return "Unkonwn error.\n";
}

int
sim_quit(struct Simulation *simp)
{
    return 0;
}

void
usage()
{
    printf("Usage");
}

int
main(int argc, char **argv)
{
    struct Simulation sim;
    sim_init(&sim);

    return 0;
}
