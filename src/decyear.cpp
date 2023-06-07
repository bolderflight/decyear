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

#if defined(ARDUINO)
#include "Arduino.h"
#else
#include <cstddef>
#include <cinttypes>
#endif

#include "decyear.h"  // NOLINT
#include "juliandate.h"  // NOLINT

namespace bfs {

double decyear(const int16_t yyyy, const int8_t mm, const int8_t dd,
               const int8_t h, const int8_t m, const int8_t s) {
  double jd = juliandate(yyyy, mm, dd, h, m, s);
  double epoch = juliandate(yyyy, 1, 1, 0, 0, 0);
  bool leap_year = false;
  if (yyyy % 400 == 0) {
    leap_year = true;
  } else if (yyyy % 100 == 0) {
    leap_year = false;
  } else if (yyyy % 4 == 0) {
    leap_year = true;
  }
  double decyear;
  if (leap_year) {
    decyear = static_cast<double>(yyyy) + (jd - epoch) / 366.0;
  } else {
    decyear = static_cast<double>(yyyy) + (jd - epoch) / 365.0;
  }
  return decyear;
}

double decyear(const int16_t yyyy, const int8_t mm, const int8_t dd) {
  return decyear(yyyy, mm, dd, 0, 0, 0);
}

}  // namespace bfs
