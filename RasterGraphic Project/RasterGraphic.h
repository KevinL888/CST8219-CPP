//RasterGraphic.h
#pragma once

class RasterGraphic
{
	string name;
	forward_list<GraphicElement> GraphicElements;
public:
	RasterGraphic(string s) : name(s) {}
	void InsertGraphicElement();
	void DeleteGraphicElement();
	friend ostream& operator<<(ostream&, RasterGraphic&);
};