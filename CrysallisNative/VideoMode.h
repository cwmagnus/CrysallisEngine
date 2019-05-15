#pragma once

#include <vector>

struct GLFWmonitor;

namespace CrysallisNative
{
	class VideoMode
	{
	public:
		unsigned int Width, Height, RefreshRate;

		VideoMode();
		VideoMode(unsigned int modeWidth, unsigned int modeHeight, unsigned int modeRefreshRate = 60);

		inline bool IsValid() const
		{
			return Width > 0 && Height > 0 && RefreshRate > 0;
		}

		static VideoMode GetDesktopMode();
		static const std::vector<VideoMode> GetFullScreenModes();
		static GLFWmonitor* GetPrimaryMonitorHandle();
	};
}
