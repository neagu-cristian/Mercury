#include "include/Game.hpp"
#include <GameStateStart.hpp>

#include <iostream>

using namespace std;

int main()
{
    Game game;

    game.pushState(new GameStateStart(&game));
    game.gameLoop();

    return 0;
}


/*
43 6
25 34
25 80
5  128
82 128
61 80
61 34
*/

/*
43 5
25 30
25 80
9  110
5  95
4  128
17 120
36 142
54 142
68 120
82 128
82 95
75 110
62 80
62 30
43 5
*/