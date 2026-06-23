#include <stdio.h>

int main() {
    char board[9] = {'1','2','3','4','5','6','7','8','9'};
    int player = 1, choice;
    char mark;

    for(int i = 0; i < 9; i++) {

        printf("\n");
        printf(" %c | %c | %c\n", board[0], board[1], board[2]);
        printf("---|---|---\n");
        printf(" %c | %c | %c\n", board[3], board[4], board[5]);
        printf("---|---|---\n");
        printf(" %c | %c | %c\n\n", board[6], board[7], board[8]);

        if(player == 1) {
            mark = 'X';
        } else {
            mark = 'O';
        }

        printf("Player %d, enter position: ", player);
        scanf("%d", &choice);

        if(board[choice-1] == 'X' || board[choice-1] == 'O') {
            printf("Invalid move! Try again.\n");
            i--;
            continue;
        }

        board[choice-1] = mark;

        // Win check
        if(
            (board[0]==board[1] && board[1]==board[2]) ||
            (board[3]==board[4] && board[4]==board[5]) ||
            (board[6]==board[7] && board[7]==board[8]) ||
            (board[0]==board[3] && board[3]==board[6]) ||
            (board[1]==board[4] && board[4]==board[7]) ||
            (board[2]==board[5] && board[5]==board[8]) ||
            (board[0]==board[4] && board[4]==board[8]) ||
            (board[2]==board[4] && board[4]==board[6])
        ) {
            printf("\n Player %d wins!\n", player);
            return 0;
        }

        // Switch player
        if(player == 1)
            player = 2;
        else
            player = 1;
    }

    printf("\nIt's a draw!\n");
    return 0;
}
