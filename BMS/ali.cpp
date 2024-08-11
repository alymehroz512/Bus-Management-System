#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class Bus {
public:
    int bus_no;
    int seat[32] = {0}; // Initialize all seats to 0 (empty)
    string arrival_time;
    string departure_time;
    string driver_name;
    string from;
    string to;

    void install();
    void reserveSeat();
    void showBusData();
    void displaySeats();
};

vector<Bus> buses;

void line() {
    for (int j = 0; j <= 79; j++)
        cout << "-";
    cout << endl;
}

void Bus::install() {
    cout << "\nEnter Bus no: ";
    cin >> bus_no;
    cout << "\nEnter Driver name: ";
    cin >> driver_name;
    cout << "\nEnter Arrival time: ";
    cin >> arrival_time;
    cout << "\nEnter Departure time: ";
    cin >> departure_time;
    cout << "\nTravelling from: ";
    cin >> from;
    cout << "\nTravelling to: ";
    cin >> to;
}

void Bus::reserveSeat() {
    int seat_number;
    cout << "\nEnter Seat number (1-32): ";
    cin >> seat_number;

    if (seat_number < 1 || seat_number > 32) {
        cout << "\nInvalid seat number. Try again.";
        return;
    }

    if (seat[seat_number - 1] == 0) {
        cout << "\nEnter Passenger name: ";
        cin >> seat[seat_number - 1];
        cout << "\n\t\t\tYour seat is booked!" << endl;
    } else {
        cout << "\nSeat already booked. Try another seat.";
    }
}

void Bus::showBusData() {
    line();
    cout << "\nBus no:\t" << bus_no
         << "\nDriver:\t" << driver_name
         << "\tArrival time:\t" << arrival_time
         << "\tDeparture time:\t" << departure_time
         << "\nFrom:\t" << from
         << "\tTo:\t" << to << endl;
    line();
}

void Bus::displaySeats() {
    line();
    for (int k = 0; k < 32; k++) {
        if (seat[k] != 0) {
            cout << k + 1 << "." << "Booked" << setw(4);
        } else {
            cout << k + 1 << ".Empty" << setw(4);
        }
    }
    line();
}

int main() {
    int choice;
    do {
        cout << "\t---WELCOME TO BUS RESERVATION SYSTEM---\n";
        cout << "\t\t\t1. Install\n"
             << "\t\t\t2. Reservation\n"
             << "\t\t\t3. Your Data\n"
             << "\t\t\t4. Display Seats\n"
             << "\t\t\t5. Exit\n"
             << "\t\t\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Bus newBus;
            newBus.install();
            buses.push_back(newBus);
            break;
        }
        case 2: {
            int bus_no;
            cout << "\nEnter the bus number you want to book: ";
            cin >> bus_no;
            bool found = false;
            for (auto &bus : buses) {
                if (bus.bus_no == bus_no) {
                    bus.reserveSeat();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "\nBus number not found. Try again.";
            }
            break;
        }
        case 3: {
            int bus_no;
            cout << "\nEnter the bus number: ";
            cin >> bus_no;
            bool found = false;
            for (auto &bus : buses) {
                if (bus.bus_no == bus_no) {
                    bus.showBusData();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "\nBus number not found. Try again.";
            }
            break;
        }
        case 4: {
            int bus_no;
            cout << "\nEnter the bus number: ";
            cin >> bus_no;
            bool found = false;
            for (auto &bus : buses) {
                if (bus.bus_no == bus_no) {
                    bus.displaySeats();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "\nBus number not found. Try again.";
            }
            break;
        }
        case 5:
            cout << "\nExiting the system.";
            break;
        default:
            cout << "\nInvalid choice. Try again.";
        }
    } while (choice != 5);

    return 0;
}
