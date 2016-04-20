#include "stdafx.h"
#include "../Bodies/Cone.h"

static const double EXPECTED_RADIUS = 9;
static const double EXPECTED_HEIGHT = 4.5;
static const double EXPECTED_DENSITY = 25000;

static const double WRONG_EXPECTED_RADIUS = -9;
static const double WRONG_EXPECTED_DENSITY = -25000;

struct ConeFixture
{
	CCone cone;
	CCone cone_fail;

	ConeFixture()
		: cone(EXPECTED_RADIUS, EXPECTED_HEIGHT, EXPECTED_DENSITY)
		, cone_fail(WRONG_EXPECTED_RADIUS, EXPECTED_HEIGHT, WRONG_EXPECTED_DENSITY)
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(Cone, ConeFixture)

BOOST_AUTO_TEST_CASE(HasDimensions)
{
	BOOST_CHECK_EQUAL(cone.IsDataMoreZero(), true);
	BOOST_CHECK_EQUAL(cone.GetHeight(), EXPECTED_HEIGHT);
	BOOST_CHECK_EQUAL(cone.GetRadius(), EXPECTED_RADIUS);
}

BOOST_AUTO_TEST_CASE(BadCylIsFail)
{
	BOOST_CHECK_EQUAL(cone_fail.IsDataMoreZero(), false);
}

BOOST_AUTO_TEST_CASE(HasDensity)
{
	BOOST_CHECK_EQUAL(cone.GetDensity(), EXPECTED_DENSITY);
}

BOOST_AUTO_TEST_CASE(HasVolume)
{
	const double EXPECTED_VOLUME = (1.0 / 3) * (M_PI * EXPECTED_RADIUS * EXPECTED_RADIUS) *
		EXPECTED_HEIGHT;
	BOOST_CHECK_EQUAL(cone.GetVolume(), EXPECTED_VOLUME);

	IBody &coneAsBody = cone;
	BOOST_CHECK_EQUAL(coneAsBody.GetVolume(), EXPECTED_VOLUME);
}

BOOST_AUTO_TEST_CASE(HasMass)
{
	const double EXPECTED_MASS = cone.GetVolume() * cone.GetDensity();
	BOOST_CHECK_EQUAL(cone.GetMass(), EXPECTED_MASS);
}

BOOST_AUTO_TEST_SUITE_END()