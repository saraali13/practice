SIGINT //ctrl C
SIGTERM //Graceful termination
SIGSEGV//segmentation fault
SEGUSR1,SEGUSR2 //User defined
SIGKILL //Forced Kill (cannot be caught)
SIGCHLD //Child terminated
SIGALRM //Timer alarm
SIG_IGN //Ignore the signal
signal(int signum/*Signal type*/, sighandler_t handler/*Handler function or ignore*/);

struct sigaction sa;
sa.sa_handler = my_handler;
sigaction(SIGINT, &sa, NULL);

