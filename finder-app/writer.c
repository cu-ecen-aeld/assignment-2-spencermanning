#include "syslog.h"
#include <stdio.h>

int main (int argc, char *argv[]) {
    // argc = 2
    // argv[0] = writefile
    // argv[1] = writestr

    printf("Arguments are %s, %s, %s\n", argv[0], argv[1], argv[2]);
    // Exit if arguments aren't supplied
    if (argc != 3) {
        printf("Incorrect arguments given: argc=%d\n", argc);
        return 1;
    }

    // Open logger
    openlog(NULL,0,LOG_USER);
    syslog(LOG_DEBUG, "Writing %s to %s\n", argv[1], argv[0]);

    FILE *file;
    file = fopen(argv[1], "w"); // TODO: do I need to cast argv?
    if (!file) {
        syslog(LOG_ERR, "File didn't open\n");
        printf("File didn't open\n");
        return 1;
    }
    // write to file
    fprintf(file, "%s", argv[2]);

    fclose(file);


}