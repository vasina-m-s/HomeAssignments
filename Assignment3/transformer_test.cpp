/*
* Marina Vasina
* st140082@student.spbu.ru
* Assignment4
*/

#include <gtest/gtest.h>

#include <sstream>
#include "Transformer.h"
#include "Autobot.h"
#include "Decepticon.h"
#include "Maximal.h"
#include "Gun.h"
#include "Battle.h"

TEST(TransformerTest, SetGet) {
    Gun* g = new Gun("Blaster", 10);
    Gun* gu = new Gun("Pistol", 20);
    Battle b;
    Autobot t("Optimus", 10, 100, 10, b, g, 10, 17);

    EXPECT_EQ(t.getName(), "Optimus");
    EXPECT_EQ(t.getLevel(), 10);
    EXPECT_EQ(t.getHealth(), 100);
    EXPECT_EQ(t.getSpeed(), 10);
    EXPECT_EQ(t.getGun()->getModel(), "Blaster");
    EXPECT_EQ(t.getGun()->getDamage(), 10);

    t.setName("OtherPrime");
    t.setLevel(11);
    t.setHealth(50);
    t.setSpeed(15);
    t.setGun(gu);

    EXPECT_EQ(t.getName(), "OtherPrime");
    EXPECT_EQ(t.getLevel(), 11);
    EXPECT_EQ(t.getHealth(), 50);
    EXPECT_EQ(t.getSpeed(), 15);
    EXPECT_EQ(t.getGun()->getModel(), "Pistol");

}

TEST(TransformerTest, Methods) {
    Gun* g = new Gun("Gun", 10);
    Battle b;
    Autobot t("Bumblebee", 5, 150, 15, b, g, 10, 17);

    EXPECT_TRUE(t.move());
    EXPECT_TRUE(t.fire());
}


TEST(AutobotTest, SetGet)
{
    Gun* g = new Gun("Gun", 10);
    Battle b;

    Autobot a("Bumblebee", 5, 150, 15, b, g, 10, 13);

    EXPECT_EQ(a.getBravery(), 10);
    EXPECT_EQ(a.getAgility(), 13);

    a.setBravery(16);
    a.setAgility(17);

    EXPECT_EQ(a.getBravery(), 16);
    EXPECT_EQ(a.getAgility(), 17);
}

TEST(AutobotTest, Methods)
{
    	Gun* g = new Gun("Gun", 10);
    	Battle b;

    	Autobot a("Bumblebee", 5, 150, 15, b, g, 10, 13);

	testing::internal::CaptureStdout();
    	a.win();
    	std::string output = testing::internal::GetCapturedStdout();
    	EXPECT_NE(output.find("Autobot win()"), std::string::npos);

	testing::internal::CaptureStdout();
    	a.defend();
    	std::string output1 = testing::internal::GetCapturedStdout();
    	EXPECT_NE(output1.find("Autobot defend()"), std::string::npos);

	testing::internal::CaptureStdout();
    	a.transform();
    	std::string output2 = testing::internal::GetCapturedStdout();
    	EXPECT_NE(output2.find("Autobot transform()"), std::string::npos);

	testing::internal::CaptureStdout();
    	a.move();
    	std::string output3 = testing::internal::GetCapturedStdout();
    	EXPECT_NE(output3.find("move()"), std::string::npos);

	testing::internal::CaptureStdout();
    	a.fire();
    	std::string output4 = testing::internal::GetCapturedStdout();
    	EXPECT_NE(output4.find("fire()"), std::string::npos);
}

TEST(DecepticonTest, SetGet)
{
    Gun* g = new Gun("EvilGun", 20);
    Battle b;

    Decepticon d("Megatron", 7, 200, 12, b, g, 95, 85);

    // Проверяем начальные значения
    EXPECT_EQ(d.getEvil(), 95);
    EXPECT_EQ(d.getMind(), 85);

    // Меняем значения
    d.setEvil(100);
    d.setMind(90);

    EXPECT_EQ(d.getEvil(), 100);
    EXPECT_EQ(d.getMind(), 90);
}

TEST(DecepticonTest, Methods)
{
    	Gun* g = new Gun("DarkGun", 25);
    	Battle b;

    	Decepticon d("Starscream", 6, 180, 14, b, g, 80, 70);

    	EXPECT_TRUE(d.doEvilPlan());
	EXPECT_TRUE(d.evilLaugh());

	testing::internal::CaptureStdout();
    	d.transform();
    	std::string output = testing::internal::GetCapturedStdout();
    	EXPECT_NE(output.find("Decepticon transform()"), std::string::npos);

	testing::internal::CaptureStdout();
    	d.doEvilPlan();
    	std::string output1 = testing::internal::GetCapturedStdout();
    	EXPECT_NE(output1.find("Decepticon doEvilPlan()"), std::string::npos);

	testing::internal::CaptureStdout();
    	d.evilLaugh();
    	std::string output2 = testing::internal::GetCapturedStdout();
    	EXPECT_NE(output2.find("Decepticon evilLaugh()"), std::string::npos);
}

TEST(MaximalTest, SetGet)
{
    Gun* g = new Gun("PowerGun", 30);
    Battle b;

    Maximal m("Optimus", 8, 250, 15, b, g, "Bear", 100);

    EXPECT_EQ(m.getAnimal(), "Bear");
    EXPECT_EQ(m.getStrength(), 100);

    m.setAnimal("Tiger");
    m.setStrength(120);

    EXPECT_EQ(m.getAnimal(), "Tiger");
    EXPECT_EQ(m.getStrength(), 120);
}

TEST(MaximalTest, Methods)
{
    	Gun* g = new Gun("WildGun", 40);
    	Battle b;

    	Maximal m("Bumblebee", 6, 200, 12, b, g, "Wolf", 80);

    	EXPECT_TRUE(m.transformBeast());

	testing::internal::CaptureStdout();
    	m.transformBeast();
    	std::string output = testing::internal::GetCapturedStdout();
    	EXPECT_NE(output.find("Maximal transformBeast()"), std::string::npos);

	testing::internal::CaptureStdout();
    	m.transform();
    	std::string output1 = testing::internal::GetCapturedStdout();
    	EXPECT_NE(output1.find("Maximal transform()"), std::string::npos);

	testing::internal::CaptureStdout();
    	m.move();
    	std::string output2 = testing::internal::GetCapturedStdout();
    	EXPECT_NE(output2.find("Maximal move()"), std::string::npos);
}



TEST(TransformerTest, Vector)
{
    	Gun* g = new Gun("Gun", 10);
	Battle b;

    	std::vector<Transformer*> vec =
    	{
        new Autobot("A1", 1, 10, 15, b, g, 5, 50),
        new Autobot("A2", 2, 20, 25, b, g, 6, 60),
        new Autobot("A3", 3, 30, 35, b, g, 7, 70),
        new Decepticon("D1", 1, 10, 15, b, g, 10, 20),
        new Decepticon("D2", 2, 20, 25, b, g, 20, 30),
        new Decepticon("D3", 3, 30, 35, b, g, 30, 40),
        new Maximal("M1", 1, 10, 15, b, g, "wolf", 20),
        new Maximal("M2", 2, 20, 25, b, g, "fox", 30),
        new Maximal("M3", 3, 30, 35, b, g, "rabbit", 40),
	};

    for (auto* t : vec)
    {
        testing::internal::CaptureStdout();
        t->transform();
        std::string out = testing::internal::GetCapturedStdout();
        EXPECT_FALSE(out.empty());
    }

    for (auto* t : vec) delete t;
}
