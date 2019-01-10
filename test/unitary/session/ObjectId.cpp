#include <gtest/gtest.h>

extern "C"
{
#include "../src/c/core/session/object_id.c"
}

TEST(ObjectIDTest, Initialization)
{
    uxrObjectId object = uxr_object_id(0xAAAA, 0xBB);
    EXPECT_EQ(0xAAAA, object.id);
    EXPECT_EQ(0xBB, object.type);
}

TEST(ObjectIDTest, FromRaw)
{
    uint16_t data = 0xABAA;
    uxrObjectId object = uxr_object_id_from_raw(reinterpret_cast<uint8_t*>(&data));
    EXPECT_EQ(0x0AAA, object.id);
    EXPECT_EQ(0x0B, object.type);
}

TEST(ObjectIDTest, ToRaw)
{
    uint16_t data = 0;
    uxrObjectId object = uxr_object_id(0xAAAA, 0xBB);
    uxr_object_id_to_raw(object, reinterpret_cast<uint8_t*>(&data));
    EXPECT_EQ(0xABAA, data);
}

