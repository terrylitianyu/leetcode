/**
 * @file 012.c
 */
#include <string.h>

#define MAX_LENGTH 17
#define MAX_UNIT_LENGTH 5

char* intToRoman(int num) {
  if (num >= 4000) return NULL;
  char* rtn = malloc(sizeof(char) * MAX_LENGTH);
  rtn[0] = '\0';
  char* thousand_string = malloc(sizeof(char) * MAX_UNIT_LENGTH);
  char* hundred_string = malloc(sizeof(char) * MAX_UNIT_LENGTH);
  char* ten_string = malloc(sizeof(char) * MAX_UNIT_LENGTH);
  char* unit_string = malloc(sizeof(char) * MAX_UNIT_LENGTH);

  int thousand = num / 1000;
  int hundred = (num % 1000) / 100;
  int ten = (num % 100) / 10;
  int unit = (num % 10);

  switch (thousand)
  {
    case 1:
      thousand_string = "M";
      break;
    case 2:
      thousand_string = "MM";
      break;
    case 3:
      thousand_string = "MMM";
      break;
    default:
      thousand_string = "";
  }
  switch (hundred)
  {
    case 1:
      hundred_string = "C";
      break;
    case 2:
      hundred_string = "CC";
      break;
    case 3:
      hundred_string = "CCC";
      break;
    case 4:
      hundred_string = "CD";
      break;
    case 5:
      hundred_string = "D";
      break;
    case 6:
      hundred_string = "DC";
      break;
    case 7:
      hundred_string = "DCC";
      break;
    case 8:
      hundred_string = "DCCC";
      break;
    case 9:
      hundred_string = "CM";
      break;
    default:
      hundred_string = "";
  }
  switch (ten)
  {
    case 1:
      ten_string = "X";
      break;
    case 2:
      ten_string = "XX";
      break;
    case 3:
      ten_string = "XXX";
      break;
    case 4:
      ten_string = "XL";
      break;
    case 5:
      ten_string = "L";
      break;
    case 6:
      ten_string = "LX";
      break;
    case 7:
      ten_string = "LXX";
      break;
    case 8:
      ten_string = "LXXX";
      break;
    case 9:
      ten_string = "XC";
      break;
    default:
      ten_string = "";
  }
  switch (unit)
  {
    case 1:
      unit_string = "I";
      break;
    case 2:
      unit_string = "II";
      break;
    case 3:
      unit_string = "III";
      break;
    case 4:
      unit_string = "IV";
      break;
    case 5:
      unit_string = "V";
      break;
    case 6:
      unit_string = "VI";
      break;
    case 7:
      unit_string = "VII";
      break;
    case 8:
      unit_string = "VIII";
      break;
    case 9:
      unit_string = "IX";
      break;
    default:
      unit_string = "";
  }
  strncat(rtn, thousand_string, MAX_LENGTH);
  strncat(rtn, hundred_string, MAX_LENGTH);
  strncat(rtn, ten_string, MAX_LENGTH);
  strncat(rtn, unit_string, MAX_LENGTH);
  return rtn;
}
