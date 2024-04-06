#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * main - Entry point, copies the content of a file to another file
 * @argc: Number of arguments
 * @argv: Array of argument strings
 *
 * Return: 0 on success, 97 if incorrect number of arguments,
 * 98 if file_from cannot be read, 99 if file_to cannot be created or written,
 * 100 if a file descriptor cannot be closed
 */

int main(int argc, char *argv[])
{
    int fd_from, fd_to, rd, wr;
    char buf[BUFFER_SIZE];
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

    if (argc != 3)
    {
        dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
        exit(97);
    }

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
    {
        dprintf(2, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
    if (fd_to == -1)
    {
        dprintf(2, "Error: Can't write to %s\n", argv[2]);
        close(fd_from);
        exit(99);
    }

    do
    {
        rd = read(fd_from, buf, BUFFER_SIZE);
        if (rd == -1)
        {
            dprintf(2, "Error: Can't read from file %s\n", argv[1]);
            close(fd_from);
            close(fd_to);
            exit(98);
        }

        wr = write(fd_to, buf, rd);
        if (wr == -1)
        {
            dprintf(2, "Error: Can't write to %s\n", argv[2]);
            close(fd_from);
            close(fd_to);
            exit(99);
        }
    } while (rd == BUFFER_SIZE);

    if (close(fd_from) == -1 || close(fd_to) == -1)
    {
        dprintf(2, "Error: Can't close fd %d\n", fd_from == -1 ? fd_from : fd_to);
        exit(100);
    }

    return (0);
}
