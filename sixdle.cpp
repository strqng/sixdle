using namespace std;
#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>


void getWord(int x)
{
    cout << "game launched";
}

int main()
{
    cout << "sixdle, worlde with six letters" << endl;
    cout <<"Enter '1' To begin" << endl;
    int playGame;
    cin >> playGame;

    if(playGame == 1)
    {
        getWord(playGame);
    }
    else
    {
        return 0;
    }

    return 0;
}
