// Image.h
#pragma once

class Image
{
protected:
	int pixel_x;
	int pixel_y;
	int duration;
	char* name;
public:
	Image(int x, int y, int duration, char* name);
	Image(const Image&);
	virtual ~Image()
	{
		if (name)
			delete[]name;
	}
	virtual int BufferSize() = 0;
	friend ostream& operator<<(ostream&, Image&);
};