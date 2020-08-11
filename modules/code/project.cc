/*
 * file: project.cc
 * author: Michael Brockus
 * gmail: <michaelbrockus@gmail.com>
 */
#include "project.h"

// All possible winning states
std::vector<std::vector<std::pair<int, int>>> winningStates
{
    // Every row
    { std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(0, 2) },
    { std::make_pair(1, 0), std::make_pair(1, 1), std::make_pair(1, 2) },
    { std::make_pair(2, 0), std::make_pair(2, 1), std::make_pair(2, 2) },

    // Every column
    { std::make_pair(0, 0), std::make_pair(1, 0), std::make_pair(2, 0) },
    { std::make_pair(0, 1), std::make_pair(1, 1), std::make_pair(2, 1) },
    { std::make_pair(0, 2), std::make_pair(1, 2), std::make_pair(2, 2) },

    // Every diagonal
    { std::make_pair(0, 0), std::make_pair(1, 1), std::make_pair(2, 2) },
    { std::make_pair(2, 0), std::make_pair(1, 1), std::make_pair(0, 2) }
};

//
// Get all available legal moves (spaces that are not occupied)
//
std::vector<std::pair<int, int>> getLegalMoves(char board[3][3])
{
    std::vector<std::pair<int, int>> legalMoves;
    for (int index = 0; index < 3; ++index)
    {
        for (int subIndex = 0; subIndex < 3; ++subIndex)
        {
            if (board[index][subIndex] != AI_MARKER && board[index][subIndex] != PLAYER_MARKER)
            {
                legalMoves.push_back(std::make_pair(index, subIndex));
            } // end if
        } // end for
    } // end for

    return legalMoves;
} // end of function getLegalMoves

//
// Check if a position is occupied
//
bool positionOccupied(char board[3][3], std::pair<int, int> pos)
{
    std::vector<std::pair<int, int>> legalMoves = getLegalMoves(board);

    for (auto index = 0; index < legalMoves.size(); ++index)
    {
        if (pos.first == legalMoves[index].first && pos.second == legalMoves[index].second)
        {
            return false;
        } // end if
    } // end for

    return true;
} // end of function positionOccupied

//
// Get all board positions occupied by the given marker
//
std::vector<std::pair<int, int>> getOccupiedPositions(char board[3][3], char marker)
{
    std::vector<std::pair<int, int>> occupiedPositions;

    for (auto index = 0; index < 3; ++index)
    {
        for (int subIndex = 0; subIndex < 3; ++subIndex)
        {
            if (marker == board[index][subIndex])
            {
                occupiedPositions.push_back(std::make_pair(index, subIndex));
            } // end if
        } // end for
    } // end for

    return occupiedPositions;
} // end of function getOccupiedPositions

//
// Check if the board is full
//
bool boardIsFull(char board[3][3])
{
    std::vector<std::pair<int, int>> legal_moves = getLegalMoves(board);

    if (0 == legal_moves.size())
    {
        return true;
    } // end if
    else
    {
        return false;
    } // end else
} // end of function boardIsFull

//
// Check if the game has been won
//
bool gameIsWon(std::vector<std::pair<int, int>> occupiedPositions)
{
    bool game_won;

    for (int i = 0; i < winningStates.size(); i++)
    {
        game_won = true;
        std::vector<std::pair<int, int>> curr_win_state = winningStates[i];
        for (int j = 0; j < 3; j++)
        {
            if (!(std::find(std::begin(occupiedPositions),
                std::end(occupiedPositions), curr_win_state[j]) != std::end(occupiedPositions)))
            {
                game_won = false;
                break;
            } // end if
        } // end for

        if (game_won)
        {
            break;
        } // end if
    } // end for
    return game_won;
} // end of function gameIsWon

//
// get the opponent marker char
//
char getOpponentMarker(char marker)
{
    char opponentMarker;
    if (marker == PLAYER_MARKER)
    {
        opponentMarker = AI_MARKER;
    } // end if
    else
    {
        opponentMarker = PLAYER_MARKER;
    } // end else

    return opponentMarker;
} // end of function getOpponentMarker

//
// Check if someone has won or lost
//
int getBoardState(char board[3][3], char marker)
{

    char opponentMarker = getOpponentMarker(marker);

    std::vector<std::pair<int, int>> occupiedPositions = getOccupiedPositions(board, marker);

    if (gameIsWon(occupiedPositions))
    {
        return static_cast<int>(State::WIN);
    } // end if

    occupiedPositions = getOccupiedPositions(board, opponentMarker);

    if (gameIsWon(occupiedPositions))
    {
        return static_cast<int>(State::LOSS);
    } // end if

    if (boardIsFull(board))
    {
        return static_cast<int>(State::DRAW);
    } // end if

    return static_cast<int>(State::DRAW);
} // end of function getBoardState

//
// Apply the minimax game optimization algorithm
//
std::pair<int, std::pair<int, int>> minimaxOptimization(char board[3][3], char marker, int depth, int alpha, int beta)
{
    // Initialize best move
    std::pair<int, int> bestMove = std::make_pair(-1, -1);
    int bestScore = (marker == AI_MARKER) ? static_cast<char>(State::LOSS) : static_cast<char>(State::WIN);

    // If we hit a terminal state (leaf node), return the best score and move
    if (boardIsFull(board) || static_cast<int>(State::DRAW) != getBoardState(board, AI_MARKER))
    {
        bestScore = getBoardState(board, AI_MARKER);
        return std::make_pair(bestScore, bestMove);
    } // end if

    std::vector<std::pair<int, int>> legalMoves = getLegalMoves(board);

    for (int index = 0; index < legalMoves.size(); ++index)
    {
        std::pair<int, int> currMove = legalMoves[index];
        board[currMove.first][currMove.second] = marker;

        // Maximizing player's turn
        if (marker == AI_MARKER)
        {
            int score = minimaxOptimization(board, PLAYER_MARKER, depth + 1, alpha, beta).first;

            // Get the best scoring move
            if (bestScore < score)
            {
                bestScore = score - depth * 10;
                bestMove = currMove;

                // Check if this branch's best move is worse than the best
                // option of a previously search branch. If it is, skip it
                alpha = std::max(alpha, bestScore);
                board[currMove.first][currMove.second] = EMPTY_SPACE;
                if (beta <= alpha)
                {
                    break;
                }  // end if
            }  // end if

        }  // end if 
        else // Minimizing opponent's turn
        {
            int score = minimaxOptimization(board, AI_MARKER, depth + 1, alpha, beta).first;

            if (bestScore > score)
            {
                bestScore = score + depth * 10;
                bestMove = currMove;

                // Check if this branch's best move is worse than the best
                // option of a previously search branch. If it is, skip it
                beta = std::min(beta, bestScore);
                board[currMove.first][currMove.second] = EMPTY_SPACE;
                if (beta <= alpha)
                {
                    break;
                } // end if
            } // end if
        } // end else

        board[currMove.first][currMove.second] = EMPTY_SPACE; // Undo move
    } // end for
    return std::make_pair(bestScore, bestMove);
} // end of function minimaxOptimization

//
// Check if the game is finished
//
const bool gameIsDone(char board[3][3])
{
    if (boardIsFull(board))
    {
        return true;
    } // end if

    if (static_cast<int>(State::DRAW) != getBoardState(board, AI_MARKER))
    {
        return true;
    } // end if

    return false;
}

//
// game main execution logic starts here
//
void mainExecution()
{
    char board[3][3] = { { EMPTY_SPACE } };
    std::cout << "********************************\n\n\tTic Tac Toe Dodo\n\n********************************" << std::endl << std::endl;
    std::cout << "Player = X\t Dodo = O" << std::endl << std::endl;

    while (!gameIsDone(board))
    {
        int row, col;
        std::cout << "Row play: ";
        std::cin >> row;
        std::cout << "Col play: ";
        std::cin >> col;
        std::cout << std::endl << std::endl;

        if (positionOccupied(board, std::make_pair(row, col)))
        {
            std::cout << "The position (" << row << ", " << col << ") is occupied. Try another one..." << std::endl;
            continue;
        } // end if
        else
        {
            board[row][col] = PLAYER_MARKER;
        } // end else

        std::pair<int, std::pair<int, int>> aiMove = minimaxOptimization(board, AI_MARKER, START_DEPTH,
            static_cast<int>(State::LOSS), static_cast<int>(State::WIN));

        board[aiMove.second.first][aiMove.second.second] = AI_MARKER;

        printPoard(board);
    } // end while

    std::cout << "********** GAME OVER **********" << std::endl << std::endl;
    int playerState = getBoardState(board, PLAYER_MARKER);
    std::cout << "PLAYER "; printGameState(playerState);
} // end of function mainExecution
