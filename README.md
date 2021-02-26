# Conways Game of Life

Developed by the mathematician John Horton Conway, the game of life consists of a rectangular n × m grid of cells, where each cell can be alive or dead. Every cell interacts with its eight neighbors (horizontally, vertically, diagonally adjacent), and at each step of time:

  • a cell with fewer than two live neighbors dies (underpopulation);\
  • a cell with two or three live neighbors continues to live;\
  • a cell with four or more live neighbors dies (overpopulation);\
  • a dead cell with exactly three live neighbors becomes alive (reproduction).
  
This program will represent a grid as a 2-dimensional array with n lines, each of length m. Each line consists of the character O for an alive cell and the standard underscore character _ for a dead cell.

An invalid input is immediately rejected by the program (e.g., if it contains other characters than _ or O).

More information about the game, its rule andm tests can be found at:
https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
