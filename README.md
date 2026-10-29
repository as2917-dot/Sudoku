To compile and run the above code you will need to install Raylib on your computer.

This code runs in O(N) time complexity per cell rather than trying to test validity of entire board per frame which would take O(N^3), it follows all standard rules in a sudoku board i.e no repetition in the same row, column or sub square. Incorrectly filled cells are denoted by red, the current square is highlighted by yellow, if a board has no red markings after being filled completely you have successfully solved the board.
Only 9 clues are used with the numbers 1-9 scattered throughout the entire 9X9 board, so it is trivially always valid. This approach largely removes traditional backtracking algorithms with exponential time complexities.

Note: There maybe multiple solutions to any given clue configuration due to a very small number of clues.
