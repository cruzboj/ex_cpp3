#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(const char* name) : Player(name){}

void HumanPlayer::placeAllShips()
{
    for (int i = 0; i < MaxShips; i++)
    {
        cout << "Ship:" << i + 1<< " Size: " << getShip(i)->getSize() << endl;
        int row = 0, col = 0;
        bool horizontal = 0;
        cout << "Row:";
        cin >> row;
        cout << "Column: ";
        cin >> col;
        cout << "Horizontal(0 For Vertical/1 For horizontal):";
        cin >> horizontal;
        //cout << row << col << horizontal << endl;
        if (getGrid().inBounds(row, col, getShip(i)->getSize(), horizontal))
        {
            int IsOccupied = 0;
            if (horizontal == 1)
            {
                for (int j = col; j < col + getShip(i)->getSize(); j++)
                {
                    if (getGrid().isTileOccupied(row - 1, j - 1) == true)
                    {
                        cout << "Occupied" << endl;
                        IsOccupied++;
                    }
                }
                if (IsOccupied == 0)
                {
                    getGrid().placeShip(row, col, getShip(i)->getSize(), horizontal, getShipChar(i));
                    //getGrid().PrintGrid();
                }
                else
                {
                    i--;
                }
            }
            else if (horizontal == 0)
            {
                for (int j = row; j < row + getShip(i)->getSize(); j++)
                {
                    if (getGrid().isTileOccupied(j - 1, col - 1) == true)
                    {
                        cout << "Occupied" << endl;
                        IsOccupied++;
                    }
                }
                if (IsOccupied == 0)
                {
                    getGrid().placeShip(row, col, getShip(i)->getSize(), horizontal, getShipChar(i));
                    //getGrid().PrintGrid();
                }
                else
                    i--;
            }
        }
        else
        {
            cout << "Out of Bounds" << endl;
            i--;
            continue;
        }
    }
}

HumanPlayer::~HumanPlayer(){
    cout << playerName << " player Destractor" << endl;
    delete[] playerName;
}