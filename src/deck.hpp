#ifndef DECK_HPP
#define DECK_PP
#include <deque>

namespace cor {

	template<typename T>
	class Deck
	{
	public:
		Deck() = default;
		~Deck() = default;
		T& top();
		const T& top() const;

		bool empty();
		size_t size();
		void push(const T& elem);
		void push(T&& elem);

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
