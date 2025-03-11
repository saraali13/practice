#include <stdio.h>// for basic I/O
#include <unistd.h>// for system calls like fork(), exec(), pipe()
#include <fcntl.h> //for file manipulation
#include <sys/stat.h> //for permissions and metadata
#include <signal.h> //for signal handling
#include <sys/types.h>	//Data types like pid_t, size_t, off_t, etc.

//make file add own created headers like:
#include "myheader.h"
