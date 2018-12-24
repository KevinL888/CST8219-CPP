// GraphicElement.h
#pragma once

class GraphicElement
{
	string fileName;
	vector<Image*> Images;
public:
	GraphicElement(string s, vector<Image*> d) :fileName(s), Images(d) {}
	GraphicElement(const GraphicElement&);
	~GraphicElement()
	{
		vector<Image*>::iterator it;
		for (it = Images.begin(); it != Images.end(); it++)
			delete *it;
	}
	friend ostream& operator<<(ostream&, GraphicElement&);
};