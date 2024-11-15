#include <stdio.h>
#include <string.h>

struct Flight {
    char flightNumber[10];
    int availableSeats;
};

int main() {
    struct Flight flight1 = {"AA101", 100};
    
    flight1.availableSeats--;
    printf("Flight %s, Available seats: %d\n", flight1.flightNumber, flight1.availableSeats);
    
    return 0;
}
