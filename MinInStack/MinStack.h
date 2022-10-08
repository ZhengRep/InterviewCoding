#pragma once

#include<stack>
#include<assert.h>

template<typename T> 
class MinStack
{
public:
	MinStack() {};
	~MinStack() {};

	void push(const T& value);
	void pop();

	T& top();
	const T& top() const;

	const T& min() const;

	bool empty() const;
	size_t size() const;

private:
	std::stack<T> m_data; //stack of data
	std::stack<T> m_min; //stack of min data
};

template<typename T>
void MinStack<T>::push(const T& value)
{
	if (m_data.size() == 0 || value < m_min.top()) {
		m_min.push(value);
	}
	else {
		m_min.push(m_min.top());
	}
	m_data.push(value);
}

template<typename T>
void MinStack<T>::pop()
{
	assert(!m_data.empty() && !m_min.empty());
	m_data.pop();
	m_min.pop();
}

template<typename T>
T& MinStack<T>::top()
{
	// TODO: insert return statement here
	return m_data.top();
}

template<typename T>
const T& MinStack<T>::top() const
{
	// TODO: insert return statement here
	return m_data.top();
}

template<typename T>
const T& MinStack<T>::min() const
{
	assert(!m_min.empty());
	return m_min.top();
}

template<typename T>
bool MinStack<T>::empty() const
{
	return m_data.empty();
}

template<typename T>
size_t MinStack<T>::size() const
{
	return m_data.size();
}
