#ifndef TEXTURE2D
#define TEXTURE2D
#include <glad/glad.h>
#include <iostream>

class Texture2D
{
public:
	Texture2D();
	~Texture2D();

	void LoadTexture(const char* fileName);
};
#endif // !TEXTURE2D
