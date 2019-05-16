#include "VideoMode.h"

#include <GLFW/glfw3.h>

namespace CrysallisNative
{
	VideoMode::VideoMode() :
		Width(0),
		Height(0),
		RefreshRate(0)
	{

	}

	VideoMode::VideoMode(int modeWidth, int modeHeight, int modeRefreshRate) :
		Width(modeWidth),
		Height(modeHeight),
		RefreshRate(modeRefreshRate)
	{

	}

	VideoMode VideoMode::GetDesktopMode()
	{
		GLFWmonitor* monitor = glfwGetPrimaryMonitor();

		// Get the video mode from the monitor if monitor exists
		const GLFWvidmode* mode;
		if (monitor)
		{
			mode = glfwGetVideoMode(monitor);
			return VideoMode(mode->width, mode->height, mode->refreshRate);
		}
		
		return VideoMode();
	}

	GLFWmonitor* VideoMode::GetPrimaryMonitorHandle()
	{
		return glfwGetPrimaryMonitor();
	}
}
