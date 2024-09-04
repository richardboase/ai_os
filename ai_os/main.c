// main.c
#include <stdio.h>

// Declare the run_gui function
void run_gui(int argc, char **argv);

int main(int argc, char **argv) {
    printf("Initializing AI OS...\n");

    // Call the GUI initialization function
    run_gui(argc, argv);

    return 0;
}