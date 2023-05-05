// definition module
#include <iostream>
#include "dec.h"

std::string board[9] = {
    " ", " ", " ",
    " ", " ", " ",
    " ", " ", " "
};

unsigned player = 1;
unsigned position = 0; // 0-9

void draw_board(){
    std::cout << "   "<< board[0] << "  |  " << board[1] << "  |  " << board[2] << '\n'; 
    std::cout << " _____|_____|_____ \n"; 
    std::cout << "      |     |      \n"; 
    std::cout << "   "<< board[3] << "  |  " << board[4] << "  |  " << board[5] << '\n';
    std::cout << " _____|_____|_____ \n"; 
    std::cout << "      |     |      \n"; 
    std::cout << "   "<< board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n\n";
}

void introduction(){
    std::cout << "Press [Enter] to begin: ";
    getchar();
    std::cout << "\n***************\n";
    std::cout << "Tic-Tac-Toe\n";
    std::cout << "***************\n";

    std::cout << "Player 1) X\n";
    std::cout << "Player 2) 0\n";

    std::cout << "The 3x3 grid is show below:\n\n";
    draw_board(); 
}

bool is_winner(){
    //checking the rows
    if(board[0]!=" " &&(board[0]==board[1])&&(board[0]==board[2])) return true;       
    if(board[3]!=" " &&(board[3]==board[4])&&(board[3]==board[5])) return true;       
    if(board[6]!=" " &&(board[6]==board[7])&&(board[6]==board[8])) return true;       
    //checking the columns
    if(board[0]!=" " &&(board[0]==board[3])&&(board[0]==board[6])) return true;
    if(board[1]!=" " &&(board[1]==board[4])&&(board[1]==board[7])) return true;
    if(board[2]!=" " &&(board[2]==board[5])&&(board[2]==board[8])) return true;
    //checking the diagonals
    if(board[0]!=" " &&(board[0]==board[4])&&(board[0]==board[8])) return true;
    if(board[2]!=" " &&(board[2]==board[4])&&(board[2]==board[6])) return true;
    return false;
}

void set_position(){
    std::cout << "Player " << player << "'s enter num in range (1-9): ";
    while(!(std::cin >> position)){
        std::cout << "Please enter a valid number beetwen (1-9): " << std::endl;
        std::cin.clear();
        std::cin.ignore();
    }
    while(board[position - 1] != " "){
        std::cout << "Oops, enter another number, that position is allready filled.\n";
        std::cout << "Player " << player << "'s turn, enter num in range (1-9)";
        std::cin >> position;
        std::cout << '\n';
    }
}

void set_char(){
    board[position - 1] = (player % 2 == 1) ? "X" : "O"; 
}

void change_player(){
    player = (player == 1) ? 2 : 1;   
}

bool filled_up(){
    for(auto square : board){
        if(square == " ") return false;
    }
    return true;
}

void take_turn(){
    while(!filled_up() && !is_winner()){
        set_position();
        set_char();
        draw_board();
        change_player();
    }
    game();
}

void game(){
    if(is_winner()){
        change_player();
        std::cout << "Player " << player << " is winner.";
    } else if(filled_up()){
        std::cout << "Its a draw.";
    } else{
        take_turn();
    }
}
