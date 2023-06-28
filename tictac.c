#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <math.h>


char board[3][3];
const char PLAYER = 'X';
const char COMP = 'O';

void resetBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void drawBoard(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // Draw the Tic Tac Toe board
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    // Draw vertical lines
    SDL_RenderDrawLine(renderer, 200, 0, 200, 600);
    SDL_RenderDrawLine(renderer, 400, 0, 400, 600);

    // Draw horizontal lines
    SDL_RenderDrawLine(renderer, 0, 200, 600, 200);
    SDL_RenderDrawLine(renderer, 0, 400, 600, 400);

    // Draw X and O symbols for each cell based on the board array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int x = j * 200 + 100;
            int y = i * 200 + 100;

            if (board[i][j] == PLAYER) {
                // Draw X symbol
                SDL_RenderDrawLine(renderer, x - 50, y - 50, x + 50, y + 50);
                SDL_RenderDrawLine(renderer, x + 50, y - 50, x - 50, y + 50);
            } else if (board[i][j] == COMP) {
                // Draw O symbol
                int radius = 50;
                int numSegments = 100;
                float angleStep = 2 * 3.14159265358979323846 / numSegments;

                for (int k = 0; k < numSegments; k++) {
                    float angle = k * angleStep;
                    int px = x + radius * cosf(angle);
                    int py = y + radius * sinf(angle);
                    SDL_RenderDrawPoint(renderer, px, py);
                }
            }
        }
    }

    SDL_RenderPresent(renderer);
}
void computerMove() {
    srand(time(0));
    int x;
    int y;

    if (checkFreeSpaces() > 0) {
        do {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');

        board[x][y] = COMP;
    }
}


void handleEvents() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            // Handle quit event (e.g., exit the game)
            return;
        } else if (event.type == SDL_MOUSEBUTTONDOWN) {
            // Handle mouse button down event
            int x = event.button.x;
            int y = event.button.y;

            // Convert mouse position to cell coordinates
            int cellX = x / 200;
            int cellY = y / 200;

            // Check if the selected cell is valid and empty
            if (board[cellY][cellX] == ' ') {
                // Update the board with the player's move
                board[cellY][cellX] = PLAYER;

                // Perform computer's move
                computerMove();
            }
        }
    }
}

int checkFreeSpaces() {
    int freeSpaces = 9;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != ' ') {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}


char checkWinner() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return board[0][0];
    }

    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return board[0][2];
    }

    return ' ';
}

void printWinner(char winner) {
    if (winner == PLAYER) {
        printf("You win!\n");
    } else if (winner == COMP) {
        printf("You lose!\n");
    } else {
        printf("It's a tie!\n");
    }
}

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Tic Tac Toe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    char winner = ' ';
    resetBoard();

    while (winner == ' ' && checkFreeSpaces() != 0) {
        handleEvents();
        drawBoard(renderer);
        winner = checkWinner();
    }

    drawBoard(renderer);
    printWinner(winner);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
