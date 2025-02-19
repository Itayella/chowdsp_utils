/*################################################################################
  ##
  ##   Copyright (C) 2016-2022 Keith O'Hara
  ##
  ##   This file is part of the GCE-Math C++ library.
  ##
  ##   Licensed under the Apache License, Version 2.0 (the "License");
  ##   you may not use this file except in compliance with the License.
  ##   You may obtain a copy of the License at
  ##
  ##       http://www.apache.org/licenses/LICENSE-2.0
  ##
  ##   Unless required by applicable law or agreed to in writing, software
  ##   distributed under the License is distributed on an "AS IS" BASIS,
  ##   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  ##   See the License for the specific language governing permissions and
  ##   limitations under the License.
  ##
  ################################################################################*/

#ifndef _gcem_abs_HPP
#define _gcem_abs_HPP

/**
 * Compile-time absolute value function
 *
 * @param x a real-valued input.
 * @return the absolute value of \c x, \f$ |x| \f$.
 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wfloat-equal"

template <typename T>
constexpr T
    abs (const T x) noexcept
{
    return ( // deal with signed-zeros
        x == T (0) ? T (0) :
                   // else
            x < T (0) ? -x
                      : x);
}
#pragma clang diagnostic pop
#endif
