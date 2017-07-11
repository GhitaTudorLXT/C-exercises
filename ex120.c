#include <stdio.h>

#define TAB_STOP 4

int main()
{
	char c;
	int curr_length;

	curr_length = 0;
	c = getchar();
	while (c != EOF)
	{
		if (c == '\t')
		{
			int rem_sp = TAB_STOP - (curr_length % TAB_STOP);

			while (rem_sp)
			{
				putchar(' ');
				curr_length++;
				rem_sp--;
			}
		}
		else
		{
			putchar(c);
			curr_length++;
		}

		c = getchar();
	}
}