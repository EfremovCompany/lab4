#include "stdafx.h"
#include "Parallelepiped.h"
#include <sstream>

// TODO: use unified style for delimiters in initalization lists
CParallelepiped::CParallelepiped(double width, double height, double depth, double density)
	: CAbstractBody(density)
	, m_width(width)
	, m_height(height)
	, m_depth(depth)
{
}

CParallelepiped::~CParallelepiped(void)
{
}

double CParallelepiped::GetWidth() const
{
	return m_width;
}

double CParallelepiped::GetHeight() const
{
	return m_height;
}

double CParallelepiped::GetDepth() const
{
	return m_depth;
}


bool CParallelepiped::IsDataMoreZero() const
{
	// TODO: simplify
	if (m_width > 0 && m_height > 0 && m_depth > 0)
	{
		return true;
	}
	return false;
}

double CParallelepiped::GetVolume() const
{
	return GetWidth() * GetHeight() * GetDepth();
}

std::string CParallelepiped::GetInfo() const
{
	std::ostringstream info;

	info << "Parallelepiped with width " << GetWidth();
	info << ", height " << GetHeight();
	info << ", depth " << GetDepth();
	info << " and density " << GetDensity();

	return info.str();
}