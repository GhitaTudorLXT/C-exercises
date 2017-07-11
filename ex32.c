#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void escape(char *s, char *t)
{
	int i,j;

	i = j = 0;

	while (1)
	{
		switch(t[i])
		{
			case('\n'):
				s[j++] = '\\';
				s[j] = 'n';
				break;
			case('\t'):
				s[j++] = '\\';
				s[j] = 't';
				break;
			default:
				s[j] = t[i];
		}

		j++;
		i++;

		if (t[i] == '\0')
		{
			s[j] = t[i];
			break;
		}
	}
}

int main(int argc, char **argv)
{
	char s[1024];
	char t[1024];

	int fd = open("ex32.in", O_RDONLY);
	int len = read(fd, t, 1023);
	t[len] = 0;

	escape(s,t);

	printf("%s\n", s);

	return 0;
}