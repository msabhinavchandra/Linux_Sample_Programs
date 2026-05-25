#include <stdio.h>
#include <unistd.h>// for link() and symlink() functions

int main()
{
    // Create hard link
    link("file1.txt", "hardlink.txt");

    // Create soft link
    symlink("file1.txt", "softlink.txt");

    printf("Hard link and Soft link created\n");

    return 0;
}