#pragma once
#include "SolidBody.h"
#include "Sphere.h"

class CCone final :
	public CAbstractBody
{
public:
	CCone(double radius, double height, double density);
	~CCone(void);

	double GetRadius() const;
	double GetHeight() const;

	virtual bool IsDataMoreZero() const override;
	virtual double GetVolume() const override;
	virtual std::string GetInfo() const override;

private:
	double m_height, m_radius;
};