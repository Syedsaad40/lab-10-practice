#include <stdio.h>

int maxPieces(int length) {
    if (length == 0) return 0;
    if (length < 0) return -1;
    
    int cut1 = maxPieces(length - 1);
    int cut2 = maxPieces(length - 2);
    int cut3 = maxPieces(length - 3);
    
    int maxCut = (cut1 > cut2 ? cut1 : cut2);
    maxCut = (maxCut > cut3 ? maxCut : cut3);
    
    if (maxCut == -1) return -1;
    
    return maxCut + 1;
}

int main() {
    printf("Maximum pieces: %d\n", maxPieces(5));
    return 0;
}
