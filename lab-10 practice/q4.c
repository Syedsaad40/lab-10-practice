#include <stdio.h>
#include <string.h>

#define MAX_FLIGHTS 100

typedef struct {
    char flightNumber[10];
    char departureCity[50];
    char arrivalCity[50];
    char departureTime[6];
    char arrivalTime[6];
    int availableSeats;
} Flight;

Flight flights[MAX_FLIGHTS];
int flightCount = 0;

void addFlight(char* flightNumber, char* departureCity, char* arrivalCity, char* departureTime, char* arrivalTime, int availableSeats) {
    if (flightCount < MAX_FLIGHTS) {
        strcpy(flights[flightCount].flightNumber, flightNumber);
        strcpy(flights[flightCount].departureCity, departureCity);
        strcpy(flights[flightCount].arrivalCity, arrivalCity);
        strcpy(flights[flightCount].departureTime, departureTime);
        strcpy(flights[flightCount].arrivalTime, arrivalTime);
        flights[flightCount].availableSeats = availableSeats;
        flightCount++;
    } else {
        printf("Flight list is full.\n");
    }
}

void bookSeat(char* flightNumber) {
    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i].flightNumber, flightNumber) == 0) {
            if (flights[i].availableSeats > 0) {
                flights[i].availableSeats--;
                printf("Seat booked on flight %s.\n", flightNumber);
            } else {
                printf("No available seats on flight %s.\n", flightNumber);
            }
            return;
        }
    }
    printf("Flight not found.\n");
}

void displayAvailableFlights(char* departureCity, char* arrivalCity) {
    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i].departureCity, departureCity) == 0 && strcmp(flights[i].arrivalCity, arrivalCity) == 0 && flights[i].availableSeats > 0) {
            printf("Flight Number: %s\nDeparture: %s\nArrival: %s\nDeparture Time: %s\nArrival Time: %s\nAvailable Seats: %d\n",
                   flights[i].flightNumber, flights[i].departureCity, flights[i].arrivalCity, flights[i].departureTime, flights[i].arrivalTime, flights[i].availableSeats);
        }
    }
}

void updateFlightDetails(char* flightNumber, char* departureTime, char* arrivalTime, int availableSeats) {
    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i].flightNumber, flightNumber) == 0) {
            strcpy(flights[i].departureTime, departureTime);
            strcpy(flights[i].arrivalTime, arrivalTime);
            flights[i].availableSeats = availableSeats;
            printf("Flight details updated.\n");
            return;
        }
    }
    printf("Flight not found.\n");
}

int main() {
    addFlight("AA123", "New York", "Los Angeles", "08:00", "11:00", 10);
    addFlight("BA456", "Chicago", "Miami", "09:30", "13:00", 5);
    bookSeat("AA123");
    displayAvailableFlights("New York", "Los Angeles");
    updateFlightDetails("AA123", "08:30", "11:30", 9);
    return 0;
}

