/*
* Marina Vasina
* st140082@student.spbu.ru
* Assignment5
*/

#ifndef MATRIX
#define MATRIX

#include <vector>
#include <stdexcept>

template <typename T>
class Matrix {
	private:
    		size_t rows, cols;
    		std::vector<std::vector<T>> data;
	public: //constructors
    		Matrix(std::size_t r, std::size_t c) : rows(r), cols(c), data(r, std::vector<T>(c, T{})) {};
		Matrix(const std::vector<std::vector<T>>& init) : rows(init.size()), cols(init[0].size()), data(init) {};
		
		//Destructor
		~Matrix() {};
		
		//Getters
	    	std::size_t getRows() const { return rows; }
    		std::size_t getCols() const { return cols; }
    		const std::vector<std::vector<T>>& getData() const { return data; }

		T& operator()(std::size_t row, std::size_t col)
    		{
        		return data[row][col];
    		}

		const T& operator()(std::size_t row, std::size_t col) const
    		{
        		return data[row][col];
    		}


    	// multiplication by a scalar
    	Matrix<T> operator*(const T& scalar) const
	{
        	Matrix<T> result(rows, cols);
        	for (size_t i = 0; i < rows; ++i)
            		for (size_t j = 0; j < cols; ++j)
                		result.data[i][j] = data[i][j] * scalar;
        	return result;
    	}

    	// Matrix addition
    	Matrix<T> operator+(const Matrix<T>& Matrix2) const 
	{
            	Matrix<T> result(rows, cols);
        	for (std::size_t i = 0; i < rows; ++i)
            		for (std::size_t j = 0; j < cols; ++j)
                		result.data[i][j] = data[i][j] + Matrix2.data[i][j];
       		return result;
    	}

    	// matrix multiplication
    	Matrix<T> operator*(const Matrix<T>& Matrix2) const
	{
               	Matrix<T> result(rows, Matrix2.cols);
        	for (std::size_t i = 0; i < rows; ++i)
            		for (std::size_t j = 0; j < Matrix2.cols; ++j)
                		for (std::size_t k = 0; k < cols; ++k)
                    			result.data[i][j] += data[i][k] * Matrix2.data[k][j];
        	return result;
    	}

    	// Transposition
    	Matrix<T> transpose() const 
	{
        	Matrix<T> result(cols, rows);
        	for (std::size_t i = 0; i < rows; ++i)
            		for (std::size_t j = 0; j < cols; ++j)
                		result.data[j][i] = data[i][j];
        return result;
    	}
};

#endif // MATRIX_H