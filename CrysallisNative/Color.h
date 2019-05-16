#pragma once

namespace CrysallisNative
{
	struct Color
	{
		float Red;
		float Blue;
		float Green;
		float Alpha;

		Color() :
			Red(0.0f),
			Blue(0.0f),
			Green(0.0f),
			Alpha(0.0f)
		{

		}

		Color(float red, float green, float blue, float alpha = 1.0f) :
			Red(red),
			Blue(blue),
			Green(green),
			Alpha(alpha)
		{

		}
	};
}