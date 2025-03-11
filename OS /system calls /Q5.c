#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Signal handler function
void alarm_handler(int sig) {
    printf("Alarm triggered! Time's up!\n");
}

int main() {
    // Registering the signal handler
    signal(SIGALRM, alarm_handler);

    printf("Setting an alarm for 5 seconds...\n");

    // Set an alarm for 5 seconds
    alarm(5);

    // Wait until the alarm goes off
    printf("Waiting for the alarm...\n");
    pause();  // Pause program until a signal is received

    return 0;
}
