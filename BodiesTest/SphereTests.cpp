#include "stdafx.h"
#include "../Bodies/Sphere.h"

/* —фера
	имеет радиус
	имеет объем
	имеет плотность
	имеет массу
*/

static const double EXPECTED_RADIUS = 3.5;
static const double EXPECTED_DENSITY = 8920;
static const double EXPECTED_RADIUS_MINUS = -3.5;

struct SphereFixture
{
	CSphere sphere;
	CSphere sphere_bad;

	SphereFixture()
		:sphere(EXPECTED_RADIUS, EXPECTED_DENSITY), sphere_bad(EXPECTED_RADIUS_MINUS, EXPECTED_DENSITY)
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(Sphere, SphereFixture)

BOOST_AUTO_TEST_CASE(IsSphereOK)
{
	BOOST_CHECK_EQUAL(sphere.IsDataMoreZero(), true);
}

BOOST_AUTO_TEST_CASE(HasRadius)
{
	BOOST_CHECK_EQUAL(sphere.GetRadius(), EXPECTED_RADIUS);
}

BOOST_AUTO_TEST_CASE(CantLessZero)
{
	BOOST_CHECK_EQUAL(sphere_bad.IsDataMoreZero(), false);
}

BOOST_AUTO_TEST_CASE(HasVolume)
{
	const double EXPECTED_VOLUME = 4 * M_PI / 3 * pow(EXPECTED_RADIUS, 3);
	BOOST_CHECK_EQUAL(sphere.GetVolume(), EXPECTED_VOLUME);
	IBody & sphereAsBody = sphere;
	BOOST_CHECK_EQUAL(sphereAsBody.GetVolume(), EXPECTED_VOLUME);
}

BOOST_AUTO_TEST_CASE(HasDensity)
{
	BOOST_CHECK_EQUAL(sphere.GetDensity(), EXPECTED_DENSITY);
}

BOOST_AUTO_TEST_CASE(HasMass)
{
	BOOST_CHECK_EQUAL(sphere.GetMass(), EXPECTED_DENSITY * sphere.GetVolume());
}


BOOST_AUTO_TEST_SUITE_END()

