// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      ThreadInfoTest.h
//! @brief     Declares unit test for ThreadInfo class.
//!
//! @homepage  http://bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef THREADINFOTEST_H_
#define THREADINFOTEST_H_

#include "ThreadInfo.h"

#include "gtest/gtest.h"

class ThreadInfoTest : public ::testing::Test
{
 protected:
    ThreadInfoTest()
        : thread_info() {}

    ThreadInfo thread_info;
};

TEST_F(ThreadInfoTest, DefaultValues)
{
    EXPECT_EQ(1, thread_info.n_batches);
    EXPECT_EQ(0, thread_info.current_batch);
    EXPECT_EQ(0, thread_info.n_threads);
    EXPECT_EQ(0, thread_info.current_thread);
}

#endif /* THREADINFOTEST_H_ */