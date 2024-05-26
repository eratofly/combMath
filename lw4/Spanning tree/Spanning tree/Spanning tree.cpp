#include <cmath>
#include <iostream>
#include <vector>

std::vector<std::vector<double>> CreateKirchhoffMatrix(std::vector<std::vector<double>>& matrix)
{
	int n = static_cast<int>(matrix.size());
	std::vector<std::vector<double>> matrixKirchhoff(n, std::vector<double>(n, 0));

	for (int i = 0; i < n; ++i)
	{
		int deg = 0;
		for (int j = 0; j < n; ++j)
		{
			if (matrix[i][j] != 0)
			{
				deg++;
				matrixKirchhoff[i][j] = -1;
			}
		}
		matrixKirchhoff[i][i] = deg;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			std::cout << matrixKirchhoff[i][j] << ' ';
		std::cout << std::endl;
	}
	std::cout << std::endl;


	return matrixKirchhoff;
};

double FindDet(std::vector<std::vector<double>>& matrix)
{
	int n = static_cast<int>(matrix.size());
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			std::cout << matrix[i][j] << "";
		std::cout << std::endl;
	}
	std::cout << std::endl;

	double det = 1;

	for (int i = 0; i < n; ++i)
	{

		double pivotElement = matrix[i][i];
		int pivotRow = i;
		for (int row = i + 1; row < n; ++row)
		{
			if (std::abs(matrix[row][i]) > std::abs(pivotElement))
			{
				pivotElement = matrix[row][i];
				pivotRow = row;
			}
		}
		if (pivotElement == 0.0)
		{
			return 0.0;
		}
		if (pivotRow != i)
		{
			matrix[i].swap(matrix[pivotRow]);
			det *= -1.0;
		}
		det *= pivotElement;

		for (int row = i + 1; row < n; ++row)
		{
			for (int col = i + 1; col < n; ++col)
			{
				matrix[row][col] -= matrix[row][i] * matrix[i][col] / pivotElement;
			}
		}
	}

	return det;
}

//std::vector<std::vector<double>> GetMinor(std::vector<std::vector<double>> matrix, int row, int column)
//{
//	int n = static_cast<int>(matrix.size());
//	std::vector<std::vector<double>> matrixMinor(n - 1, std::vector<double>(n - 1, 0));
//	int rowCount = 0, columnCount = 0;
//
//	for (int i = 0; i < n; i++)
//	{
//		if (i != row)
//		{
//			columnCount = 0;
//			for (int j = 0; j < n; j++)
//			{
//				if (j != column)
//				{
//					matrixMinor[rowCount][columnCount] = matrix[i][j];
//					columnCount++;
//				}
//			}
//			rowCount++;
//		}
//	}
//	return matrixMinor;
//}

std::vector<std::vector<double>> GetMinor(std::vector<std::vector<double>>& matrix, int row, int col)
{
	std::vector<std::vector<double>> minor;
	int n = matrix.size();

	for (int i = 0; i < n; ++i)
	{
		if (i == row)
			continue;

		std::vector<double> temp_row;
		for (int j = 0; j < n; ++j)
		{
			if (j != col)
			{
				temp_row.push_back(matrix[i][j]);
			}
		}
		minor.push_back(temp_row);
	}

	return minor;
}

double Cofactor(std::vector<std::vector<double>>& matrix, int row, int col)
{
	int sign = ((row + col) % 2 == 0) ? 1 : -1;
	std::vector<std::vector<double>> minor = GetMinor(matrix, row, col);

	// Вычисляем определитель минора
	double det = 0.0;
	int n = minor.size();
	if (n == 1)
	{
		det = minor[0][0];
	}
	else
	{
		det = FindDet(minor);
	}

	return det;
}


std::vector<std::vector<double>> AlgebraicComplement(std::vector<std::vector<double>>& matrix)
{
	int n = matrix.size();
	std::vector<std::vector<double>> result(n, std::vector<double>(n, 0.0));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			result[i][j] = Cofactor(matrix, i, j);
		}
	}

	return result;
}

//std::vector<std::vector<double>> FindAlgDop(std::vector<std::vector<double>>& matrix)
//{
//	int n = static_cast<int>(matrix.size());
//
//	// находим определитель матрицы A
//	int det = FindDet(matrix);
//
//	if (det > 0) // это для знака алгебраического дополнения
//		det = -1;
//	else
//		det = 1;
//
//	std::vector<std::vector<double>> matrixMinor(n - 1, std::vector<double>(n - 1, 0));
//
//	for (int j = 0; j < n; j++)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			// получаем алгебраическое дополнение
//			matrixMinor = GetMinor(matrix, j, i);
//			if ((i + j) % 2 == 0)
//				matrixMinor[j][i] = -det * FindDet(matrixMinor);
//			else
//				matrixMinor[j][i] = det * FindDet(matrixMinor);
//		}
//	}
//
//	return matrixMinor;
//}
