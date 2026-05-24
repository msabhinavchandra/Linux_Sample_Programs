// import headers
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{

	int ch;			// choice input
	char name[100]; // for file name
	int fd;			// file descriptor
	printf("1.Create file\n2.Read file\n3.delete file\n4.Create Directory\n5.Delete Directory\n");
	printf("Select an option:");
	scanf("%d", &ch); // for string no need of & for filename context

	switch (ch)
	{
	case 1:
		// create a file
		printf("Enter the name of the file: ");
		scanf("%s", name);						 // no need to put & for string
		fd = open(name, O_CREAT | O_RDWR, 0777); // name,flags,permissions
		if (fd >= 0)
		{
			printf("File created successfully");
		}
		break;
	case 2:
		// READ FILE
		printf("Enter the Name of file: ");
		scanf("%s", name); // no need to put & for string
		char data[100];
		fd = open(name, O_RDONLY);
		read(fd, data, sizeof(data));
		printf("File contents: %s", data);
		break;
	case 3:
		// delete a file
		printf("Enter the name of the file: ");
		scanf("%s", name); // no need to put & for string
		unlink(name);	   // deletes the file
		break;
	case 4:
		// create a directory
		printf("Enter the name of the directory: ");
		scanf("%s", name); // no need to put & for string
		mkdir(name, 0777); // name,permissions
		break;
	case 5:
		// delete a directory
		printf("Enter the name of the directory: ");
		scanf("%s", name); // no need to put & for string
		rmdir(name);
	}

	return 0;
}
