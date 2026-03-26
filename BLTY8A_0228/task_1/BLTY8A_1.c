#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 256

int main(void) {
    char fileName[MAX];
    char line[MAX];
    FILE *fp;
    int i;

    printf("Fájl neve: ");
    fgets(fileName, MAX, stdin);

    fileName[strcspn(fileName, "\n")] = '\0';

    fp = fopen(fileName, "w");
    if (fp == NULL) {
        printf("Hiba a fájl megnyitásakor!\n");
        return 1;
    }

    printf("Adja meg a sorokat (# jel a befejezéshez):\n");

    while (1) {
        fgets(line, MAX, stdin);

        if (strcmp(line, "#\n") == 0 || strcmp(line, "#") == 0) {
            break;
        }

        fputs(line, fp);
    }

    fclose(fp);

    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Hiba a fájl újranyitásakor!\n");
        return 1;
    }

    printf("\nA fájl tartalma nagybetűsen:\n");

    while (fgets(line, MAX, fp) != NULL) {
        for (i = 0; line[i] != '\0'; i++) {
            line[i] = toupper((unsigned char)line[i]);
        }
        printf("%s", line);
    }

    fclose(fp);

    return 0;
}