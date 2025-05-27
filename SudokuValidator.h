#ifndef SUDOKUVALIDATOR_H // allows the SudokuValidator class to only be defined once
#define SUDOKUVALIDATOR_H // defines SudokuValidator

#include "SudokuBoard.h" // includes contents from the SudokuBoard class
#include <string> // includes std::string

class SudokuValidator { // class body defined
private: // private member variables and methods
    const SudokuBoard& board; // board from SudokuBoard class as a constant
    std::string errorMessage; // a string to output errors

    bool checkRow(int row) const; // a private bool method indicating if a specific row in the board's grid contains all unique numbers 1-9
    bool checkColumn(int col) const; // a private bool method indicating if a specific column in the board's grid contains all unique numbers 1-9
    bool checkSubgrid(int startRow, int startCol) const; // a private bool method indicating if all 3x3 subgrids in grid are unique numbers 1-9

public: // public methods and constructors
    SudokuValidator(const SudokuBoard& board); // overloaded constructor passing on SudokuBoard's board methods and variables
    bool validate(); // a public bool method that usings check private methods to confirm if the grid in its entirety is valid
    const std::string& getErrorMessage() const; // returns errorMessage variable
};

#endif // end of class definition
