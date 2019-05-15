#include "Window.h"

namespace CrysallisNativeWrapper
{
	Window::Window() : _window(new CrysallisNative::Window())
	{
		
	}

	bool Window::Test()
	{
		return _window->Test();
	}
}
