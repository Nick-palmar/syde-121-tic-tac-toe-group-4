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

bool check_if_winner(vector<vector<string>> board);
// PURPOSE: 
//     INPUTS: 
//     OUTPUTS: 


void output_board(vector<vector<string>> board);
// PURPOSE: Outputs the board to console to show occupied and unoccupied positions
//     INPUTS: board - a 2D vector containing all the elements in the board as strings (numbers for empty spaces, X's, O's)
//     OUTPUTS: Nothing; output to console


void update_board(vector<vector<string>>& board, char& current_player);
// PURPOSE: 
//     INPUTS: 
//     OUTPUTS: Nothing


void execute_tic_tac_toe();
// PURPOSE: 


//bool check_if_winner(vector<vector<string>> board) {
//
//}


void update_board(vector<vector<string>>& board, char& current_player) {
    int input = 0;
    bool occupied = false;

    do {

        if (occupied) {
            cout << "Location is occupied." << endl;
        }

        cout << "Player " << current_player << ", enter a location to mark (1-16): ";
        cin >> input;
        
        if (input >= 1 && input <= 16) {
            occupied = true && (board[(input - 1) / board[0].size()][(input - 1) % board[0].size()] == "X" || board[(input - 1) / board[0].size()][(input - 1) % board[0].size()] == "O");
        }
    } while (input < 1 || input > 16 || occupied);

    board[(input - 1) / board[0].size()][(input - 1) % board[0].size()] = current_player;

    if (current_player == 'X') {
        current_player = 'O';
    }
    else {
        current_player = 'X';
    }
}


void output_board(vector<vector<string>> board) {
    // loop through all indicies and output with proper format
    for (int col = 0; col < board.size(); col++) {
        cout << endl;
        for (int row = 0; row < board[col].size(); row++) {
            // add extra space if lenght one
            if (board[col][row].length() == 1)
                cout << board[col][row] << " \t";
            // no extra space if length 2
            else
                cout << board[col][row] << "\t";
        }
    }

    // end line for formatting
    cout << endl;

}


void execute_tic_tac_toe() {
    // initialize and declare variables
    vector<vector<string>> board = { {"1", "2", "3", "4"}, {"5", "6", "7", "8"}, {"9", "10", "11", "12"}, {"13", "14", "15", "16"} };
    char starting_player = 'X';
    char current_player = 'X';
    bool winner = false;

    while (true) {
        output_board(board);
        update_board(board, current_player);
    }

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


