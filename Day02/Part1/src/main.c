/*
** Main file AdventOfCode 2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#include "cubes_counts.h"

#define FILENAME "../input.txt"

int skip_number(char *str)
{
    int pos = 0;

    for (; (str[pos]) && (str[pos] == ' '); pos++) {}
    for (; (str[pos]) && (str[pos] <= '9' && str[pos] >= '0'); pos++) {}
    for (; (str[pos]) && (str[pos] == ' '); pos++) {}

    return (pos);
}

int get_game_end(char *str)
{
    int pos = 0;

    for (pos = 0; str[pos] && str[pos] != ':'; pos++) {}

    return (pos + 1);
}

int is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ') {
        return 1;
    }

    return 0;
}

int get_game_id(char *str)
{
    int pos = 0;

    for (pos = 0; str[pos] && is_alpha(str[pos]); pos++) {}

    return (atoi(str + pos));
}

int check_color(char *str, int amount)
{
    if (strncmp(str, "red", 3) == 0) {
        if (amount > RED_CUBES_COUNT) {
            return 1;
        }
    } else if (strncmp(str, "green", 5) == 0) {
        if (amount > GREEN_CUBES_COUNT) {
            return 1;
        }
    } else if (strncmp(str, "blue", 4) == 0) {
        if (amount > BLUE_CUBES_COUNT) {
            return 1;
        }
    }

    return 0;
}

int check_draw(char *str)
{
    char *token;
    int number;

    token = strtok_r(str, ",", &str);
    while (token != NULL)
    {
        number = atoi(token);
    
        if (check_color(token + skip_number(token), number)) {
            return 1;
        }

        token = strtok_r(NULL, ",", &str);
    }

    return 0;
}

int check_line(char *str)
{
    char *token;

    token = strtok_r(str, ";", &str);
    while (token != NULL)
    {
        if (check_draw(token)) {
            return 1;
        }

        token = strtok_r(NULL, ";", &str);
    }

    return 0;
}

int main(void)
{
    size_t size = 0;
    int sum = 0;
    int file = 0;
    char *file_content;
    char *token;

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

    close(file);

    token = strtok_r(file_content, "\n", &file_content);
    while (token != NULL)
    {
        printf("Check game %s\n", token);
        if (check_line(token + get_game_end(token))) {
            printf("Game %d is impossible\n", get_game_id(token));
        } else {
            sum += get_game_id(token);
            printf("Game %d is possible\n", get_game_id(token));
        }

        token = strtok_r(NULL, "\n", &file_content);
    }

    printf("Sum of possible games: %d\n", sum);

    return 0;
}
