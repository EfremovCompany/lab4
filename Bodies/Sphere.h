#pragma once
#include "Solidbody.h"

class CSphere final : public CAbstractBody
{
public:
	CSphere(double radius, double density);
	~CSphere(void);

	double GetRadius() const;
	
	virtual bool IsDataMoreZero() const override;
	double GetVolume() const override final;
	std::string GetInfo() const override final;
private:
	double m_radius;
};

