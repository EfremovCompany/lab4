#include "stdafx.h"
#include "../Bodies/Parallelepiped.h"

static const double EXPECTED_WIDTH = 3;
static const double EXPECTED_HEIGHT = 4.2;
static const double EXPECTED_DEPTH = 2;
static const double EXPECTED_DENSITY = 7700;

static const double WRONG_EXPECTED_WIDTH = -3;
static const double WRONG_EXPECTED_HEIGHT = -4.2;

struct ParallelepipedFixture
{
	CParallelepiped par;

	ParallelepipedFixture()
		: par(EXPECTED_WIDTH, EXPECTED_HEIGHT, EXPECTED_DEPTH,
			EXPECTED_DENSITY)
	{
	}
};

struct ParallelepipedFixtureFail
{
	CParallelepiped par_fail;

	ParallelepipedFixtureFail()
		: par_fail(WRONG_EXPECTED_WIDTH, WRONG_EXPECTED_HEIGHT, EXPECTED_DEPTH,
			EXPECTED_DENSITY)
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(Parallelepiped, ParallelepipedFixture)

BOOST_AUTO_TEST_CASE(HasDimensions)
{
	BOOST_CHECK_EQUAL(par.GetWidth(), EXPECTED_WIDTH);
	BOOST_CHECK_EQUAL(par.GetHeight(), EXPECTED_HEIGHT);
	BOOST_CHECK_EQUAL(par.GetDepth(), EXPECTED_DEPTH);
}

BOOST_AUTO_TEST_CASE(HasDensity)
{
	BOOST_CHECK_EQUAL(par.GetDensity(), EXPECTED_DENSITY);
}

BOOST_AUTO_TEST_CASE(HasVolume)
{
	const double EXPECTED_VOLUME = EXPECTED_WIDTH *
		EXPECTED_HEIGHT * EXPECTED_DEPTH;
	BOOST_CHECK_EQUAL(par.GetVolume(), EXPECTED_VOLUME);

	IBody &parallelepipedAsBody = par;
	BOOST_CHECK_EQUAL(parallelepipedAsBody.GetVolume(), EXPECTED_VOLUME);
}

BOOST_AUTO_TEST_CASE(HasWeight)
{
	const double EXPECTED_WEIGHT = par.GetVolume() * par.GetDensity();
	BOOST_CHECK_EQUAL(par.GetMass(), EXPECTED_WEIGHT);
}

BOOST_AUTO_TEST_CASE(HasInfo)
{
	const std::string info = par.GetInfo();
	std::ostringstream expectedInfo;

	expectedInfo << "Parallelepiped with width " << par.GetWidth();
	expectedInfo << ", height " << par.GetHeight();
	expectedInfo << ", depth " << par.GetDepth();
	expectedInfo << " and density " << par.GetDensity();

	BOOST_CHECK_EQUAL(expectedInfo.str(), info);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(par_fail, ParallelepipedFixtureFail)

BOOST_AUTO_TEST_CASE(IsMoreZero)
{
	BOOST_CHECK_EQUAL(par_fail.IsDataMoreZero(), false);
}

BOOST_AUTO_TEST_SUITE_END()