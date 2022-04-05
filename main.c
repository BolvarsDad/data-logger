#include <stdio.h>
#include <string.h>
#include <stdint.h>

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
void        sim_step        (struct Simulation *simp);
void        sim_reset       (struct Simulation *simp);
void        sim_quit        (struct Simulation *simp);

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

int
sim_enter(struct Simulation *simp, char const *prompt)
{
    double buffer[MAX] = {};
    const char *delim = ',';

    return 0;
}

void
sim_compute(struct Simulation *simp)
{
}

void
sim_sanitize(struct Simulation *simp)
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

void
usage()
{
    printf("Usag");
}

int
main(int argc, char **argv)
{
    struct Simulation sim;
    sim_init(&sim);

    return 0;
}
