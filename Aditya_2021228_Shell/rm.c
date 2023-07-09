#include <stdio.h>
int main() {
     char str[20];
    printf("Enter the name of the File: ");
    scanf("%s",str);
    if (remove(str) != 0) {
        printf("file not deleted");
    } else {
        printf("file deleted.");
    }
    return 0;
}