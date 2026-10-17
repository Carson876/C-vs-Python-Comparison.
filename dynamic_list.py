
import sys
import time


def main():
    try:
        n = int(sys.argv[1]) if len(sys.argv) > 1 else 100000

        if not 1 <= n <= 1000000:
            raise ValueError

    except ValueError:
        print("Enter a size from 1 to 1000000.")
        return 1

    numbers = []

    start = time.process_time()

    for i in range(n):
        numbers.append(i % 1000)

    for _ in range(n // 4):
        numbers.pop()

    elapsed_ms = (time.process_time() - start) * 1000

    print("Language: Python")
    print(f"Added: {n}")
    print(f"Removed: {n // 4}")
    print(f"Final count: {len(numbers)}")
    print(f"Time (ms): {elapsed_ms:.3f}")
    print(f"Checksum: {sum(numbers)}")

    return 0


if __name__ == "__main__":
    sys.exit(main())
