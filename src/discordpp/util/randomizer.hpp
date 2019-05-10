#ifndef RANDOMIZER_HPP
#define RANDOMIZER_HPP

#include <random>

namespace discordpp
{
namespace randomizer
{

std::random_device dev;
std::mt19937 rng(dev());

template <class T = int>
static T getRandom(T begin, T end)
{
    std::uniform_int_distribution<std::mt19937::result_type> dist(begin,end);
    return dist(rng);
}

template <class T = int>
static inline T getRandom(T end)
{
    return getRandom<T>(0, end);
}
} // namespace randomizer
} // namespace discordpp

#endif