//***********************************************************
// Student Names: Nicolas Palmar and Kevin Wang
// Student Number: 
//
// SYDE 121 Lab: Home Assignment: 4, question 1
// Filename: a4_q1
// We hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts.  This coded solution has
// not been plagiarized from other sources and has not been knowingly
// plagiarized by others
//
// Project: Tic Tac Toe
// Purpose: Play tic tac toe with another person
// Due Date: Friday, November 6, 2020
//**************************************************************

/*
1. Test Cases

Vertical, horizontal and diagonal tests
------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------
// vertical tic tac toe test cases
board = { {"X", "X", "X", "X" }, {"5", "6", "7", "8"}, {"9", "10", "11", "12"}, {"13", "14", "15", "16"} };
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
cout << "board 6: Expected -> 1. Returned: " << check_if_winner(board) << endl;
-------------------------------------------------------------------------------------------------------------
// horizontal tic tac toe test cases
board = { {"X", "2", "3", "4" }, {"X", "6", "7", "8"}, {"X", "10", "11", "12"}, {"X", "14", "15", "16"} };
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
cout << "board 6: Expected -> 1. Returned: " << check_if_winner(board) << endl;
-------------------------------------------------------------------------------------------------------------
// diagonal tic tac toe test cases
board = { {"X", "X", "X", "X" }, {"5", "6", "7", "8"}, {"9", "10", "11", "12"}, {"13", "14", "15", "16"} };
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
cout << "board 6: Expected -> 1. Returned: " << check_if_winner(board) << endl;
-------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------

Input Validation
-------------------------------------------------------------------------------------------------------------
Test #1: Test an input of 0 when asked for a loction (under 1; should not accept) -> rejects the input, works. 
Test #2: Test an input of -200 when asked for a loction (under 1; should not accept) -> rejects the input, Works.
Test #3: Test 17 when asked for a location (over 16; should not accept) -> rejects the input, Works.
Test #4: Test 100 when asked for a location (over 16; should not accept) -> rejects the input, Works. 
Test #5: Test the numbers 1 and 16 (to ensure that these boundary cases are accepted) -> works.
Test #6: Now, test occupied locations and check the that program will not accept these entries -> rejects the input, works.

Test #7: Test a -1 when asked to play again (1 is to play again, 0 is to quit) -> rejects the input, works. 
Test #8: Test a 2 when asked to play again (1 is to play again, 0 is to quit) -> rejects the input, works.
-------------------------------------------------------------------------------------------------------------

Real Game Test Cases
-------------------------------------------------------------------------------------------------------------
Test #1: Test a horizontal tic tac toe for player X in row 1 -> Works, says that player X wins. 
Test #2: Test a vertical tic tac toe for player X in column 1-> Works, says that player X wins.
Test #3: Test a diagonal tic tac toe for player X -> Works, says that player X wins.
Test #4: Test the other diagonal tic tac toe for player X -> Works, says that player X wins.

Test #4: Test a horizontal tic tac toe for player O in row 4-> Works, says that player O wins.
Test #5: Test a vertical tic tac toe for player O in column 4-> Works, says that player O wins.
Test #7: Test a diagonal tic tac toe for player O -> Works, says that player O wins.
Test #8: Test the other diagonal tic tac toe for player O -> Works, says that player O wins. 

Test #9: Test a tie game scenario -> Works, says that there was a tie game.

After running the game for a total of 8 tries with results: 3 wins for X, 4 wins for O, 1 tie, check if the output is correct.
Output: 
Player X has won 3 times!
Player O has won 4 times!
There has been a tie 1 time!
Works.

Also, after running the game multiple times, it was checked if the starting player alternates in successive games -> works. 
-------------------------------------------------------------------------------------------------------------

2. Limitations of simulation
-------------------------------------------------------------------------------------------------------------
As a computer game, this simulation is limited by the fact that it requires 2 players. Many computer games have both single player and double player mode,
however this simulation does not have a single player mode since there is no computer player programmed. This would be a limitaiton.

Another limitation would be limitation in user input. The user input as a string is not being checked, so there will be an error if the user enters a string or
a character that is not an integer. 
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// declare indicies for score variables and board boundary values as constants
const int PLAYER_X = 0, PLAYER_O = 1, TIE = 2, MIN_VAL = 1, MAX_VAL = 16;

void output_victories(int score[]);
// PURPOSE: Outputs the number of victories and ties for both players
//     INPUTS: score - a c-style array of length 3 containing the number of times each player has won as well as the number of ties
//     OUTPUTS: nothing; outputs to console


bool check_diagonal(vector<vector<string>> board, int col, int row);
// PURPOSE: Check using loops if there is a diagonal tic tac toe situation occuring
//     INPUTS: board - a 2D vector containing all the elements in the board as strings (numbers for empty spaces, X's, O's)
//             col - an integer value corresponding to the current column being checks
//             row - an integer value corresponding to the current row being checks
//     OUTPUTS: A boolean value; true if there is a tic tac toe diagonally otherwise false


bool check_vertical(vector<vector<string>> board, int col, int row);
// PURPOSE: Check recursively if there is a vertical tic tac toe situation occuring
//     INPUTS: board - a 2D vector containing all the elements in the board as strings (numbers for empty spaces, X's, O's)
//             col - an integer value corresponding to the current column being checks
//             row - an integer value corresponding to the current row being checks
//     OUTPUTS: A boolean value; true if there is a tic tac toe vertically otherwise false


bool check_horizontal(vector<vector<string>> board, int col, int row);
// PURPOSE: Check recursively if there is a horizontal tic tac toe situation occuring
//     INPUTS: board - a 2D vector containing all the elements in the board as strings (numbers for empty spaces, X's, O's)
//             col - an integer value corresponding to the current column being checks
//             row - an integer value corresponding to the current row being checks
//     OUTPUTS: A boolean value; true if there is a tic tac toe horizontally otherwise false


bool check_if_winner(vector<vector<string>> board);
// PURPOSE: Check if someone has won the game by doing vertical, horizontal, and diagonal board checks
//     INPUTS: board - a 2D vector containing all the elements in the board as strings (numbers for empty spaces, X's, O's)
//     OUTPUTS: A boolean value; true if there is a winner meaning a tic tac toe diagonally, vertically, or horizontally otherwise false


void update_board(vector<vector<string>>& board, char& current_player, char& other_player);
// PURPOSE: Asks the user to input a location, inserts an X or O based on the turn if that location exists or is not occupied, and then switches the turn
//     INPUTS: board - a 2D vector containing all the elements in the board as strings (numbers for empty spaces, X's, O's)
//            current_player - an X or O character corresponding to the user whose turn it is
//            other_player - an X or O character corresponding to the user whose turn is next
//     OUTPUTS: Nothing


void output_board(vector<vector<string>> board);
// PURPOSE: Outputs the board to console to show occupied and unoccupied positions
//     INPUTS: board - a 2D vector containing all the elements in the board as strings (numbers for empty spaces, X's, O's)
//     OUTPUTS: Nothing; output to console


bool check_if_play_again();
// PURPOSE: Checks if the user wants to play again
//     INPUTS: Nothing
//     OUTPUTS: A boolean value; true if the user enters 1 to repeat the game, false if the user enters 0 to quit the game


void execute_tic_tac_toe();
// PURPOSE: Execute the main tic tac toe program for player X and O on a 4x4 grid


bool check_diagonal(vector<vector<string>> board, int col, int row) {
    // check if the space 1 row down and 1 column to the right is a match starting from the top left corner
    while (board[row][col] == board[row + 1][col + 1] && row < board.size() && col < board.size()) {
        // if the second last row satisfies the check, this is a diagonal tic tac toe
        if (row == board.size() - 2) {
            return true;
        }
        row++;
        col++;
    }
    row = 0;
    col = 3;
    // check if the space 1 row down and 1 column to the left is a match starting from the top right corner
    while (board[row][col] == board[row + 1][col - 1] && row < board.size() && col >= 0) {
        // if the second last row satisfies the check, this is a diagonal tic tac toe
        if (row == board.size() - 2) {
            return true;
        }
        row++;
        col--;
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
        return check_horizontal(board, 0, ++row);

    // next space to the right is a match, move to the right and continue check
    return check_horizontal(board, ++col, row);
}


bool check_if_winner(vector<vector<string>> board) {
    // declare variables
    bool horizontal, vertical, diagonal;

    // call functions to do the checks
    horizontal = check_horizontal(board, 0, 0);
    vertical = check_vertical(board, 0, 0);
    diagonal = check_diagonal(board, 0, 0);

    // return if there is a winner
    return (vertical || horizontal || diagonal);
}


void update_board(vector<vector<string>>& board, char& current_player, char& other_player) {
    int input = 0;
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


void output_victories(int score[]) {
    // output the scores to the console
    cout << "\nPlayer X has won " << score[PLAYER_X] << (score[PLAYER_X] == 1 ? " time!" : " times!") << endl;
    cout << "Player O has won " << score[PLAYER_O] << (score[PLAYER_O] == 1 ? " time!" : " times!") << endl;
    cout << "There has been a tie " << score[TIE] << (score[TIE] == 1 ? " time!" : " times!") << endl;
}


void execute_tic_tac_toe() {
    // initialize and declare variables
    char starting_player = 'X';
    char current_player, other_player;
    bool play_again = false;
    int score[3] = { 0 };

    // loop until the users do not want to play again
    do {
        // initialize or reset game variables
        int turns = 0;
        vector<vector<string>> board = { {"1", "2", "3", "4"}, {"5", "6", "7", "8"}, {"9", "10", "11", "12"}, {"13", "14", "15", "16"} };
        bool winner = false, tie = false;

        // sets the current and other player based on the starting player
        current_player = starting_player;
        
        if (current_player == 'X') 
            other_player = 'O';
        else 
            other_player = 'X';
       

        // main game loop
        do {
            // output board to console
            output_board(board);

            // take input and update the game board
            update_board(board, current_player, other_player);
            turns++;

            // process the board and check if a player has won vertically, horizontally, or diagonally
            winner = check_if_winner(board);

            // output message to console if someone wins
            if (winner) {
                output_board(board);
                cout << "\nPlayer " << other_player << " has won!" << endl;

                // update score
                if (other_player == 'X')
                    score[PLAYER_X]++;
                else
                    score[PLAYER_O]++;
            }
            // check if there is a tie
            else if (turns >= MAX_VAL) {
                // update score
                tie = true;
                score[TIE]++;

                // output tie message to console
                output_board(board);
                cout << "\nPlayers have tied!" << endl;
            }
        } while (!winner && !tie);

        // get user input to check if they would like to continue
        play_again = check_if_play_again();

        // if the game continues, the starting player switches
        if (play_again && starting_player == 'X') 
            starting_player = 'O';
        else if (play_again && starting_player == 'O') 
            starting_player = 'X';
    } while (play_again);

    // game has ended, print out victories
    output_victories(score);
}


int main()
{
    execute_tic_tac_toe();
}



