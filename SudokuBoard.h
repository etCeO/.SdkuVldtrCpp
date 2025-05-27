#ifndef SUDOKUBOARD_H // allows the SudokuBoard class to only be defined once
#define SUDOKUBOARD_H // defines SudokuBoard

#include <iostream> // includes input and output functions
#include <string> // includes std::string
#include <fstream> // includes ifstream and ofstream

class SudokuBoard { // class body defined
private: // private variables
    int grid[9][9]; // 9x9 Sudoku grid

public: // public constructors and methods
    SudokuBoard(); // default constructor
    void loadFromFile(const std::string& filename); // public void method that takes in a filename and processes its contents
    void saveToFile(const std::string& filename, const std::string& message) const; // public void method that takes in a filename and message as strings
    // takes previous file from loadFromFile() and creates a new file with the same contents plus a correction
    // this tells the reader whether their solution is correct or incorrect
    int getCell(int row, int col) const; // returns the value of a single cell in SudokuBoard's grid
    void setCell(int row, int col, int value); // sets the value of a single cell in SudokuBoard's grid

    friend std::ostream& operator<<(std::ostream& os, const SudokuBoard& board); // outstream operator that prints the grid
};

#endif // end of class definition
