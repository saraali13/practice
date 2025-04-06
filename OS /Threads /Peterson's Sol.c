int turn;           // shared variable
bool flag[2];       // shared flag array

// Process P0
do {
    flag[0] = true;          // I want to enter
    turn = 1;                // Give other process the turn
    while (flag[1] && turn == 1);   // Wait if other wants to enter and it's their turn

    // Critical Section
    // ...

    flag[0] = false;         // I'm done

    // Remainder Section
} while (true);

// Process P1
do {
    flag[1] = true;          
    turn = 0;
    while (flag[0] && turn == 0);

    // Critical Section
    // ...

    flag[1] = false;

    // Remainder Section
} while (true);
