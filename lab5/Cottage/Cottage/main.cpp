﻿#include <iostream>
#include "Window.h"
#include "GLFWInitializer.hpp"

int main()
{
	GLFWInitializer initGLFW;
	Window window(800, 600, "Cottage");
	window.Run();
}
