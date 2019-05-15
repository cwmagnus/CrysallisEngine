#pragma once

#include "../CrysallisNative/Window.h"

namespace CrysallisNativeWrapper
{
	public ref class Window
	{
	public:
		Window();

		bool Test();

	private:
		CrysallisNative::Window* _window;
	};
}
