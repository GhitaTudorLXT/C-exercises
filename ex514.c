/* Will not compile */

#include <string.h>

int main(int argc, char **argv)
{
  int nlines;
  int numeric = 0;
  int reversed = 0;
  int i;

  for (i = 1; i < argc; i++)
  {
    if (!strcmp(argv[i], "-n"))
      numeric = 1;

    if (!strcmp(argv[i], "-r"))
      reversed = 1;
  }

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) //not defined
  {
    qsort((void**) lineptr, 0, nlines-1, (int (*)(void*,void*))(numeric ? numcmp : strcmp), reversed);
    writelines(lineptr, nlines); //not defined
    return 0;
  }

  else 
  {
    printf("input too big to sort\n");
    return 1;
  }
}

void qsort(void *v[], int left, int right, int (*comp)(void *, void *), int reversed)
{
  int i, last;
  void swap(void *v[], int, int);

  if (left >= right)    /* do  nothing if array contains */
    return;           /* fewer than two elements */

  swap(v, left, (left + right) / 2);

  last = left;

  for (i = left+1; i <= right;  i++)
    if ((*comp)(v[i], v[left]) < 0 && !reversed || (*comp)(v[i], v[left]) > 0 && reversed)
      swap(v, ++last, i);

  swap(v, left, last);
  qsort(v, left, last-1, comp);
  qsort(v, last+1, right, comp);
}