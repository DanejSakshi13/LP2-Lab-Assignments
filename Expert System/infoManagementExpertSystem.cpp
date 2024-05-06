#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Document {
public:
    string name;
    string type;

    Document(string name, string type) {
        this->name = name;
        this->type = type;
    }
};

class InformationManagement {
public:
    vector<Document> documents;

    void addDocument(string name, string type) {
        Document doc(name, type);
        documents.push_back(doc);
    }

    void searchDocuments(string query) {
        cout << "Search Results for '" << query << "':" << endl;
        for (size_t i = 0; i < documents.size(); ++i) {
            if (documents[i].name.find(query) != string::npos || documents[i].type.find(query) != string::npos) {
                cout << "- " << documents[i].name << " (" << documents[i].type << ")" << endl;
            }
        }
    }
};

int main() {
    InformationManagement infoSystem;

    // Add sample documents
    infoSystem.addDocument("Research Paper on AI", "Research");
    infoSystem.addDocument("Annual Report 2023", "Financial");
    infoSystem.addDocument("Employee Handbook", "Policy");

    cout << "Welcome to the Information Management System!" << endl;

    char choice;
    do {
        cout << "\nWhat would you like to do?" << endl;
        cout << "1. Search for a document" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case '1': {
                string query;
                cout << "Enter your search query: ";
                cin >> query;
                infoSystem.searchDocuments(query);
                break;
            }
            case '2': {
                cout << "Exiting the Information Management System..." << endl;
                break;
            }
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != '2');

    return 0;
}
