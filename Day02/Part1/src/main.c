/*
** Main file AdventOfCode 2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

// Cubes counts header file, used to get the cubes max count
#include "cubes_counts.h"

// Input file (change if needed)
#define FILENAME "../input.txt"

// Skips the number at the beginning of the string
int skip_number(char *str)
{
    // Position in the string
    int pos = 0;

    // Skip spaces if any before
    for (; (str[pos]) && (str[pos] == ' '); pos++) {}
    
    // Skip number
    for (; (str[pos]) && (str[pos] <= '9' && str[pos] >= '0'); pos++) {}
    
    // Skip spaces if any after
    for (; (str[pos]) && (str[pos] == ' '); pos++) {}

    // Return the position of the first character after the number
    return (pos);
}

// Skips the "Game #:" part of the string
int get_game_end(char *str)
{
    // Position in the string
    int pos = 0;

    // Skip to the "":" character
    for (pos = 0; str[pos] && str[pos] != ':'; pos++) {}

    // Return the position of the first character after the ":"
    return (pos + 1);
}

// Checks if the character is a letter or a space
int is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ') {
        return 1;
    }

    return 0;
}

// Gets the game id from the string
int get_game_id(char *str)
{
    // Position in the string
    int pos = 0;

    // Skip to the first character after the game id
    for (pos = 0; str[pos] && is_alpha(str[pos]); pos++) {}

    // Return the game id
    return (atoi(str + pos));
}

// Checks if the color amount is below the max count or if game is impossible
int check_color(char *str, int amount)
{
    // Check if the color is red & if the amount is above the max count
    if (strncmp(str, "red", 3) == 0)
    {
        if (amount > RED_CUBES_COUNT) {
            return 1;
        }
    }
    // Check if the color is green & if the amount is above the max count
    else if (strncmp(str, "green", 5) == 0)
    {
        if (amount > GREEN_CUBES_COUNT) {
            return 1;
        }
    }
    // Check if the color is blue & if the amount is above the max count
    else if (strncmp(str, "blue", 4) == 0)
    {
        if (amount > BLUE_CUBES_COUNT) {
            return 1;
        }
    }

    // Error, the color does not match any
    return 0;
}

// Checks if the draw is possible
int check_draw(char *str)
{
    // Subdivided string
    char *token;

    // Amount of cubes
    int amount;

    // Get the first token
    token = strtok_r(str, ",", &str);

    // Run until there is no more token left in string
    while (token != NULL)
    {
        // Get the amount of cubes
        amount = atoi(token);
    
        // Check if the color draw is impossible
        if (check_color(token + skip_number(token), amount)) {
            // Return 1, game is impossible
            return 1;
        }

        // Get the next token
        token = strtok_r(NULL, ",", &str);
    }

    // Return 0, draw is possible
    return 0;
}

// Checks if the game is possible
int check_line(char *str)
{
    // Subdivided string
    char *token;

    // Get the first token
    token = strtok_r(str, ";", &str);

    // Run until there is no more token left in string
    while (token != NULL)
    {
        // Check if the draw is impossible
        if (check_draw(token)) {
            // Return 1, game is impossible
            return 1;
        }

        // Get the next token
        token = strtok_r(NULL, ";", &str);
    }

    // Return 0, game is possible
    return 0;
}

int main(void)
{
    // Size of the file
    size_t size = 0;

    // Sum of possible games
    int sum = 0;

    // File descriptor
    int file = 0;

    // File content
    char *file_content;

    // Subdivided string
    char *token;

    // Open the file (not gonna explain everything here, very technical stuff) 
    printf("Open file %s\n", FILENAME);

    FILE *fp = fopen(FILENAME, "r");

    if (fp == NULL) {
        printf("Error while opening file\n");
        return (84);
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fclose(fp);
    file = open(FILENAME, O_RDONLY);

    if (file == -1) {
        printf("Error while opening file\n");
        return (84);
    }

    file_content = malloc(sizeof(char) * size);

    if (file_content == NULL) {
        printf("Error while allocating memory\n");
        close(file);
        return (84);
    }

    if (read(file, file_content, size) == -1) {
        free(file_content);
        close(file);
        printf("Error while reading file\n");
        return (84);
    }

    // Close the file after reading it
    close(file);

    // Get the first token
    token = strtok_r(file_content, "\n", &file_content);

    // Run until there is no more token left in string
    while (token != NULL)
    {
        // Print the game id
        printf("Check game %s\n", token);

        // Check if the game is impossible
        if (check_line(token + get_game_end(token)))
        {
            printf("Game %d is impossible\n", get_game_id(token));
        }
        else
        {
            // Add the game id to the sum
            sum += get_game_id(token);
            printf("Game %d is possible\n", get_game_id(token));
        }

        // Get the next token
        token = strtok_r(NULL, "\n", &file_content);
    }

    // Print the sum of possible games
    printf("Sum of possible games: %d\n", sum);

    // Return 0, no error in program
    return 0;
}
