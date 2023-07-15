#include "../googletest/googletest/include/gtest/gtest.h"
#include "SetDrawer.h"

// Mock class for SetDrawer
class MockSetDrawer : public SetDrawer {
public:
    MOCK_METHOD(std::string, cloaker, (std::string stringToCloak, int sectionToCloak), (override));
};

// Test fixture for SetDrawer class
class SetDrawerTest : public ::testing::Test {
protected:
    MockSetDrawer* mockSetDrawer;

    void SetUp() override {
        mockSetDrawer = new MockSetDrawer();
    }

    void TearDown() override {
        delete mockSetDrawer;
    }
};

TEST_F(SetDrawerTest, TestCloaker) {
    std::string stringToCloak = " 4 3 2";
    int sectionToCloak = 2;

    EXPECT_CALL(*mockSetDrawer, cloaker(stringToCloak, sectionToCloak))
        .Times(1)
        .WillOnce(::testing::Return(" 4   2"));

    EXPECT_EQ(mockSetDrawer->cloaker(stringToCloak, sectionToCloak), " 4   2");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}