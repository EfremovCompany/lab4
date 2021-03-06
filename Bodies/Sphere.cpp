#include "stdafx.h"
#include "Sphere.h"
#include <sstream>

CSphere::CSphere(double radius, double density)
	: CAbstractBody(density)
	, m_radius(radius)
{
}

CSphere::~CSphere(void)
{
}

double CSphere::GetRadius() const
{
	return m_radius;
}

bool CSphere::IsDataMoreZero() const
{
	// TODO: simplify
	if (m_radius > 0)
	{
		return true;
	}
	return false;
}

double CSphere::GetVolume() const
{
	return (4 * M_PI / 3 * pow(GetRadius(), 3));
}

std::string CSphere::GetInfo() const
{
	std::ostringstream info;

	info << "Sphere with radius " << GetRadius();
	info << " and density " << GetDensity();

	return info.str();
}