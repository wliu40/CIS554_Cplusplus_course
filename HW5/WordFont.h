////////////////////////////////////////////////////////////////////////////////////////
// WordFont.h
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
using std::string;
using std::vector;

#ifndef WORDFONT_H
#define WORDFONT_H

class WordFont
{
public:
	WordFont(); // constructor should prompt the user provide the information
	void draw();

private:
	string word; // word input by the user
	char pixelChar; // the character which will represent the pixel
	size_t fontSize;
	bool isBold; // if true, the letters will be bold, vise versa

	// the 2-D vectors which represent and stored the corresponding letters
	vector< vector<char> > A;
	vector< vector<char> > B;
	vector< vector<char> > C;
	vector< vector<char> > D;
	vector< vector<char> > E;
	vector< vector<char> > F;
	vector< vector<char> > G;
	vector< vector<char> > H;
	vector< vector<char> > I;
	vector< vector<char> > J;
	vector< vector<char> > K;
	vector< vector<char> > L;
	vector< vector<char> > M;
	vector< vector<char> > N;
	vector< vector<char> > O;
	vector< vector<char> > U;
	vector < vector< vector<char> > > letterArray; // 3-D vector stores the 2-D vectors

	void setWord(); // set word
	void setPixelChar(); // set pixelChar
	void setFontSize(); // set fontSize
	void setBold(); // set isBold

	// set functions to set the 2-D vectors
	void setA();
	void setB();
	void setC();
	void setD();
	void setE();
	void setF();
	void setG();
	void setH();
	void setI();
	void setJ();
	void setK();
	void setL();
	void setM();
	void setN();
	void setO();
	void setU();
	void resize(vector<vector <char> > &vec); // resize the vecter with correct size
	void build3DArray(); // set function to set the 3-D vector
	void drawLetter(const size_t begin, const size_t end); // draw the letter of 3-D vector in the span from begin to end
};

#endif