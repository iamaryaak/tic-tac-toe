#include <iostream>
#include <string>
using namespace std;

bool checkWin(char *board){
    bool res = false;
    for(int i = 0; i < 1; i++){
        for(int j = 0; j < 1; j++){
            // check pairs
             if(board[i][j] == 1){
                // check for 2nd
                if(board[i+1][j] == '1' && board[i+2][j] == '1'){
                    res = true;
                }else if(board[i][j+1] == '1' && board[i][j+2] == '1'){
                    res = true;
                }else if(board[i+1][j+1] == '1' && board[i+2][j+2] == '1'){
                    res = true;
                }
             }
        }
    }

    return res;
}

int main(){

    // create 3x3 array - game board
    // 1 = X
    // 2 = O
    int board[3][3] = {{},{},{}};
    int size_r = 3;
    int size_c = 3;

    // print the board
    cout << "Board:" << endl;
    int n = sizeof(board)/sizeof(board[0]);
    // loop through the array elements
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    // while the board is not filled up (draws are allowed)
    bool filled = false;
    while(!filled){
        // check filled
        for(int i = 0; i < size_r; i++){
            for(int j = 0; j < size_c; j++){
                if(board[i] == 0){
                    break;
                }
            }
        }


        if(filled){
            cout << "Board is filled up.\n";
            break;
        }
        cout << "Continue Game...\n";
        // TODO: add restraints
        // get user inputs
        string user_x;
        string user_y;
        string user_input;
        cout << "Choose a row: ";
        getline(cin, user_x);
        cout << "Choose a col: ";
        getline(cin, user_y);
        string user_choice = user_x + ", " + user_y + "\n";
        // User will be 'X' = 1
        cout << "\nUser Chose: \n";
        cout << user_choice;

        board[stoi(user_x)-1][stoi(user_y)-1] = 1;
        checkWin(board);


        // for now add random for bot
        int bot_x = 0;
        int bot_y = 0;
        do{
            // range of 0 and 
            bot_x = rand() % (3);
            bot_y = rand() % (3); 
        }while(board[bot_x][bot_y] == 1);

        cout << bot_x << bot_y << endl;
        board[bot_x][bot_y] = 2;

        // print the board
        cout << "Board:" << endl;
        int n = sizeof(board)/sizeof(board[0]);
        // loop through the array elements
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        checkWin(board);

    }

    return 0;
}