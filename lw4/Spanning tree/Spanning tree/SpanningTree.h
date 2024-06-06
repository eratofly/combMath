#ifndef SPANNINGTREE_H
#define SPANNINGTREE_H

#include <vector>

std::vector<std::vector<double>> CreateKirchhoffMatrix(std::vector<std::vector<double>>& matrix);
std::vector<std::vector<double>> AlgebraicComplement(std::vector<std::vector<double>>& matrix);
double CountSpanningTrees(std::vector<std::vector<double>>& algebraicComplementMatrix);


#endif