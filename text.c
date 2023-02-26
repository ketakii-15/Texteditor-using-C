#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main(int argc, char *argv[]) {
    char file_name[256];
    char buffer[MAX_LINE_LENGTH];
    FILE *file;
    int line_number = 1;

    // Ask user for file name
    printf("Enter file name: ");
    scanf("%s", file_name);

    // Open the file
    file = fopen(file_name, "r+");

    // Check if the file exists
    if (file == NULL) {
        printf("File not found.\n");
        return 1;
    }

    // Display the contents of the file
    while (fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
        printf("%d: %s", line_number, buffer);
        line_number++;
    }

    // Move the file pointer to the end of the file
    fseek(file, 0, SEEK_END);

    // Ask user for input
    printf("Enter text: ");
    fgets(buffer, MAX_LINE_LENGTH, stdin);

    // Write the input to the file
    fputs(buffer, file);

    // Close the file
    fclose(file);

    return 0;
}
