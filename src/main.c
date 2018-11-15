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
#define OPN_BRW "start https://www.youtube.com/watch?v=j5C6X9vOEkU"
#else
#include <unistd.h>
#define CLEAR "clear"
#define OPN_BRW "open https://www.youtube.com/watch?v=j5C6X9vOEkU"
#endif

#define TIMER_MINUTES 45
#define SLEEP 60000

typedef enum { false, true } bool;

void display_main_screen(const char **opt, const size_t num_opts);
size_t get_uinput(const char *msg, const uint8_t min_res, const uint8_t max_res);
void start_timer(const uint8_t minutes, const uint16_t sleep_len);
void start_alarm();

int main(void)
{
  const char *opt[] = {"Start timer", "Exit"};
  size_t num_opts = sizeof(opt) / sizeof(opt[0]);
  size_t choice;

  display_main_screen(opt, num_opts);

  choice = get_uinput("What to do?", 1, num_opts);

  if (choice == num_opts)
    exit(EXIT_SUCCESS);
  else if (choice == 1)
  {
    start_timer(TIMER_MINUTES, SLEEP);
    start_alarm();
  }

  return EXIT_SUCCESS;
}

void display_main_screen(const char **opt, const size_t num_opts)
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

size_t get_uinput(const char *msg, const uint8_t min_res, const uint8_t max_res)
{
  size_t res;

  printf("\n\n%s", msg);

  while (true)
  {
    printf("\n> ");

    if (scanf(" %u", &res) != 1)
    {
      printf("\nThat is not a valid input");
      fflush(stdin);
      continue;
    }

    if (res < min_res || res > max_res)
      printf("\nPlease enter an option between %d and %d", min_res, max_res);
    else
      break;
  }

  return res;
}

void start_timer(const uint8_t minutes, const uint16_t sleep_len)
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

void start_alarm()
{
  system(OPN_BRW);
}
