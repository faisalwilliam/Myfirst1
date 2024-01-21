
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;
class TicTacToe {
private:
	std::vector<std::vector<char>> board; // 2D vector representing the game board
	char playerSymbol;  // Symbol for the player ('X' or 'O')
	char computerSymbol; // Symbol for the computer opponent
	int boardSize;  // Size of the board (NxN grid)
	int winCondition; // Number of symbols in a row needed to win
	// Check for a win condition (horizontal, vertical, diagonal)
	bool checkWin(char symbol) {
		int diagonal1 = 0, diagonal2 = 0;
		for (int i = 0; i < boardSize; ++i) {
			// Counters for the number of symbols in each row and column
			int horizontal = 0, vertical = 0;
			// Check diagonals
			if (board[i][i] == symbol) diagonal1++;
			if (board[i][boardSize - i - 1] == symbol) diagonal2++;
			for (int j = 0; j < boardSize; ++j) {
				// Count symbols in rows and columns
				if (board[i][j] == symbol) horizontal++;
				if (board[j][i] == symbol) vertical++;
			}
			// Check if the current row or column has a winning condition
			if (horizontal == winCondition || vertical == winCondition) return true;
		}
		// Check diagonals for win condition
		return diagonal1 == winCondition || diagonal2 == winCondition;
	}
	// Check if the board is full
	bool isBoardFull() {
		for (auto& row : board) {
			for (auto cell : row) {
				// If any cell is empty, the board isn't full
				if (cell == '-') return false;
			}
		}
		return true;
	}
	// Get player's move from input
	std::pair<int, int> getPlayerMove() {
		int x, y;
		do {
			std::cout << "Enter row and column (0 based index): ";
			std::cin >> x >> y;  // Keep asking until a valid move is entered
		} while (x < 0 || x >= boardSize || y < 0 || y >= boardSize || board[x][y] != '-');
		return std::make_pair(x, y);
	}
	// Calculate the computer's move randomly
	void makeComputerMove() {
		std::pair<int, int> move;
		do {
			// Generate random positions until an empty spot is found
			move.first = rand() % boardSize;
			move.second = rand() % boardSize;
		} while (board[move.first][move.second] != '-');
		board[move.first][move.second] = computerSymbol;
	}
	// Print the current state of the board
	void printBoard() {
		for (auto& row : board) {
			for (auto cell : row) {
				std::cout << cell << ' ';
			}
			std::cout << '\n';
		}
	}
public:
	// Constructor to initialize the game
	TicTacToe(int size, int winConditionLength) {
		boardSize = size;
		winCondition = winConditionLength;
		board = std::vector<std::vector<char>>(boardSize, std::vector<char>(boardSize, '-'));
		playerSymbol = 'X'; // Default value
		computerSymbol = 'O'; // Default value
	}
	// Set player's symbol and adjust computer's accordingly
	void setPlayerSymbol(char symbol) {
		playerSymbol = symbol;
		computerSymbol = (symbol == 'X') ? 'O' : 'X';
	}
	// Main game loop
	void playGame() {
		bool playerTurn = true;
		bool won = false;
		while (!isBoardFull() && !won) {
			printBoard();
			if (playerTurn) {
				// Player's move
				std::cout << "Player's Turn!\n";
				std::pair<int, int> playerMove = getPlayerMove();
				board[playerMove.first][playerMove.second] = playerSymbol;
				won = checkWin(playerSymbol);
			}
			else {
				// Computer's move
				std::cout << "Computer's Turn!\n";
				makeComputerMove();
				won = checkWin(computerSymbol);
			}
			// Switch turns
			playerTurn = !playerTurn;
		}
		// Print final state of the board and the result
		printBoard();
		if (won) {
			std::cout << ((playerTurn) ? "Computer" : "Player") << " Wins!\n";
		}
		else {
			std::cout << "It's a Tie!\n";
		}
	}
};
int main() {
	srand(time(nullptr)); // Seed for random number generator (used in computer's move)
	// Variables to store user input for game settings
	int boardSize, winLength;
	char symbolChoice;
	// Gather user input
	std::cout << "Select board size: ";
	std::cin >> boardSize;
	std::cout << "Select win condition length: ";
	std::cin >> winLength;
	std::cout << "Choose your symbol (X/O): ";
	std::cin >> symbolChoice;
	// Initialize and play the game
	TicTacToe game(boardSize, winLength);
	game.setPlayerSymbol(symbolChoice);
	game.playGame();
	return 0;
}