#include <stdio.h>

void hanoi(int disks, char source, char dest, char temp) {
    if (disks == 1) {
        printf("Move disk %d from %c to %c\n", disks, source, dest);
        return;
    }

    hanoi(disks - 1, source, temp, dest);
    printf("Move disk %d from %c to %c\n", disks, source, dest);
    hanoi(disks - 1, temp, dest, source);
}

int main() {
    int disks;
    scanf("%d", &disks);

    hanoi(disks, 'A', 'C', 'B');
    return 0;
}
