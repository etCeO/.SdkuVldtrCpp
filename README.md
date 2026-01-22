# Sudoku Validator

- A program that traverses and analyzes a text-based Sudoku puzzle file to validate whether it represents a correct solution, ensuring all rows, columns, and subgrids satisfy standard Sudoku constraints.

## Author Info

- Full Name: Ethan E. Lopez
- Student ID: 2425516
- Chapman Email: etlopez@chapman.edu
- Course Number And Section: CPSC-298
- Assignment Or Exercise Number: PA 2: Sudoku Validator

## Usage

1. Compile the program using the appropriate compiler for the language used.
2. Run the executable and provide the path to a Sudoku .txt file as input (either via command-line argument or standard input, depending on implementation).
3. The program outputs whether the Sudoku solution is valid or invalid based on constraint checks.

## Input Format

- The input file must be a plain text (.txt) file.
- The file contains a 9×9 grid of integers.
- Each row represents a Sudoku row, with numbers separated by spaces.
- Valid values range from 1 to 9, inclusive.
- Any deviation from this format or from Sudoku rules results in an invalid solution.

## Implementation Details

- The program reads the Sudoku grid from a file and stores it in a 2D data structure.
- Validation is performed by checking:
1. Each row for duplicate values
2. Each column for duplicate values
3. Each 3×3 subgrid for duplicate values
- Efficient data structures (such as arrays or sets) are used to track seen values during validation.
- The program reports a final boolean result indicating whether the Sudoku solution satisfies all constraints.
