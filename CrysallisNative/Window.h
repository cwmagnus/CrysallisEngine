#pragma once

namespace CrysallisNative
{
	enum WindowStyle
	{
		Windowed,
		FullScreen,
		Borderless
	};

	class Window
	{
	public:
		Window();

		~Window();

		bool Test()
		{
			return true;
		}
	};
}
