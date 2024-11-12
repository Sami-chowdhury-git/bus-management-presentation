#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
    #define Sleep(ms) usleep((ms) * 1000)
#endif

#define MAX_SEATS 32
#define ROUTE_COUNT 2
#define BUS_COUNT 5

// Defining buses for each route
char routeNames[ROUTE_COUNT][50] = {
    "Sylhet to Dhaka",
    "Sylhet to Chittagong"
};

char busNames[ROUTE_COUNT][BUS_COUNT][50] = {
    {"Green Line Dhaka", "Hanif Enterprise Dhaka", "Shyamoli Paribahan Dhaka", "Shohag Paribahan Dhaka", "Ena Transport Dhaka"},
    {"Green Line Chittagong", "Hanif Enterprise Chittagong", "Shyamoli Paribahan Chittagong", "Shohag Paribahan Chittagong", "Ena Transport Chittagong"}
};

char passengerNames[ROUTE_COUNT][BUS_COUNT][MAX_SEATS][50] = { '\0' };
int seatAvailability[ROUTE_COUNT][BUS_COUNT] = {
    { MAX_SEATS, MAX_SEATS, MAX_SEATS, MAX_SEATS, MAX_SEATS },
    { MAX_SEATS, MAX_SEATS, MAX_SEATS, MAX_SEATS, MAX_SEATS }
};

void login();
void viewBusList(int route, int showPrompt);
void bookTickets();
void viewBusStatus();
void cancelBooking();
int selectRoute();

int main() {
    login();
    int choice;

    do {
        system("cls");
        printf("========== BUS MANAGEMENT SYSTEM ==========\n\n");
        printf("1. View Bus List\n");
        printf("2. Book Tickets\n");
        printf("3. View Bus Status\n");
        printf("4. Cancel Booking\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewBusList(selectRoute(), 1);
                break;
            case 2:
                bookTickets();
                break;
            case 3:
                viewBusStatus();
                break;
            case 4:
                cancelBooking();
                break;
            case 5:
                printf("Thank you for using the Bus Management System.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                Sleep(1000);
        }
    } while (choice != 5);

    return 0;
}

void login() {
    char username[10], password[10], c = ' ';
    int attempts = 0;

    do {
        system("cls");
        printf("========== LOGIN ==========\n");
        printf("Username: ");
        scanf("%s", username);

        printf("Password: ");
        int i = 0;
        while (i < 10) {
            password[i] = getch();
            c = password[i];
            if (c == 13) break;
            else printf("*");
            i++;
        }
        password[i] = '\0';

        if (strcmp(username, "sami") == 0 && strcmp(password, "project") == 0) {
            printf("\n\nLogin successful!");
            Sleep(1000);
            break;
        } else {
            printf("\n\nIncorrect username or password. Try again.");
            attempts++;
            Sleep(1000);
        }
    } while (attempts < 3);

    if (attempts >= 3) {
        printf("\nToo many failed attempts! Exiting...\n");
        exit(1);
    }
}

int selectRoute() {
    int routeChoice;
    printf("Select Route:\n");
    for (int i = 0; i < ROUTE_COUNT; i++) {
        printf("%d. %s\n", i + 1, routeNames[i]);
    }
    printf("Enter your choice: ");
    scanf("%d", &routeChoice);
    return routeChoice - 1;
}

void viewBusList(int route, int showPrompt) {
    system("cls");
    printf("========== %s BUS LIST ==========\n", routeNames[route]);
    for (int i = 0; i < BUS_COUNT; i++) {
        printf("%d. %s\n", i + 1, busNames[route][i]);
    }

    if (showPrompt) {
        printf("\nPress any key to return to the main menu...");
        fflush(stdin);
        getch();
    }
}

void bookTickets() {
    int route = selectRoute();
    int busNumber, seatNumber, ticketPrice, seatsToBook;
    char passengerName[50];

    if (route < 0 || route >= ROUTE_COUNT) {
        printf("Invalid route selection!\n");
        Sleep(1000);
        return;
    }

    system("cls");
    viewBusList(route, 0);
    printf("\nSelect a bus by number: ");
    scanf("%d", &busNumber);

    if (busNumber < 1 || busNumber > BUS_COUNT) {
        printf("Invalid bus selection!\n");
        Sleep(1000);
        return;
    }

    busNumber -= 1;
    ticketPrice = (route == 0) ? 200 : 400;

    printf("Enter the number of tickets to book: ");
    scanf("%d", &seatsToBook);

    if (seatsToBook > seatAvailability[route][busNumber]) {
        printf("Not enough seats available! Only %d seats left.\n", seatAvailability[route][busNumber]);
        Sleep(2000);
        return;
    }

    for (int i = 0; i < seatsToBook; i++) {
        printf("Enter seat number to book (1-%d): ", MAX_SEATS);
        scanf("%d", &seatNumber);

        if (seatNumber < 1 || seatNumber > MAX_SEATS) {
            printf("Invalid seat number!\n");
            Sleep(1000);
            i--; // Repeat the current seat input
            continue;
        }

        if (strlen(passengerNames[route][busNumber][seatNumber - 1]) != 0) {
            printf("Seat %d is already booked! Choose another seat.\n", seatNumber);
            Sleep(2000);
            i--; // Repeat the current seat input
            continue;
        }

        printf("Enter your name for seat %d: ", seatNumber);
        scanf("%s", passengerName);

        strcpy(passengerNames[route][busNumber][seatNumber - 1], passengerName);
        seatAvailability[route][busNumber]--;

        printf("Seat %d booked successfully!\n", seatNumber);
    }

    printf("\nTotal price: %d Taka\n", ticketPrice * seatsToBook);
    Sleep(2000);
}

void viewBusStatus() {
    int route = selectRoute();
    int busNumber;

    if (route < 0 || route >= ROUTE_COUNT) {
        printf("Invalid route selection!\n");
        Sleep(1000);
        return;
    }

    system("cls");
    viewBusList(route, 0);
    printf("\nSelect a bus to view status by number: ");
    scanf("%d", &busNumber);

    if (busNumber < 1 || busNumber > BUS_COUNT) {
        printf("Invalid bus selection!\n");
        Sleep(1000);
        return;
    }

    busNumber -= 1;

    printf("========== SEAT STATUS for %s on %s ==========\n", busNames[route][busNumber], routeNames[route]);
    for (int i = 0; i < MAX_SEATS; i++) {
        if (strlen(passengerNames[route][busNumber][i]) == 0) {
            printf("Seat %d: Empty\n", i + 1);
        } else {
            printf("Seat %d: %s\n", i + 1, passengerNames[route][busNumber][i]);
        }
    }

    printf("\nPress any key to return to the main menu...");
    fflush(stdin);
    getch();
}

void cancelBooking() {
    int route = selectRoute();
    int busNumber, seatNumber, cancellationFee;

    if (route < 0 || route >= ROUTE_COUNT) {
        printf("Invalid route selection!\n");
        Sleep(1000);
        return;
    }

    system("cls");
    viewBusList(route, 0);
    printf("\nSelect a bus to cancel booking by number: ");
    scanf("%d", &busNumber);

    if (busNumber < 1 || busNumber > BUS_COUNT) {
        printf("Invalid bus selection!\n");
        Sleep(1000);
        return;
    }

    busNumber -= 1;
    cancellationFee = (route == 0) ? 200 : 400;

    printf("Enter the seat number to cancel: ");
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > MAX_SEATS || strlen(passengerNames[route][busNumber][seatNumber - 1]) == 0) {
        printf("Invalid or empty seat selection!\n");
        Sleep(1000);
        return;
    }

    printf("Booking for %s on seat %d has been canceled. Refund amount: %d Taka\n", passengerNames[route][busNumber][seatNumber - 1], seatNumber, cancellationFee);
    passengerNames[route][busNumber][seatNumber - 1][0] = '\0';
    seatAvailability[route][busNumber]++;

    printf("\nPress any key to return to the main menu...");
    fflush(stdin);
    getch();
}
