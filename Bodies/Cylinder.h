#pragma once
#include "SolidBody.h"

class CCylinder final :
	public CAbstractBody
{
public:
	CCylinder(double radius, double height, double density);
	~CCylinder(void);

	double GetRadius() const;
	double GetHeight() const;

	virtual bool IsDataMoreZero() const override;
	virtual double GetVolume() const override;
	virtual std::string GetInfo() const override;

private:
	double m_height, m_radius;
};
