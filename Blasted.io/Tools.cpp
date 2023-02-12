#include "Tools.h"

/// <summary>
/// Lerp is a linear interpolation function for smoothly blending between two values.
/// </summary>
sf::Vector2f tools::Lerp(sf::Vector2f start, sf::Vector2f end, float percent)
{
	return start + (end - start) * percent;
}

sf::Vector2f tools::normalize(sf::Vector2f vector)
{
	float length = sqrt((vector.x * vector.x) + (vector.y * vector.y));
	if (length != 0)
		return sf::Vector2f(vector.x / length, vector.y / length);
	else
		return vector;
	return sf::Vector2f();
}