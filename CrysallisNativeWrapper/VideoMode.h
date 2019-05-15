#pragma once

#include "../CrysallisNative/VideoMode.h"

using namespace System;
using namespace System::Collections::Generic;

namespace CrysallisNativeWrapper
{
	public ref class VideoMode
	{
	public:
		property unsigned int Width
		{
			unsigned int get()
			{
				return _videoMode->Width;
			}

			void set(unsigned int value)
			{
				_videoMode->Width = value;
			}
		}

		property unsigned int Height
		{
			unsigned int get()
			{
				return _videoMode->Height;
			}

			void set(unsigned int value)
			{
				_videoMode->Height = value;
			}
		}

		property unsigned int RefreshRate
		{
			unsigned int get()
			{
				return _videoMode->RefreshRate;
			}

			void set(unsigned int value)
			{
				_videoMode->RefreshRate = value;
			}
		}

		VideoMode();
		VideoMode(unsigned int modeWidth, unsigned int modeHeight);
		VideoMode(unsigned int modeWidth, unsigned int modeHeight, unsigned int modeRefreshRate);

		inline bool IsValid()
		{
			return _videoMode->IsValid();
		}

		static VideoMode^ GetDesktopMode();
		static List<VideoMode^>^ GetFullScreenModes();

	private:
		CrysallisNative::VideoMode* _videoMode;
	};
}
