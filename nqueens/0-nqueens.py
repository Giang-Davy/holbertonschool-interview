a#!/usr/bin/python3


import sys


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


def is_safe(board, row, col):
    # Vérifie la colonne
    for i in range(row):
        if board[i] == col or \
           board[i] - i == col - row or \
           board[i] + i == col + row:
            return False
    return True


def solve_nqueens(N, board, row):
    if row == N:
        print([[i, board[i]] for i in range(N)])
        return

    for col in range(N):
        if is_safe(board, row, col):
            board[row] = col
            solve_nqueens(N, board, row + 1)
            board[row] = -1


def nqueens(N):
    board = [-1] * N
    solve_nqueens(N, board, 0)


nqueens(N)
