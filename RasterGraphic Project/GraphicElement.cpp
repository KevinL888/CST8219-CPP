/*******************************************************************************************************************************************
Filename:			GraphicElement.cpp
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
Purpose:			Class is responsible for handling GraphicElements. Use of a vector container to hold images. Overloaded function (<<)
					for outputting all the images in the vector.
********************************************************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
#include "Image.h"
#include "SystemMemoryImage.h"
#include "GPUMemoryImage.h"
#include <string>
#include "GraphicElement.h"

/*******************************************************************************************************************************************
Function name: GraphicElement
Purpose: copy constructor to make a deep copy so that GraphicElement object that is passed in the parameters has its own independent memory.
Function In Parameters: const GraphicElement& graphic
Function Out Parameters: none
Version: 1.0
Author/Student Name: Kevin Lai
*******************************************************************************************************************************************/
GraphicElement::GraphicElement(const GraphicElement& graphic)
{
	this->fileName = graphic.fileName;

	for (int i = 0; i < (signed int)graphic.Images.size(); i++)
	{
		this->Images.emplace_back(graphic.Images[i]);
	}
}

/*******************************************************************************************************************************************
Function name: operator<<
Purpose: Create an iterator to iterate through the vector and print out all the Images(SystemMemoryImage, GPUMemoryImage) in a certain format.
Function In Parameters: ostream& out, GraphicElement& graphic
Function Out Parameters: ostream&  (out)
Version: 1.0
Author/Student Name: Kevin Lai
*******************************************************************************************************************************************/
ostream& operator<<(ostream& out, GraphicElement& graphic)
{
	vector<Image*>::iterator IV;
	int counter = 0;

	out << "\tfileName = ";
	out << graphic.fileName;

	for (IV = graphic.Images.begin(); IV != graphic.Images.end(); IV++)
	{
		out << endl << "\tImage #" << counter << ": ";
		/*dynamic cast to GPUMemoryImage object if sucessfull then we print GPU image along with shader*/
		GPUMemoryImage *GPU = dynamic_cast<GPUMemoryImage*>(*IV);
		/*if object is null then it is a System Memory Image*/
		if (!GPU)
			out << "System Memory Image" << endl;
		else
			out << "GPU Memory Image. Shader = " << GPU->GetShader() << endl;

		out << *(*IV);
		out << (*IV)->BufferSize() << " bytes" << endl;
		counter++;
	}
	cout << endl;
	return out;
}