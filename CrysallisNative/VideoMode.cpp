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

	VideoMode::VideoMode(unsigned int modeWidth, unsigned int modeHeight, unsigned int modeRefreshRate) :
		Width(modeWidth),
		Height(modeHeight),
		RefreshRate(modeRefreshRate)
	{

	}

	VideoMode VideoMode::GetDesktopMode()
	{
		GLFWmonitor* monitor = glfwGetPrimaryMonitor();

		// Get the video mode from the monitor if valid
		const GLFWvidmode* mode;
		if (monitor)
		{
			mode = glfwGetVideoMode(monitor);
			return VideoMode(mode->width, mode->height, mode->refreshRate);
		}
		
		return VideoMode();
	}

	const std::vector<VideoMode> VideoMode::GetFullScreenModes()
	{
		int modeCount;
		GLFWmonitor* monitor = glfwGetPrimaryMonitor();
		
		// Get the list of available video modes if the monitor is valid
		const GLFWvidmode* modes;
		if (monitor)
		{
			modes = glfwGetVideoModes(monitor, &modeCount);
			std::vector<VideoMode> videoModes(modeCount);
			for (int i = 0; i < modeCount; i++)
			{
				videoModes[i] = VideoMode(modes[i].width, modes[i].height, modes[i].refreshRate);
			}

			return videoModes;
		}

		return std::vector<VideoMode>();
	}

	GLFWmonitor* VideoMode::GetPrimaryMonitorHandle()
	{
		return glfwGetPrimaryMonitor();
	}
}
