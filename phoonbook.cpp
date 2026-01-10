// Had to add stuff because first output variant raped my eyesight TwT
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Abonent
{
private:
    string name;
    string worknumber;
    string homenumber;
    string mobilenumber;
    string desc;

public:
    static int count;

    Abonent(string n, string w, string h, string m, string d) : name(n), worknumber(w), homenumber(h), mobilenumber(m), desc(d)
    {
        count++;
    }
    Abonent() : Abonent("", "", "", "", "") {}
    Abonent(string n) : Abonent(n, "", "", "", "") {}
    Abonent(string n, string w) : Abonent(n, w, "", "", "") {}
    Abonent(string n, string w, string h) : Abonent(n, w, h, "", "") {}
    Abonent(string n, string w, string h, string m) : Abonent(n, w, h, m, "") {}

    void printInfo() const
    {
      // Added these separators here V
        cout << "-----------------------------" << endl;
        cout << "Name          : " << name << endl;
        cout << "Work Number   : " << worknumber << endl;
        cout << "Home Number   : " << homenumber << endl;
        cout << "Mobile Number : " << mobilenumber << endl;
        cout << "Description   : " << desc << endl;
        cout << "-----------------------------" << endl;
      // Added these separators here ^
    }

    string GetName() const { return name; }
    string GetWorkNumber() const { return worknumber; }
    string GetHomeNumber() const { return homenumber; }
    string GetMobileNumber() const { return mobilenumber; }
    string GetDesc() const { return desc; }

    ~Abonent() { count--; }
};

int Abonent::count = 0;

Abonent* SearchByName(const vector<Abonent>& abonents, const string& name)
{
    for (const auto& abonent : abonents)
        if (abonent.GetName() == name)
            return const_cast<Abonent*>(&abonent);
    return nullptr;
}

Abonent* SearchByWorkNumber(const vector<Abonent>& abonents, const string& worknumber)
{
    for (const auto& abonent : abonents)
        if (abonent.GetWorkNumber() == worknumber)
            return const_cast<Abonent*>(&abonent);
    return nullptr;
}

Abonent* SearchByHomeNumber(const vector<Abonent>& abonents, const string& homenumber)
{
    for (const auto& abonent : abonents)
        if (abonent.GetHomeNumber() == homenumber)
            return const_cast<Abonent*>(&abonent);
    return nullptr;
}

Abonent* SearchByMobileNumber(const vector<Abonent>& abonents, const string& mobilenumber)
{
    for (const auto& abonent : abonents)
        if (abonent.GetMobileNumber() == mobilenumber)
            return const_cast<Abonent*>(&abonent);
    return nullptr;
}

// It was pain in the ass to make this one work
string randomPhone()
{
    string number = "380";
    for (int i = 0; i < 9; i++)
        number += to_string(rand() % 10);
    return number;
}

void FillRandomly(vector<Abonent>& abonents, int n)
{
    for (int i = 0; i < n; i++)
    {
        string name = "Name" + to_string(i);
        string work = randomPhone();
        string home = randomPhone();
        string mobile = randomPhone();
        string desc = "Random desc";
        abonents.push_back(Abonent(name, work, home, mobile, desc));
    }
}

int main()
{
    srand(time(NULL));
    bool active = true;
    vector<Abonent> abonents;

    FillRandomly(abonents, 10);

    while (active)
    {
      // Added these separators here V
        cout << "\n===== PHONEBOOK MENU =====\n";
        cout << "1. Search by Name\n";
        cout << "2. Search by Work Number\n";
        cout << "3. Search by Home Number\n";
        cout << "4. Search by Mobile Number\n";
        cout << "5. Delete by Name\n";
        cout << "6. Exit\n";
        cout << "Choose an option: ";
        int choice;
        cin >> choice;

        Abonent* found = nullptr;

        if (choice == 1)
        {
            string name;
            cout << "Enter Name: ";
            cin >> name;
            found = SearchByName(abonents, name);
        }
        else if (choice == 2)
        {
            string worknumber;
            cout << "Enter Work Number: ";
            cin >> worknumber;
            found = SearchByWorkNumber(abonents, worknumber);
        }
        else if (choice == 3)
        {
            string homenumber;
            cout << "Enter Home Number: ";
            cin >> homenumber;
            found = SearchByHomeNumber(abonents, homenumber);
        }
        else if (choice == 4)
        {
            string mobilenumber;
            cout << "Enter Mobile Number: ";
            cin >> mobilenumber;
            found = SearchByMobileNumber(abonents, mobilenumber);
        }
        else if (choice == 5)
        {
            string name;
            cout << "Enter Name to delete: ";
            cin >> name;
            abonents.erase(remove_if(abonents.begin(), abonents.end(),
                [&name](const Abonent& a) { return a.GetName() == name; }),
                abonents.end());
            cout << "Deleted if existed." << endl;
        }
        else if (choice == 6)
        {
            active = false;
        }

        if (found)
        {
          // Added these separators here V
            cout << "\n+++ Abonent Found +++" << endl;
            found->printInfo();
        }
        else if (choice >= 1 && choice <= 4 && !found)
        {
            cout << "\n--- Not Found ---" << endl;
          // Added these separators here ^
        }
    }
}

// Ty <3
