int turn; // shared variable: 0 or 1

// Process P0
do {
    while (turn != 0);     // Wait until it's your turn

    // Critical section
    // ...

    turn = 1;              // Give turn to P1

    // Remainder section
} while (true);

// Process P1
do {
    while (turn != 1);     // Wait until it's your turn

    // Critical section
    // ...

    turn = 0;              // Give turn to P0

    // Remainder section
} while (true);
