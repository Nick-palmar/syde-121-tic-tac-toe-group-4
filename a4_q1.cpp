//***********************************************************
// Student Name: 
// Student Number: 
//
// SYDE 121 Lab: Home Assignment: 4, question 1
// Filename: a4_q1
// I hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts.  This coded solution has
// not been plagiarized from other sources and has not been knowingly
// plagiarized by others
//
// Project: Tic Tac Toe
// Purpose: Play tic tac toe with another person
// Due Date: Friday, November 6, 2020
//**************************************************************

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check_diagonal(vector<vector<string>> board, int col, int row);
// PURPOSE:
//     INPUTS:
//     OUTPUTS:

bool check_vertical(vector<vector<string>> board, int col, int row);
// PURPOSE: Check recursively if there is a vertical tic tac toe situation occuring
//     INPUTS: board - a 2D vector containing all the elements in the board as strings (numbers for empty spaces, X's, O's)
//             col - an integer value corresponding to the current column being checks
//             row - an integer value corresponding to the current row being checks
//     OUTPUTS: A boolean value; true if there is a tic tac toe vertically otherwise false

bool check_horizontal(vector<vector<string>> board, int col, int row);
// PURPOSE:
//     INPUTS:
//     OUTPUTS:

bool check_if_winner(vector<vector<string>> board);
// PURPOSE: Check if someone has won the game by doing vertical, horizontal, and diagonal board checks
//     INPUTS:
//     OUTPUTS:

void update_board(vector<vector<string>>& board, char& current_player, char& other_player);
// PURPOSE:
//     INPUTS:
//     OUTPUTS: Nothing

void output_board(vector<vector<string>> board);
// PURPOSE: Outputs the board to console to show occupied and unoccupied positions
//     INPUTS: board - a 2D vector containing all the elements in the board as strings (numbers for empty spaces, X's, O's)
//     OUTPUTS: Nothing; output to console

bool check_if_play_again();
// PURPOSE:
//     INPUTS:
//     OUTPUTS:

void execute_tic_tac_toe();
// PURPOSE:

bool check_diagonal(vector<vector<string>> board, int col, int row) {
    // check if the space 1 row down and 1 column to the right is a match starting from the top left corner
    while (board[row][col] == board[row + 1][col + 1] && row < board.size() && col < board.size()) {
        // if the second last row satisfies the check, this is a diagonal tic tac toe
        if (row == board.size() - 2) {
            return true;
        }
        row ++;
        col ++;
    }
    row = 0;
    col = 3;
    // check if the space 1 row down and 1 column to the left is a match starting from the top right corner
    while (board[row][col] == board[row + 1][col - 1] && row < board.size() && col >= 0) {
        // if the second last row satisfies the check, this is a diagonal tic tac toe
        if (row == board.size() - 2) {
            return true;
        }
        row ++;
        col --;
    }
    return false;
}

bool check_vertical(vector<vector<string>> board, int col, int row) {
    // base case 1, reached the bottom: nothing is left to check, this is a vertical tic tac toe
    if (row >= (board.size() - 1))
        return true;

    // base case 2, no more columns left to check, no tic tac toe has occured
    else if (col >= board[row].size())
        return false;

    // check if the next space down is not a match, move to next column if not
    if (board[row][col] != board[row + 1][col])
        return check_vertical(board, ++col, 0);

    // next space down is a match, move down and continue check
    return check_vertical(board, col, ++row);
}

bool check_horizontal(vector<vector<string>> board, int col, int row) {
    // base case 1, reached all the way to the right: nothing is left to check, this is a horizontal tic tac toe
    if (col >= (board.size() - 1))
        return true;

    // base case 2, no more rows left to check, no tic tac toe has occured
    else if (row >= board[col].size())
        return false;

    // check if the next space to the right is not a match, move to next row if not
    if (board[row][col] != board[row][col + 1])
        return check_vertical(board, 0, ++ row);

    // next space to the right is a match, move to the right and continue check
    return check_horizontal(board, ++ col, row);
}

bool check_if_winner(vector<vector<string>> board) {
    bool horizontal, vertical, diagonal;
    
    horizontal = check_horizontal(board, 0, 0);
    vertical = check_vertical(board, 0, 0);
    diagonal = check_diagonal(board, 0, 0);

    return (vertical || horizontal || diagonal);
}


void update_board(vector<vector<string>>& board, char& current_player, char& other_player) {
    int input = 0;
    const int MIN_VAL = 1, MAX_VAL = 16;
    bool occupied = false;

    // loops user input if user enters an invalid or occupied location
    do {

        if (occupied) {
            cout << "Location is occupied." << endl;
        }

        cout << "Player " << current_player << ", enter a location to mark (" << MIN_VAL << "-" << MAX_VAL << "): ";
        cin >> input;

        // occupied is true if there exists an "X" or "O" in the entered location
        if (input >= MIN_VAL && input <= MAX_VAL) {
            occupied = board[(input - 1) / board[0].size()][(input - 1) % board[0].size()] == "X" || board[(input - 1) / board[0].size()][(input - 1) % board[0].size()] == "O";
        }

    } while (input < MIN_VAL || input > MAX_VAL || occupied);

    // updates the board with an "X" or "O" based on the turn
    board[(input - 1) / board[0].size()][(input - 1) % board[0].size()] = current_player;

    // switches the turn
    if (current_player == 'X') {
        current_player = 'O';
        other_player = 'X';
    }
    else {
        current_player = 'X';
        other_player = 'O';
    }
}


void output_board(vector<vector<string>> board) {
    // loop through all indicies and output with proper format
    for (int row = 0; row < board.size(); row++) {
        cout << endl;
        for (int col = 0; col < board[row].size(); col++) {
            // add extra space if length one
            if (board[row][col].length() == 1)
                cout << board[row][col] << " \t";
            // no extra space if length 2
            else
                cout << board[row][col] << "\t";
        }
    }

    // end line for formatting
    cout << endl;

}

bool check_if_play_again() {
    int continue_value = 0;
    
    // user enters 1 or 0 to determine if the game continues
    do {
        cout << "\nPlay again? Enter 1 to play again or 0 to quit: ";
        cin >> continue_value;
    } while (continue_value != 1 && continue_value != 0);
    
    // if user enters 1, the game continues
    if (continue_value == 1) {
        return true;
    }
    // if user enters 0, the game ends
    else {
        return false;
    }
}

void execute_tic_tac_toe() {
    // initialize and declare variables
    char starting_player = 'X';
    char current_player, other_player;
    bool play_again = false;
    
    do {
        vector<vector<string>> board = { {"1", "2", "3", "4"}, {"5", "6", "7", "8"}, {"9", "10", "11", "12"}, {"13", "14", "15", "16"} };
        bool winner = false;
        
        // sets the current and other player based on the starting player
        current_player = starting_player;
        
        if (current_player == 'X') {
            other_player = 'O';
        }
        
        else {
            other_player = 'X';
        }

        do {
            output_board(board);
            update_board(board, current_player, other_player);
        
            winner = check_if_winner(board);
        
            if (check_if_winner(board)) {
                cout << "Player " << other_player << " has won!" << endl;
            }
        
        } while (!winner);
        
        
        play_again = check_if_play_again();
        
        // if the game continues, the starting player switches
        if (play_again && starting_player == 'X') {
            starting_player = 'O';
        }
        else if (play_again && starting_player == 'O') {
            starting_player = 'X';
        }
        
    } while (play_again);

    // vertical tic tac toe test cases
    /*board = { {"X", "X", "X", "X" }, {"5", "6", "7", "8"}, {"9", "10", "11", "12"}, {"13", "14", "15", "16"} };
    cout << "board 1: Expected -> 0. Returned: " << check_if_winner(board) << endl;

    board = { {"X", "X", "X", "X" }, {"X", "6", "7", "8"}, {"X", "10", "11", "12"}, {"13", "14", "15", "16"} };
    cout << "board 2: Expected -> 0. Returned: " << check_if_winner(board) << endl;

    board = { {"X", "X", "X", "X" }, {"X", "6", "7", "8"}, {"X", "10", "11", "12"}, {"X", "14", "15", "16"} };
    cout << "board 3: Expected -> 1. Returned: " << check_if_winner(board) << endl;

    board = { {"X", "X", "X", "X" }, {"5", "6", "7", "X"}, {"9", "10", "11", "X"}, {"13", "14", "15", "X"} };
    cout << "board 4: Expected -> 1. Returned: " << check_if_winner(board) << endl;

    board = { {"X", "X", "X", "X" }, {"5", "6", "7", "X"}, {"9", "10", "11", "X"}, {"13", "14", "15", "O"} };
    cout << "board 5: Expected -> 0. Returned: " << check_if_winner(board) << endl;

    board = { {"X", "X", "O", "X" }, {"5", "6", "O", "X"}, {"9", "10", "O", "X"}, {"13", "14", "O", "O"} };
    cout << "board 6: Expected -> 1. Returned: " << check_if_winner(board) << endl;*/
    
    // horizontal tic tac toe test cases
    /*board = { {"X", "2", "3", "4" }, {"X", "6", "7", "8"}, {"X", "10", "11", "12"}, {"X", "14", "15", "16"} };
    cout << "board 1: Expected -> 0. Returned: " << check_if_winner(board) << endl;

    board = { {"X", "X", "X", "4" }, {"X", "6", "7", "8"}, {"X", "10", "11", "12"}, {"X", "14", "15", "16"} };
    cout << "board 2: Expected -> 0. Returned: " << check_if_winner(board) << endl;

    board = { {"X", "X", "X", "X" }, {"X", "6", "7", "8"}, {"X", "10", "11", "12"}, {"X", "14", "15", "16"} };
    cout << "board 3: Expected -> 1. Returned: " << check_if_winner(board) << endl;

    board = { {"X", "X", "X", "X" }, {"5", "6", "7", "X"}, {"9", "10", "11", "X"}, {"13", "14", "15", "X"} };
    cout << "board 4: Expected -> 1. Returned: " << check_if_winner(board) << endl;

    board = { {"X", "X", "X", "O" }, {"5", "6", "7", "X"}, {"9", "10", "11", "X"}, {"13", "14", "15", "X"} };
    cout << "board 5: Expected -> 0. Returned: " << check_if_winner(board) << endl;

    board = { {"X", "X", "O", "X" }, {"O", "O", "O", "O"}, {"9", "10", "11", "X"}, {"13", "14", "15", "X"} };
    cout << "board 6: Expected -> 1. Returned: " << check_if_winner(board) << endl;*/
    
    // diagonal tic tac toe test cases
    /*board = { {"X", "X", "X", "X" }, {"5", "6", "7", "8"}, {"9", "10", "11", "12"}, {"13", "14", "15", "16"} };
    cout << "board 1: Expected -> 0. Returned: " << check_if_winner(board) << endl;

    board = { {"X", "X", "X", "X" }, {"5", "X", "7", "8"}, {"9", "10", "X", "12"}, {"13", "14", "15", "16"} };
    cout << "board 2: Expected -> 0. Returned: " << check_if_winner(board) << endl;

    board = { {"X", "X", "X", "X" }, {"5", "X", "7", "8"}, {"9", "10", "X", "12"}, {"13", "14", "15", "X"} };
    cout << "board 3: Expected -> 1. Returned: " << check_if_winner(board) << endl;

    board = { {"X", "X", "X", "X" }, {"5", "6", "X", "8"}, {"9", "X", "11", "12"}, {"X", "14", "15", "16"} };
    cout << "board 4: Expected -> 1. Returned: " << check_if_winner(board) << endl;

    board = { {"X", "X", "X", "X" }, {"5", "X", "7", "8"}, {"9", "10", "X", "12"}, {"13", "14", "15", "O"} };
    cout << "board 5: Expected -> 0. Returned: " << check_if_winner(board) << endl;

    board = { {"1", "2", "3", "X" }, {"O", "O", "X", "O"}, {"O", "X", "11", "X"}, {"13", "X", "15", "O"} };
    cout << "board 6: Expected -> 1. Returned: " << check_if_winner(board) << endl;*/


    //    do {
    //        // take input
    //        update_board(board, current_player);
    //
    //        // output board to console
    //        output_board(board);
    //
    //        // check game board
    //        winner = check_if_winner(board);
    //    } while (!winner);
}


int main()
{
    execute_tic_tac_toe();
}



