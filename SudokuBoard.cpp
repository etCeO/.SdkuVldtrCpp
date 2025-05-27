#include <iostream> // imports input and output functions
#include <fstream> // includes file processing, reading, and writing methods
#include <string> // includes std::string
#include <sstream> // DR. EEL: Required for std::istringstream
#include "SudokuBoard.h" // includes contents from SudokuBoard class

using std::cout; // shortens output to cout
using std::cin; // shortens input to cin
using std::endl; // shortens newline to endl

SudokuBoard::SudokuBoard(){}; // default constructor
// int grid[9][9] is defined from loadFromFile() method
    
void SudokuBoard::loadFromFile(const std::string& filename) {
    // a public void method that takes in a filename and reads its contents into grid

    cout << "Loading File..." << endl;

    std::ifstream inFile(filename); // ifstream identified as inFile to observe the file's reading
    std::string line; // string line for every line in txt file reading
    int count_row = 0; // a variable defining each row's index

    if (inFile.is_open()) { // if the file is opened
        int i = 0; // i is declared and assigned to row 0
        while (std::getline(inFile, line)) { // while there are lines to be read in the txt file
            // DR. EEL's edits
            std::istringstream ss(line); // creates a string stream to parse the line
            std::string val; // std::string val is created to store each line read
            int count_col = 0; // keeps track of indexing for each number read in the 9x9 grid
            // a variable defining each column's index
            while (std::getline(ss, val, ' ') && count_col < 9) { // read space-separated values from the line
                // while the delimiter is defined
                cout << val << " "; // print val followed by a space in each row
                grid[count_row][count_col] = std::stoi(val); // converts string to int through typecasting
                // assign the val to grid at it's equivalent row and column in board
                count_col++; // increment columns after each number is read
            }
            cout << endl; // newline for each row when completed
            count_row++; // increment after each row is read
        }
    

        // my old code that I tried :( :
        // // for each line
        //     int x = 0; // x is declared assigned to column 0
        //     for (int j : line) { // for all ints that are read in line
        //         grid[i][x] = j; // assign them to their corresponding cell in grid
        //         ++x; // increment each column in line by 1
        //     }
        //     ++i; // increment row value after each line is read
        inFile.close(); // close the file when done
    }
    else { // if an error occurs
        cout << "Error opening file!" << endl; // output this
    }
    }

    
void SudokuBoard::saveToFile(const std::string& filename, const std::string& message) const {
    // a public void method that takes in a filename with a message and copies the original grid to a result file
    // the resulting file also outputs if the solution is valid or not

    std::ofstream outFile(filename); // ofstream identified as outFile is used to write to a file

    if (outFile.is_open()) { // if a file is opened
        for (int i = 0; i < 9; i++) { // for each row in grid
            for (int j = 0; j < 9; j++) { // for each column in grid
                outFile << grid[i][j] << " "; // write the cell number followed by a space
            }
            outFile << endl; // end with a newline when each row is completed
        }
        outFile << message << endl; // after grid is copied, write the file message
        // string message either tells us the correction in format "Column 3 has duplicates." or "The Sudoku solution is valid!"
        outFile.close(); // close the file when done writing
    }
    else { // if an error occurs
        cout << "Error writing to the file!" << endl; // output this
    }

}
    
int SudokuBoard::getCell(int row, int col) const { // a constant int public method that returns an individual value from grid
    return grid[row][col]; // row is the first index while column is the second index in a 2d array
}
    
void SudokuBoard::setCell(int row, int col, int value) { // a void public method that assigns a specific cell in grid to a new value
    grid[row][col] = value; // value is not in the new cell location
}

// OVERLOADED OPERATOR

std::ostream& operator<<(std::ostream& os, const SudokuBoard& board) { // prints the contents of SudokuBoard when needed
    os << board.grid << endl; // grid is the only member variable in board
    return os; // os is an output stream that accumulates this value
}
