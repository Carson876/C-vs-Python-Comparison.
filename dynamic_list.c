
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} IntList;

static int append(IntList *list, int value) {
    if (list->size == list->capacity) {
        size_t new_capacity;

        if (list->capacity == 0)
            new_capacity = 8;
        else
            new_capacity = list->capacity * 2;

        int *new_data = realloc(
            list->data,
            new_capacity * sizeof(int)
        );

        if (!new_data)
            return 0;

        list->data = new_data;
        list->capacity = new_capacity;
    }

    list->data[list->size] = value;
    list->size++;

    return 1;
}

static int pop(IntList *list) {
    if (list->size == 0)
        return 0;

    list->size--;
    return 1;
}

int main(int argc, char *argv[]) {
    long n = 100000;

    if (argc > 1) {
        char *end;
        n = strtol(argv[1], &end, 10);

        if (*end != '\0' || n < 1 || n > 1000000) {
            printf("Enter a size from 1 to 1000000.\n");
            return 1;
        }
    }

    IntList list = {NULL, 0, 0};

    clock_t start = clock();

    for (long i = 0; i < n; i++) {
        if (!append(&list, (int)(i % 1000))) {
            printf("Memory allocation failed.\n");
            free(list.data);
            return 1;
        }
    }

    for (long i = 0; i < n / 4; i++)
        pop(&list);

    double elapsed_ms =
        (double)(clock() - start) * 1000.0 / CLOCKS_PER_SEC;

    long long checksum = 0;

    for (size_t i = 0; i < list.size; i++)
        checksum += list.data[i];

    printf("Language: C\n");
    printf("Added: %ld\n", n);
    printf("Removed: %ld\n", n / 4);
    printf("Final count: %zu\n", list.size);
    printf("Time (ms): %.3f\n", elapsed_ms);
    printf("Checksum: %lld\n", checksum);

    free(list.data);
    return 0;
}
