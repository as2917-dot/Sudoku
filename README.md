To compile and run the above code you will need to install Raylib on your computer.

This code runs in O(N) time complexity per cell rather than trying to test validity of entire board per frame which would take O(N^3), it follows all standard rules in a sudoku board i.e no repetition in the same row, column or sub square. Incorrectly filled cells are denoted by red, the current square is highlighted by yellow, if a board has no red markings after being filled completely it has been successfully solved.
Only 9 clues are used with the numbers 1-9 scattered throughout the entire 9X9 board marked in blue, so it is trivially always valid. This approach largely removes traditional backtracking algorithms with exponential time complexities.

Note: There may be multiple solutions to any given clue configuration due to a very small number of clues.


![Screenshot 1](https://github.com/as2917-dot/Sudoku/blob/main/Screenshot%202026-09-12%20134011.png)

![Screenshot 2](https://github.com/as2917-dot/Sudoku/blob/main/Screenshot%202026-09-12%20223318.png)

![Screenshot 3](https://github.com/as2917-dot/Sudoku/blob/main/Screenshot%202026-09-18%20233935.png)
