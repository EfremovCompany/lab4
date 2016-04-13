#pragma once

#include "Body.h"
#include <vector>
#include <memory>

class CCompound final :
	public IBody
{
public:

	bool AddBody(const std::shared_ptr<IBody> &body);

	size_t GetContentsCount() const;

	virtual bool IsDataMoreZero() const override;
	virtual double GetVolume() const override;
	virtual double GetDensity() const override;
	virtual double GetMass() const override;
	virtual std::string GetInfo() const override;

private:
	std::vector<std::shared_ptr<IBody>> m_contents;

	bool HasBodyInside(const IBody *body) const;
};