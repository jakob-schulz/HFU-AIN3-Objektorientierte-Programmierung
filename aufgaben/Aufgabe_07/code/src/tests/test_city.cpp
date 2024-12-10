#include <cassert>
#include <string>
#include "../main/city.h"

oopTutorium::City createCity()
{
    std::string pois[] = {"Sauron", "Minas Morgul", "Orodruin"};
    oopTutorium::City result("Mordor", 47, 11, pois, 3);
    return result;
}

void testCtor()
{
    std::string pois[] = {"Sauron", "Minas Morgul", "Orodruin"};
    oopTutorium::City city("Mordor", 47, 11, pois, 3);
    pois[0] = "Gandalf";
    assert(city.getPOI(0) == "Sauron");
}

void testGetNameXY()
{
    oopTutorium::City city("Mordor", 47, 11, nullptr, 0);
    assert(city.getName() == "Mordor");
    assert(city.getX() == 47);
    assert(city.getY() == 11);
}

void testGetPOI()
{
    auto city = createCity();
    assert(city.getPOI(0) == "Sauron");
    assert(city.getPOI(1) == "Minas Morgul");
    assert(city.getPOI(2) == "Orodruin");
    try
    {
        city.getPOI(3);
        assert(false);
    }
    catch (...)
    {
    }
    try
    {
        city.getPOI(-1);
        assert(false);
    }
    catch (...)
    {
    }
}

void testSetPOI()
{
    auto city = createCity();
    city.setPOI(0, "Gandalf");
    assert(city.getPOI(0) == "Gandalf");

    try
    {
        city.setPOI(3, "Gandalf");
        assert(false);
    }
    catch (...)
    {
    }
    try
    {
        city.setPOI(-1, "Gandalf");
        assert(false);
    }
    catch (...)
    {
    }
}

void testGetNumberOfPOIs()
{
    auto city = createCity();
    assert(city.getNumberOfPOIs() == 3);
}

void testCopyConstructor()
{
    std::string pois[] = {"Sauron", "Minas Morgul", "Orodruin"};
    oopTutorium::City mordor("Mordor", 47, 11, pois, 3);
    auto copy = mordor;
    mordor.setPOI(2, "Cirith Ungol");
    assert(copy.getPOI(2) == "Orodruin");
}

void testCityWithoutPOIs()
{
    oopTutorium::City city("Mordor", 47, 11, nullptr, 0);
    assert(city.getNumberOfPOIs() == 0);
    try
    {
        oopTutorium::City city("Mordor", 47, 11, nullptr, 23);
        assert(false);
    }
    catch (...)
    {
    }
    oopTutorium::City empty("Mordor", 47, 11);
    assert(empty.getNumberOfPOIs() == 0);
}

void testAddMethod()
{
    std::string pois[] = {"Sauron", "Minas Morgul"};
    oopTutorium::City city("Mordor", 47, 11, pois, 2);
    city.add("Orodruin");
    assert(city.getNumberOfPOIs() == 3);
    assert(city.getPOI(2) == "Orodruin");
    oopTutorium::City empty("Mordor", 47, 11);
    empty.add("Orodruin");
    assert(empty.getNumberOfPOIs() == 1);
    assert(empty.getPOI(0) == "Orodruin");
}

void testRemoveMethod()
{
    std::string pois[] = {"Sauron", "Minas Morgul", "Orodruin"};
    oopTutorium::City city("Mordor", 47, 11, pois, 3);
    oopTutorium::City copy1 = city;
    assert(true == copy1.remove("Orodruin"));
    assert(copy1.getNumberOfPOIs() == 2);
    assert(false == copy1.remove("Shire"));
    oopTutorium::City copy2 = city;
    assert(true == copy2.remove("Sauron"));
    assert(copy2.getNumberOfPOIs() == 2);
    assert(copy2.getPOI(0) == "Minas Morgul");
    std::string saurons[] = {"Sauron", "Sauron", "Sauron"};
    oopTutorium::City same("Mordor", 47, 11, saurons, 3);
    assert(true == same.remove("Sauron"));
    assert(same.getNumberOfPOIs() == 0);
}

void test_consoleOutput()
{
    std::string pois[] = {"Sauron", "Minas Morgul", "Orodruin"};
    oopTutorium::City city("Mordor", 47, 11, pois, 3);
    std::cout << city << std::endl;
}

void testCity()
{
    testCtor();
    testGetNameXY();
    testGetPOI();
    testSetPOI();
    testGetNumberOfPOIs();
    testCopyConstructor();
    testCityWithoutPOIs();
    testAddMethod();
    testRemoveMethod();
    test_consoleOutput();
}

int main()
{
    std::cout << "starting test_city...." << std::endl;
    testCity();
    std::cout << "...finished" << std::endl;
    return 0;
}