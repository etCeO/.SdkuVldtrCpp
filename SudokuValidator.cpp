#include <iostream> // imports input and output functions
#include <string> // includes std::string
#include "SudokuBoard.h" // includes contents from SudokuBoard class
#include "SudokuValidator.h" // includes contents from SudokuValidator class

using std::cout; // shortens output to cout
using std::cin; // shortens input to cin
using std::endl; // shortens newline to endl

bool SudokuValidator::checkRow(int row) const {
    // a private bool method for checking if a row in a 9x9 grid contain all unique numbers
    for (int i = 0; i < 9; i++) { // for all numbers in row
        for (int j = i + 1; j < 9; j++) { // compare these with numbers that come after
            if (board.getCell(row, i) == board.getCell(row, j)) { // if any number in row is repeated with getCell()
                return false; // return false saying the row is not unique
            }
        }
    }
    return true; // if all numbers pass without duplicates return true
    // the row is valid
}

bool SudokuValidator::checkColumn(int col) const {
    // a private bool method for checking if a column in a 9x9 grid contains unique numbers
    for (int i = 0; i < 9; i++) { // for all numbers in column
        for (int j = i + 1; j < 9; j++) { // compare these with numbers that come after
            if (board.getCell(i, col) == board.getCell(j, col)) { // if any number in column is repeated with getCell()
                return false; // return false saying the column is not unique
            }
        }
    }
    return true; // if all numbers pass without duplicates return true
    // the column is valid
}

bool SudokuValidator::checkSubgrid(int startRow, int startCol) const {
    // a private bool method for checking 3x3 subgrids starting at a specific row and column
    for (int i = startRow; i < startRow + 3; i++) { // for each row of 3 starting at startRow
        for (int j = startCol; j < startCol + 3; j++) { // for each column of 3 starting at startCol
            for (int x = i; x < startRow + 3; x++) { // check numbers that come after
                int y; // defined for indexing columns
                if (x == i) { // if x is i 
                    y = j + 1; // y is the number that comes after j
                } else { // if x is not i and potentially out of range
                    y = startCol; // y is the beginning of the column
                }
                for (y; y < startCol + 3; y++) { // check numbers that come after
                    if (board.getCell(i, j) == board.getCell(x, y)) { // if any numbers in the subgrid are repeated
                        return false; // return false saying the subgrid is not unique
                    }
                }
            }
        }
    }
    return true; // if all numbers pass without duplicates return true
    // the subgrid is valid
}

// OVERLOADED CONSTRUCTOR
SudokuValidator::SudokuValidator(const SudokuBoard& board) : board(board){};
// takes in parameter board from SudokuBoard as a constant and assigns it as variable board in SudokuValidator
// std::string errorMessage is declared but not defined until validate() method is called 
// errorMessage will serve the purpose of identifying problems in the sudoku puzzle

bool SudokuValidator::validate() {
    // a public bool method that calls all previous check() private methods to validate the entire sudoku grid
    std::string valid = "Sudoku_Valid.txt"; // name of solution txt file if the sudoku board is valid
    std::string invalid = "Sudoku_Invalid.txt"; // name of the error txt file if the sudoku board is invalid
    // txts are in type string for opening and writing to files in saveToFile() method from the sudoku board
    std::string validMessage = "The Soduku solution is valid!"; // string validMessage that prints when a solution is correct
    for (int a = 0; a < 9; a++) { // for all numbers in rows
        for (int b = 0; b < 9; b++) { // for all numbers in columns
            if (board.getCell(a,b) < 1 || board.getCell(a,b) > 9) { // if any number in grid is not in range 1-9
                errorMessage = "Board has INVALID NUMBERS!!! (must be in range 1-9)";
                cout << errorMessage << endl; // print an invalid errorMessage
                board.saveToFile(invalid, errorMessage); // save the results to "Sudoku_Invalid.txt"
                return false; // break the loop and further processing by returning false to the method
            }
        }
    }
    for (int i = 0; i < 9; i++) { // for rows and columns indexed 0-8
        if (!(checkRow(i))) { // if any row 0-8 has repeating numbers
            // rows 0-8 become rows 1-9 because this is how we count rows in sudoku
            errorMessage = "Row " + std::to_string(i+1) + " has duplicates."; // assign errorMessage to a string that tells which row has duplicates
            cout << errorMessage << endl; // print the errorMessage to the terminal
            board.saveToFile(invalid, errorMessage); // save the results to "Sudoku_Invalid.txt"
            return false; // break the loop and further processing by returning false to the method
        }
        else if (!(checkColumn(i))) { // if any column 0-8 has repeating numbers
            // columns 0-8 become columns 1-9 because this is how we count columns in sudoku
            errorMessage = "Column " + std::to_string(i+1) + " has duplicates."; // assign errorMessage to a string that tells which column has duplicates
            cout << errorMessage << endl; // print the errorMessage to the terminal
            board.saveToFile(invalid, errorMessage); // save the results to "Sudoku_Invalid.txt"
            return false; // break the loop and further processing by returning false to the method
        }
    }
    // when all rows and columns are valid and don't have repeating numbers
    // start checking subgrids
    // indexes for subgrid must be a maximum of six as the method will call the parameters to go from starting point to two more indexes after
    // six is thus the maximum index in the loop that permits the method to go from rows/columns 6-8 in the final subgrid
    for (int x = 0; x < 7; x++) { // for all rows starting at 0-6
        for (int y = 0; y < 7; y++) { // for all columns starting at 0-6
            if (x % 3 == 0 && y % 3 == 0) { // if an index is 0, 3, or 6, in both x and y, this is the start of a subgrid
                if (!(checkSubgrid(x,y))) { // if a subgrid has repeating numbers
                    errorMessage = "Subgrid starting at Row " + std::to_string(x+1) + ", Column " + std::to_string(y+1) + " has duplicates.";
                    // assign errorMessage to a string telling which subgrid is repeating
                    cout << errorMessage << endl; // print the errorMessage to the terminal
                    board.saveToFile(invalid, errorMessage); // save the results to "Sudoku_Invalid.txt"
                    return false; // break the loop and further processing by returning false to the method
                }
            }
        }
    }
    cout << validMessage << endl; // if all tests pass, print the validMessage saying the solution is valid to the terminal
    board.saveToFile(valid, validMessage); // save the results to "Sudoku_Valid.txt"
    return true; // return the solution as valid
}

// ACCESSOR
const std::string& SudokuValidator::getErrorMessage() const { // returns string errorMessage when needed
    return errorMessage;
}



