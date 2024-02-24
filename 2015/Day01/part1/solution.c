#include <stdio.h>
#include <stdlib.h>

int main(void) {

    FILE *fp;
    if ((fp = fopen("input.txt", "r")) == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *steps = malloc(filesize + 1);
    if (steps == NULL) {
        printf("Memory Allocation Error\n");
        fclose(fp);
        return 1;
    }

    if (fread(steps, 1, filesize, fp) != filesize) {
        printf("Error reading file\n");
        fclose(fp);
        free(steps);
        return 1;
    }

    steps[filesize] = '\0';

    int count = 0;
    for (int i = 0; steps[i] != '\0'; i++) {
      if (steps[i] == '\n') {
        continue;
      }
      count += (steps[i] == '(') ? 1 : -1;
   }

    printf("Santa is on floor %d\n", count);

    free(steps);
    fclose(fp);
    return 0;
}
