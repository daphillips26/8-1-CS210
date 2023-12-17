/*
Clocks Code
Name: Donnell Phillips
Date: 11/12/23
*/

#include <iostream>
#include <string>
using namespace std;

// Turns int into a two digit string 9 -> "09"
std::string twoDigitString(unsigned int n) {
    // Ensure that n is not greater than 59
    n = std::min(n, 59u);

    // Use the conditional operator to check if n is less than 10
    // If true, add a leading 0, otherwise convert n to a string directly
    return (n < 10) ? "0" + std::to_string(n) : std::to_string(n);
}

std::string nCharString(size_t n, char c) {
    // Ensure that n is not negative
    if (n < 0) {
        return "";
    }

    // Declare and initialize a string variable
    std::string result;

    // Append n copies of the character c to the string
    for (size_t i = 0; i < n; ++i) {
        result += c;
    }

    // Return the resulting string
    return result;
}

// Function to format time to 24-hour clock time
std::string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    // Ensure that hours, minutes, and seconds are within valid ranges
    h = std::min(h, 23u);
    m = std::min(m, 59u);
    s = std::min(s, 59u);

    // Use twoDigitString function to format each component
    std::string formattedTime = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);

    return formattedTime;
}

std::string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    // Ensure that hours, minutes, and seconds are within valid ranges
    h = std::min(h, 23u);
    m = std::min(m, 59u);
    s = std::min(s, 59u);

    std::string period = "AM";
    if (h >= 12) {
        period = "PM";
        if (h > 12) {
            h = h - 12;
        }
    }
    else if (h == 0) {
        h = 12;
    }

    // Use twoDigitString function to format each component
    std::string formattedTime = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " " + period;

    return formattedTime;
}

void printMenu() {
    std::cout << "***********************" << std::endl;
    std::cout << "* 1 - Add One Hour    *" << std::endl;
    std::cout << "* 2 - Add One Minute  *" << std::endl;
    std::cout << "* 3 - Add One Second  *" << std::endl;
    std::cout << "* 4 - Exit Program    *" << std::endl;
    std::cout << "***********************" << std::endl;
}

void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
    std::cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << std::endl;
    std::cout << "*      12-HOUR CLOCK      *";
    std::cout << nCharString(3, ' ');
    std::cout << "*      24-HOUR CLOCK      *";
    std::cout << std::endl;
    std::cout << "*       " << formatTime12(h, m, s) << "       *";
    std::cout << nCharString(3, ' ');
    std::cout << "*         " << formatTime24(h, m, s) << "        *";
    std::cout << std::endl;
    std::cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << std::endl;
}


// Global Variables
unsigned int currentHour;
unsigned int currentMinute;
unsigned int currentSecond;

// Get Functions
unsigned int getHour() {
    return currentHour;
}

unsigned int getMinute() {
    return currentMinute;
}

unsigned int getSecond() {
    return currentSecond;
}

// Set Functions
void setHour(unsigned int h) {
    // Ensure the input value is valid (0 to 23)
    currentHour = h % 24;
}

void setMinute(unsigned int m) {
    // Ensure the input value is valid (0 to 59)
    currentMinute = m % 60;
}

void setSecond(unsigned int s) {
    // Ensure the input value is valid (0 to 59)
    currentSecond = s % 60;
}


//Adds one hour
void addOneHour() {

    // Check the value of getHour()
    unsigned int currentHour = getHour();

    // If getHour() is between 0 and 22 (inclusive), add 1 to the hour and call setHour() with the new value
    if (currentHour >= 0 && currentHour <= 22) {
        setHour(currentHour + 1);
    }
    else if (currentHour == 23) {
        // If getHour() is 23, set the next value for hour to 0
        setHour(0);
    }

    // nothing to return, just setHour to the appropriate value
}

//Adds one minute
void addOneMinute() {

     // Check the value of getMinute()
    unsigned int currentMinute = getMinute();

    // If getMinute() is between 0 and 58 (inclusive), add 1 to it and call setMinute() with the new value
    if (currentMinute >= 0 && currentMinute < 59) {
        setMinute(currentMinute + 1);
    }
    else if (currentMinute == 59) {
        // If getMinute() is 59, set minutes to 0 and call addOneHour()
        setMinute(0);
        addOneHour();
    }

    // nothing to return, just setMinute to the appropriate value and use addOneHour if needed
}

//Adds one second
void addOneSecond() {
    
     // Check the value of getSecond()
    unsigned int currentSecond = getSecond();

    // If getSecond() is between 0 and 58 (inclusive), add 1 to it and call setSecond() with the new value
    if (currentSecond >= 0 && currentSecond < 59) {
        setSecond(currentSecond + 1);
    }
    else if (currentSecond == 59) {
        // If getSecond() is 59, set seconds to 0 and call addOneMinute()
        setSecond(0);
        addOneMinute();
    }

    // nothing to return, just call setSecond() with the right value and addOneMinute() when needed
}


int main() {
    // Get user input for the initial time
    cout << "Enter initial time (format: HH MM SS): ";
    unsigned int initialHour, initialMinute, initialSecond;
    cin >> initialHour >> initialMinute >> initialSecond;

    // Set initial time
    setHour(initialHour);
    setMinute(initialMinute);
    setSecond(initialSecond);

    // Display time with both 12 and 24-hour clocks
    displayClocks(getHour(), getMinute(), getSecond());

    // Display menu
    printMenu();

    // Loop to handle user input
    while (true) {
        // Get user input for menu option
        cout << "Enter menu option (1-4): ";
        int menuInput;
        cin >> menuInput;

        // Perform actions based on user input
        switch (menuInput) {
        case 1:
            // Run the add hour function
            addOneHour();
            break;
        case 2:
            // Run the add minutes function
            addOneMinute();
            break;
        case 3:
            // Run the add second function
            addOneSecond();
            break;
        case 4:
            // Ask the user if they want to exit
            cout << "Do you want to exit? (y/n): ";
            char exitChoice;
            cin >> exitChoice;
            if (exitChoice == 'y' || exitChoice == 'Y') {
                cout << "The End" << endl;
                return 0;  // Exit the program
            }
            break;
        default:
            cout << "Invalid menu option. Please try again." << endl;
            break;
        }

        // Display clocks and menu again
        displayClocks(getHour(), getMinute(), getSecond());
        printMenu();
    }

    return 0;
}
