#include "version.h"
#include <getopt.h>
#include <stdbool.h>

typedef struct
{
    short port;
    bool verbose;
} args_t;

int main(int argc, char *argv[])
{
    int opt;
    while ((opt = getopt(argc, argv, ":p:v:")) != -1)
    {
    }

    return 0;
}
