#include "google_test.h"
#include "StringUtils.h"

class StringUtilsTest : public ::testing::Test
{
protected:
    ~StringUtilsTest();
};

StringUtilsTest::~StringUtilsTest() = default;

TEST_F(StringUtilsTest, removeSubstring)
{
    std::string target("one two threeone five one");
    std::string result = StringUtils::removeSubstring(target, "one");
    EXPECT_EQ(result, " two three five ");
}

TEST_F(StringUtilsTest, toLower)
{
    std::string target("QyQz");
    EXPECT_EQ(StringUtils::to_lower(target), std::string("qyqz"));
}
