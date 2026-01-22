# Sudoku Validator

- A program that traverses and analyzes a text-based Sudoku puzzle file to validate whether it represents a correct solution, ensuring all rows, columns, and subgrids satisfy standard Sudoku constraints.

## Author Info

- Full Name: Ethan E. Lopez
- Student ID: 2425516
- Chapman Email: etlopez@chapman.edu
- Course Number And Section: CPSC-298
- Assignment Or Exercise Number: PA 2: Sudoku Validator

## Usage

- Compile the program using the appropriate compiler for the language used.
- Run the executable and provide the path to a Sudoku .txt file as input (either via command-line argument or standard input, depending on implementation).
- The program outputs whether the Sudoku solution is valid or invalid based on constraint checks.

## Input Format

- The input file must be a plain text (.txt) file.
- The file contains a 9×9 grid of integers.
- Each row represents a Sudoku row, with numbers separated by spaces.
- Valid values range from 1 to 9, inclusive.
- Any deviation from this format or from Sudoku rules results in an invalid solution.

## Example:

5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9

## Implementation Details

- The program reads the Sudoku grid from a file and stores it in a 2D data structure.
- Validation is performed by checking:
1. Each row for duplicate values
2. Each column for duplicate values
3. Each 3×3 subgrid for duplicate values
- Efficient data structures (such as arrays or sets) are used to track seen values during validation.
- The program reports a final boolean result indicating whether the Sudoku solution satisfies all constraints.
