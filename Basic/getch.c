#include <stdio.h>

int main() {
    int c, count = 0;
    while ((c = getchar()) != EOF) {
        putchar(c);
        count++;
    }
    printf("Total chars: %d\n", count);
}
