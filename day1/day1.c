#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <errno.h>
#include <string.h>
#include <getopt.h>
#include <sys/types.h>


int calibrationValue(char* s, int len) {
    int d;
    printf("len = %d\n", len);
    for(int i = 0; i < len; i++){

        printf("%d", (int)s[i]);
        // if((int) s[i] >= 48 && (int) s[i] > 58) {
        //     printf("%c", s[i]);
        // }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    FILE *f;
    char* line = NULL;
    size_t len;
    ssize_t read;
    
    f = fopen(argv[1], "r");
    if(f == NULL)
        exit(EXIT_FAILURE);
    
    int cal = 0;
    while((read = getline(&line, &len, f)) != -1) {
        printf("%s", line);
        cal += calibrationValue(line, len);
    }

    printf("Calibration value: %d\n", cal);

    printf("\nFinished.\n");
    return 0;
}
