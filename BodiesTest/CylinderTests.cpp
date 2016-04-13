#include "stdafx.h"
#include "../Bodies/Cylinder.h"

static const double EXPECTED_RADIUS = 9;
static const double EXPECTED_HEIGHT = 4.5;
static const double EXPECTED_DENSITY = 25000;

static const double WRONG_EXPECTED_RADIUS = -9;
static const double WRONG_EXPECTED_DENSITY = -25000;

struct CylinderFixture
{
	CCylinder cylinder;

	CylinderFixture()
		: cylinder(EXPECTED_RADIUS, EXPECTED_HEIGHT, EXPECTED_DENSITY)
	{
	}
};

struct CylinderFailFixture
{
	CCylinder cylinder_fail;

	CylinderFailFixture()
		: cylinder_fail(WRONG_EXPECTED_RADIUS, EXPECTED_HEIGHT, WRONG_EXPECTED_DENSITY)
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(Cylinder, CylinderFixture)

BOOST_AUTO_TEST_CASE(HasDimensions)
{
	BOOST_CHECK_EQUAL(cylinder.GetHeight(), EXPECTED_HEIGHT);
	BOOST_CHECK_EQUAL(cylinder.GetRadius(), EXPECTED_RADIUS);
}

BOOST_AUTO_TEST_CASE(HasDensity)
{
	BOOST_CHECK_EQUAL(cylinder.GetDensity(), EXPECTED_DENSITY);
}

BOOST_AUTO_TEST_CASE(HasVolume)
{
	const double EXPECTED_VOLUME = (M_PI * EXPECTED_RADIUS * EXPECTED_RADIUS) *
		EXPECTED_HEIGHT;
	BOOST_CHECK_EQUAL(cylinder.GetVolume(), EXPECTED_VOLUME);

	IBody &cylinderAsBody = cylinder;
	BOOST_CHECK_EQUAL(cylinderAsBody.GetVolume(), EXPECTED_VOLUME);
}

BOOST_AUTO_TEST_CASE(HasMass)
{
	const double EXPECTED_MASS = cylinder.GetVolume() * cylinder.GetDensity();
	BOOST_CHECK_EQUAL(cylinder.GetMass(), EXPECTED_MASS);
}

BOOST_AUTO_TEST_CASE(HasInfo)
{
	const std::string info = cylinder.GetInfo();
	std::ostringstream expectedInfo;

	expectedInfo << "Cylinder with base radius " << cylinder.GetRadius();
	expectedInfo << ", height " << cylinder.GetHeight();
	expectedInfo << " and density " << cylinder.GetDensity();

	BOOST_CHECK_EQUAL(expectedInfo.str(), info);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(cylinder_fail, CylinderFailFixture)

BOOST_AUTO_TEST_CASE(IsZero)
{
	BOOST_CHECK_EQUAL(cylinder_fail.IsDataMoreZero(), false);
}

BOOST_AUTO_TEST_SUITE_END()