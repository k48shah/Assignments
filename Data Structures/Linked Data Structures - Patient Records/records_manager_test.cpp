//Kathan Shah 20713485
//Harim Park 20744108
#include "records_manager_test.hpp"
#include "records_manager.hpp"

using namespace std;

bool RecordsManagerTest::test1(RecordsManager* manager)
{
	return manager->insertRecord(1002, 315, "Inserted Identity", "Random Street", "31/10/96");
}

bool RecordsManagerTest::test2(RecordsManager* manager)
{
	return manager->insertRecord(1000, 500, "Same CatID", "Sesame Street", "32/13/19");
}

bool RecordsManagerTest::test3(RecordsManager* manager)
{
	return manager->insertRecord(1004, 212, "HackerMan", "Hacker Street", "h4x3d");
}

bool RecordsManagerTest::test4(RecordsManager* manager)
{
	return manager->removeRecord(1003, 212);
}

bool RecordsManagerTest::test5(RecordsManager* manager)
{
	manager->insertRecord(1030, 65, "Test Subject 1", "Test Street", "24/12/99");
	manager->insertRecord(1011, 323, "Test Subject 2", "Test Street", "24/12/99");
	return manager->insertRecord(1024, 276, "Over Capacity", "Unknown", "25/12/95");
}

bool RecordsManagerTest::test6(RecordsManager* manager)
{
	return manager->removeRecord(1004, 212);
}

bool RecordsManagerTest::test7(RecordsManager* manager)
{
	return manager->removeRecord(1, 1);
}

bool RecordsManagerTest::test8(RecordsManager* manager)
{
	return manager->insertRecord(2030, 65, "Test Subject 1", "Test Street", "24/12/99") 
	* manager->insertRecord(1000, 299, "Test Subject 2", "Test Street", "24/12/99");
}

bool RecordsManagerTest::test9(RecordsManager* manager)
{
	return manager->removeRecord(1000, 300) * manager->removeRecord(1004, 212);
}
