#include "main.h"

/**
 * close_fd - closes a file descriptor and prints
 * an error message if it fails
 *
 * @fd: file descriptor to close
 * @filename: name of the file being closed
 *
 * Return: 0 on success, 100 on failure
 */
int close_fd(int fd, char *filename)
{
    int oops;

    oops = close(fd);
    if (oops == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
        dprintf(STDERR_FILENO, "Error: Can't close fd %s\n", filename);
        return (100);
    }
    return (0);
}

/**
 * copy_file - copies the content of one file to another
 *
 * @src: source file descriptor
 * @dest: destination file descriptor
 * @src_name: name of the source file
 * @dest_name: name of the destination file
 *
 * Return: 0 on success, 98 if read error, 99 if write error, 100 if close error
 */
int copy_file(int src, int dest, char *src_name, char *dest_name)
{
    ssize_t bytes_read, bytes_written;
    char buf[1024];

    do {
        bytes_read = read(src, buf, sizeof(buf));
        if (bytes_read == -1)
        {
            dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src_name);
            close_fd(src, src_name);
            close_fd(dest, dest_name);
            return (98);
        }
        bytes_written = write(dest, buf, bytes_read);
        if (bytes_written == -1 || bytes_written != bytes_read)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest_name);
            close_fd(src, src_name);
            close_fd(dest, dest_name);
            return (99);
        }
    } while (bytes_read == sizeof(buf));

    return (0);
}

/**
 * main - program to copy a file
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 97 if incorrect number of arguments,
 * 98 if file_from does not exist or is unreadable,
 * 99 if write fails, 100 if file close fails
 */
int main(int argc, char *argv[])
{
    int fd_src, fd_dest, status;

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        return (97);
    }

    fd_src = open(argv[1], O_RDONLY);
    if (fd_src == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        return (98);
    }

    fd_dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_dest == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
        close_fd(fd_src, argv[1]);
        return (99);
    }

    status = copy_file(fd_src, fd_dest, argv[1], argv[2]);

    if (close_fd(fd_src, argv[1]) == 100)
        return (100);
    if (close_fd(fd_dest, argv[2]) == 100)
        return (100);

    return (status);
}
