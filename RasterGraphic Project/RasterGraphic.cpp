/*******************************************************************************************************************************************
Filename:			RasterGraphic.cpp
Version:			1.0
Author:				Kevin Lai
Student No:			040 812 704
Course Name/Number:	C++ Programming CST8219
Lab Sect:			301
Assignment #:		3
Assignment name:	RasterGraphic Project in C++ using Polymorphic Inheritance and RTTI
Due Date:			December 1 2018
Submission Date:    December 1 2018
Professor:			Andrew Tyler
Purpose:			Use of forward list to store Graphic Elements. Allow the user to manipulate
					the forward list ( appending, removing ). Report the Raster Graphic to show
					all the GraphicElements in the list.
********************************************************************************************************************************************/
#include <string>
#include <iostream>
#include <forward_list>
#include <vector>
using namespace std;
#include "Image.h"
#include "SystemMemoryImage.h"
#include "GPUMemoryImage.h"
#include "GraphicElement.h"
#include "RasterGraphic.h"

/*******************************************************************************************************************************************
Function name: InsertGraphicElement
Purpose: Take in a filename from the user and store it in a string. Take in all attributes of a Image (pixel x, pixel y, duration,
		 image name) and ask user which type of Image (1:System Memory Image, 2: GPU Memory Image) Insert new GraphicElement into the 
		 forward list, if the list is empty then GraphicElement is the new head of the forward list otherwise do one pass through the 
		 forward list and count the amount of nodes in the forward list. Display the amount of nodes to the user and ask user to specify 
		 where he wants new node to be inserted after. use emplace_after function to insert node after index specifed by user.

Function In Parameters: none
Function Out Parameters: none
Version: 1.0
Author/Student Name: Kevin Lai
*******************************************************************************************************************************************/
void RasterGraphic::InsertGraphicElement()
{
	vector<Image*> imageContainer;
	string fileName;
	string shader;
	char imageName[50];
	int pixel_x, pixel_y, duration, numImages, elementPosition = 0, counter = 0, type = 0;
	cout << "Insert a GraphicElement in the RasterGraphic\nPlease enter the GraphicElement filename: ";
	cin >> fileName;  /*get input for fileName from user*/

	cout << "Entering the GraphicElement Images (the sets of dimensions and durations)\nPlease enter the number of Images: ";
	cin >> numImages;  /*get input from user for number of images*/

					   /*loop through number of images and get all attributes from user.*/
	for (int i = 0; i <numImages; i++)
	{
		cout << "Please enter pixel x-width for Image #" << i << " pixel_x:";
		cin >> pixel_x;
		cout << "Please enter pixel y-width for Image #" << i << " pixel_y:";
		cin >> pixel_y;
		cout << "Please enter the duration sec for this Image: ";
		cin >> duration;
		cout << "Please enter the name for this Image: ";
		cin >> imageName;
		cout << "Please enter the type for this Image (1 = SystemMemoryImage, 2 = GPUMemoryImage): ";

		while (!(cin >> type) || (type != 1 && type != 2))
		{
			cout << "Please enter the type for this Image (1 = SystemMemoryImage, 2 = GPUMemoryImage): ";
			cin.clear();
			cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		}

		/*create SystemMemoryImage*/
		if (type == 1)
		{
			imageContainer.emplace_back(new SystemMemoryImage(pixel_x, pixel_y, duration, imageName));
		}
		/*create GPUMemoryImage*/
		else
		{
			cout << "Please enter the file name of the associated GPU shader: ";
			cin >> shader;
			imageContainer.emplace_back(new GPUMemoryImage(pixel_x, pixel_y, duration, imageName, shader));
		}
		cout << endl;
	}
	/*check to see if the forward list is empty*/
	if (this->GraphicElements.empty())
	{
		this->GraphicElements.emplace_front(fileName, imageContainer); /*place new GraphicElement as head of the forward list*/
		cout << "This is the first GraphicElement in the list\n\n";
	}
	else
	{
		forward_list<GraphicElement>::iterator IFL;

		counter = distance(GraphicElements.begin(), GraphicElements.end()); /*count number of GraphicElement in the forward list*/

		if (counter > 1)
		{
			cout << "There are " << counter << " GraphicElement(s) in the list\nPlease specify the position, between 0 and " << (counter - 1) << " to insert after : ";
			while (!(cin >> elementPosition) || elementPosition < 0 || elementPosition >(counter - 1))
			{
				cout << "invalid input please specify a number between 0 and " << (counter - 1) << " to insert after : ";
				cin.clear();
				cin.ignore(numeric_limits <streamsize> ::max(), '\n');
			}
		}

		IFL = GraphicElements.begin(); /*set iterator back to the beginning of the forward list*/
		advance(IFL, elementPosition); /*advance to the location specifed by user*/
		GraphicElements.emplace_after(IFL, fileName, imageContainer); /*insert Graphic Element after the index specified by the user*/
		cout << endl;
	}
}

/*******************************************************************************************************************************************
Function name: DeleteGraphicElement
Purpose: Checks to see if there is any GraphicElements to remove from the forward list. If there is a GraphicElement to remove then
		 pop_front function will delete GraphicElement from the head of the forward list.
Function In Parameters: none
Function Out Parameters: none
Version: 1.0
Author/Student Name: Kevin Lai
*******************************************************************************************************************************************/
void RasterGraphic::DeleteGraphicElement()
{
	if (!(this->GraphicElements.empty()))
	{
		this->GraphicElements.pop_front();
		cout << "Delete the first GraphicElement from the RasterGraphic\nGraphicElement deleted\n\n";
	}
	else
		cout << "There are no GraphicElements to delete\n" << endl;
}

/*******************************************************************************************************************************************
Function name: operator<<
Purpose: Create an iterator to iterate through the forward list and print out all the Graphic Elements in a certain format.
		 to a GraphicElement.
Function In Parameters: ostream& out, RasterGraphic& RG
Function Out Parameters: ostream&   (out)
Version: 1.0
Author/Student Name: Kevin Lai
*******************************************************************************************************************************************/
ostream& operator<<(ostream& out, RasterGraphic& RG)
{
	forward_list<GraphicElement>::iterator IFL;
	int counter = 0;
	out << "RasterGraphic " << RG.name << endl;
	out << "Run the RasterGraphic" << endl;
	for (IFL = RG.GraphicElements.begin(); IFL != RG.GraphicElements.end(); IFL++)
	{
		out << "GraphicElement #" << counter;
		out << *IFL;
		counter++;
	}
	out << endl;
	out << "Output finished" << endl;

	return out;
}