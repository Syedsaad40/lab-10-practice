#include <stdio.h>

// Recursive function to find the maximum number of pieces
int max_pieces(int length) {
    if (length == 0) return 0;

   
    if (length < 0) return -1;

  
    int cut1 = max_pieces(length - 1);
    int cut2 = max_pieces(length - 2);
    int cut3 = max_pieces(length - 3);

    int max_cut = (cut1 > cut2 ? cut1 : cut2);
    max_cut = (max_cut > cut3 ? max_cut : cut3);

   
    return (max_cut == -1) ? -1 : max_cut + 1;
}

int main() {
    int length;
    printf("Enter the length of the rope: ");
    scanf("%d", &length);

    int result = max_pieces(length);
    if (result == -1) {
        printf("The rope cannot be cut into pieces of length 1, 2, or 3.\n");
    } else {
        printf("Maximum number of pieces: %d\n", result);
    }

    return 0;
}

