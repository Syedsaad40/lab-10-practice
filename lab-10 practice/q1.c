#include <stdio.h>

int calculateWeight(int* boxes, int n) {
    int totalWeight = 0;
    for (int i = 0; i < n; i++) {
        totalWeight += boxes[i];
    }
    return totalWeight;
}

int main() {
    int boxes[] = {5, 10, 15};  // example weights
    int n = sizeof(boxes) / sizeof(boxes[0]);
    printf("Total weight: %d\n", calculateWeight(boxes, n));
    return 0;
}
