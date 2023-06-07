/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2023 Bolder Flight Systems Inc
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the “Software”), to
* deal in the Software without restriction, including without limitation the
* rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
* sell copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
* IN THE SOFTWARE.
*/

#include "decyear.h"
#include "gtest/gtest.h"
#include <cmath>

/* Test a random date */
TEST(DecYear, Date) {
  EXPECT_FLOAT_EQ(2023.40974727296, bfs::decyear(2023, 5, 30, 13, 23, 10));
  EXPECT_FLOAT_EQ(2023.40821917808, bfs::decyear(2023, 5, 30));
}

/* Test a leap year */
TEST(DecYear, LeapYear) {
  EXPECT_FLOAT_EQ(2016.41135998533, bfs::decyear(2016, 5, 30, 13, 23, 10));
  EXPECT_FLOAT_EQ(2016.40983606557, bfs::decyear(2016, 5, 30));
}
