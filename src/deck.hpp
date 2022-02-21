#ifndef DECK_HPP
#define DECK_PP
#include <deque>

namespace cor {

	/**
	* @brief container class symbolizing a deck of cards
	*/
	template<typename T>
	class Deck
	{
	public:
		/**
		* @brief constructs an empty deck
		*/
		Deck() = default;

		/**
		* @brief defualt constructor
		*/
		~Deck() = default;

		/**
		* @brief gets the top object in the deck
		* @return reference to the top element in the deck
		*/
		T& top();

		/**
		* @brief gets the top object in the deck
		* @return cosnt reference to the top element in the deck
		*/
		const T& top() const;

		/**
		* @brief checks if the deck is empty
		* @return true if the deck is empty else false
		*/
		bool empty();

		/**
		* @brief gets the size of the deck
		* @return the size if the deck
		*/
		size_t size();

		/**
		* @brief inserts an element by copying
		* @param the element to insert
		*/
		void push(const T& elem);

		/**
		* @brief inserts an element by moving it 
		* @param the element to insert
		*/
		void push(T&& elem);

		/**
		* @brief erases an element at the top
		*/
		void pop();
	private:
		std::deque<T> m_stack;
	};

	template<typename T>
	inline T & Deck<T>::top()
	{
		return m_stack.back();
	}

	template<typename T>
	inline const T & Deck<T>::top() const
	{
		return m_stack.back();
	}

	template<typename T>
	inline bool Deck<T>::empty()
	{
		return m_stack.empty();
	}

	template<typename T>
	inline size_t Deck<T>::size()
	{
		return m_stack.size();
	}

	template<typename T>
	inline void Deck<T>::push(const T & elem)
	{
		m_stack.push_back(elem);
	}

	template<typename T>
	inline void Deck<T>::push(T && elem)
	{
		m_stack.push_back(std::move(elem));
	}

	template<typename T>
	inline void Deck<T>::pop()
	{
		m_stack.pop_back();
	}

} // !namespace cor

#endif // !DECK_HPP
