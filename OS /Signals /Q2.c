#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int sig) {
    write(STDERR_FILENO, "Caught SIGINT\n", 14);  // signal-safe
    _exit(0);  // terminate
}

int main() {
    struct sigaction sa;
    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);  // no additional signals blocked during handler
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);  // register signal handler

    while (1) {
        pause();  // wait for signals
    }
    return 0;
}
