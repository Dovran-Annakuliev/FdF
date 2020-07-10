#include "../includes/fdf.h"

void	errors(int err)
{
	if (err == 1)
	{
		write(1, "usage: ./FdF target_file\n", 26);
		exit(0);
	}
	else if (err == 2)
	{
		write(1, "invalid map\n", 12);
		exit(0);
	}
	else
	{
		write(1, "error\n", 6);
		exit(0);
	}
}
