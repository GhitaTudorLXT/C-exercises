#include <stdio.h>

int main()
{
	char c;
	while ((c = getchar()) != EOF)
	{
		switch(c)
		{
			case('\t'):
				printf("\\t");
				break;
			case('\b'):				/* To input a backspace press CTRL+BACKSPACE */
				printf("\\b");
				break;
			case('\\'):
				printf("\\\\");
				break;
			default:
				printf("%c", c);
		}
	}

	return 0;
}