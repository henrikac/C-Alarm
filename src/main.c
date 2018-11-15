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
#else
#include <unistd.h>
#endif

#define TIMER_MINUTES 45
#define SLEEP 60000

void start_timer(uint8_t minutes, uint16_t sleep_len);

int main(void)
{
  start_timer(TIMER_MINUTES, SLEEP);

  return EXIT_SUCCESS;
}

void start_timer(uint8_t minutes, uint16_t sleep_len)
{
  int i;
  uint8_t minutes_left;

  for (i = 0; i < minutes; i++)
  {
    minutes_left = minutes - i;
    printf("\n%d %s left", minutes_left, minutes_left > 1 ? "minutes" : "minute");
    Sleep(sleep_len);
  }

  printf("\nDone!");
}
