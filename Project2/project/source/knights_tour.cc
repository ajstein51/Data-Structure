#include <iostream>
#include <iomanip>
#include "knights_tour.h"
using namespace std;

KnightsTour::KnightsTour(int board_size) {
  this->board_size = board_size;

  this->board.resize(board_size);
  for (int i = 0; i < board_size; ++i) {
    this->board[i].resize(board_size);
  }
}

void KnightsTour::print() {
  for (int i = 0; i < this->board_size; i++) {
    for (int j = 0; j < this->board_size; j++)
      cout << setw(4) << this->board[i][j] << " ";
    cout << endl;
  }
  cout << endl << endl;
}

// Function: get_moves()
//    Desc: Get the row and column indices of all valid
//          knight moves reachable from position row, col.
//          An invalid move would be one that sends the
//          knight off the edge of the board or
//          to a position that has already been visited.
//          
//    int row         - Current row position of knight.
//    int col         - Current column position of knight.
//    int row_moves[] - Array to store row indices
//                      of all valid new moves reachable from
//                      the current position row, col.
//    int col_moves[] - Array to store column indices
//                      of all valid new moves reachable from
//                      the current position row, col.
//    int num_moves -   Number of valid moves found. Corresponds
//                      to the sizes of row_moves and col_moves.

void KnightsTour::get_moves(int row, int col, int row_moves[], int col_moves[], int& num_moves) { // do first (only 1 or two loops)
  int tmpx, tmpy;
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      tmpx = row_moves[i], tmpy = col_moves[j];
      if(isvalid(tmpx, tmpy) == true){
        num_moves++;
      }
    }
  }
    
}
// Function: move() --> Recursive
//     int row        - Current row position of knight.
//     int col        - Current column position of knight.
//     int& m         - Current move id in tour.
//                      Stored in board at position
//                      row, col.
//     int& num_tours - Total number of tours found.

void KnightsTour::move(int row, int col, int& m, int& num_tours) { // clockwise tour, row = x, col = y, call print function when it finds a complete tour
  m++;
  board[row][col] = m;
  int x_moves[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };  
  int y_moves[8] = {  1, 2,  2,  1, -1, -2, -2, -1 }; 
  int num_moves = 0;
  get_moves(row, col, x_moves, y_moves, num_moves);
  if(m == 25){
    num_tours++;
    print();
  }
  for(int i = 0; i < num_moves; i++)
    move(x_moves[i], y_moves[i], m, num_tours);
  
  m--;
  board[row][col] = 0;

}// backtrack decrement M and undo the move (set back to 0)

bool KnightsTour::isvalid(int x, int y){
  if(x > 0 && x < 5 && y > 0 && y < 5 && board[x][y] == 0)
    return true;
  return false;
}

int KnightsTour::generate(int row, int col) {
  int m = 0;
  int num_tours = 0;
  move(row, col, m, num_tours);

  return num_tours;
}
