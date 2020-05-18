#include "gtest/gtest.h"
#include "formule.cpp"


//--------------------------------------------------------------------------------------------------------------------
//                                       Tests de la classe formule
//-------------------------------------------------------------------------------------------------------------

TEST(transforme, AND) 
{
    EXPECT_EQ(transforme(1, 3, 1), 1);
    EXPECT_EQ(transforme(1, 3, 0), 0);
    EXPECT_EQ(transforme(0, 3, 0), 0);
    EXPECT_EQ(transforme(0, 3, 1), 0);

}

TEST(transforme, OR) 
{
    EXPECT_EQ(transforme(1, 2, 1), 1);
    EXPECT_EQ(transforme(0, 2, 1), 1);
    EXPECT_EQ(transforme(1, 2, 0), 1);
    EXPECT_EQ(transforme(0, 2, 0), 0);
}