////////////////////////////////////////////////////////////////////////////////////////
// WordFont.cpp
// -----------------------------------------------------------------------------------
// Course: CIS554
// HomeWork 5
// Author: Wei Liu
// Date: 3/20/2015
// -----------------------------------------------------------------------------------
// Class descriptinon: 
// WordFont class will read a word that you input, and draw it on the screen with a 
// character height and width that you specify. 
//
////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "WordFont.h"
using namespace std;

WordFont::WordFont() // constructor, promopt the use to input the requirements
{
	setWord();
	setPixelChar();
	setFontSize();
	setBold();
}

void WordFont::setWord() // set function for private data member word
{
	cout << "Enter a word (less than 100 letters), using A-N, O, U: ";
	getline(cin,  word);
}
void WordFont::setPixelChar()
{
	cout << "Enter the pixel character you want to use to draw: ";
	cin >> pixelChar;
}
void WordFont::setFontSize() // set function for private data member fontSize
{
	cout << "Enter the Font Size(8 - 12): ";
	int tmp;
	cin >> tmp;
	while (1)
	{
		if (tmp < 8)
		{
			cout << "[ERROR]Input a number greater or equal to 8: ";
			cin >> tmp;
			continue;
		}
		else if (tmp > 12)
		{
			cout << "[ERROR]Input a number less or equal to 12: ";
			cin >> tmp;
			continue;
		}
		fontSize = tmp;
		break;
	}
}
void WordFont::setBold() // set function for private data member isBold
{
	cout << "Bold ? (0 = No, 1 = Yes): ";
	int num;	
	cin >> num;
	if (num)
		isBold = true;
	else
		isBold = false;
}

void WordFont::build3DArray() // convert the word to corresponding 2D vectors and put them into 3D vector
{
	for (auto &c : word) // C++ 11, for each letter in string of word
	{
		c = toupper(c); // convert c to uppercase
		switch (c)
		{
		case 'A':
			setA();
			letterArray.push_back(A);			
			break;
		case 'B':
			setB();
			letterArray.push_back(B);			
			break;
		case 'C':
			setC();
			letterArray.push_back(C);
			break;
		case 'D':
			setD();
			letterArray.push_back(D);
			break;
		case 'E':
			setE();
			letterArray.push_back(E);
			break;
		case 'F':
			setF();
			letterArray.push_back(F);
			break;
		case 'G':
			setG();
			letterArray.push_back(G);
			break;
		case 'H':
			setH();
			letterArray.push_back(H);
			break;
		case 'I':
			setI();
			letterArray.push_back(I);
			break;
		case 'J':
			setJ();
			letterArray.push_back(J);
			break;
		case 'K':
			setK();
			letterArray.push_back(K);
			break;
		case 'L':
			setL();
			letterArray.push_back(L);
			break;
		case 'M':
			setM();
			letterArray.push_back(M);
			break;
		case 'N':
			setN();
			letterArray.push_back(N);
			break;
		case 'O':
			setO();
			letterArray.push_back(O);
			break;
		case 'U':
			setU();
			letterArray.push_back(U);
			break;
		default: // capture the invalid input and sent out the message
			cout << "[ERROR]: \"" << c << "\" is an invalid letter. Please check!" << endl;
			break;
		}
	}
}
void WordFont::drawLetter(const size_t begin, const size_t end) // draw the letters in 3D letterArray from begin to end
{
	for (unsigned j = 0; j < fontSize; j++) // each row
	{
		for (size_t i = begin; i < end; i++) //each letter
		{
			for (unsigned k = 0; k < fontSize; k++) // each colomn
			{
				cout << letterArray[i][j][k];
			}
			cout << "   ";
		}
		cout << endl;
	}
	cout << endl;
}

void WordFont::draw() // public function which print the 3D letterArray
{
	build3DArray();
	cout << endl;
	if (letterArray.size() >= 6)
	{		
		size_t cnt = 0;
		while (cnt + 5 < letterArray.size())
		{
			drawLetter(cnt, cnt + 5);
			cnt += 5;
		}
		drawLetter(cnt, letterArray.size());
	}
	else
		drawLetter(0, letterArray.size());
}


void WordFont::resize(vector<vector <char> > &vec) // set the 2-D vector size by fontSize times fontSize
{
	vec.resize(fontSize);
	for (unsigned i = 0; i < fontSize; ++i)
	{
		vec[i].resize(fontSize, ' ');
	}
}

void WordFont::setA() // set vector A with correct size and content
{
	resize(A);
	for (size_t i = 0; i < fontSize; i++)	
	{
		A[0][i] = pixelChar;
		A[fontSize / 2 - 1][i] = pixelChar;
	}
	for (size_t i = 1; i < fontSize; i++)
	{
		A[i][0] = pixelChar;
		A[i][fontSize - 1] = pixelChar;
	}

	if (isBold)
	{
		for (size_t i = 0; i<fontSize; i++)
		{
			A[fontSize / 2][i] = pixelChar;
		}
		for (size_t i = 1; i < fontSize; i++)
		{
			A[i][1] = pixelChar;
			A[i][fontSize - 2] = pixelChar;
		}
	}
}

void WordFont::setB() // set vector B with correct size and content
{
	resize(B);
	for (size_t i = 0; i < fontSize - 1; i++)
	{
		B[0][i] = pixelChar;
	}
	for (size_t i = 1; i < fontSize - 2; i++)
	{
		B[fontSize - 1][i] = pixelChar;
	}
	for (size_t i = 0; i < fontSize - 3; i++)
	{
		B[fontSize / 2 - 1][i] = pixelChar;
	}
	for (size_t i = 1; i < fontSize; i++)
	{
		B[i][0] = pixelChar;
	}
	for (size_t i = 1; i < fontSize - 1; i++)
	{
		B[i][fontSize - 1] = pixelChar;
	}
	B[fontSize / 2 - 1][fontSize - 1] =  ' ';
	B[fontSize / 2][fontSize - 2] = pixelChar;
	B[fontSize / 2][fontSize - 1] = ' ';
	B[fontSize / 2 - 2][fontSize - 2] = pixelChar;
	B[fontSize / 2 - 2][fontSize - 1] = ' ';
	if (isBold)
	{
		for (size_t i = 1; i < fontSize; i++)
		{
			B[i][1] = pixelChar;
			B[i][fontSize - 2] = pixelChar;
		}
		B[fontSize / 2 - 1][fontSize - 1] = ' ';
		B[fontSize / 2 - 1][fontSize - 2] = ' ';
		B[0][fontSize - 1] = ' ';
		B[fontSize - 1][fontSize - 1] = ' ';
		B[0][fontSize - 2] = ' ';
		B[fontSize - 1][fontSize - 2] = ' ';
		B[1][fontSize - 1] = ' ';
		B[fontSize - 2][fontSize - 1] = ' ';
	}
}

void WordFont::setC() // set vector C with correct size and content
{
	resize(C);
	for (size_t i = 0; i < fontSize; i++)
	{
		C[0][i] = pixelChar;
		C[fontSize - 1][i] = pixelChar;
	}
	for (size_t i = 1; i < fontSize; i++)
	{
		C[i][0] = pixelChar;
	}

	if (isBold)
	{
		for (size_t i = 0; i < fontSize; i++)
		{
			C[1][i] = pixelChar;
			C[fontSize - 2][i] = pixelChar;
		}
		for (size_t i = 1; i < fontSize; i++)
		{
			C[i][1] = pixelChar;
		}
	}
}

void WordFont::setD()  // set vector D with correct size and content
{
	resize(D);
	for (size_t i = 0; i < fontSize; i++)
	{
		D[0][i] = pixelChar;
		D[fontSize - 1][i] = pixelChar;
	}
	for (size_t i = 1; i < fontSize; i++)
	{
		D[i][0] = pixelChar;
		D[i][fontSize - 1] = pixelChar;
	}
	D[0][fontSize - 1] = ' ';
	D[fontSize - 1][fontSize - 1] = ' ';

	if (isBold)
	{
		for (size_t i = 0; i < fontSize; i++)
		{
			D[1][i] = pixelChar;
			D[fontSize - 2][i] = pixelChar;
		}
		for (size_t i = 1; i < fontSize; i++)
		{
			D[i][1] = pixelChar;
			D[i][fontSize - 2] = pixelChar;
		}
	}
}

void WordFont::setE() // set vector E with correct size and content
{
	resize(E);
	for (size_t i = 0; i < fontSize; i++)
	{
		E[0][i] = pixelChar;
		E[fontSize / 2 - 1][i] = pixelChar;
		E[fontSize - 1][i] = pixelChar;
	}
	for (size_t i = 1; i < fontSize; i++)
	{
		E[i][0] = pixelChar;
	}

	if (isBold)
	{
		for (size_t i = 0; i < fontSize; i++)
		{
			E[1][i] = pixelChar;
			E[fontSize / 2][i] = pixelChar;
			E[fontSize - 2][i] = pixelChar;
		}
		for (size_t i = 1; i < fontSize; i++)
		{
			E[i][1] = pixelChar;
		}
	}
}

void WordFont::setF() // set vector F with correct size and content
{
	resize(F);
	for (size_t i = 0; i < fontSize; i++)
	{
		F[0][i] = pixelChar;
		F[fontSize / 2 - 1][i] = pixelChar;
	}
	for (size_t i = 1; i < fontSize; i++)
	{
		F[i][0] = pixelChar;
	}

	if (isBold)
	{
		for (size_t i = 0; i < fontSize; i++)
		{
			F[1][i] = pixelChar;
			F[fontSize / 2][i] = pixelChar;
		}
		for (size_t i = 1; i < fontSize; i++)
		{
			F[i][1] = pixelChar;
		}
	}
}

void WordFont::setG() // set vector G with correct size and content
{
	resize(G);
	for (size_t i = 0; i < fontSize - 1; i++)
	{
		G[0][i] = pixelChar;
		G[fontSize - 1][i] = pixelChar;
	}
	for (size_t i = 1; i < fontSize; i++)
	{
		G[i][0] = pixelChar;
		if (i > fontSize / 2 - 1)
			G[i][fontSize - 2] = pixelChar;
	}
	for (size_t i = fontSize / 2 - 1; i < fontSize; i++)
	{
		G[fontSize / 2 - 1][i] = pixelChar;
	}
	if (isBold)
	{
		for (size_t i = 0; i < fontSize - 1; i++)
		{
			G[1][i] = pixelChar;
			G[fontSize - 2][i] = pixelChar;
		}
		for (size_t i = 1; i < fontSize; i++)
		{
			G[i][1] = pixelChar;
			if (i > fontSize / 2 - 1)
				G[i][fontSize - 3] = pixelChar;
		}
		for (size_t i = fontSize / 2 - 1; i < fontSize; i++)
		{
			G[fontSize / 2][i] = pixelChar;
		}
	}
}

void WordFont::setH() // set vector H with correct size and content
{
	resize(H);
	for (size_t i = 0; i < fontSize; i++)
	{
		H[i][0] = pixelChar;
		H[i][fontSize - 1] = pixelChar;
		H[fontSize / 2 - 1][i] = pixelChar;
	}
	if (isBold)
	{
		for (size_t i = 0; i < fontSize; i++)
		{
			H[fontSize / 2][i] = pixelChar;
		}
		for (size_t i = 0; i < fontSize; i++)
		{
			H[i][1] = pixelChar;
			H[i][fontSize - 2] = pixelChar;
		}
	}
}

void WordFont::setI() // set vector I with correct size and content
{
	resize(I);
	for (size_t i = 0; i < fontSize; i++)
	{
		I[0][i] = pixelChar;
		I[fontSize - 1][i] = pixelChar;
	}

	for (size_t i = 1; i < fontSize; i++)
	{
		I[i][fontSize / 2] = pixelChar;
	}

	if (isBold)
	{
		for (size_t i = 0; i < fontSize; i++)
		{
			I[1][i] = pixelChar;
			I[fontSize - 2][i] = pixelChar;
		}

		for (size_t i = 1; i < fontSize; i++)
		{
			I[i][fontSize / 2 - 1] = pixelChar;
		}
	}
}

void WordFont::setJ() // set vector J with correct size and content
{
	resize(J);
	for (size_t i = 0; i < fontSize; i++)
	{
		J[0][i] = pixelChar;
		if (i < fontSize / 2 + 1)
			J[fontSize - 1][i] = pixelChar;
	}
	for (size_t i = 1; i < fontSize; i++)
	{
		J[i][fontSize / 2 + 1] = pixelChar;
		if (i > fontSize * 2 / 3)
			J[i][0] = pixelChar;
	}
	if (isBold)
	{
		for (size_t i = 0; i < fontSize; i++)
		{
			J[1][i] = pixelChar;
			if (i < fontSize / 2 + 1)
				J[fontSize - 2][i] = pixelChar;
		}
		for (size_t i = 1; i < fontSize; i++)
		{
			J[i][fontSize / 2] = pixelChar;
			if (i > fontSize * 2 / 3)
				J[i][1] = pixelChar;
		}
	}
}
void WordFont::setK() // set vector K with correct size and content
{
	resize(K);
	for (size_t i = 0; i < fontSize; i++)
	{
		K[i][0] = pixelChar;
	}
	size_t i, j;
	for (i = fontSize / 2 - 1, j = 0; i >= 0 && j < fontSize - 1; i--, j += 2)
	{
		K[i][j] = pixelChar;
	}
	for (i = fontSize / 2, j = 0; i < fontSize && j < fontSize; i++, j += 2)
	{
		K[i][j] = pixelChar;
	}

	if (isBold)
	{
		for (size_t i = 0; i < fontSize; i++)
		{
			K[i][1] = pixelChar;
		}
		size_t i, j;
		for (i = fontSize / 2 - 1, j = 0; i >= 0 && j < fontSize - 1; i--, j += 2)
		{
			K[i + 1][j] = pixelChar;
		}
		for (i = fontSize / 2, j = 0; i < fontSize && j < fontSize; i++, j += 2)
		{
			K[i - 1][j] = pixelChar;
		}
	}
}

void WordFont::setL() // set vector L with correct size and content
{

	resize(L);
	for (size_t i = 0; i < fontSize; i++)
	{
		L[fontSize - 1][i] = pixelChar;
	}
	for (size_t i = 0; i < fontSize; i++)
	{
		L[i][0] = pixelChar;
	}
	if (isBold)
	{
		for (size_t i = 0; i < fontSize; i++)
		{
			L[i][1] = pixelChar;
			L[fontSize - 2][i] = pixelChar;
		}
	}
}

void WordFont::setM() // set vector M with correct size and content
{
	resize(M);
	for (size_t i = 0; i < fontSize; i++)
	{
		M[i][0] = pixelChar;
		M[i][fontSize - 1] = pixelChar;
	}
	int tmp = (fontSize % 2) ? fontSize / 2 : fontSize / 2 - 1;
	for (int i = 0; i <= tmp; i++)
	{
		M[i][i] = pixelChar;
	}

	for (int i = tmp - 1; i >= 0; i--)
	{
		M[i][fontSize - i - 1] = pixelChar;
	}
	if (isBold)
	{
		for (size_t i = 2; i < fontSize; i++)
		{
			M[i][1] = pixelChar;
			M[i][fontSize - 2] = pixelChar;
		}

		int tmp = (fontSize % 2) ? fontSize / 2 : fontSize / 2 - 1;
		for (int i = 2; i <= tmp; i++)
		{
			M[i + 1][i] = pixelChar;
		}

		for (int i = tmp - 1; i >= 0; i--)
		{
			M[i + 1][fontSize - i - 1] = pixelChar;
		}
	}
}
void WordFont::setN() // set vector N with correct size and content
{
	resize(N);
	for (size_t i = 0; i < fontSize; i++)
	{
		N[i][0] = pixelChar;
		N[i][fontSize - 1] = pixelChar;
		N[i][i] = pixelChar;
	}
	if (isBold)
	{
		for (size_t i = 1; i < fontSize - 1; i++)
		{
			N[i][1] = pixelChar;
			N[i][fontSize - 2] = pixelChar;
			N[i + 1][i] = pixelChar;
		}
		N[fontSize - 1][1] = pixelChar;
		N[0][fontSize - 2] = pixelChar;
	}
}

void WordFont::setO() // set vector O with correct size and content
{
	resize(O);
	for (size_t i = 1; i < fontSize - 1; i++)
	{
		O[0][i] = pixelChar;
		O[fontSize - 1][i] = pixelChar;

		O[i][0] = pixelChar;
		O[i][fontSize - 1] = pixelChar;
	}
	if (isBold)
	{
		for (size_t i = 0; i < fontSize; i++)
		{
			O[1][i] = pixelChar;
			O[fontSize - 2][i] = pixelChar;
		}
		for (size_t i = 1; i < fontSize; i++)
		{
			O[i][1] = pixelChar;
			O[i][fontSize - 2] = pixelChar;
		}
	}
}

void WordFont::setU() // set vector U with correct size and content
{

	resize(U);
	for (size_t i = 1; i < fontSize - 1; i++)
	{

		U[fontSize - 1][i] = pixelChar;
	}
	for (size_t i = 0; i < fontSize - 1; i++)
	{
		U[i][0] = pixelChar;
		U[i][fontSize - 1] = pixelChar;
	}
	if (isBold)
	{
		for (size_t i = 0; i < fontSize; i++)
		{
			U[fontSize - 2][i] = pixelChar;
			U[i][1] = pixelChar;
			U[i][fontSize - 2] = pixelChar;
		}
	}
}


