// pls grade it high :3
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Abonent
{
private:
    string FLnames;
    string HomeNumber;
    string MobileNumber;
    string WorkNumber;
    string Description;
    static int abonent_count;

public:
    // Constructors
    Abonent() : FLnames(""), HomeNumber(""), MobileNumber(""), WorkNumber(""), Description("") { abonent_count++; }
    Abonent(string flnames) : FLnames(flnames), HomeNumber(""), MobileNumber(""), WorkNumber(""), Description("") { abonent_count++; }
	Abonent(string flnames, string homenumber) : FLnames(flnames), HomeNumber(homenumber), MobileNumber(""), WorkNumber(""), Description("") { abonent_count++; }
	Abonent(string flnames, string homenumber, string mobilenumber) : FLnames(flnames), HomeNumber(homenumber), MobileNumber(mobilenumber), WorkNumber(""), Description("") { abonent_count++; }
	Abonent(string flnames, string homenumber, string mobilenumber, string worknumber) : FLnames(flnames), HomeNumber(homenumber), MobileNumber(mobilenumber), WorkNumber(worknumber), Description("") { abonent_count++; }
    Abonent(string flnames, string homenumber, string mobilenumber, string worknumber, string description) : FLnames(flnames), HomeNumber(homenumber), MobileNumber(mobilenumber), WorkNumber(worknumber), Description(description) { abonent_count++; }
    // Destructor
    ~Abonent() { abonent_count--; }
    // Getters
    static int getAbonentCount() { return abonent_count; }
    string getFLnames() const { return FLnames; }
    string getHomeNumber() const { return HomeNumber; }
    string getMobileNumber() const { return MobileNumber; }
    string getWorkNumber() const { return WorkNumber; }
    string getDescription() const { return Description; }
    // Setters
    void setFLnames(const string& flnames) { FLnames = flnames; }
    void setHomeNumber(const string& homenumber) { HomeNumber = homenumber; }
    void setMobileNumber(const string& mobilenumber) { MobileNumber = mobilenumber; }
    void setWorkNumber(const string& worknumber) { WorkNumber = worknumber; }
    void setDescription(const string& description) { Description = description; }
	// Print method
    void Print() const {
        cout << "---------------------\n";
        cout << "Name        : " << FLnames << endl;
        cout << "Home phone  : " << HomeNumber << endl;
        cout << "Mobile phone: " << MobileNumber << endl;
        cout << "Work phone  : " << WorkNumber << endl;
        cout << "Description : " << Description << endl;
    }
};

int Abonent::abonent_count = 0;

class PhoneBook
{
private:
    vector<Abonent> abonents;

public:
    PhoneBook() = default;
    void Add()
    {
        string n, hn, mn, wn, d;
        cin.ignore();
        cout << "Enter full name >>> ";
        getline(cin, n);
        cout << "Enter home number >>> ";
        getline(cin, hn);
        cout << "Enter mobile number >>> ";
        getline(cin, mn);
        cout << "Enter work number >>> ";
        getline(cin, wn);
        cout << "Enter description >>> ";
        getline(cin, d);
        abonents.emplace_back(n, hn, mn, wn, d);
        cout << "Abonent added successfully.\n";
    }
    void Delete(const string& fullname)
    {
        auto oldSize = abonents.size();

        // Erase-Remove Idiom. DARE doubt my knowledge.
        abonents.erase(remove_if(abonents.begin(), abonents.end(), [&fullname](const Abonent& a) { return a.getFLnames() == fullname;}), abonents.end());

        if (abonents.size() < oldSize)
            cout << "Abonent deleted.\n";
        else
            cout << "Abonent not found.\n";
    }
    void SearchByName(const string& fullname) const
    {
        bool found = false;
        for (const auto& a : abonents) {
            if (a.getFLnames() == fullname) {
                a.Print();
                found = true;
            }
        }
        if (!found)
            cout << "Abonent not found.\n";
    }
    void SearchByPhoneNumber(const string& phonenumber) const
    {
        for (const auto& a : abonents) {
            if (a.getHomeNumber() == phonenumber ||
                a.getMobileNumber() == phonenumber ||
                a.getWorkNumber() == phonenumber)
            {
                a.Print();
                return;
            }
        }
        cout << "Abonent not found.\n";
    }
    void ShowAll() const
    {
        if (abonents.empty()) {
            cout << "PhoneBook is empty.\n";
            return;
        }

        for (const auto& a : abonents)
            a.Print();
    }
};
void Header(const string& title)
{
    cout << "\n========================================\n";
    cout << "   " << title << "\n";
    cout << "========================================\n";
}
void Menu()
{
    Header("PHONE BOOK MENU");
    cout << " [1] Add abonent\n";
    cout << " [2] Delete abonent\n";
    cout << " [3] Search by name\n";
    cout << " [4] Search by phone number\n";
    cout << " [5] Show all abonents\n";
    cout << " [0] Exit\n";
    cout << "----------------------------------------\n";
    cout << "Choose option >>> ";
}

void Loop()
{
    PhoneBook book;
    int choice;
    string input;

    while (true)
    {
        Menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            Header("ADD ABONENT");
            book.Add();
            break;

        case 2:
            Header("DELETE ABONENT");
            cin.ignore();
            cout << "Full name >>> ";
            getline(cin, input);
            book.Delete(input);
            break;

        case 3:
            Header("SEARCH BY NAME");
            cin.ignore();
            cout << "Full name >>> ";
            getline(cin, input);
            book.SearchByName(input);
            break;

        case 4:
            Header("SEARCH BY PHONE");
            cin.ignore();
            cout << "Phone number >>> ";
            getline(cin, input);
            book.SearchByPhoneNumber(input);
            break;

        case 5:
            Header("ALL ABONENTS");
            book.ShowAll();
            break;

        case 0:
            Header("EXIT");
            cout << "bb my nigga <3\n";
            return;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}

int main()
{
    Loop();
}
