#include <stdio.h>
char board[9]={' ',' ',' ',' ',' ',' ',' ',' ',' ',};
char vincitore=' ';
char board_vincente(char board[]) {
    if(board[0]==board[1]&&board[1]==board[2])
        if(board[0]!=' ') return board[0];
    if(board[3]==board[4]&&board[4]==board[5])
        if(board[3]!=' ') return board[3];
    if(board[6]==board[7]&&board[7]==board[8])
        if(board[6]!=' ') return board[6];
    if(board[0]==board[3]&&board[3]==board[6])
        if(board[0]!=' ') return board[0];
    if(board[1]==board[4]&&board[4]==board[7])
        if(board[1]!=' ') return board[1];
    if(board[3]==board[5]&&board[5]==board[8])
        if(board[3]!=' ') return board[3];
    if(board[0]==board[4]&&board[4]==board[8])
        if(board[0]!=' ') return board[0];
    if(board[2]==board[4]&&board[4]==board[6])
        if(board[2]!=' ') return board[2];
    return ' ';
}





void print_board(char board[]) {
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[0], board[1], board[2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", board[3], board[4], board[5]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", board[6], board[7], board[8]);

    printf("     |     |     \n\n");
}


void reset_board(char* board) {
    /*
     * PRE: board ha dimensione BOARD_SIZE
     * POST per ogni i tale che 0<=i<BOARD_SIZE si ha board[i]=CASELLA_VUOTA
     */
    for(int i=0; i<9; i+=1)
        *(board+i) = ' ';
}

int main()
{
    char Turno;
    int casella;
    printf("selezionare chi inizia x oppure o\n");
    scanf("%c",&Turno);
    
    while(vincitore!='x'&&vincitore!='o'){
        print_board(board);
        printf("Selezionare la casella, Turno %c\n",Turno);
        scanf("%d",&casella);
        *(board+casella-1)=Turno;
        
        vincitore=board_vincente(board);
        if(Turno=='x')
            Turno='o';
        else
            Turno='x';
    }
    printf("Vincitore: %c",vincitore);
}