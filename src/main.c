/*
 * Project:          C Alarm
 * Programmer:       Henrik Abel Christensen
 * Date Completed:   in progress
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#if defined _WIN32 || defined _WIN64
#include <windows.h>
#define CLEAR "cls"
#else
#include <unistd.h>
#define CLEAR "clear"
#endif

#define TIMER_MINUTES 45
#define SLEEP 60000

void display_main_screen(char **opt, size_t num_opts);
void start_timer(uint8_t minutes, uint16_t sleep_len);

int main(void)
{
  char *opt[] = {"Start timer", "Exit"};
  size_t num_opts = sizeof(opt) / sizeof(opt[0]);

  display_main_screen(opt, num_opts);

  start_timer(TIMER_MINUTES, SLEEP);

  return EXIT_SUCCESS;
}

void display_main_screen(char **opt, size_t num_opts)
{
  int i;

  system(CLEAR);

  printf("==========\n");
  printf(" C ALARM\n");
  printf("==========\n");

  for (i = 0; i < num_opts; i++)
  {
    printf("\n%d) %s", i + 1, opt[i]);
  }
}

void start_timer(uint8_t minutes, uint16_t sleep_len)
{
  int i;
  uint8_t minutes_left;

  for (i = 0; i < minutes; i++)
  {
    minutes_left = minutes - i;
    printf("\n%2d %s left", minutes_left, minutes_left > 1 ? "minutes" : "minute");
    Sleep(sleep_len);
  }

  printf("\nDone!");
}
