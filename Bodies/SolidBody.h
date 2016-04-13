#pragma once
#include "Body.h"

// rename to CAbstractBody
class CAbstractBody :
	public IBody
{
public:
	//TODO сделать конструктор явным
	explicit CAbstractBody(double density);
	~CAbstractBody();
	
	double GetDensity() const final;
	double GetMass() const final;
private:
	double m_density;
};