#include<iostream>
#include<string>
using namespace std;

struct PhoneBookEntry {
    string name;
    string phoneNumber;
    PhoneBookEntry* next;

    PhoneBookEntry(string name, string phoneNumber) {
        this->name = name;
        this->phoneNumber = phoneNumber;
        next = nullptr;
    }
};

class HashTable {
private:
    static const int TABLE_SIZE = 10;   //size of hash table
    PhoneBookEntry* table[TABLE_SIZE];

    int hashFunction(string name) {
        int hash = 0;
        for (char c: name) {
            hash += c;
        }
        return hash % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    void insert(string name, string phoneNumber) {
        int index = hashFunction(name);
        PhoneBookEntry* newEntry = new PhoneBookEntry(name, phoneNumber);

        if(table[index] == nullptr) {
            table[index] = newEntry;
        } else {
            PhoneBookEntry* current = table[index];
            while(current->next != nullptr) {
                current = current->next;
            }
            current->next = newEntry;
        }
    }

    string lookup(string name) {
        int index = hashFunction(name);
        PhoneBookEntry* current = table[index];

        while(current != nullptr) {
            if(current->name == name) {
                return current->phoneNumber;
            }
            current = current->next;
        }

        return "Name not found!";
    }

    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            PhoneBookEntry* current = table[i];
            while (current != nullptr) {
                PhoneBookEntry* toDelete = current;
                current = current->next;
                delete toDelete;
            }
        }
    }
};

int main() {
    HashTable phoneBook;

    // Insert some entries
    phoneBook.insert("Alice", "123-456-7890");
    phoneBook.insert("Bob", "234-567-8901");
    phoneBook.insert("Charlie", "345-678-9012");

    // Lookup phone numbers
    cout << "Alice's phone number: " << phoneBook.lookup("Alice") << endl;
    cout << "Bob's phone number: " << phoneBook.lookup("Bob") << endl;
    cout << "Eve's phone number: " << phoneBook.lookup("Eve") << endl;

    return 0;
}