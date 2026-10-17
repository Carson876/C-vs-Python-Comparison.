
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    const char *filename = argc > 1 ? argv[1] : "numbers.txt";

    FILE *file = fopen(filename, "r");

    if (!file) {
        perror("Cannot open input file");
        return 1;
    }

    char line[256];
    long long total = 0;
    long long count = 0;
    int invalid = 0;
    int blank = 0;
    int minimum = 0;
    int maximum = 0;

    while (fgets(line, sizeof(line), file)) {
        char *p = line;

        while (isspace((unsigned char)*p))
            p++;

        if (*p == '\0') {
            blank++;
            continue;
        }

        errno = 0;

        char *end;
        long long value = strtoll(p, &end, 10);

        while (isspace((unsigned char)*end))
            end++;

        if (p == end || *end != '\0' || errno == ERANGE ||
            value < INT_MIN || value > INT_MAX) {
            invalid++;
            continue;
        }

        if (count == 0 || value < minimum)
            minimum = (int)value;

        if (count == 0 || value > maximum)
            maximum = (int)value;

        total += value;
        count++;
    }

    if (ferror(file)) {
        perror("Error reading file");
        fclose(file);
        return 1;
    }

    fclose(file);

    printf("File: %s\n", filename);
    printf("Valid: %lld\n", count);
    printf("Invalid: %d\n", invalid);
    printf("Blank: %d\n", blank);
    printf("Sum: %lld\n", total);

    if (count > 0) {
        printf("Minimum: %d\n", minimum);
        printf("Maximum: %d\n", maximum);
        printf("Average: %.2f\n", (double)total / count);
    } else {
        printf("No valid numbers were found.\n");
    }

    return 0;
}
