#if (!defined(_ADV_TYPES_H))
#define _ADV_TYPES_H

#define PC_NAME_SIZE	30
#define PC_TITLE_SIZE	50

#define PC_RACE_HUMAN		1
#define PC_RACE_ELF		2
#define PC_RACE_TROLL		3

#define PC_CLASS_WARRIOR	1
#define PC_CLASS_WIZARD		2
#define PC_CLASS_THIEF		3

typedef struct playing_character
{
  char name[PC_NAME_SIZE];
  char title[PC_TITLE_SIZE];
  int race;                     // human, elf etc
  int class;                    // wizard, warrior etc
  int gold;
} PC;

#endif
