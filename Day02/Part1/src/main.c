/*
** Main file AdventOfCode 2023
*/

// 12 red
// 13 green
// 14 blue

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
    char teststr[] = "Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue";
    
    printf("%s\n", teststr);
    printf("%d\n", get_game(teststr));

    return 0;
}
