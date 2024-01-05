#!/usr/bin/python3

import sys

def print_solution(board):
    for row in board:
        print(" ".join(row))

def is_safe(board, row, column, n):
    # Check if there is a queen in the same column
    for i in range(row):
        if board[i][col] == 'Q':
            return False

    # Check upper left diagonal
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 'Q':
            return False

    # Check upper right diagonal
    for i, j in zip(range(row, -1, -1), range(col, n)):
        if board[i][j] == 'Q':
            return False

    return True

def solve_nqueens(n):
    board = [['.' for _ in range(n)] for _ in range(n)]
    solutions = []

    def backtrack(row):
        nonlocal solutions
        if row == n:
            solutions.append(["".join(row) for row in board])
            return

        for col in range(n):
            if is_safe(board, row, col, n):
                board[row][col] = 'Q'
                backtrack(row + 1)
                board[row][col] = '.'

    backtrack(0)

    return solutions

def main():
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    solutions = solve_nqueens(N)

    for solution in solutions:
        print_solution(solution)
        print()

if __name__ == "__main__":
    main()
