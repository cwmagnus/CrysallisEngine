#pragma once

#include <string>

#include "VideoMode.h"
#include "Color.h"

struct GLFWwindow;

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
		Window(VideoMode mode, const std::string& title, WindowStyle style = WindowStyle::Windowed);

		~Window();

		void Create(VideoMode mode, const std::string& title, WindowStyle style = WindowStyle::Windowed);
		void Recreate(VideoMode mode, const std::string& title, WindowStyle style = WindowStyle::Windowed);
		void Close();
		void Clear(const Color& clearColor = Color());
		void PollEvents();
		void Display();
		bool IsOpen() const;

		void SetSize(unsigned int width, unsigned int height);
		void SetPosition(int x, int y);
		void SetTitle(const std::string& title);
		void SetVerticalSyncEnabled(bool enabled);

	private:
		GLFWwindow* _windowHandle;
		bool _initialized;

		bool Initialize(VideoMode mode, const std::string& title, WindowStyle style);
	};
}
