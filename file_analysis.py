
import re
import sys


def main():
    filename = sys.argv[1] if len(sys.argv) > 1 else "numbers.txt"

    values = []
    invalid = 0
    blank = 0

    try:
        with open(filename, "r", encoding="utf-8") as file:
            for line in file:
                text = line.strip()

                if not text:
                    blank += 1
                    continue

                if not re.fullmatch(r"[+-]?[0-9]+", text):
                    invalid += 1
                    continue

                number = int(text)

                if not -2147483648 <= number <= 2147483647:
                    invalid += 1
                    continue

                values.append(number)

    except OSError as error:
        print(f"Cannot open/read input file: {error}")
        return 1

    print(f"File: {filename}")
    print(f"Valid: {len(values)}")
    print(f"Invalid: {invalid}")
    print(f"Blank: {blank}")
    print(f"Sum: {sum(values)}")

    if values:
        print(f"Minimum: {min(values)}")
        print(f"Maximum: {max(values)}")
        print(f"Average: {sum(values) / len(values):.2f}")
    else:
        print("No valid numbers were found.")

    return 0


if __name__ == "__main__":
    sys.exit(main())
