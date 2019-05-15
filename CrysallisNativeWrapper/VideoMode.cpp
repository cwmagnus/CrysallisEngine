#include "VideoMode.h"

namespace CrysallisNativeWrapper
{
	VideoMode::VideoMode() : 
		_videoMode(new CrysallisNative::VideoMode())
	{

	}

	VideoMode::VideoMode(unsigned int modeWidth, unsigned int modeHeight) :
		_videoMode(new CrysallisNative::VideoMode(modeWidth, modeHeight, 60))
	{

	}

	VideoMode::VideoMode(unsigned int modeWidth, unsigned int modeHeight, unsigned int modeRefreshRate) :
		_videoMode(new CrysallisNative::VideoMode(modeWidth, modeHeight, modeRefreshRate))
	{

	}

	VideoMode^ VideoMode::GetDesktopMode()
	{
		CrysallisNative::VideoMode nativeMode = CrysallisNative::VideoMode::GetDesktopMode();
		VideoMode^ mode = gcnew VideoMode(nativeMode.Width, nativeMode.Height, nativeMode.RefreshRate);
		return mode;
	}

	List<VideoMode^>^ VideoMode::GetFullScreenModes()
	{
		List<VideoMode^>^ videoModes = gcnew List<VideoMode^>();
		for (CrysallisNative::VideoMode nativeMode : CrysallisNative::VideoMode::GetFullScreenModes())
		{
			videoModes->Add(gcnew VideoMode(nativeMode.Width, nativeMode.Height, nativeMode.RefreshRate));
		}
		return videoModes;
	}
}