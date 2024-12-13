#include <stdio.h>

int main() {
    FILE *filePointer;
    int integerValue;
    float floatValue;
    char stringValue[50];

    // Opening a file in read mode ("r")
    filePointer = fopen("input.txt", "r");

    // Checking if the file opened successfully
    if (filePointer == NULL) {
        printf("Unable to open the file.\n");
        return 1; // Return an error code
    }

    // Reading data from the file using fscanf
    fscanf(filePointer, "%s", stringValue);

    // Printing the read values
    // printf("Integer: %d\n", integerValue);
    // printf("Float: %f\n", floatValue);
    printf("String: %s\n", stringValue);

    // Closing the file
    fclose(filePointer);

    return 0;
}
