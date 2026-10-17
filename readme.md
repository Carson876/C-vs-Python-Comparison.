
# Comparing C and Python

## Project Overview

For this project, I am comparing C and Python to see how they differ in performance, readability, error handling, and memory management. I created three programs in each language that perform the same tasks. I then tested the programs to see how their execution times compare and checked that they produce the same results.

## Programs

The project contains three experiments.

### Experiment 1: Sorting and Searching

Files:
- sort_search.c
- sort_search.py

Both programs generate random numbers, sort them using merge sort, and perform 10,000 binary searches. This experiment compares execution time, syntax, and code length.

### Experiment 2: File Reading and Error Handling

Files:
- file_analysis.c
- file_analysis.py
- numbers.txt

Both programs read numbers from a text file and calculate the sum, minimum, maximum, and average. They also count invalid entries and blank lines.

This experiment compares how both languages handle files and errors.

### Experiment 3: Dynamic Lists and Memory Management

Files:
- dynamic_list.c
- dynamic_list.py

Both programs add numbers to a collection and remove some of them.

C uses realloc() and free() to manage memory manually. Python uses built-in lists that automatically manage memory.

This experiment compares performance, memory management, and the amount of code needed.

## Requirements

The following tools are needed:

- GCC compiler
- Python 3
- Visual Studio Code
- Windows PowerShell

## Compiling the C Programs

Open the terminal in VS Code and run:

```powershell
gcc -O2 -std=c11 sort_search.c -o sort_search.exe
gcc -O2 -std=c11 file_analysis.c -o file_analysis.exe
gcc -O2 -std=c11 dynamic_list.c -o dynamic_list.exe
```

## Running the Programs

### Experiment 1

```powershell
.\sort_search.exe 10000
python sort_search.py 10000

.\sort_search.exe 50000
python sort_search.py 50000
```

### Experiment 2

```powershell
.\file_analysis.exe numbers.txt
python file_analysis.py numbers.txt
```

### Experiment 3

```powershell
.\dynamic_list.exe 10000
python dynamic_list.py 10000

.\dynamic_list.exe 100000
python dynamic_list.py 100000
```

## Performance Results

These results were collected from my Windows computer. Each test was run once, so the results are preliminary.

| Test | C (ms) | Python (ms) |
|---|---:|---:|
| Sorting 10,000 numbers | 1.000 | 15.625 |
| Searching 10,000 queries (10K items) | 1.000 | 15.625 |
| Sorting 50,000 numbers | 7.000 | 93.750 |
| Searching 10,000 queries (50K items) | 2.000 | 15.625 |
| Dynamic List 10,000 | 0.000 | 15.625 |
| Dynamic List 100,000 | 0.000 | 15.625 |

The results show that C was faster than Python in the sorting and searching tests.

The dynamic list program reported 0.000 milliseconds for C. This does not mean the program took no time. The timer was not precise enough to measure the operation accurately.

More tests will be needed to calculate reliable averages.

## Correctness Results

### Sorting and Searching

10,000 numbers:
- Matches found: 982
- Checksum: 501252616

50,000 numbers:
- Matches found: 3934
- Checksum: 2508342600

Both languages produced identical results.

### File Analysis

Both programs produced:

- Valid numbers: 6
- Invalid entries: 3
- Blank lines: 2
- Sum: 90
- Minimum: -10
- Maximum: 45
- Average: 15.00

### Dynamic Lists

10,000 numbers:
- Numbers removed: 2500
- Final count: 7500
- Checksum: 3621250

100,000 numbers:
- Numbers removed: 25000
- Final count: 75000
- Checksum: 37462500

Both languages produced identical results.

## Comparison of C and Python

### Performance

Based on my initial results, C generally performed faster than Python. However, I still need to repeat the experiments several times and calculate averages.

### Readability

Python generally uses shorter syntax and requires fewer statements for certain operations. C requires more explicit instructions, especially when dealing with memory and data structures.

### Memory Management

C requires the programmer to manually allocate and release memory using functions such as malloc(), realloc(), and free().

Python automatically manages memory and provides built-in lists that can grow without manually allocating memory.

### Error Handling

C typically handles errors by checking return values and reporting problems.

Python provides exception handling using try and except statements.

### Development Effort

Python provides built-in features that can make programs easier to write. C may require additional code for similar functionality.

I plan to compare lines of code and the effort needed to develop and debug each program.

## Project Progress

So far, I have:

- Created three C programs.
- Created three Python programs.
- Compiled and executed all three C programs.
- Tested all three Python programs.
- Compared sorting and searching performance.
- Tested file reading and error handling.
- Tested dynamic lists and memory management.
- Verified that matching programs produce the same results.
- Recorded initial performance results.

## Next Steps

The remaining work includes:

1. Running each performance test five times.
2. Calculating average execution times.
3. Creating graphs to compare results.
4. Counting lines of code in each program.
5. Evaluating readability and development effort.
6. Writing the final research report.
7. Preparing the final presentation.

## Tools and Assistance

This project uses GCC, Python 3, and Visual Studio Code.


