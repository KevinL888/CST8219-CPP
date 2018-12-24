// SystemMemoryImage.h
#pragma once



class  SystemMemoryImage : public Image
{
public:
	SystemMemoryImage(int x, int y, int duration, char* name) :Image(x, y, duration, name) {};
	SystemMemoryImage(const SystemMemoryImage& RGMD) :Image(RGMD) {}
	int BufferSize() { return pixel_x*pixel_y * sizeof(double); }
};

