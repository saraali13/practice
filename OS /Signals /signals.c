SIGINT //ctrl C
SIGTERM //Graceful termination
SIGKILL //Forced Kill (cannot be caught)
SIGCHLD //Child terminated
SIGALRM //Timer alarm

signal(int signum/*Signal type*/, sighandler_t handler/*Handler function or ignore*/);

struct sigaction sa;
sa.sa_handler = my_handler;
sigaction(SIGINT, &sa, NULL);

