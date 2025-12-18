/*
* Marina Vasina
* st140082@student.spbu.ru
* Assignment5
*/

#include "Matrix.h"
#include "Rational.h"
#include <gtest/gtest.h>
#include <vector>


TEST(MatrixTest, Basic)
{
	Matrix<int> m(2, 3);
    	EXPECT_EQ(m.getRows(), 2);
   	EXPECT_EQ(m.getCols(), 3);

   	m(0, 0) = 1;
	m(0, 1) = 2;
	m(0, 2) = 3;
    	m(1, 0) = 4;
    	m(1, 1) = 5;
    	m(1, 2) = 6;

	EXPECT_EQ(m(0,0), 1);
	EXPECT_EQ(m(1,2), 6);
}

TEST(MatrixTest, Scalar)
{
    	Matrix<int> m(2, 2);
    	m(0, 0) = 1;
    	m(0, 1) = 2;
    	m(1, 0) = 3;
    	m(1, 1) = 4;

    	Matrix<int> result = m * 3;
    	EXPECT_EQ(result(0, 0), 3);
    	EXPECT_EQ(result(0, 1), 6);
    	EXPECT_EQ(result(1, 0), 9);
    	EXPECT_EQ(result(1, 1), 12);
}

TEST(MatrixTest, Addition)
{
    	Matrix<int> A(2, 2);
    	A(0, 0) = 1;
    	A(0, 1) = 2;
    	A(1, 0) = 3;
    	A(1, 1) = 4;

    	Matrix<int> B(2, 2);
    	B(0, 0) = 5;
    	B(0, 1) = 6;
    	B(1, 0) = 7;
    	B(1, 1) = 8;

    	Matrix<int> C = A + B;
    	EXPECT_EQ(C(0, 0), 6);
    	EXPECT_EQ(C(0, 1), 8);
    	EXPECT_EQ(C(1, 0), 10);
    	EXPECT_EQ(C(1, 1), 12);

}

TEST(MatrixTest, Multiplication)
{
    	Matrix<int> A(2, 3);
    	A(0, 0) = 1;
    	A(0, 1) = 2;
    	A(0, 2) = 3;
    	A(1, 0) = 4;
    	A(1, 1) = 5;
    	A(1, 2) = 6;

    	Matrix<int> B(3, 2);
    	B(0, 0) = 7;
    	B(0, 1) = 8;
    	B(1, 0) = 9;
    	B(1, 1) = 10;
    	B(2, 0) = 11;
    	B(2, 1) = 12;

    	Matrix<int> C = A * B;
    	EXPECT_EQ(C.getRows(), 2);
    	EXPECT_EQ(C.getCols(), 2);
    	EXPECT_EQ(C(0, 0), 58);
    	EXPECT_EQ(C(0, 1), 64);
    	EXPECT_EQ(C(1, 0), 139);
    	EXPECT_EQ(C(1, 1), 154);
}

TEST(MatrixTest, Transpose)
{
    	Matrix<int> m(2, 3);
    	m(0, 0) = 1;
    	m(0, 1) = 2;
    	m(0, 2) = 3;
    	m(1, 0) = 4;
   	m(1, 1) = 5;
    	m(1, 2) = 6;

    	Matrix<int> t = m.transpose();
    	EXPECT_EQ(t.getRows(), 3);
	EXPECT_EQ(t.getCols(), 2);
    	EXPECT_EQ(t(0, 0), 1);
    	EXPECT_EQ(t(0, 1), 4);
    	EXPECT_EQ(t(1, 0), 2);
    	EXPECT_EQ(t(2, 1), 6);
}


TEST(MatrixTest, RationalType) {
	Matrix<Rational> m(2, 2);
	m(0, 0) = Rational(1, 2);    
	m(0, 1) = Rational(2, 3);    
	m(1, 0) = Rational(3, 4);    
	m(1, 1) = Rational(4, 5);    

    	Matrix<Rational> t = m.transpose();

    	EXPECT_EQ(t.getRows(), 2);
    	EXPECT_EQ(t.getCols(), 2);
    	EXPECT_EQ(t(0, 0), Rational(1, 2));
    	EXPECT_EQ(t(0, 1), Rational(3, 4));
    	EXPECT_EQ(t(1, 0), Rational(2, 3));
    	EXPECT_EQ(t(1, 1), Rational(4, 5));
}

TEST(RationalTest, Invariant) {
    Rational r1(4, 8);
    EXPECT_EQ(r1, Rational(1, 2));

    Rational r2(10, 20);
    EXPECT_EQ(r2, Rational(1, 2));

    Rational r3(-2, 4);
    EXPECT_EQ(r3, Rational(-1, 2));

    Rational r4(0, 5);
    EXPECT_EQ(r4, Rational(0, 1));
}