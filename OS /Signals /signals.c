SIGINT //ctrl C
SIGTERM //Graceful termination
SIGSEGV//segmentation fault
SEGUSR1,SEGUSR2 //User defined
SIGKILL //Forced Kill (cannot be caught)
SIGCHLD //Child terminated
SIGALRM //Timer alarm
SIGILL //illegal instruction
SIGQUIT //Quit from keyboard ctrl \
SIGPIPE //wrting to a pipe with no read end
SIGTERM //process termination
SIGCONT //resume execution if stopped
SIGSTOP //stop process execution , ctrl Z
SIGSTP //stopped process issued from tty
SIGTTIN/TTOUT //background process requies input / output
SIGURG //urgent condition on socket
SIGXCPU //CPU time limit exceeded
SIGXFSZ //File size limit exceeded

SIG_IGN //Ignore the signal
SIG_ERR //error in signal creation
signal(int signum/*Signal type*/, sighandler_t handler/*Handler function or ignore*/);

struct sigaction sa;
sa.sa_handler = my_handler;
sigemptyset(&sa.sa_mask);
sa.sa_falgs=0;
sigaction(SIGINT, &sa, NULL); // -1 == error

while(1)
{
  // perform task or wait for the signal to call the signal funtion 
}
return EXIT_SUCCESS;
