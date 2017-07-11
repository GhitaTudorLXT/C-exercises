#include <stdio.h>

static char daytab[2][13] = { 
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} 
}; 

/* day_of_year:  set day of year from month & day */ 
int day_of_year(int year, int month, int day) 
{
  int i, leap;

  if (year < 0 || month > 12 || day < 0)
    return -1;

  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

  if (day > daytab[leap][month])
    return -1;

  for (i = 1; i < month; i++)
    day += daytab[leap][i];

  return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i, leap;

  if (year < 0)
  {
    *pmonth = -1;
    *pday = -1;
    return;
  }

  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

  if ((leap && yearday > 366) || (!leap && yearday > 365))
  {
    *pmonth = -1;
    *pday = -1;
    return;
  }

  for (i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];

  *pmonth = i;
  *pday = yearday;
}

int main()
{
  printf("%d\n", day_of_year(2017,7,11));

  int month;
  int day;
  int year = 2017;

  month_day(year, 192, &month, &day);
  printf("%d.%d.%d\n", day, month, year);

  return 0;
}