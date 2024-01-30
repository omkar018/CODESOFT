#include<iostream>
using namespace std;

void display(char tictac[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            cout << tictac[i][j] << "  ";
        cout << "\n";
    }
    cout << "\n";
}


int fixMove(int pos, char tictac[3][3],char move)
{
    int row = (pos - 1)/3;
    int col = (pos - 1)%3;

    if(tictac[row][col]!='X' && tictac[row][col]!='O')
    {
        tictac[row][col] = move;
        return 1;
    }

    else
        return 0;
}

void switchPlayer(char &CurrenPlayer)
{
    if(CurrenPlayer == 'X')
        CurrenPlayer = 'O';
    else
        CurrenPlayer = 'X';
}


int checkWin(char tictac[3][3])
{
    for(int i=0;i<3;i++)
    {
        if((tictac[i][0] == tictac[i][1]) &&  (tictac[i][1] == tictac[i][2]))
            return 1;

        if((tictac[0][i] == tictac[1][i]) &&  (tictac[1][i] == tictac[2][i]))
            return 1;
    }

        if (tictac[0][0] == tictac[1][1] && tictac[1][1] == tictac[2][2]) 
            return 1;

        if (tictac[0][2] == tictac[1][1] && tictac[1][1] == tictac[2][0]) 
            return 1;

    return 0;
}


int checkDraw(char tictac[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(tictac[i][j]!='X' && tictac[i][j]!='O')
                return 0;
        }
    }
    return 1;
}


int main()
{
    char tictac[3][3] = 
    {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };

    char currentPlayer = 'X';
    cout << "\n         TIC-TAC-TOE :\n\nEnter your moves from available slots(1-9):\n";
    while(1)
    {
        display(tictac);

        int opt;
        cout << "\nPlayer " << currentPlayer << "'s turn :";
        cin >> opt;

        if(fixMove(opt,tictac,currentPlayer)==0)
        {
            cout << "\nYour Move is invalid.. try and select the remaining options only";
            continue;
        }

        if(checkWin(tictac))
        {
            display(tictac);
            cout << "\n\nEnd of the game !! & the winner is ..... player :" << currentPlayer; 
            break;
        }

        else
        {
            if(checkDraw(tictac))
            {
                display(tictac);
                cout << "\n\nThe game ends in a draw !!! ";
                break;
            }
            else
                switchPlayer(currentPlayer);
        }
    }

    int ip;
    cout << "\n\nLet's have another game :\n Press 1 if YES\nPress 0 if NO\nChoice:";
    cin >> ip;
    if(ip == 1)
        main();
    else
        return 0;
}