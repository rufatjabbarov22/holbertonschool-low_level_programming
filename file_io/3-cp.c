#include "main.h"

/**
 * main - program to copy filr
 * @argc: arguments as input
 * @argv: filenames to use
 * Return: 0 if success
 */

int main(int argc, char *argv[])
{
	int fd1, fd2;
	ssize_t bytes_read, bytes_written;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}

	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		return (98);
	}

	fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fd2 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(fd1);
		return (99);
	}

	do {
		bytes_read = read(fd1, buf, sizeof(buf));
		if (bytes_read == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			close(fd1);
			close(fd2);
			return (98);
		}
		bytes_written = write(fd2, buf, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(fd1);
			close(fd2);
			return (99);
		}
	} while (bytes_read == sizeof(buf));

	if (close(fd1) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd1);
		return (100);
	}
	if (close(fd2) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd2);
		return (100);
	}
	return (0);
}
