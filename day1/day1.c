#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <errno.h>
#include <string.h>
#include <getopt.h>
#include <sys/types.h>

int calibrationValue(char* s) {
    int len = strlen(s) - 1;
    int left = -1;
    int right = -1;
    int dig;
    for(int i = 0; i < len; i++) {
        dig = (int) s[i] - 48;
        if(dig < 0 || dig > 9) {
            continue;
        }

        if(left == -1) {
            left = dig;
        } else {
            right = dig;
        }
    }

    if(left == -1) {
        return 0;
    }

    int cal = left*10 + (right > -1 ? right : left);
    printf("\tcal = %d\n", cal);

    return cal;
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
        cal += calibrationValue(line);
    }

    printf("\nCalibration value: %d\n", cal);

    printf("\nFinished.\n");
    return 0;
}
