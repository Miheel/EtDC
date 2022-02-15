#ifndef RANDGEN_HPP
#define RANDGEN_HPP

#include <random>
#include <limits>

namespace cor {

	using uniform_result = int;

	/**
	* @brief Random generator class
	*/
	class RandGen
	{
	public:
		/**
		* @brief default constructor
		*/
		RandGen() = default;

		/**
		* @brief parametrisized constructor
		* @param seed a seed for the random engine 
		*/
		RandGen(std::mt19937::result_type seed)
			:rng(seed), dist(0, std::numeric_limits<int>::max()) {}

		/**
		* @brief overloaded function operator 
		* @return a ramdom number between 0 and std::numeric_limits<int>::max()
		*/
		uniform_result operator()() {
			return dist(rng);
		}

		/**
		* @brief overloaded function operator
		* @param range_min the smalest number in the range
		* @param range_max the biggest number in the range
		* @return a ramdom number between range_min and range_max
		* @see int operator()(int range_min = 0, int range_max = std::numeric_limits<int>::max())
		*/
		uniform_result operator()(int range_min, int range_max) {
			return std::uniform_int_distribution<int>(range_min, range_max)(rng);
		}

	private:
		std::mt19937 rng{ std::random_device{}() };
		std::uniform_int_distribution<int> dist;
	};

}// !namespace cor

#endif // !RANDGEN_HPP
