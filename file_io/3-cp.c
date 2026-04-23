#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * close_file - closes a file descriptor
 * @fd: file descriptor to close
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * open_source - opens source file
 * @filename: source filename
 *
 * Return: source file descriptor
 */
int open_source(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}

	return (fd);
}

/**
 * open_dest - opens destination file
 * @filename: destination filename
 *
 * Return: destination file descriptor
 */
int open_dest(char *filename)
{
	int fd;

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}

	return (fd);
}

/**
 * copy_file - copies content from one file to another
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * @file_from: source filename
 * @file_to: destination filename
 */
void copy_file(int fd_from, int fd_to, char *file_from, char *file_to)
{
	ssize_t rd, wr;
	char buffer[1024];

	rd = read(fd_from, buffer, 1024);
	while (rd > 0)
	{
		wr = write(fd_to, buffer, rd);
		if (wr == -1 || wr != rd)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			close_file(fd_from);
			close_file(fd_to);
			exit(99);
		}
		rd = read(fd_from, buffer, 1024);
	}
	if (rd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		close_file(fd_from);
		close_file(fd_to);
		exit(98);
	}
}

/**
 * main - copies the content of a file to another file
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open_source(av[1]);
	fd_to = open_dest(av[2]);
	copy_file(fd_from, fd_to, av[1], av[2]);
	close_file(fd_from);
	close_file(fd_to);

	return (0);
}
