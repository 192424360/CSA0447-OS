#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int source, dest;
    char buffer[100];
    int bytes;

    char src[100], dst[100];

    // Input file names
    printf("Enter the filename to open for reading\n");
    scanf("%s", src);

    printf("Enter the filename to open for writing\n");
    scanf("%s", dst);

    // Open source file
    source = open(src, O_RDONLY);
    if (source < 0) {
        printf("Error opening source file\n");
        return 1;
    }

    // Open/create destination file
    dest = open(dst, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest < 0) {
        printf("Error opening destination file\n");
        return 1;
    }

    // Read and write loop
    while ((bytes = read(source, buffer, sizeof(buffer))) > 0) {
        write(dest, buffer, bytes);
    }

    printf("\nContents copied to %s\n", dst);

    // Close files
    close(source);
    close(dest);

    return 0;
}
