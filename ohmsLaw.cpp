// Copyright Carolyn
// Created by: Carolyn Webster Pless
// Created on: 22/12/09
// Gets the user input for the type of calculation (voltage, resistance,
// or current) they would like to perform. Then, gets the user input
// Depending on the type of calculation. Uses a function and return
// Values to calculate the voltage/current/resistance. This is then
// Displayed back to the user in main().

#include <cctype>
#include <iostream>

// To calculate ohms law
float CalculateOhmsLaw(std::string typeOfCalculation,
float resistance, float current, float voltage) {
    // variable for the answer which will be returned
    float answer;

    // IF ELSE to calculate the answer based on the type of calculation
    if (typeOfCalculation == "voltage") {
        answer = resistance * current;
    } else if (typeOfCalculation == "resistance") {
        answer = voltage / current;
    } else {
        answer = voltage / resistance;
    }
    return answer;
}

int main() {
    // Variables
    std::string voltageString, resistanceString, currentString;
    std::string typeOfCalculationUser;
    float userVoltage, userResistance, userCurrent, answer;

    // Title of the program
    std::cout << "Ohms law Calculator\n";

    // User input for the type of calculation
    std::cout <<
    "Enter the type of calculation (voltage, resistance, or current): ";
    std::cin >> typeOfCalculationUser;

    // If the calculation is voltage
    if (typeOfCalculationUser == "voltage") {
        // User inputs
        std::cout << "Enter the resistance: ";
        std::cin >> resistanceString;
        std::cout << "Enter the current: ";
        std::cin >> currentString;
        // Try Catch to make sure the inputs are floats
        try {
            userResistance = stof(resistanceString);
            userCurrent = stof(currentString);
            // IF ELSE to make sure the inputs are positive
            if (userResistance < 0 || userCurrent < 0) {
                std::cout << "Please enter a positive number!\n";
            } else {
                // Calling the function and displaying the answer
                answer = CalculateOhmsLaw(typeOfCalculationUser,
                userResistance, userCurrent, userVoltage);
                std::cout << "The voltage of a circuit with resistance "
                << userResistance << "R And current " << userCurrent <<
                "Ω is " << answer << "V\n";
            }
        } catch (std::invalid_argument) {
            std::cout << "Please enter a valid number! \n";
        }

    // If the calculation is resistance
    } else if (typeOfCalculationUser == "resistance") {
        // User Inputs
        std::cout << "Enter the voltage: ";
        std::cin >> voltageString;
        std::cout << "Enter the current: ";
        std::cin >> currentString;
        // Try Catch to make sure the inputs are floats
        try {
            userVoltage = stof(voltageString);
            userCurrent = stof(currentString);
            // IF ELSE to make sure the inputs are positive
            if (userVoltage < 0 || userCurrent < 0) {
                std::cout << "Please enter a positive number!\n";
            } else {
                // Calling the function and displaying the answer
                answer = CalculateOhmsLaw(typeOfCalculationUser,
                userResistance, userCurrent, userVoltage);
                std::cout << "The resistance of a circuit with voltage "
                << userVoltage<< "V And current " << userCurrent << "Ω is "
                << answer << "R\n";
            }
        } catch (std::invalid_argument) {
            std::cout << "Please enter a valid number! \n";
        }
    // If the calculation is current
    } else if (typeOfCalculationUser == "current") {
        // User inputs
        std::cout << "Enter the voltage: ";
        std::cin >> voltageString;
        std::cout << "Enter the resistance: ";
        std::cin >> resistanceString;
        // TRY CATCH to make sure the inputs are floats
        try {
            userResistance = stof(resistanceString);
            userVoltage = stof(voltageString);
            // IF ELSE to make sure the inputs are positive
            if (userResistance < 0 || userVoltage < 0) {
                std::cout << "Please enter a positive number!\n";
            // Calling the function and displaying the answer
            } else {
                answer = CalculateOhmsLaw(typeOfCalculationUser,
                userResistance, userCurrent, userVoltage);
                std::cout << "The current of a circuit with voltage "
                          << userVoltage << "V and resistance " <<
                          userResistance << "R is " << answer << "Ω\n";
            }
        } catch (std::invalid_argument) {
            std::cout << "Please enter a valid number! \n";
        }
    } else {
        std::cout << "Please enter voltage, resistance, or current!\n";
    }
}
