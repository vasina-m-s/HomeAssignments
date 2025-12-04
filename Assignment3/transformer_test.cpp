/*
* Marina Vasina
* st140082@student.spbu.ru
* Assignment3
*/

#include <gtest/gtest.h>

#include "Transformer.h"
#include "Autobot.h"
#include "Decepticon.h"
#include "Maximal.h"

TEST(TransformerTest, SetGet) {
    Gun* g = new Gun("Blaster", 10);
    Gun* gu = new Gun("Pistol", 20);
    Battle b;
    Transformer t("Optimus", 10, 100, 10, b, g);

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
    Transformer t("Bumblebee", 5, 150, 15, b, g);

    EXPECT_TRUE(t.move());
    EXPECT_TRUE(t.fire());
    EXPECT_TRUE(t.transform());
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

    EXPECT_TRUE(a.win());
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
}
