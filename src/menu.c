/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:16:20 by abdsalah          #+#    #+#             */
/*   Updated: 2025/05/02 19:28:09 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void print_menu_title(WINDOW *menu_win, char *title)
{
    int win_width;
    int title_x;
    
    win_width = getmaxx(menu_win);
    werase(menu_win);
    box(menu_win, 0, 0);
    
    title_x = (win_width - ft_strlen(title)) / 2;
    mvwprintw(menu_win, 1, title_x, "%s", title);
    wrefresh(menu_win);
}

void print_menu(WINDOW *menu_win, int highlight, char **choices, int n_choices, char *title)
{
    int win_width;
    int choice_x;
    int choice_y;
    
    win_width = getmaxx(menu_win);
    print_menu_title(menu_win, title);
    for (int i = 0; i < n_choices; ++i)
    {
        choice_x = (win_width - ft_strlen(choices[i])) / 2;
        choice_y = 3 + i * 2;
        if (i == highlight)
            wattron(menu_win, A_REVERSE);
        mvwprintw(menu_win, choice_y, choice_x, "%s", choices[i]);
        wattroff(menu_win, A_REVERSE);
    }
    wrefresh(menu_win);
}

int navigate_menu(char **choices, int n_choices, char *title)
{
    int selected = 0;
    int input;
    int choice = -1;
    int menu_width = 40;
    int menu_height = n_choices * 2 + 5;
    int startx = (COLS - menu_width) / 2;
    int starty = (LINES - menu_height) / 2;

    WINDOW *menu_win = newwin(menu_height, menu_width, starty, startx);
    keypad(menu_win, TRUE);
    while (1)
    {
        print_menu(menu_win, selected, choices, n_choices, title);
        input = wgetch(menu_win);

        if (input == KEY_UP)
            selected = (selected - 1 + n_choices) % n_choices;
        else if (input == KEY_DOWN)
            selected = (selected + 1) % n_choices;
        else if (input == ENTER || input == '\n')
        {
            choice = selected;
            break;
        }
    }
    delwin(menu_win);
    return choice;
}

void start_menu(t_game *game)
{
    (void)game;

    char *main_choices[] = { "Start", "Quit" };
    char *grid_choices[] = { "4x4", "5x5" };

    int main_choice = navigate_menu(main_choices, ARRAY_SIZE(main_choices), "Welcome to 2048");
    if (main_choice == 0)
    {
        int grid_choice = navigate_menu(grid_choices, ARRAY_SIZE(grid_choices), "Select Grid Size");
        if (grid_choice == 0)
            game->grid_size = 4;
        else
            game->grid_size = 5;
        endwin();
    }
    else
    {
        endwin();
        printf("Goodbye!\n");
        exit(0);
    }
}
