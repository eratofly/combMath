#ifndef SCC_H
#define SCC_H
#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<int>> FindStrongComponents(std::istream& inputFile);
void FindStrongComponentsFromFile(std::string const& fileName);

#endif