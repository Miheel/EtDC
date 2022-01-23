#ifndef RANDGEN_HPP
#define RANDGEN_HPP

#include <random>
#include <limits>

namespace cor {

	using uniform_result = int;

	class RandGen
	{
	public:
		RandGen() = default;
		RandGen(std::mt19937::result_type seed)
			:rng(seed), dist(0, std::numeric_limits<int>::max()) {}

		uniform_result operator()() {
			return dist(rng);
		}

		//int operator()(int range_min = 0, int range_max = std::numeric_limits<int>::max())
		uniform_result operator()(int range_min, int range_max) {
			return std::uniform_int_distribution<int>(range_min, range_max)(rng);
		}

	private:
		std::mt19937 rng{ std::random_device{}() };
		std::uniform_int_distribution<int> dist;
	};

}// !namespace cor

#endif // !RANDGEN_HPP
