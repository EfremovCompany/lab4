#include "stdafx.h"
#include "Cone.h"
#include <sstream>

// TODO: use unified style for delimiters in initalization lists
CCone::CCone(double radius, double height, double density)
	: CAbstractBody(density)
	, m_radius(radius)
	, m_height(height)
{
}

CCone::~CCone(void)
{
}

double CCone::GetRadius() const
{
	return m_radius;
}

double CCone::GetHeight() const
{
	return m_height;
}

bool CCone::IsDataMoreZero() const
{
	return (m_height > 0 && m_radius > 0);
}

double CCone::GetVolume() const
{
	return (1.0 / 3) * (M_PI * m_radius * m_radius) * m_height;
}

std::string CCone::GetInfo() const
{
	std::ostringstream info;

	info << "Cone with base radius " << GetRadius();
	info << ", height " << GetHeight();
	info << " and density " << GetDensity();

	return info.str();
}