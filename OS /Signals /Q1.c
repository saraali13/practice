#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig) {
    printf("Caught SIGINT (Ctrl+C). Exiting cleanly...\n");
    _exit(0);
}

int main() {
    signal(SIGINT, handle_sigint);
    while(1) {
        printf("Running...\n");
        sleep(1);
    }
}
