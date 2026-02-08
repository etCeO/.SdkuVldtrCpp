# Sudoku Validator

- A program that traverses and analyzes a text-based Sudoku puzzle file to validate whether it represents a correct solution, ensuring all rows, columns, and subgrids satisfy standard Sudoku constraints.

## Author Info

- Full Name: Ethan E. Lopez
- Chapman Email: etlopez@chapman.edu
- Course Number And Section: CPSC-298
- Assignment Or Exercise Number: PA 2: Sudoku Validator

## Usage

1. Compile the program using an adequate compiler for C++.
2. Execute the generated executable file with the path of the Sudoku.txt file as the input, either from the command line or standard input as appropriate.
3. The program will print whether the Sudoku solution is valid or not based on the constraint checks.

## Input Format

- The input file needs to be in plain text (.txt) format
- The file contains a 9x9 grid of integers.
- Each row is a Sudoku row with numbers separated by spaces.
- Values can range from 1 to 9, inclusive.
- Any change in the format or rules of Sudoku renders the solution incorrect.

## Implementation Details

- The program reads the input Sudoku puzzle from the specified file and stores it in a 2D data structure.
- The validation procedure involves checking the following:
1. Each row for duplicate values
2. Each column for duplicate values
3. Each 3×3 subgrid for duplicate values
- Efficient data structures, like arrays or sets, are employed for keeping track of seen values.
- The program includes a final boolean output indicating whether the solution satisfies all the constraints.
