#include "gtest/gtest.h"

#include<PRNG.h>

#include <array>

using namespace std;

namespace {

class PRNGTest : public ::testing::Test {
    protected:
    PRNG rng;

    virtual void SetUp() {
       
        static const array<uint64_t, 16> seed
                = {{0x374be26ee31f1e78, 0xd4eef394f72f149b, 0x91cb5a7001068c8b, 0x718ef6c2be5efbe7,
                    0xbb0dd94396008d70, 0x4f0996d1cd72d2d8, 0x2419b74e0b39e9b3, 0x0da693cf50e1396e,
                    0xcaec0e7f4cae7ffa, 0x350b63e4717957c6, 0xbe8460185de680dc, 0xff18c7a0efbcec26,
                    0xff1a72bb0ca9ac7f, 0x3b4818e046188158, 0xcac3e320230a44ba, 0xcaf9544740fbd288}};
        rng.setSeed(seed);
    }

    virtual void TearDown() {

    }
};

TEST_F(PRNGTest, test_positive_bits_occur)
{
    uint64_t result = 0;
    for(unsigned int i = 0; i < 20; i++) {
        result |= rng.getRandomUnsignedLongLong(0xffffffffffffffff);
    }
    result &= 0xffffffffffffffff;
    EXPECT_EQ(0xffffffffffffffff, result);
}

TEST_F(PRNGTest, test_negative_bits_occur)
{
    uint64_t result = 0xffffffffffffffff;
    for(unsigned int i = 0; i < 20; i++) {
        result &= rng.getRandomUnsignedLongLong(0xffffffffffffffff);
    }
    EXPECT_EQ(0, result);
}

TEST_F(PRNGTest, test_uniform_results_unsigned_char)
{
    int bins[5]{0};
    for(unsigned int i = 0; i < 100000; i++) {
        bins[rng.getRandomUnsignedChar(4)]++;
    }
    EXPECT_LT(bins[0], 21000);
    EXPECT_GT(bins[0], 19000);
    EXPECT_LT(bins[1], 21000);
    EXPECT_GT(bins[1], 19000);
    EXPECT_LT(bins[2], 21000);
    EXPECT_GT(bins[2], 19000);
    EXPECT_LT(bins[3], 21000);
    EXPECT_GT(bins[3], 19000);
    EXPECT_LT(bins[4], 21000);
    EXPECT_GT(bins[4], 19000);
}

TEST_F(PRNGTest, test_uniform_results_unsigned_int)
{
    int bins[5]{0};
    for(unsigned int i = 0; i < 100000; i++) {
        bins[rng.getRandomUnsignedInt(4)]++;
    }
    EXPECT_LT(bins[0], 21000);
    EXPECT_GT(bins[0], 19000);
    EXPECT_LT(bins[1], 21000);
    EXPECT_GT(bins[1], 19000);
    EXPECT_LT(bins[2], 21000);
    EXPECT_GT(bins[2], 19000);
    EXPECT_LT(bins[3], 21000);
    EXPECT_GT(bins[3], 19000);
    EXPECT_LT(bins[4], 21000);
    EXPECT_GT(bins[4], 19000);
}

TEST_F(PRNGTest, test_uniform_results_unsigned_long)
{
    int bins[5]{0};
    for(unsigned int i = 0; i < 100000; i++) {
        bins[rng.getRandomUnsignedLong(4)]++;
    }
    EXPECT_LT(bins[0], 21000);
    EXPECT_GT(bins[0], 19000);
    EXPECT_LT(bins[1], 21000);
    EXPECT_GT(bins[1], 19000);
    EXPECT_LT(bins[2], 21000);
    EXPECT_GT(bins[2], 19000);
    EXPECT_LT(bins[3], 21000);
    EXPECT_GT(bins[3], 19000);
    EXPECT_LT(bins[4], 21000);
    EXPECT_GT(bins[4], 19000);
}

TEST_F(PRNGTest, test_uniform_results_unsigned_long_long)
{
    int bins[5]{0};
    for(unsigned int i = 0; i < 100000; i++) {
        bins[rng.getRandomUnsignedLongLong(4)]++;
    }
    EXPECT_LT(bins[0], 21000);
    EXPECT_GT(bins[0], 19000);
    EXPECT_LT(bins[1], 21000);
    EXPECT_GT(bins[1], 19000);
    EXPECT_LT(bins[2], 21000);
    EXPECT_GT(bins[2], 19000);
    EXPECT_LT(bins[3], 21000);
    EXPECT_GT(bins[3], 19000);
    EXPECT_LT(bins[4], 21000);
    EXPECT_GT(bins[4], 19000);
}

TEST_F(PRNGTest, test_uniform_results_int)
{
    int bins[5]{0};
    for(unsigned int i = 0; i < 100000; i++) {
        bins[rng.getRandomInt(3, 7) - 3]++;
    }
    EXPECT_LT(bins[0], 21000);
    EXPECT_GT(bins[0], 19000);
    EXPECT_LT(bins[1], 21000);
    EXPECT_GT(bins[1], 19000);
    EXPECT_LT(bins[2], 21000);
    EXPECT_GT(bins[2], 19000);
    EXPECT_LT(bins[3], 21000);
    EXPECT_GT(bins[3], 19000);
    EXPECT_LT(bins[4], 21000);
    EXPECT_GT(bins[4], 19000);
}

TEST_F(PRNGTest, test_uniform_results_long)
{
    int bins[5]{0};
    for(unsigned int i = 0; i < 100000; i++) {
        bins[rng.getRandomLong(3, 7) - 3]++;
    }
    EXPECT_LT(bins[0], 21000);
    EXPECT_GT(bins[0], 19000);
    EXPECT_LT(bins[1], 21000);
    EXPECT_GT(bins[1], 19000);
    EXPECT_LT(bins[2], 21000);
    EXPECT_GT(bins[2], 19000);
    EXPECT_LT(bins[3], 21000);
    EXPECT_GT(bins[3], 19000);
    EXPECT_LT(bins[4], 21000);
    EXPECT_GT(bins[4], 19000);
}

TEST_F(PRNGTest, test_uniform_results_long_long)
{
    int bins[5]{0};
    for(unsigned int i = 0; i < 100000; i++) {
        bins[rng.getRandomLongLong(3, 7) - 3]++;
    }
    EXPECT_LT(bins[0], 21000);
    EXPECT_GT(bins[0], 19000);
    EXPECT_LT(bins[1], 21000);
    EXPECT_GT(bins[1], 19000);
    EXPECT_LT(bins[2], 21000);
    EXPECT_GT(bins[2], 19000);
    EXPECT_LT(bins[3], 21000);
    EXPECT_GT(bins[3], 19000);
    EXPECT_LT(bins[4], 21000);
    EXPECT_GT(bins[4], 19000);
}

TEST_F(PRNGTest, test_uniform_results_float)
{
    int totalLow = 0;
    for(unsigned int i = 0; i < 100000; i++) {
        if(rng.getRandomFloat() < 0.2)
            totalLow++;
    }
    EXPECT_LT(totalLow, 21000);
    EXPECT_GT(totalLow, 19000);
}

TEST_F(PRNGTest, test_uniform_results_double)
{
    int totalLow = 0;
    for(unsigned int i = 0; i < 100000; i++) {
        if(rng.getRandomDouble() < 0.2)
            totalLow++;
    }
    EXPECT_LT(totalLow, 21000);
    EXPECT_GT(totalLow, 19000);
}

TEST_F(PRNGTest, test_uniform_results_long_double)
{
    int totalLow = 0;
    for(unsigned int i = 0; i < 100000; i++) {
        if(rng.getRandomLongDouble() < 0.2)
            totalLow++;
    }
    EXPECT_LT(totalLow, 21000);
    EXPECT_GT(totalLow, 19000);
}

TEST_F(PRNGTest, test_uniform_results_max_float)
{
    int totalLow = 0;
    for(unsigned int i = 0; i < 100000; i++) {
        if(rng.getRandomFloat(5) < 1)
            totalLow++;
    }
    EXPECT_LT(totalLow, 21000);
    EXPECT_GT(totalLow, 19000);
}

TEST_F(PRNGTest, test_uniform_results_max_double)
{
    int totalLow = 0;
    for(unsigned int i = 0; i < 100000; i++) {
        if(rng.getRandomDouble(5) < 1)
            totalLow++;
    }
    EXPECT_LT(totalLow, 21000);
    EXPECT_GT(totalLow, 19000);
}

TEST_F(PRNGTest, test_uniform_results_max_long_double)
{
    int totalLow = 0;
    for(unsigned int i = 0; i < 100000; i++) {
        if(rng.getRandomLongDouble(5) < 1)
            totalLow++;
    }
    EXPECT_LT(totalLow, 21000);
    EXPECT_GT(totalLow, 19000);
}

TEST_F(PRNGTest, test_uniform_results_min_max_float)
{
    int totalLow = 0;
    for(unsigned int i = 0; i < 100000; i++) {
        if(rng.getRandomFloat(1, 6) < 2)
            totalLow++;
    }
    EXPECT_LT(totalLow, 21000);
    EXPECT_GT(totalLow, 19000);
}

TEST_F(PRNGTest, test_uniform_results_min_max_double)
{
    int totalLow = 0;
    for(unsigned int i = 0; i < 100000; i++) {
        if(rng.getRandomDouble(1, 6) < 2)
            totalLow++;
    }
    EXPECT_LT(totalLow, 21000);
    EXPECT_GT(totalLow, 19000);
}

TEST_F(PRNGTest, test_uniform_results_min_max_long_double)
{
    int totalLow = 0;
    for(unsigned int i = 0; i < 100000; i++) {
        if(rng.getRandomLongDouble(1, 6) < 2)
            totalLow++;
    }
    EXPECT_LT(totalLow, 21000);
    EXPECT_GT(totalLow, 19000);
}

TEST_F(PRNGTest, test_large_uniform)
{
    int bins[3]{0};
    uint64_t limits[3];
    limits[0] = std::numeric_limits<uint64_t>::max() / 4;
    limits[1] = limits[0] * 2;
    limits[2] = limits[0] * 3;
    for(unsigned int i = 0; i < 33333; i++) {
        uint64_t rand = rng.getRandomUnsignedLongLong(limits[2]);
        if(rand < limits[0])
            bins[0]++;
        else if(rand < limits[1])
            bins[1]++;
        else
            bins[2]++;
    }
    EXPECT_LT(bins[0], 12111);
    EXPECT_GT(bins[0], 10111);
    EXPECT_LT(bins[1], 12111);
    EXPECT_GT(bins[1], 10111);
    EXPECT_LT(bins[2], 12111);
    EXPECT_GT(bins[2], 10111);

}

TEST_F(PRNGTest, test_max_bound_unsigned_char)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_LE(rng.getRandomUnsignedChar(2), 2);
    }
}

TEST_F(PRNGTest, test_min_bound_unsigned_char)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_GE(rng.getRandomUnsignedChar(2), 0);
    }
}

TEST_F(PRNGTest, test_max_bound_unsigned_int)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_LE(rng.getRandomUnsignedInt(2), 2);
    }
}

TEST_F(PRNGTest, test_min_bound_unsigned_int)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_GE(rng.getRandomUnsignedInt(2), 0);
    }
}

TEST_F(PRNGTest, test_max_bound_unsigned_long)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_LE(rng.getRandomUnsignedLong(2), 2);
    }
}

TEST_F(PRNGTest, test_min_bound_unsigned_long)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_GE(rng.getRandomUnsignedLong(2), 0);
    }
}

TEST_F(PRNGTest, test_max_bound_unsigned_long_long)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_LE(rng.getRandomUnsignedLongLong(2), 2);
    }
}

TEST_F(PRNGTest, test_min_bound_unsigned_long_long)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_GE(rng.getRandomUnsignedLongLong(2), 0);
    }
}

TEST_F(PRNGTest, test_max_bound_char)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_LE(rng.getRandomChar(1, 3), 3);
    }
}

TEST_F(PRNGTest, test_min_bound_char)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_GE(rng.getRandomChar(1, 3), 1);
    }
}

TEST_F(PRNGTest, test_max_bound_char_negative)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_LE(rng.getRandomChar(-3, -1), -1);
    }
}

TEST_F(PRNGTest, test_min_bound_char_negative)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_GE(rng.getRandomChar(-3, -1), -3);
    }
}

TEST_F(PRNGTest, test_max_bound_int)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_LE(rng.getRandomInt(1, 3), 3);
    }
}

TEST_F(PRNGTest, test_min_bound_int)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_GE(rng.getRandomInt(1, 3), 1);
    }
}

TEST_F(PRNGTest, test_max_bound_int_negative)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_LE(rng.getRandomInt(-3, -1), -1);
    }
}

TEST_F(PRNGTest, test_min_bound_int_negative)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_GE(rng.getRandomInt(-3, -1), -3);
    }
}

TEST_F(PRNGTest, test_max_bound_unsigned_int_2)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_LE(rng.getRandomUnsignedInt(1, 3), 3);
    }
}

TEST_F(PRNGTest, test_min_bound_unsigned_int_2)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_GE(rng.getRandomUnsignedInt(1, 3), 1);
    }
}

TEST_F(PRNGTest, test_max_bound_long)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_LE(rng.getRandomLong(1, 3), 3);
    }
}

TEST_F(PRNGTest, test_min_bound_long)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_GE(rng.getRandomLong(1, 3), 1);
    }
}

TEST_F(PRNGTest, test_max_bound_long_negative)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_LE(rng.getRandomLong(-3, -1), -1);
    }
}

TEST_F(PRNGTest, test_min_bound_long_negative)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_GE(rng.getRandomLong(-3, -1), -3);
    }
}

TEST_F(PRNGTest, test_max_bound_unsigned_long_2)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_LE(rng.getRandomUnsignedLong(1, 3), 3);
    }
}

TEST_F(PRNGTest, test_min_bound_unsigned_long_2)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_GE(rng.getRandomUnsignedLong(1, 3), 1);
    }
}

TEST_F(PRNGTest, test_max_bound_long_long)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_LE(rng.getRandomLongLong(1, 3), 3);
    }
}

TEST_F(PRNGTest, test_min_bound_long_long)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_GE(rng.getRandomLongLong(1, 3), 1);
    }
}

TEST_F(PRNGTest, test_max_bound_long_long_negative)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_LE(rng.getRandomLongLong(-3, -1), -1);
    }
}

TEST_F(PRNGTest, test_min_bound_long_long_negative)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_GE(rng.getRandomLongLong(-3, -1), -3);
    }
}

TEST_F(PRNGTest, test_min_bound_int_half_negative)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_GE(rng.getRandomInt(-1, 1), -1);
    }
}

TEST_F(PRNGTest, test_max_bound_char_half_negative)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_LE(rng.getRandomChar(-1, 1), 1);
    }
}

TEST_F(PRNGTest, test_max_bound_int_half_negative)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_LE(rng.getRandomInt(-1, 1), 1);
    }
}

TEST_F(PRNGTest, test_min_bound_long_half_negative)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_GE(rng.getRandomLong(-1, 1), -1);
    }
}

TEST_F(PRNGTest, test_max_bound_long_half_negative)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_LE(rng.getRandomLong(-1, 1), 1);
    }
}

TEST_F(PRNGTest, test_min_bound_long_long_half_negative)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_GE(rng.getRandomLongLong(-1, 1), -1);
    }
}

TEST_F(PRNGTest, test_max_bound_long_long_half_negative)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_LE(rng.getRandomLongLong(-1, 1), 1);
    }
    cout << endl;
}

TEST_F(PRNGTest, test_max_bound_float)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_LT(rng.getRandomFloat(2), 2);
    }
}

TEST_F(PRNGTest, test_min_bound_float)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_GE(rng.getRandomFloat(2), 0);
    }
}

TEST_F(PRNGTest, test_max_bound_double)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_LT(rng.getRandomDouble(2), 2);
    }
}

TEST_F(PRNGTest, test_min_bound_double)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_GE(rng.getRandomDouble(2), 0);
    }
}

TEST_F(PRNGTest, test_max_bound_long_double)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_LT(rng.getRandomLongDouble(2), 2);
    }
}

TEST_F(PRNGTest, test_min_bound_long_double)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_GE(rng.getRandomLongDouble(2), 0);
    }
}

TEST_F(PRNGTest, test_max_bound_float_2)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_LT(rng.getRandomFloat(1, 3), 3);
    }
}

TEST_F(PRNGTest, test_min_bound_float_2)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_GE(rng.getRandomFloat(1, 3), 1);
    }
}

TEST_F(PRNGTest, test_max_bound_double_2)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_LT(rng.getRandomDouble(1, 3), 3);
    }
}

TEST_F(PRNGTest, test_min_bound_double_2)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_GE(rng.getRandomDouble(1, 3), 1);
    }
}

TEST_F(PRNGTest, test_max_bound_long_double_2)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_LT(rng.getRandomLongDouble(1, 3), 3);
    }
}

TEST_F(PRNGTest, test_min_bound_long_double_2)
{
    for(unsigned int i = 0; i < 100; i++) {
        EXPECT_GE(rng.getRandomLongDouble(1, 3), 1);
    }
}

TEST(PRNG_constructor, test_different_seeds)
{
    PRNG rng1, rng2;
    for(unsigned int i = 0; i < 16; i++)
    {
        EXPECT_NE(rng1.getState()[i], rng2.getState()[i]);
    }
}

TEST(PRNG_constructor, test_all_seed_bits_can_be_set)
{
    uint64_t results[16]{0};
    for(unsigned int i = 0; i < 30; i++)
    {
        for(unsigned int j = 0; j < 16; j++)
        {
            PRNG rng;
            results[j] |= rng.getState()[j];
        }
    }
    for(unsigned int j = 0; j < 16; j++)
    {
        EXPECT_EQ(0xffffffffffffffff, results[j]);
    }
}

TEST(PRNG_constructor, test_all_seed_bits_can_be_unset)
{
    uint64_t results[16]{0xffffffffffffffff};
    for(unsigned int i = 0; i < 30; i++)
    {
        for(unsigned int j = 0; j < 16; j++)
        {
            PRNG rng;
            results[j] &= rng.getState()[j];
        }
    }
    for(unsigned int j = 0; j < 16; j++)
    {
        EXPECT_EQ(0, results[j]);
    }
}

}
