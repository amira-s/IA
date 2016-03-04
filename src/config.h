#ifndef CONFIG_H
#define CONFIG_H
#include "../lib/colors.h"

#define BACKGROUND_COLOR   BG_WHITE
#define PRINTABLE_RESOURCE FG_WHITE""BG_CYAN" "COLOR_RESET
#define PRINTABLE_SPACE    BACKGROUND_COLOR" "COLOR_RESET
#define PRINTABLE_PLAYER   BACKGROUND_COLOR""FG_BLUE"@"COLOR_RESET
#define PRINTABLE_TRACE    BACKGROUND_COLOR""FG_YELLOW"'"COLOR_RESET
#define PRINTABLE_EXIT     BG_RED""FG_RED"#"COLOR_RESET

#endif /* CONFIG_H */