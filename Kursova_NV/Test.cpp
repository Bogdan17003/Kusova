
#define BOOST_TEST_MODULE mytests

#include <boost/test/included/unit_test.hpp>
#include "../Kursova_NV/Container.h"

BOOST_AUTO_TEST_CASE(Len_Test)
{
	Container C;
	BOOST_REQUIRE_EQUAL(0, C.Len());
	Cultural_institution *teater = new Theater("Theater named Lesia Ukrainka", "Ukraine", "Kiev", 1, "1", 1891, 23, 4);
	Cultural_institution *cinema = new Cinema("Oscar", "Ukraine", "Kiev", 1, "1", 2009, 8, 2, 2);
	C.Add_elem(teater);
	C.Add_elem(cinema);
	BOOST_REQUIRE_EQUAL(2, C.Len());
}

BOOST_AUTO_TEST_SUITE(TestAddElement)

BOOST_AUTO_TEST_CASE(Theater_test_add)
{
	Container C;
	
	Cultural_institution *teater = new Theater("Theater named Lesia Ukrainka", "Ukraine", "Kiev", 1, "1", 1891, 23, 4);
	C.Add_elem(teater);
	BOOST_REQUIRE_EQUAL(1, C.Len());
}

BOOST_AUTO_TEST_CASE(Cinema_test_add)
{
	Container C;

	Cultural_institution *cinema = new Cinema("Oscar", "Ukraine", "Kiev", 1, "1", 2009, 8, 2, 2);
	C.Add_elem(cinema);
	BOOST_REQUIRE_EQUAL(1, C.Len());
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestDeleteElement)

BOOST_AUTO_TEST_CASE(Theater_test_delete)
{
	Container C;

	Cultural_institution *teater = new Theater("Theater named Lesia Ukrainka", "Ukraine", "Kiev", 1, "1", 1891, 23, 4);
	C.Add_elem(teater);
	C.Delete_container();
	BOOST_REQUIRE_EQUAL(0, C.Len());
}

BOOST_AUTO_TEST_CASE(Cinema_test_delete)
{
	Container C;

	Cultural_institution *cinema = new Cinema("Oscar", "Ukraine", "Kiev", 1, "1", 2009, 8, 2, 2);
	C.Add_elem(cinema);
	C.Delete_container();
	BOOST_REQUIRE_EQUAL(0, C.Len());
}

BOOST_AUTO_TEST_CASE(Delete_all_container)
{
	Container C;

	Cultural_institution *cinema1 = new Cinema("Oscar", "Ukraine", "Kiev", 1, "5", 2009, 8, 2, 2);
	Cultural_institution *cinema2 = new Cinema("Oscar", "Ukraine", "Kiev", 2, "4", 2009, 8, 2, 2);
	Cultural_institution *cinema3 = new Cinema("Oscar", "Ukraine", "Kiev", 3, "3", 2009, 8, 2, 2);
	Cultural_institution *cinema4 = new Cinema("Oscar", "Ukraine", "Kiev", 4, "2", 2009, 8, 2, 2);
	Cultural_institution *cinema5 = new Cinema("Oscar", "Ukraine", "Kiev", 5, "1", 2009, 8, 2, 2);
	Cultural_institution *teater1 = new Theater("Theater named Lesia Ukrainka", "Ukraine", "Kiev", 1, "1", 1891, 23, 0);
	Cultural_institution *teater2 = new Theater("Theater named Lesia Ukrainka", "Ukraine", "Kiev", 1, "1", 1891, 23, 1);
	Cultural_institution *teater3 = new Theater("Theater named Lesia Ukrainka", "Ukraine", "Kiev", 1, "1", 1891, 23, 2);
	Cultural_institution *teater4 = new Theater("Theater named Lesia Ukrainka", "Ukraine", "Kiev", 1, "1", 1891, 23, 3);
	C.Add_elem(cinema1);
	C.Add_elem(cinema2);
	C.Add_elem(cinema3);
	C.Add_elem(cinema4);
	C.Add_elem(cinema5);
	C.Add_elem(teater1);
	C.Add_elem(teater2);
	C.Add_elem(teater3);
	C.Add_elem(teater4);
	C.Delete_container();
	BOOST_REQUIRE_EQUAL(0, C.Len());
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(Test_Check)

BOOST_AUTO_TEST_CASE(First_data)
{
	Container C;

	Cultural_institution *theater = new Theater("Theater named Lesia Ukrainka", "Ukraine", "Kiev", 1, "3", 2001, 23, 4);
	Cultural_institution *cinema = new Cinema("Oscar", "Ukraine", "Kiev", 5, "March", 2001, 8, 2, 2);

	BOOST_REQUIRE_EQUAL(0, C.Check(theater, cinema));

}
BOOST_AUTO_TEST_CASE(Second_month)
{
	Container C;

	Cultural_institution *theater = new Theater("Theater named Lesia Ukrainka", "Ukraine", "Kiev", 1, "March", 2000, 23, 4);
	Cultural_institution *cinema = new Cinema("Oscar", "Ukraine", "Kiev", 1, "1", 2000, 8, 2, 2);

	BOOST_REQUIRE_EQUAL(1, C.Check(theater, cinema));
}

BOOST_AUTO_TEST_CASE(Third_year)
{
	Container C;

	Cultural_institution *theater = new Theater("Theater named Lesia Ukrainka", "Ukraine", "Kiev", 1, "1", 1891, 23, 4);
	Cultural_institution *cinema = new Cinema("Oscar", "Ukraine", "Kiev", 1, "1", 2009, 8, 2, 2);

	BOOST_REQUIRE_EQUAL(0, C.Check(theater, cinema));
}

BOOST_AUTO_TEST_SUITE_END()