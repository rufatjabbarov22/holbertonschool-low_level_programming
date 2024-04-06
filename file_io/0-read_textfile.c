#include "main.h"

#define BUFFER_SIZE 1024

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @filename: The name of the file to read
 *
 * Return: The actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename)
{
    int fd, bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];

    if (filename == NULL)
        return (0);

    /* Open the file for reading */
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (0);

    /* Read from file */
    bytes_read = read(fd, buffer, BUFFER_SIZE);
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
