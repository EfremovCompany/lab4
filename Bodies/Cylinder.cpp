#include "stdafx.h"
#include "Cylinder.h"
#include <sstream>

// TODO: use unified style for delimiters in initalization lists
CCylinder::CCylinder(double radius, double height, double density)
	: CAbstractBody(density)
	, m_radius(radius)
	, m_height(height)
{
	
}

CCylinder::~CCylinder(void)
{
}

double CCylinder::GetRadius() const
{
	return m_radius;
}

double CCylinder::GetHeight() const
{
	return m_height;
}



bool CCylinder::IsDataMoreZero() const
{
	// TODO: simplify method
	return (m_height > 0 && m_radius > 0);
}

double CCylinder::GetVolume() const
{
	return M_PI * m_radius * m_radius * m_height;
}

std::string CCylinder::GetInfo() const
{
	std::ostringstream info;

	info << "Cylinder with base radius " << GetRadius();
	info << ", height " << GetHeight();
	info << " and density " << GetDensity();

	return info.str();
}