#pragma once

struct GLFWmonitor;

namespace CrysallisNative
{
	class VideoMode
	{
	public:
		int Width, Height, RefreshRate;

		VideoMode();
		VideoMode(int modeWidth, int modeHeight, int modeRefreshRate = 60);

		inline bool IsValid() const
		{
			return Width > 0 && Height > 0 && RefreshRate > 0;
		}

		static VideoMode GetDesktopMode();
		static GLFWmonitor* GetPrimaryMonitorHandle();
	};
}
