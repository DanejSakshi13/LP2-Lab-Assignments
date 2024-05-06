#include <iostream>
#include <string>

using namespace std;

const int MAX_FLIGHTS = 100;
const int MAX_CARGO = 100;

class AirlineScheduler {
private:
    struct Flight {
        string flightNumber;
        string origin;
        string destination;
        string departureTime;
        string arrivalTime;
    };

    struct Cargo {
        string cargoId;
        string origin;
        string destination;
        string departureTime;
        string arrivalTime;
    };

    Flight flights[MAX_FLIGHTS];
    Cargo cargo[MAX_CARGO];
    int flightCount = 0;
    int cargoCount = 0;

public:
    void scheduleFlight(string flightNumber, string origin, string destination, string departureTime, string arrivalTime) {
        if (flightCount < MAX_FLIGHTS) {
            flights[flightCount++] = {flightNumber, origin, destination, departureTime, arrivalTime};
            cout << "Flight " << flightNumber << " scheduled successfully." << endl;
        } else {
            cout << "Maximum number of flights reached." << endl;
        }
    }

    void scheduleCargo(string cargoId, string origin, string destination, string departureTime, string arrivalTime) {
        if (cargoCount < MAX_CARGO) {
            cargo[cargoCount++] = {cargoId, origin, destination, departureTime, arrivalTime};
            cout << "Cargo " << cargoId << " scheduled successfully." << endl;
        } else {
            cout << "Maximum number of cargo schedules reached." << endl;
        }
    }

    void displayFlights() {
        cout << "Scheduled Flights:" << endl;
        for (int i = 0; i < flightCount; ++i) {
            cout << "Flight Number: " << flights[i].flightNumber << ", Origin: " << flights[i].origin << ", Destination: " << flights[i].destination << endl;
        }
    }

    void displayCargo() {
        cout << "Scheduled Cargo:" << endl;
        for (int i = 0; i < cargoCount; ++i) {
            cout << "Cargo ID: " << cargo[i].cargoId << ", Origin: " << cargo[i].origin << ", Destination: " << cargo[i].destination << endl;
        }
    }
};

int main() {
    AirlineScheduler scheduler;

    // Schedule flights
    scheduler.scheduleFlight("F001", "New York", "London", "10:00", "14:00");
    scheduler.scheduleFlight("F002", "Paris", "Tokyo", "15:00", "10:00");

    // Schedule cargo
    scheduler.scheduleCargo("C001", "Shanghai", "Los Angeles", "08:00", "18:00");
    scheduler.scheduleCargo("C002", "Chicago", "Sydney", "12:00", "08:00");

    // Display scheduled flights and cargo
    scheduler.displayFlights();
    scheduler.displayCargo();

    return 0;
}
