/*
** Main file AdventOfCode 2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

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

// Gets the color id from the string (red, green or blue)
int get_color_id(char *str)
{
    // Check if the color is red
    if (strncmp(str, "red", 3) == 0)
    {
        // Returns red id
        return 0;
    }
    // Check if the color is green
    else if (strncmp(str, "green", 5) == 0)
    {
        // Returns green id
        return 1;
    }
    // Check if the color is blue
    else if (strncmp(str, "blue", 4) == 0)
    {
        // Returns blue id
        return 2;
    }

    // Error, the color does not match any
    return (-1);
}

// Gets draw values for each colors
void get_draw_mins(char *str, int *colors)
{
    // Subdivided string
    char *token;
    // Number of cubes, color id
    int number, id;

    // Get the first token
    token = strtok_r(str, ",", &str);

    // Run until there is no more token left in string
    while (token != NULL)
    {
        // Get the number of cubes
        number = atoi(token);

        // Get the color id
        id = get_color_id(token + skip_number(token));
    
        // Check if the number of cubes is greater than the current one
        if (colors[id] < number) {
            colors[id] = number;
        }

        // Get the next token
        token = strtok_r(NULL, ",", &str);
    }
}

// Gets the power of the line
int get_line_power(char *str)
{
    // Subdivided string
    char *token;

    // Colors minimums for each lines
    int colors[3] = {0, 0, 0};

    // Power of the line
    int power;

    // Get the first token
    token = strtok_r(str, ";", &str);

    // Run until there is no more token left in string
    while (token != NULL)
    {
        // Get the colors minimums
        get_draw_mins(token, colors);

        // Get the next token
        token = strtok_r(NULL, ";", &str);
    }

    // Get the power of the line
    power = colors[0] * colors[1] * colors[2];

    // Print the power of the line and colors minimums
    printf("Power: %d Colors: %d %d %d\n", power, colors[0], colors[1], colors[2]);

    // Return the power of the line
    return power;
}

int main(void)
{
    // Size of the file
    size_t size = 0;

    // File descriptor
    int file = 0;

    // File content
    char *file_content;

    // Subdivided string
    char *token;

    // Power sum
    int power = 0;

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

    // Run until there is no more token left in string (lines in file data)
    while (token != NULL)
    {
        // Print the game id
        printf("Check game %s\n", token);

        // Get the power of the line
        power += get_line_power(token + get_game_end(token));

        // Get the next token
        token = strtok_r(NULL, "\n", &file_content);
    }

    // Print the power sum
    printf("Power sum: %d\n", power);

    // Return 0, no error in program
    return 0;
}
