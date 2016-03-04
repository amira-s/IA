/*
** config.h for AI in /home/amira_s/src/AI
** 
** Made by AMIRA Syrine
** Login   <amira_s@etna-alternance.net>
** 
** Started on  Mon Feb 22 09:15:10 2016 AMIRA Syrine
** Last update Fri Mar 04 16:52:33 2016 AMIRA Syrine
*/

#ifndef CONFIG_H
#define CONFIG_H
#include "../lib/colors.h"

#define ANIM_DELAY 100000

#define MSG_NO_SOLUTIONS_FOUND "No solution found."

#define BACKGROUND_COLOR   BG_WHITE
#define PRINTABLE_RESOURCE FG_WHITE""BG_CYAN" "COLOR_RESET
#define PRINTABLE_SPACE    BACKGROUND_COLOR" "COLOR_RESET
#define PRINTABLE_PLAYER   BACKGROUND_COLOR""FG_BLUE"@"COLOR_RESET
#define PRINTABLE_TRACE    BACKGROUND_COLOR""FG_YELLOW"'"COLOR_RESET
#define PRINTABLE_EXIT     BG_RED""FG_RED"#"COLOR_RESET

#endif /* CONFIG_H */
