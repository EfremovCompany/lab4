#pragma once
#include "SolidBody.h"

class CParallelepiped final :
	public CAbstractBody
{
public:
	CParallelepiped(double width, double height, double depth, double density);
	~CParallelepiped(void);

	double GetWidth() const;
	double GetHeight() const;
	double GetDepth() const;

	virtual bool IsDataMoreZero() const override;
	virtual double GetVolume() const override;
	virtual std::string GetInfo() const override;

private:
	double m_width, m_height, m_depth;
};