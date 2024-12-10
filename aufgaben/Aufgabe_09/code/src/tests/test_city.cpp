#include <cassert>
#include <string>
#include "../main/city.h"

oopTutorium::City createCity()
{
    std::string mordor = "Mordor";
    std::string pois[] = {"Sauron", "Minas Morgul", "Orodruin"};
    oopTutorium::City result(mordor, 47, 11, pois, 3);
    return result;
}

void testCtor()
{
    std::string pois[] = {"Sauron", "Minas Morgul", "Orodruin"};
    oopTutorium::City city("Mordor", 47, 11, pois, 3);
    pois[0] = "Gandalf";
    assert(city[0] == "Sauron");
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
    assert(city[0] == "Sauron");
    assert(city[1] == "Minas Morgul");
    assert(city[2] == "Orodruin");
    try
    {
        city[3];
        assert(false);
    }
    catch (...)
    {
    }
    try
    {
        city[-1];
        assert(false);
    }
    catch (...)
    {
    }
}

void testSetPOI()
{
    auto city = createCity();
    city[0] = "Gandalf";
    assert(city[0] == "Gandalf");

    try
    {
        city[3] = "Gandalf";
        assert(false);
    }
    catch (...)
    {
    }
    try
    {
        city[-1] = "Gandalf";
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
    mordor[2] = "Cirith Ungol";
    assert(copy[2] == "Orodruin");
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
    assert(city[2] == "Orodruin");
    oopTutorium::City empty("Mordor", 47, 11);
    empty.add("Orodruin");
    assert(empty.getNumberOfPOIs() == 1);
    assert(empty[0] == "Orodruin");
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
    assert(copy2[0] == "Minas Morgul");
    std::string saurons[] = {"Sauron", "Sauron", "Sauron"};
    oopTutorium::City same("Mordor", 47, 11, saurons, 3);
    assert(true == same.remove("Sauron"));
    assert(same.getNumberOfPOIs() == 0);
}

void testConsoleOutput()
{
    std::string pois[] = {"Sauron", "Minas Morgul", "Orodruin"};
    oopTutorium::City city("Mordor", 47, 11, pois, 3);
    std::cout << city << std::endl;
}

void testIndexOperator()
{
    auto city = createCity();
    assert(city[0] == "Sauron");
    assert(city[1] == "Minas Morgul");
    assert(city[2] == "Orodruin");
    try
    {
        city[3];
        assert(false);
    }
    catch (...)
    {
    }
    try
    {
        city[-1];
        assert(false);
    }
    catch (...)
    {
    }
    city[0] = "Gandalf";
    assert(city[0] == "Gandalf");
    try
    {
        city[3] = "Gandalf";
        assert(false);
    }
    catch (...)
    {
    }
    try
    {
        city[-1] = "Gandalf";
        assert(false);
    }
    catch (...)
    {
    }
    const auto constCity = createCity();
    assert(constCity[0] == "Sauron");
}

void testAssignmentOperator()
{
    std::string pois_morder[] = {"Sauron", "Minas Morgul", "Orodruin"};
    oopTutorium::City left("Mordor", 47, 11, pois_morder, 3);
    std::string pois_arrakis[] = {"Arrakeen", "Desert"};
    oopTutorium::City right("Arrakis", 23, 42, pois_arrakis, 2);
    left = right;
    assert(left.getName() == "Arrakis");
    assert(left.getX() == 23);
    assert(left.getY() == 42);
    assert(left.getNumberOfPOIs() == 2);
    assert(left[0] == pois_arrakis[0]);
    assert(left[1] == pois_arrakis[1]);
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
    testConsoleOutput();
    testIndexOperator();
    testAssignmentOperator();
}

int main()
{
    std::cout << "starting test_city...." << std::endl;
    testCity();
    std::cout << "...finished" << std::endl;
    return 0;
}