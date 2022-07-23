#pragma once

namespace chowdsp
{
/** Anti-derivatives of the tanh function */
namespace TanhIntegrals
{
    /** First anti-derivative of tanh */
    template <typename T>
    inline T tanhAD1 (T x) noexcept
    {
        return std::log (std::cosh (x));
    }

    /** Second anti-derivative of tanh */
    template <typename T>
    inline T tanhAD2 (T x) noexcept
    {
        using Polylogarithm::Li2, Power::ipow;
        const auto expVal = std::exp ((T) -2 * x);
        return (T) 0.5 * (Li2 (-expVal) - x * (x + (T) 2 * std::log (expVal + (T) 1) - (T) 2 * std::log (std::cosh (x)))) + (ipow<2> (juce::MathConstants<T>::pi) / (T) 24);
    }
} // namespace TanhIntegrals
} // namespace chowdsp
