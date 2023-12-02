/*
** Main file AdventOfCode 2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

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

int get_color_id(char *str)
{
    if (strncmp(str, "red", 3) == 0) {
        return 0;
    } else if (strncmp(str, "green", 5) == 0) {
        return 1;
    } else if (strncmp(str, "blue", 4) == 0) {
        return 2;
    }

    return (-1);
}

int get_draw_vals(char *str, int *colors)
{
    char *token;
    int number, id;
    int power = 0;

    token = strtok_r(str, ",", &str);
    while (token != NULL)
    {
        number = atoi(token);
        id = get_color_id(token + skip_number(token));
    
        if (colors[id] < number) {
            colors[id] = number;
        }

        token = strtok_r(NULL, ",", &str);
    }
    return 0;
}

int check_line(char *str)
{
    char *token;
    int colors[3] = {0, 0, 0};
    int power;

    token = strtok_r(str, ";", &str);
    while (token != NULL)
    {
        get_draw_vals(token, colors);

        token = strtok_r(NULL, ";", &str);
    }

    power = colors[0] * colors[1] * colors[2];
    printf("Power: %d Colors: %d %d %d\n", power, colors[0], colors[1], colors[2]);

    return power;
}

int main(void)
{
    size_t size = 0;
    int sum = 0;
    int file = 0;
    char *file_content;
    char *token;
    int power = 0;

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
        power += check_line(token + get_game_end(token));

        token = strtok_r(NULL, "\n", &file_content);
    }

    printf("Power sum: %d\n", power);

    return 0;
}
