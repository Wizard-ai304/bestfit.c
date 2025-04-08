#include <stdio.h>

int main() {
    int blockSize[10], fileSize[10], blockCount, fileCount;
    int i, j, best, frag;

    printf("Enter number of blocks: ");
    scanf("%d", &blockCount);
    printf("Enter number of files: ");
    scanf("%d", &fileCount);

    printf("\nEnter sizes of blocks:\n");
    for (i = 0; i < blockCount; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("\nEnter sizes of files:\n");
    for (i = 0; i < fileCount; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &fileSize[i]);
    }

    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment\n");

    int allocated[10] = {0}; // 0 means block is free

    for (i = 0; i < fileCount; i++) {
        best = -1;

        for (j = 0; j < blockCount; j++) {
            if (!allocated[j] && blockSize[j] >= fileSize[i]) {
                if (best == -1 || blockSize[j] < blockSize[best]) {
                    best = j;
                }
            }
        }

        if (best != -1) {
            frag = blockSize[best] - fileSize[i];
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, fileSize[i], best + 1, blockSize[best], frag);
            allocated[best] = 1; // Mark block as used
        } else {
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, fileSize[i]);
        }
    }

    return 0;
}
