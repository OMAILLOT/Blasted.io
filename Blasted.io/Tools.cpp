#include "Tools.h"

/// <summary>
/// Lerp is a linear interpolation function for smoothly blending between two values.
/// </summary>
sf::Vector2f tools::Lerp(sf::Vector2f start, sf::Vector2f end, float percent)
{
	return start + (end - start) * percent;
}
