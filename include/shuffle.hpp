#ifndef SHUFFLE_HPP
#define SHUFFLE_HPP

#include <algorithm>
#include "randGen.hpp"

namespace cor {

	/**
	* @brief shuffles a sequence
	* @param first an iterator to the first position in the sequencce
	* @param last an iterator to the last position in the sequencce
	*/
	template<typename IT>
	inline void shuffleDeck(IT first, IT last)
	{
		RandGen rng;
		uniform_result rand_num;
		for (std::ptrdiff_t i = (last - first) - 1; 0 < i; i--)
		{
			do
			{
				rand_num = rng(0, (int)i + 1);
			} while (i == rand_num);
			std::iter_swap(first + i, first + rand_num);
		}
	}

}// !namespace cor

#endif // !SHUFFLE_HPP