#include "polinom.h"
#include <gtest.h>

typedef std::pair<int, double> monom;
typedef myList<monom, cmpMonom<double>> Lmonom;

polinom foo() {
	polinom v;
	std::string s = "123 * x1 y2 z3 + 1 * x0 y1 z0 - 10 * x3 y2 z0 - 12 * x1 y2 z3";
	std::istringstream sl;
	sl.str(s);
	sl >> v;
	return v;
}

TEST(polinom, can_create_polinom_with_no_operand) 
{
	ASSERT_NO_THROW(polinom p());
}

TEST(polinom, zero_polinom_seems_like_zero)
{
	polinom p;
	std::string s;
	std::ostringstream sl;
	sl.str(s);

	sl << p;
	EXPECT_EQ("0", sl.str());
}

TEST(polinom, can_create_polinom_with_list) 
{
	Lmonom l;
	monom m;

	m.first = 100;
	m.second = 1.0;
	l.append(m);
	m.first = 10;
	m.second = 2.0;
	l.append(m);
	m.first = 1;
	m.second = 3.0;
	l.append(m);

	ASSERT_NO_THROW(polinom p(l));
}

TEST(polinom, can_create_copied_polinom)
{
	Lmonom l;
	monom m;

	m.first = 100;
	m.second = 1.0;
	l.append(m);
	m.first = 10;
	m.second = 2.0;
	l.append(m);
	m.first = 1;
	m.second = 3.0;
	l.append(m);

	polinom p1(l);

	ASSERT_NO_THROW(polinom p2(p1));
}

TEST(polinom, can_create_moved_polinom)
{
	ASSERT_NO_THROW(polinom p2(foo()));
}

TEST(polinom, copied_polinom_is_equal_to_the_source_one) 
{
	Lmonom l;
	monom m;
	std::string example = "3 * x0 y0 z1 + 2 * x0 y1 z0 + 1 * x1 y0 z0 ";
	std::string s;
	std::ostringstream sl;
	sl.str(s);

	m.first = 100;
	m.second = 1.0;
	l.append(m);
	m.first = 10;
	m.second = 2.0;
	l.append(m);
	m.first = 1;
	m.second = 3.0;
	l.append(m);

	polinom p1(l);
	polinom p2(p1);

	sl << p2;
	EXPECT_EQ(example, sl.str());
}

TEST(polinom, moved_polinom_is_equal_to_source_one)
{
	Lmonom l;
	monom m;
	std::string example = "1 * x0 y1 z0 + 111 * x1 y2 z3 - 10 * x3 y2 z0 ";
	std::string s;
	std::ostringstream sl;
	sl.str(s);

	polinom p2(foo());
	sl << p2;
	EXPECT_EQ(example, sl.str());
}

TEST(polinom, copied_polinom_has_its_own_memory)
{
	Lmonom l;
	monom m;
	std::string example = "3 * x0 y0 z1 + 2 * x0 y1 z0 + 1 * x1 y0 z0 ";
	std::string s;
	std::ostringstream sl;
	sl.str(s);

	m.first = 100;
	m.second = 1.0;
	l.append(m);
	m.first = 10;
	m.second = 2.0;
	l.append(m);
	m.first = 1;
	m.second = 3.0;
	l.append(m);

	polinom p1(l);
	polinom p2(p1);
	p2 = 0.0 * p2;

	sl << p1;
	EXPECT_EQ(example, sl.str());
}

TEST(polinom, can_assign_polinom_to_itself)
{
	Lmonom l;
	monom m;

	m.first = 100;
	m.second = 1.0;
	l.append(m);
	m.first = 10;
	m.second = 2.0;
	l.append(m);
	m.first = 1;
	m.second = 3.0;
	l.append(m);

	polinom p1(l);

	ASSERT_NO_THROW(p1 = p1);
}

TEST(polinom, assign_polinom_to_itself_is_correct)
{
	Lmonom l;
	monom m;
	std::string example = "3 * x0 y0 z1 + 2 * x0 y1 z0 + 1 * x1 y0 z0 ";
	std::string s;
	std::ostringstream sl;
	sl.str(s);

	m.first = 100;
	m.second = 1.0;
	l.append(m);
	m.first = 10;
	m.second = 2.0;
	l.append(m);
	m.first = 1;
	m.second = 3.0;
	l.append(m);

	polinom p1(l);
	p1 = p1;

	sl << p1;
	EXPECT_EQ(example, sl.str());
}


TEST(polinom, can_assign_polinoms)
{
	Lmonom l;
	monom m;

	m.first = 100;
	m.second = 1.0;
	l.append(m);
	m.first = 10;
	m.second = 2.0;
	l.append(m);
	m.first = 1;
	m.second = 3.0;
	l.append(m);

	polinom p1(l);
	polinom p2;

	ASSERT_NO_THROW(p2 = p1);
}

TEST(polinom, assign_polinoms_is_correct)
{
	Lmonom l;
	monom m;
	std::string example = "3 * x0 y0 z1 + 2 * x0 y1 z0 + 1 * x1 y0 z0 ";
	std::string s;
	std::ostringstream sl;
	sl.str(s);

	m.first = 100;
	m.second = 1.0;
	l.append(m);
	m.first = 10;
	m.second = 2.0;
	l.append(m);
	m.first = 1;
	m.second = 3.0;
	l.append(m);

	polinom p1(l);
	polinom p2;
	p2 = p1;

	sl << p2;
	EXPECT_EQ(example, sl.str());
}

TEST(polinom, can_assign_move_polinoms)
{
	Lmonom l;
	monom m;

	m.first = 100;
	m.second = 1.0;
	l.append(m);
	m.first = 10;
	m.second = 2.0;
	l.append(m);
	m.first = 1;
	m.second = 3.0;
	l.append(m);

	polinom p1(l);
	
	ASSERT_NO_THROW(p1 = foo());
}

TEST(polinom, assign_move_polinoms_is_correct)
{
	Lmonom l;
	monom m;
	std::string example = "1 * x0 y1 z0 + 111 * x1 y2 z3 - 10 * x3 y2 z0 ";
	std::string s;
	std::ostringstream sl;
	sl.str(s);

	m.first = 100;
	m.second = 1.0;
	l.append(m);
	m.first = 10;
	m.second = 2.0;
	l.append(m);
	m.first = 1;
	m.second = 3.0;
	l.append(m);

	polinom p1(l);
	p1 = foo();

	sl << p1;
	EXPECT_EQ(example, sl.str());
}

/*
polinom v;
std::string s = "123 * x1 y2 z3 + 1 * x0 y1 z0 - 10 * x3 y2 z0 - 12 * x1 y2 z3";
std::istringstream sl;
sl.str(s);
sl >> v;
return v;
*/

TEST(polinom, can_add_polinoms)
{
	polinom p1;
	std::string s = "1 * x1 y0 z0 + 2 * x0 y1 z0 + 3 * x0 y0 z1";
	std::istringstream sl;
	sl.str(s);
	sl >> p1;
	sl.clear();

	polinom p2;
	s = "3 * x1 y0 z0 + 4 * x1 y1 z0 + 5 * x0 y0 z1";
	sl.str(s);
	sl >> p2;
	sl.clear();

	ASSERT_NO_THROW(p1 + p2);
}

TEST(polinom, addition_of_polinoms_is_correct_0) // monoms
{
	polinom p1;
	std::string s = "1 * x1 y0 z0 + 2 * x0 y1 z0 + 3 * x0 y0 z1";
	std::istringstream isl;
	isl.str(s);
	isl >> p1;
	isl.clear();

	polinom p2;
	s = "3 * x1 y0 z0";
	isl.str(s);
	isl >> p2;
	isl.clear();

	std::string example = "3 * x0 y0 z1 + 2 * x0 y1 z0 + 4 * x1 y0 z0 ";
	std::ostringstream osl;
	osl.str(s);
	polinom p3 = p1 + p2;
	osl << p3;
	
	EXPECT_EQ(example, osl.str());
}

TEST(polinom, addition_of_polinoms_is_correct_1) // polinoms
{
	polinom p1;
	std::string s = "1 * x1 y0 z0 + 2 * x0 y1 z0 + 3 * x0 y0 z1";
	std::istringstream isl;
	isl.str(s);
	isl >> p1;
	isl.clear();

	polinom p2;
	s = "-3 * x1 y0 z0 + 4 * x1 y1 z0 + 5 * x0 y0 z1";
	isl.str(s);
	isl >> p2;
	isl.clear();

	std::string example = "8 * x0 y0 z1 + 2 * x0 y1 z0 - 2 * x1 y0 z0 + 4 * x1 y1 z0 ";
	std::ostringstream osl;
	s.clear();
	osl.str(s);
	polinom p3 = p1 + p2;
	osl << p3;

	EXPECT_EQ(example, osl.str());
}

TEST(polinom, addition_of_polinoms_is_correct_2) // some of monoms are gone, e.g. (5x + 6y) + (5x - 6y). You sould calculate abs() < max*e-15;
{
	polinom p1;
	std::string s = "1e+20 * x1 y0 z0 + 2e+10 * x0 y1 z0 + 3 * x0 y0 z1";
	std::istringstream isl;
	isl.str(s);
	isl >> p1;
	isl.clear();

	polinom p2;
	s = "-5e+19 * x1 y0 z0 + 2e+10 * x1 y1 z0 + 5 * x0 y0 z1";
	isl.str(s);
	isl >> p2;
	isl.clear();

	std::string example = "2e+10 * x0 y1 z0 + 5e+19 * x1 y0 z0 + 2e+10 * x1 y1 z0 ";
	std::ostringstream osl;
	s.clear();
	osl.str(s);
	polinom p3 = p1 + p2;
	osl << p3;

	EXPECT_EQ(example, osl.str());
}

TEST(polinom, addition_of_polinoms_is_correct_3) // all of monoms are gone, e.g. (5x + 6y) + (-5x - 6y) 
{
	polinom p1;
	std::string s = "1 * x1 y0 z0 + 2 * x0 y1 z0 + 3 * x0 y0 z1";
	std::istringstream isl;
	isl.str(s);
	isl >> p1;
	isl.clear();

	polinom p2;
	s = "-1 * x1 y0 z0 - 2 * x0 y1 z0 - 3 * x0 y0 z1";
	isl.str(s);
	isl >> p2;
	isl.clear();

	std::string example = "0";
	std::ostringstream osl;
	s.clear();
	osl.str(s);
	polinom p3 = p1 + p2;
	osl << p3;

	EXPECT_EQ(example, osl.str());
}

TEST(polinom, addition_of_polinoms_is_correct_4) // all of monoms are gone, e.g. (5x + 6y) + (-5x - 6y) 
{
	polinom p1;
	std::string s = "1 * x1 y0 z0 + 2 * x0 y1 z0 + 3 * x0 y0 z1";
	std::istringstream isl;
	isl.str(s);
	isl >> p1;
	isl.clear();

	polinom p2;
	s = "-1 * x1 y0 z0 - 2 * x0 y1 z0 - 3 * x0 y0 z1";
	isl.str(s);
	isl >> p2;
	p2 = p2 * 1.000000000000001;
	isl.clear();

	std::string example = "- 3.55271e-15 * x0 y0 z1 ";
	std::ostringstream osl;
	s.clear();
	osl.str(s);
	polinom p3 = p1 + p2;
	osl << p3;

	EXPECT_EQ(example, osl.str());
}

TEST(polinom, can_left_multiplication)
{

}

TEST(polinom, left_multiplication_is_correct)
{

}

TEST(polinom, right_multiplication_is_correct)
{

}

TEST(polinom, can_multiplicate_polinoms)
{

}

TEST(polinom, multiplication_of_polinoms_is_correct_0) // one monom
{

}

TEST(polinom, multiplication_of_polinoms_is_correct_1) // polinom
{

}

TEST(polinom, multiplication_of_polinoms_is_correct_2) // squared polinom
{

}

TEST(polinom, multiplication_of_polinoms_is_correct_3) // zero polinom
{

}

TEST(polinom, cant_multiply_too_big_polinoms) // degree is too big
{

}

TEST(polinom, can_calculate_polinom)
{

}

TEST(polinom, calculation_polinom_is_correct_0) // one monom
{

}

TEST(polinom, calculation_polinom_is_correct_1) // polinom
{

}

TEST(polinom, calculation_polinom_is_correct_2) // zero polinom
{

}

TEST(polinom, can_print_polinom)
{

}

TEST(polinom, can_enter_polinom)
{

}

TEST(polinom, printed_polinom_is_correct)
{

}

TEST(polinom, entered_polinom_is_correct)
{

}
