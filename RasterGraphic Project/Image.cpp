/*******************************************************************************************************************************************
Filename:			Image.cpp
Version:			1.0
Author:				Kevin Lai
Student No:			040 812 704
Course Name/Number:	C++ Programming CST8219
Lab Sect:			301
Assignment #:		3
Assignment name:	RasterGraphic Project in C++ using Polymorphic Inheritance and RTTI
Due Date:			December 1 2018
Submission Date:	December 1 2018
Professor:			Andrew Tyler
Purpose:			Class is responsible for holding all attributes and behavior of a Image.
********************************************************************************************************************************************/
#include <iostream>
using namespace std;
#include "Image.h"

/*******************************************************************************************************************************************
Function name: Image
Purpose: default constructor to initialize all members with parameters.
Function In Parameters: int x, int y, int duration, char* name
Function Out Parameters: none
Version: 1.0
Author/Student Name: Kevin Lai
*******************************************************************************************************************************************/
Image :: Image (int x, int y, int duration, char* name)
{
	this->pixel_x = x;
	this->pixel_y = y;
	this->duration = duration;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

/*******************************************************************************************************************************************
Function name: Image
Purpose: copy constructor to make a deep copy so that image object that is passed in the parameters has its own independent memory.
Function In Parameters: const Image& image
Function Out Parameters: none
Version: 1.0
Author/Student Name: Kevin Lai
*******************************************************************************************************************************************/
Image::Image(const Image& image)
{
	this->pixel_x = image.pixel_x;
	this->pixel_y = image.pixel_y;
	this->duration = image.duration;
	this->name = new char[strlen(image.name) + 1];
	strcpy_s(this->name, strlen(image.name) + 1, image.name);

}

/*******************************************************************************************************************************************
Function name: operator<<
Purpose: print out all attributes of Image object in a certain format.
Function In Parameters: ostream& out, Image& image
Function Out Parameters: ostream&  (out)
Version: 1.0
Author/Student Name: Kevin Lai
*******************************************************************************************************************************************/
ostream& operator<<(ostream& out, Image& image) 
{
	out << "\tImage name = " << image.name << "; pixel_x = " << image.pixel_x << "; pixel_y = " << image.pixel_y << "; duration = " << image.duration << endl;
	out << "\tCounting the seconds for this Image: ";

	for (int i = 1; i <= image.duration; i++)
	{
		out << i << ", ";
	}
	out << endl << "\tMemory requirements = " ;

	return out;

}