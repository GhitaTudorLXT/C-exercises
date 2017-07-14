#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define in 			0
#define out 		1
#define BUFSIZE 	1024

void transfer_bytes(int dest, int source)
{
	char buffer[BUFSIZE];

	int read_bytes;

	while ((read_bytes = read(source, buffer, BUFSIZE)) > 0)
		write(dest, buffer, read_bytes);
}

int main(int argc, char *argv[])
{
	int in_fd;
	int read_bytes;

	if (argc < 2)
	{
		transfer_bytes(out, in);
	}
	else
	{
		while (--argc)
		{
			in_fd = open(*(++argv), O_RDONLY);

			if (in_fd < 0)
			{
				printf(" Error openning file %s \n", *argv);
				continue;
			}

			transfer_bytes(out, in_fd);

			close(in_fd);
		}
	}

	return 0;
}