#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

/*
 * This source file contains a daemon to collect the signal strength of the GL.iNet MiFi Router. For more information
 * on creating daemons, look here: http://www.netzmafia.de/skripten/unix/linux-daemon-howto.html
 *
 * This also contains the use of named pipes: https://www.geeksforgeeks.org/named-pipe-fifo-example-c-program/
 */

/*
 */

int main(void) {
    int fd;
    char * myfifo = '/tmp/signalstrengthfifo';
    mkfifo(myfifo, 0666); //path, then permission
    char arr1[1024], arr2[1024];


    pid_t pid, sid;

    // Fork the parent process
    pid = fork();
    if (pid < 0) {
        exit(1);
    }

    if (pid > 0) {
        // If everything goes well, we'll end up here. Exit the parent process.
        exit(0);
    }

    // Change the file mode mask in case I want to generate any files - do we need this?
    umask(0);

    // Create a new Session ID for the child process
    sid = setsid();
    if (sid < 0) {
        exit(1);
    }

    // We are switching to the root directory because it is guaranteed to be there on any Linux system
    if ((chdir("/")) < 0) {
        exit(1);
    }

    // Close standard file descriptors
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    while (1) {
        fd = open(myfifo, O_WRONLY);
        write(fd, "Hi", sizeof("Hi"));
        close(fd);

        sleep(1); //1 second
    }
    exit(EXIT_SUCCESS);

}


