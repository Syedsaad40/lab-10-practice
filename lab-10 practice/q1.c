#include <stdio.h>
#include <stdlib.h>
int calculate_total_weight(void* box[]) {
    int total_weight = 0;
    for (int i = 0; box[i] != NULL; i++) {
        if (*(int*)box[i] >= 0) {
            total_weight += *(int*)box[i];
        } else {
            total_weight += calculate_total_weight((void**)box[i]);
        }
    }
    return total_weight;
}

int main() {
    int item1 = 5, item2 = 10, item3 = 2, item4 = 3;
    void* nestedBox1[] = {(void*)&item1, (void*)&item2, NULL}; 
    void* nestedBox2[] = {(void*)&item3, (void*)&item4, (void*)nestedBox1, NULL};
    void* mainBox[] = {(void*)&item1, (void*)nestedBox2, (void*)&item2, NULL}; 
    int total_weight = calculate_total_weight(mainBox);
    printf("Total weight: %d\n", total_weight);

    return 0;
}
