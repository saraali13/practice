//process control 
fork() //creates a child process =0 child ,< error, else parent process
exec() //replace one process with another
wait(NULL)//makes parent process wait till child terminates
exit(0) //terminates the current process
getpid() //returns the process ID
getppid() //returns the parents pricess ID

exec() family
execl() //line based arr passing (l)
execlp()	//List-based(l) + uses PATH to find the program (p)
execle()	//List-based + custom environment variables (e)
execv()	//Array-based argument passing (v)
execvp()	//Array-based + uses PATH to find the program
execve()	//Array-based + custom environment variables
int execl(const char *path, const char *arg0, ..., NULL);
int execlp(const char *file, const char *arg0, ..., NULL);
int execle(const char *path, const char *arg0, ..., NULL, char * const envp[]);
int execv(const char *path, char *const argv[]);
int execvp(const char *file, char *const argv[]);
int execve(const char *path, char *const argv[], char *const envp[]);
/*path or file	Path to the executable file
arg0	The first argument (by convention, the program name itself)
argv[]	Array of arguments with argv[0] as the program name and NULL as the last element
envp[]	Array of environment variables (for execle and execve)
NULL	Must be the last argument in list-based calls*/

//ile management
open() //opens a file  
read() //read data
write() //writes data
close() //cose a file
lseek() //moves file pointer to a specific position
unlink() //delete a file
int fd = open("input.txt", O_RDONLY);  // Open file in read-only mode
ssize_t bytesRead = read(fd, buffer, sizeof(buffer));  // Read file content
write(STDOUT_FILENO, buffer, bytesRead);  // Write content to console
close(fd);

//IPC
pipe() //creates a pipe for communication
int pipe(int pipefd[2]);//creating a pipe
pipefd[0]//	Read end of the pipe
pipefd[1]//	Write end of the pipe
//Return Value	0 on success, -1 on error
pipe(fd) == -1 //error
//fork,close,read,write actions can be performed on a pipe
