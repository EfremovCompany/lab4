#include "stdafx.h"
#include "SolidBody.h"

CAbstractBody::CAbstractBody(double density)
	:m_density(density)
{
}

CAbstractBody::~CAbstractBody()
{
}




double CAbstractBody::GetDensity() const
{
	return m_density;
}

double CAbstractBody::GetMass() const
{
	return GetDensity() * GetVolume();
}