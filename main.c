#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
    int size,
	status;

    char *data = "*";

    FILE *outfile;

    if (argc != 2)
    {
	printf("USAGE: reserveds <number of meg>\n");
	exit(0);
    }

    size = atoi(argv[1]) * 1024;

    printf("SIZE: %d\n", size * 1024);

    printf("Reserving %dM of disk space...\n", size);

    outfile = fopen("reserve", "wb+");
    if (!outfile)
    {
	perror("fopen");
	exit(1);
    }

    status = fwrite(data, 1, (size * 1024), outfile);
    if (status == 0)
    {
	perror("fwrite");
	exit(1);
    }

    fclose(outfile);

    exit(0);

}
