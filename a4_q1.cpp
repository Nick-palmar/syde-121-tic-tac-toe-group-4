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
// PURPOSE: 
//     INPUTS: 
//     OUTPUTS: Nothing


void update_board(vector<vector<string>>& board, char& current_player);
// PURPOSE: 
//     INPUTS: 
//     OUTPUTS: Nothing


void execute_tic_tac_toe();
// PURPOSE: 


bool check_if_winner(vector<vector<string>> board) {

}


void update_board(vector<vector<string>>& board, char& current_player) {

}


void output_board(vector<vector<string>> board) {

}


void execute_tic_tac_toe() {
    // initialize and declare variables
    vector<vector<string>> board = { {"1", "2", "3", "4"}, {"5", "6", "7", "8"}, {"9", "10", "11", "12"}, {"13", "14", "15", "16"} };
    char starting_player = 'X';
    char current_player = 'X';
    bool winner = false;

    do {
        // take input
        update_board(board, current_player);

        // output board to console
        output_board(board);

        // check game board
        winner = check_if_winner(board);
    } while (!winner);
}


int main()
{
    execute_tic_tac_toe();
}


