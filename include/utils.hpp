#ifndef UTILS
#define UTILS

#include <string>
#include <limits>
#include <ios>

int getValidatedChoice(); //function to validate user choice in velocache menu
std::string getValidatedKeyInput();      //get validated key from user
std::string getValidatedValueInput();   //get validated value from user
int getValidatedNumberInput(int maxLimit = 1000); //get validated number from user

void exportMetricsToCSV(const std::string& opName, double p50, double p95, double p99); //exporting benchmark metrics to CSV

#endif