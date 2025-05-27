#include "SudokuBoard.h" // includes contents from SudokuBoard class
#include "SudokuValidator.h" // includes contents from SudokuValidator class
#include <iostream> // includes standard input and output functions

int main(int argc, char* argv[]) { // a main method that takes in a file .txt as a terminal input
    SudokuBoard board; // a board object from the SudokuBoard class is created

    try { // try loading / reading the txt file mentioned in input
        board.loadFromFile(argv[1]); // calls loadFromFile method from SudokuBoard that reads the file
    } catch (const std::exception& e) { // if something goes wrong, create an exception
        std::cerr << "Error loading Sudoku grid: " << e.what() << std::endl; // print an error
        return 1; // end the program
    }

    SudokuValidator validator(board); // create a sudoku validator with board
    validator.validate(); // validate the board using the validate() method
    return 0; // end the program
}
