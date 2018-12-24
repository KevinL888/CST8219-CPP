#pragma once
//GPUMemoryImage.h



class GPUMemoryImage : public Image
{
	string shader;
public:
	GPUMemoryImage(int x, int y, int duration, char* name, string shader) :Image(x, y, duration, name), shader(shader) {};
	GPUMemoryImage(const GPUMemoryImage& RGPUMD) :shader(RGPUMD.shader), Image(RGPUMD) {}
	string GetShader() { return shader; }
	int BufferSize() { return pixel_x*pixel_y * sizeof(float); }
};
