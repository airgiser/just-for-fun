/*!
 * Copyright (c) airfox 2012
 *
 * \brief A Game about Rock,Scissors and Cloth.
 * \author airfox<airgis@163.com>
 */
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include "rsc.h"
using namespace std;

static GameObject *CreateGameObject(int x)
{
    switch(x)
    {
        case 0:
            cout<<"Rock!"<<endl;
            return new Rock;
        case 1:
            cout<<"Scissors!"<<endl;
            return new Scissors;
        case 2:
            cout<<"Cloth!"<<endl;
            return new Cloth;
        default:
            exit(0);
    }
}

static void ShowResult(GameObject *player, GameObject *computer)
{
    int result = player->Play(*computer);
    cout<<"Result: ";
    switch(result)
    {
        case 0:
            cout<<"Tie.";
            break;
        case 1:
            cout<<"You lose.";
            break;
        case -1:
            cout<<"You win!";
            break;
        default:
            assert(0);
    }
    cout<<endl;
}

int main(int argc, char *argv[])
{
    srand(time(0));
    
    while(1)
    {
        int y = 0;
        cout<<"Please input a number(0-Rock 1-Scissors 2-Cloth):"<<endl;
        cin>>y;

        cout<<"Player: ";
        GameObject *player = CreateGameObject(y);

        int x = rand() % 3;
        cout<<"Computer: ";
        GameObject *computer = CreateGameObject(x);

        ShowResult(player, computer);

        delete computer;
        delete player;
    }

    return 0;
}
