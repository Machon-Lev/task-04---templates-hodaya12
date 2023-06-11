#pragma once

#include <iostream>
#include <list>
#include <exception>

// Custom exception class for an empty priority queue
class PriorityQueueEmptyException : public std::exception {
	/**
   * Returns the error message when the priority queue is empty.
   *
   * @return Error message indicating that the priority queue is empty.
   */
public:
	const char* what() const throw() {
		return "PriorityQueue empty !";
	}
};

// Comparator struct used to compare elements in the priority queue
template <typename T>
struct MyComparator {
	/**
   * Compares two elements and returns the difference between them.
   *
   * @param a The first element.
   * @param b The second element.
   * @return The difference between the two elements.
   */
	T operator()(T a, T b) const {
		return a - b;
	}
};

/**
 * A priority queue implementation using a list.
 *
 * @tparam T The type of elements in the priority queue.
 */
template <typename T>
class PriorityQueue {
public: 
	/**
	 * Inserts an element into the priority queue.
	 *
	 * The element is inserted at the correct position based on its priority.
	 *
	 * @param t The element to be inserted.
	 */
	void push(const T& t)
	{
		auto it = _List.begin();
		while (it != _List.end() && _comparator(*it, t)<0) {
			++it;
		}
		_List.insert(it, t);
	};

	/**
   * Removes and returns the highest priority element from the queue.
   *
   * The element with the highest priority is removed from the queue and returned.
   * If the priority queue is empty, it throws a PriorityQueueEmptyException.
   *
   * @return The highest priority element in the queue.
   * @throws PriorityQueueEmptyException if the priority queue is empty.
   */
	T poll() {
		if (_List.empty()) {
			throw PriorityQueueEmptyException(); // Throw exception if _List is empty
		}
		T element = _List.front();
		_List.pop_front();
		return element;
	};

private:
	std::list<T> _List; // List to store the elements of the priority queue
	MyComparator<T> _comparator;  // Comparator object for comparing elements
};
