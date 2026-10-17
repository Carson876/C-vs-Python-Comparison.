
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

static uint32_t random_state = 12345u;

static int next_number(void) {
    random_state = random_state * 1664525u + 1013904223u;
    return (int)(random_state % 100000u);
}

static size_t smaller(size_t a, size_t b) {
    return a < b ? a : b;
}

static int merge_sort(int arr[], size_t n) {
    if (n < 2) return 1;

    int *temp = malloc(n * sizeof(int));
    if (!temp) return 0;

    int *src = arr;
    int *dst = temp;

    for (size_t width = 1; width < n; width *= 2) {
        for (size_t left = 0; left < n; left += 2 * width) {
            size_t mid = smaller(left + width, n);
            size_t right = smaller(left + 2 * width, n);
            size_t i = left, j = mid, k = left;

            while (i < mid && j < right) {
                if (src[i] <= src[j])
                    dst[k++] = src[i++];
                else
                    dst[k++] = src[j++];
            }

            while (i < mid)
                dst[k++] = src[i++];

            while (j < right)
                dst[k++] = src[j++];
        }

        int *swap = src;
        src = dst;
        dst = swap;
    }

    if (src != arr)
        memcpy(arr, src, n * sizeof(int));

    free(temp);
    return 1;
}

static int binary_search(const int arr[], size_t n, int target) {
    size_t low = 0, high = n;

    while (low < high) {
        size_t mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return 1;

        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    long count = 10000;

    if (argc > 1) {
        char *end;
        count = strtol(argv[1], &end, 10);

        if (*end != '\0' || count < 1 || count > 1000000) {
            printf("Enter a size from 1 to 1000000.\n");
            return 1;
        }
    }

    size_t n = (size_t)count;
    int *numbers = malloc(n * sizeof(int));

    if (!numbers) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (size_t i = 0; i < n; i++)
        numbers[i] = next_number();

    clock_t start = clock();

    if (!merge_sort(numbers, n)) {
        printf("Merge sort memory allocation failed.\n");
        free(numbers);
        return 1;
    }

    double sort_ms =
        (double)(clock() - start) * 1000.0 / CLOCKS_PER_SEC;

    int found = 0;
    start = clock();

    for (int q = 0; q < 10000; q++) {
        int target = (q * 97) % 100000;
        found += binary_search(numbers, n, target);
    }

    double search_ms =
        (double)(clock() - start) * 1000.0 / CLOCKS_PER_SEC;

    long long checksum = 0;

    for (size_t i = 0; i < n; i++)
        checksum += numbers[i];

    printf("Language: C\n");
    printf("Items: %zu\n", n);
    printf("Sort time (ms): %.3f\n", sort_ms);
    printf("Search time for 10000 queries (ms): %.3f\n", search_ms);
    printf("Found: %d\n", found);
    printf("Checksum: %lld\n", checksum);

    free(numbers);
    return 0;
}
