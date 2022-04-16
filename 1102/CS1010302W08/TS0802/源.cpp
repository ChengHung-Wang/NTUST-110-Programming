// Name: ¤ý¥¿§»
// Date: 2022/4/7 ¤U¤È 10:24:48
// Last Update: 2022/4/12 ¤U¤È 10:24:48
// Problem statement: Matrix Multiplication
#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

class Matrix
{
public:
	int row;
	int col;

	std::vector<std::vector<int>> data;

	Matrix(int = 0, int = 0);

	friend std::istream& operator>>(std::istream&, Matrix&);
	friend std::ostream& operator<<(std::ostream&, Matrix&);

	friend Matrix operator*(const Matrix&, const Matrix&);
};

Matrix::Matrix(int row, int col)
{
	this->row = row;
	this->col = col;
	data.resize(row);
	for (int i = 0; i < row; i++) {
		data[i].resize(col);
	}
}

std::istream& operator>>(std::istream& is, Matrix& matrix)
{
	for (auto& v : matrix.data)
	{
		for (auto& i : v)
			is >> i;
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, Matrix& matrix)
{
	for (int i = 0; i < matrix.data.size(); i++)
	{
		for (int j = 0; j < matrix.data[i].size(); j++)
		{
			os << matrix.data[i][j];
			if (j != matrix.data[i].size() - 1)
				os << ' ';
		}
		if (i != matrix.data.size() - 1)
			os << '\n';
	}
	return os;
}

Matrix operator*(const Matrix& m1, const Matrix& m2)
{
	Matrix result(m1.row, m2.col);
	for (int i = 0; i < result.row; i++)
	{
		for (int j = 0; j < result.col; j++)
		{
			result.data[i][j] = 0;
			for (int k = 0; k < m1.col; k++)
				result.data[i][j] += (m1.data[i][k] * m2.data[k][j]);
		}
	}
	return result;
}

int main()
{
	// get two matrix row and column
	int m1r, m1c, m2r, m2c;
	cin >> m1r >> m1c >> m2r >> m2c;
	Matrix m1(m1r, m1c), m2(m2r, m2c);
	cin >> m1 >> m2;
	if (m1.col == m2.row)
	{
		Matrix result = m1 * m2;
		cout << result;
	}
	else
		cout << "Matrix multiplication failed.\n";
	return 0;
}