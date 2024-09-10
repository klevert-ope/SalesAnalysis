#include "DataParser.h"
#include "SalesAnalysis.h"
#include <iostream>
#include <iomanip>
#include <limits>

// ANSI color codes
const std::string RESET = "\033[0m";
const std::string BOLD = "\033[1m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";

// Helper function to print a formatted header
void printHeader(const std::string& title) {
    std::cout << "\n" << BOLD << MAGENTA << "========================" << RESET << std::endl;
    std::cout << BOLD << CYAN << title << RESET << std::endl;
    std::cout << BOLD << MAGENTA << "========================" << RESET << std::endl;
}

// Helper function to print an error message
void printError(const std::string& message) {
    std::cerr << RED << BOLD << "Error: " << message << RESET << std::endl;
}

int main() {
    std::vector<SalesRecord> records = DataParser::parseCSV("C:/Users/HomePC/CLionProjects/SalesAnalysis/data/orders_superstore.csv");

    if (records.empty()) {
        printError("No data loaded or file could not be parsed!");
        return 1;
    }

    int choice;
    do {
        printHeader("Select an Analysis Option");
        std::cout << "1. Total Sales\n";
        std::cout << "2. Total Profit\n";
        std::cout << "3. Compare Sales by Region\n";
        std::cout << "4. Compare Sales by Category\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Check if input is valid integer
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            printError("Invalid input. Please enter a number.");
            continue;
        }

        // Handle user's choice
        switch (choice) {
            case 1:
                std::cout << GREEN << std::fixed << std::setprecision(2)
                          << "Total Sales: $" << SalesAnalysis::calculateTotalSales(records) << RESET << std::endl;
                break;
            case 2:
                std::cout << GREEN << std::fixed << std::setprecision(2)
                          << "Total Profit: $" << SalesAnalysis::calculateTotalProfit(records) << RESET << std::endl;
                break;
            case 3:
                SalesAnalysis::compareSalesByRegion(records);
                break;
            case 4:
                SalesAnalysis::compareSalesByCategory(records);
                break;
            case 0:
                std::cout << YELLOW << "Exiting program." << RESET << std::endl;
                break;
            default:
                printError("Invalid choice. Please enter a number between 0 and 4.");
        }
    } while (choice != 0);

    return 0;
}
