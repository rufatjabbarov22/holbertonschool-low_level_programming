#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @filename: The name of the file to read
 *
 * Return: The actual number of letters it could read and print
 *         0 if the file can not be opened or read
 *         0 if filename is NULL
 *         0 if write fails or does not write the expected amount of bytes
 */
ssize_t read_textfile(const char *filename)
{
    int fd, bytes_read, bytes_written;
    char buffer[1024];

    if (filename == NULL)
        return (0);

    /* Open the file for reading */
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (0);

    /* Read from file */
    bytes_read = read(fd, buffer, 1024);
    if (bytes_read == -1)
    {
        close(fd);
        return (0);
    }

    /* Write to standard output */
    bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
    if (bytes_written == -1 || bytes_written != bytes_read)
    {
        close(fd);
        return (0);
    }

    /* Clean up and return bytes read */
    close(fd);
    return (bytes_read);
}
