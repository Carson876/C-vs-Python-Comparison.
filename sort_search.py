
import sys
import time


def make_numbers(n):
    state = 12345
    numbers = []

    for _ in range(n):
        state = (state * 1664525 + 1013904223) & 0xFFFFFFFF
        numbers.append(state % 100000)

    return numbers


def merge_sort(arr):
    n = len(arr)

    if n < 2:
        return

    temp = [0] * n
    src = arr
    dst = temp
    width = 1

    while width < n:
        for left in range(0, n, 2 * width):
            mid = min(left + width, n)
            right = min(left + 2 * width, n)

            i, j, k = left, mid, left

            while i < mid and j < right:
                if src[i] <= src[j]:
                    dst[k] = src[i]
                    i += 1
                else:
                    dst[k] = src[j]
                    j += 1

                k += 1

            while i < mid:
                dst[k] = src[i]
                i += 1
                k += 1

            while j < right:
                dst[k] = src[j]
                j += 1
                k += 1

        src, dst = dst, src
        width *= 2

    if src is not arr:
        arr[:] = src


def binary_search(arr, target):
    low = 0
    high = len(arr)

    while low < high:
        mid = low + (high - low) // 2

        if arr[mid] == target:
            return True

        if arr[mid] < target:
            low = mid + 1
        else:
            high = mid

    return False


def main():
    try:
        n = int(sys.argv[1]) if len(sys.argv) > 1 else 10000

        if not 1 <= n <= 1000000:
            raise ValueError

    except ValueError:
        print("Enter a size from 1 to 1000000.")
        return 1

    numbers = make_numbers(n)

    start = time.process_time()
    merge_sort(numbers)
    sort_ms = (time.process_time() - start) * 1000

    found = 0
    start = time.process_time()

    for q in range(10000):
        target = (q * 97) % 100000
        found += binary_search(numbers, target)

    search_ms = (time.process_time() - start) * 1000

    print("Language: Python")
    print(f"Items: {n}")
    print(f"Sort time (ms): {sort_ms:.3f}")
    print(f"Search time for 10000 queries (ms): {search_ms:.3f}")
    print(f"Found: {found}")
    print(f"Checksum: {sum(numbers)}")

    return 0


if __name__ == "__main__":
    sys.exit(main())
