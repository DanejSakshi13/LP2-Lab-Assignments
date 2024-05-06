#include <iostream>
#include <string>

using namespace std;

const int MAX_TICKETS = 100;

class HelpDesk {
public:
    string ticketIds[MAX_TICKETS];
    string ticketDescriptions[MAX_TICKETS];
    string ticketStatuses[MAX_TICKETS];
    int numTickets;

    HelpDesk() {
        numTickets = 0;
    }

    void createTicket(string ticketId, string description) {
        if (numTickets < MAX_TICKETS) {
            ticketIds[numTickets] = ticketId;
            ticketDescriptions[numTickets] = description;
            ticketStatuses[numTickets] = "Open";
            numTickets++;
            cout << "Ticket created successfully." << endl;
        } else {
            cout << "Maximum number of tickets reached." << endl;
        }
    }

    void closeTicket(string ticketId) {
        for (int i = 0; i < numTickets; ++i) {
            if (ticketIds[i] == ticketId) {
                ticketStatuses[i] = "Closed";
                cout << "Ticket " << ticketId << " closed successfully." << endl;
                return;
            }
        }
        cout << "Ticket not found." << endl;
    }

    void displayTicketStatus(string ticketId) {
        for (int i = 0; i < numTickets; ++i) {
            if (ticketIds[i] == ticketId) {
                cout << "Ticket " << ticketId << " is " << ticketStatuses[i] << endl;
                return;
            }
        }
        cout << "Ticket not found." << endl;
    }
};

int main() {
    HelpDesk helpDesk;

    // Create tickets
    helpDesk.createTicket("T001", "Computer not starting");
    helpDesk.createTicket("T002", "Printer not working");

    // Display ticket status
    helpDesk.displayTicketStatus("T001");
    helpDesk.displayTicketStatus("T002");

    // Close ticket
    helpDesk.closeTicket("T001");
    helpDesk.displayTicketStatus("T001");

    return 0;
}
