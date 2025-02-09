# Shortest Secret Passcode Finder

## Overview
This project solves the problem of finding the shortest possible passcode for online banking by analyzing a list of successful login attempts. Each login attempt provides three characters in order, and the goal is to deduce the shortest passcode that satisfies all the conditions from these attempts.

The method works by processing the file `keylog.txt`, which contains 50 login attempts. Each attempt provides 3 characters from the passcode in a specific order. The objective is to determine the shortest passcode by maintaining the order of characters across all the given attempts.

## Problem Description
In online banking, a common security measure is to ask the user for three random characters from their passcode. Given a passcode of unknown length, and a file containing 50 successful login attempts, the goal is to deduce the passcode.

Each login attempt in the file contains three digits, provided in the correct order. By analyzing all the attempts, the program will output the shortest possible passcode that satisfies all the constraints (i.e., the correct order of digits as specified by each login attempt).

## Solution Approach
1. **Input**: The program reads a file, `keylog.txt`, which contains 50 login attempts. Each line of the file consists of three digits from the passcode in order.
   
2. **Logic**:
   - The program analyzes the order of digits across all attempts.
   - It then determines the sequence of digits that satisfies all the login attempts, ensuring that the order of digits in each attempt is respected.

3. **Algorithms Used**:
   - **Vectors**: C++ vectors are used to store and manipulate the passcode digits efficiently, providing dynamic resizing and random access.
   - **Swap Elements**: The algorithm utilizes swap operations to reorder elements in the passcode sequence and ensure the correct order is preserved based on the login attempts.
   - **Bubble Sort**: A bubble sort algorithm is used to help organize and rearrange the passcode digits as required.
   - **Unique Value Algorithm**: The program also employs an algorithm to identify and maintain only unique passcode digits, ensuring no duplicates are included in the final passcode.

4. **Output**: The program prints the shortest passcode that fits all the provided constraints.

### Steps Taken
1. **Reading Input**: The file `keylog.txt` is read, which contains the login attempts (each consisting of three digits).
   
2. **Tracking the Order**: For each login attempt, the program considers the relative order of the digits and builds a list of possible passcode digits, maintaining the correct order between characters.

3. **Constructing the Passcode**: By analyzing the constraints (order of digits) from all the login attempts, the program deduces the shortest possible passcode that satisfies all the conditions.

4. **Output**: The program outputs the shortest passcode that fulfills all the conditions.

## Requirements
- C++ compiler (e.g., GCC, Clang)
- A text file named `keylog.txt` containing the login attempts.

## Example

### Input (`keylog.txt`):
