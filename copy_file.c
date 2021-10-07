#include <stdio.h>
#include <string.h>

int main () {
    FILE *fp;
    FILE *fp2;
    char line[1000];

    fp = fopen("file.txt", "r");
    fp2 = fopen("file2.txt", "w");

    if (fp == NULL || fp2 == NULL) {
        printf("Files do not exist within this directory\n");
        return 0;
    }
    
    while (fgets(line, 1000, fp) != NULL) {
        for (int i = 0; i <= strlen(line) - 1; i++) {
            if (line[i] < 97 || line[i] > 122) {
                fputc(line[i], fp2);
            }
            else {
                line[i] = line[i] - 32;
                fputc(line[i], fp2);
            }
        }
    }

    fclose(fp);
    fclose(fp2);

    return 0; 
}