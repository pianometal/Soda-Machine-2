//    main.cpp
//    Soda Machine 2
//
//    Created by Kyle Lovely on 8/18/20.
//    Copyright © 2020 Kyle Lovely. All rights reserved.
//
//    CODING CHALLENGES
//
//    Write a program that presents the user w/ a choice of your 5 favorite beverages
//    (Coke, Water, Sprite, ... , Whatever).
//    Then allow the user to choose a beverage by entering a number 1-5.
//    Output which beverage they chose.
//
//    Soda Machine 2 is an upgraded version of my original Soda Machine
//
//    UPGRADES in 2.0
//
//    * The user now has a set amount of money and can purchase as many drinks as they want
//    provided they have sufficient funds. If they have insufficient funds, the program will exit with a code
//
//    * Drinks now cost money instead of being free.
//
//    * If the user has insufficient funds, the user is notified and the program ends.
//
//    * Program exit codes are provided at the end

#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>

using namespace std;

// DEFINITIONS

const string Stars {"**************************************"};
const string Welcome {"Welcome to the Super Beverage Machine!"};
const string BevSelection {"We have the following beverages on tap today:"};
const string Drink1 {"Cola"};
const string Drink2 {"Orange Soda"};
const string Drink3 {"Root Beer"};
const string Drink4 {"Iced Tea"};
const string Drink5 {"Lemonade"};

const double Drink1Cost {1.00};
const double Drink2Cost {0.75};
const double Drink3Cost {0.75};
const double Drink4Cost {0.50};
const double Drink5Cost {0.50};

double CustomerCurrency {3.00};

void Greeting();
void SuccessfulPurchase();
void MakingSelection();
void CantAfford();

// MAIN

int main(int argc, const char * argv[]) {
    
    cout << Stars << endl;
    cout << Welcome << endl;
    cout << Stars << endl;
    cout << endl;
    
    Greeting();
    
    SuccessfulPurchase();
    
    cout << endl;
    
    return 0;
}

// DEFINITIONS

void Greeting() {
    
    cout << BevSelection << endl;
    cout << endl;
    
    cout << fixed;
    cout << setprecision(2);
    
    cout << "1. " << Drink1 << " $" << Drink1Cost << endl;
    cout << "2. " << Drink2 << " $" << Drink2Cost << endl;
    cout << "3. " << Drink3 << " $" << Drink3Cost << endl;
    cout << "4. " << Drink4 << " $" << Drink4Cost << endl;
    cout << "5. " << Drink5 << " $" << Drink5Cost << endl;
    cout << "6. Exit" << endl;
    cout << endl;
    cout << "You have " "$" << CustomerCurrency << " to spend." << endl;
    cout << "Which one would you like?" << endl;
    cout << "(Enter a number 1-5) ";
    
    MakingSelection();
    
};

void SuccessfulPurchase() {
    
    // Drink 5 must be set as the least expensive choice
    
    if (CustomerCurrency < Drink5Cost) {
        CantAfford();
    }
    
    cout << "Enjoy!" << endl;
    cout << "You have $" << CustomerCurrency << " left to spend." << endl;
    cout << "Would you like to buy another drink?" << endl;
    cout << "1 = YES\n2 = NO" << endl;
    
    int AnotherDrink {};
    
    cin >> AnotherDrink;
    
    if (AnotherDrink == 1) {
        
        Greeting();
    }
    
    else
        
        cout << "Thank you, come again!" << endl;
        exit(2);
    
};

void MakingSelection() {
    
    bool IsValidSelection {false};
    
    int Selection {};
    
    cin >> Selection;
    
    cout << endl;
    
    do {
        
        if (Selection == 1) {
            CustomerCurrency = CustomerCurrency - Drink1Cost;
            cout << "One " << Drink1 << " coming right up!" << endl;
            IsValidSelection = true;
        }
        
        else if (Selection == 2) {
            CustomerCurrency = CustomerCurrency - Drink2Cost;
            cout << "One " << Drink2 << " coming right up!" << endl;
            IsValidSelection = true;
        }
        
        else if (Selection == 3) {
            CustomerCurrency = CustomerCurrency - Drink3Cost;
            cout << "One " << Drink3 << " coming right up!" << endl;
            IsValidSelection = true;
        }
        
        else if (Selection == 4) {
            CustomerCurrency = CustomerCurrency - Drink4Cost;
            cout << "One " << Drink4 << " coming right up!" << endl;
            IsValidSelection = true;
        }
            
        else if (Selection == 5) {
            CustomerCurrency = CustomerCurrency - Drink5Cost;
            cout << "One " << Drink5 << " coming right up!" << endl;
            IsValidSelection = true;
        }
    
        else {
            cout << "Enter a valid selection\n" << endl;
            cin.clear();
            cin.ignore(123, '\n');
            Greeting();
            
        }
        
    } while (IsValidSelection == false);
    
    SuccessfulPurchase();
    
};

void CantAfford() {
    
    cout << "Sorry, you don't have enough money for anything in this machine." << endl;
    
    exit(1);
    
};

// EXIT CODES

// CODE 1 - User does not have enough currency to purchase a drink

// CODE 2 - User declined to purchase another drink when prompted
