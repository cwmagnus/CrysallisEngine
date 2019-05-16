#include "Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace CrysallisNative
{
	Window::Window() :
		_windowHandle(nullptr),
		_initialized(false)
	{

	}

	Window::Window(VideoMode mode, const std::string& title, WindowStyle style) :
		_windowHandle(nullptr),
		_initialized(false)
	{
		Create(mode, title, style);
	}

	Window::~Window()
	{
		glfwDestroyWindow(_windowHandle);
		glfwTerminate();
	}

	void Window::Create(VideoMode mode, const std::string& title, WindowStyle style)
	{
		if (!Initialize(mode, title, style))
		{
			// ERROR
		}
	}

	void Window::Recreate(VideoMode mode, const std::string& title, WindowStyle style)
	{
		// Calculate position needed to center the window
		int monitorX, monitorY;
		glfwGetMonitorPos(VideoMode::GetPrimaryMonitorHandle(), &monitorX, &monitorY);

		int windowWidth, windowHeight;
		glfwGetWindowSize(_windowHandle, &windowWidth, &windowHeight);

		int x = monitorX + (windowWidth - mode.Width) / 2;
		int y = monitorY + (windowHeight - mode.Height) / 2;

		// Recreate the window based on style
		switch (style)
		{
		case Windowed:
			glfwSetWindowMonitor(_windowHandle, NULL, x, y, mode.Width, mode.Height, NULL);
			break;

		case FullScreen:
			glfwSetWindowMonitor(_windowHandle, VideoMode::GetPrimaryMonitorHandle(), 0, 0,
				mode.Width, mode.Height, mode.RefreshRate);
			break;

		case Borderless:
			glfwSetWindowMonitor(_windowHandle, VideoMode::GetPrimaryMonitorHandle(), 0, 0,
				mode.Width, mode.Height, NULL);
			break;
		}
	}

	void Window::Close()
	{
		glfwSetWindowShouldClose(_windowHandle, true);
	}

	void Window::Clear(const Color& clearColor)
	{
		glClearColor(clearColor.Red, clearColor.Green, clearColor.Blue, clearColor.Alpha);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::PollEvents()
	{
		glfwPollEvents();
	}

	void Window::Display()
	{
		glfwSwapBuffers(_windowHandle);
	}

	bool Window::IsOpen() const
	{
		return !glfwWindowShouldClose(_windowHandle);
	}

	void Window::SetSize(unsigned int width, unsigned int height)
	{
		glfwSetWindowSize(_windowHandle, width, height);
		glViewport(0, 0, width, height);
	}

	void Window::SetPosition(int x, int y)
	{
		glfwSetWindowPos(_windowHandle, x, y);
	}

	void Window::SetTitle(const std::string & title)
	{
		glfwSetWindowTitle(_windowHandle, title.c_str());
	}

	void Window::SetVerticalSyncEnabled(bool enabled)
	{
		glfwSwapInterval(enabled);
	}

	bool Window::Initialize(VideoMode mode, const std::string & title, WindowStyle style)
	{
		// Check if the window has already been initialized
		if (_initialized) return false;

		// Set up context for opengl
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

		// Create the window based on window style and check if it was created successfully
		switch (style)
		{
		case Windowed:
			_windowHandle = glfwCreateWindow(mode.Width, mode.Height, title.c_str(), NULL, NULL);
			break;

		case FullScreen:
			_windowHandle = glfwCreateWindow(mode.Width, mode.Height, title.c_str(),
				VideoMode::GetPrimaryMonitorHandle(), NULL);
			break;

		case Borderless:
			_windowHandle = glfwCreateWindow(mode.Width, mode.Height, title.c_str(), NULL, NULL);
			glfwSetWindowMonitor(_windowHandle, VideoMode::GetPrimaryMonitorHandle(), 0, 0,
				mode.Width, mode.Height, mode.RefreshRate);
			break;
		}
		if (!_windowHandle)
		{
			// ERROR
			return false;
		}
		glfwMakeContextCurrent(_windowHandle);

		// Initialize OpenGL with glad
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			// ERROR
			return false;
		}
		glEnable(GL_DEPTH_TEST);
		glViewport(0, 0, mode.Width, mode.Height);

		_initialized = true;
		return true;
	}
}
