#include "DataParser.h"
#include "SalesAnalysis.h"
#include <iostream>
#include <limits>
#include <vector>

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
    // Load sales data from CSV file
    std::vector<SalesRecord> records = DataParser::parseCSV("C:/Users/HomePC/CLionProjects/SalesAnalysis/data/orders_superstore.csv");

    if (records.empty()) {
        printError("No data loaded or file could not be parsed!");
        return 1;
    }

    int choice;
    do {
        printHeader("Select an Analysis Option");
        std::cout << "1. Analyze Sales by Customer Segment\n";
        std::cout << "2. Analyze Sales Trends by Year\n";
        std::cout << "3. Analyze Discount Impact\n";
        std::cout << "4. Calculate Profit Margins by Category\n";
        std::cout << "5. Analyze Sales by Shipping Mode\n";
        std::cout << "6. Analyze Customer Loyalty (Orders per Customer)\n";
        std::cout << "7. Calculate Sales Growth\n";
        std::cout << "8. Find Top Customers by Sales\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Check if input is a valid integer
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            printError("Invalid input. Please enter a number.");
            continue;
        }

        // Handle user's choice
        switch (choice) {
            case 1:
                SalesAnalysis::analyzeSalesByCustomerSegment(records);
                break;
            case 2:
                SalesAnalysis::analyzeSalesTrends(records);
                break;
            case 3:
                SalesAnalysis::analyzeDiscountImpact(records);
                break;
            case 4:
                SalesAnalysis::calculateProfitMargins(records);
                break;
            case 5:
                SalesAnalysis::analyzeSalesByShipMode(records);
                break;
            case 6:
                SalesAnalysis::analyzeCustomerLoyalty(records);
                break;
            case 7:
                SalesAnalysis::calculateSalesGrowth(records);
                break;
            case 8:
                SalesAnalysis::findTopCustomersBySales(records);
                break;
            case 9:
                SalesAnalysis::compareSalesByRegion(records);
                break;
            case 0:
                std::cout << YELLOW << "Exiting program." << RESET << std::endl;
                break;
            default:
                printError("Invalid choice. Please enter a number between 0 and 8.");
        }
    } while (choice != 0);

    return 0;
}
