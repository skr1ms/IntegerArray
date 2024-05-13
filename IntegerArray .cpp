#include "IntegerArray.h"

const char* bad_range::what() const noexcept {
	return "";
}

const char* bad_length::what() const noexcept {
	return "Неверная длина масива";
}

IntegerArray::IntegerArray(int length) : _length{ length } {
	if (_length == 0)
		throw bad_length();

	_arr = new int(_length);
}

IntegerArray::IntegerArray(const IntegerArray& a) : IntegerArray(a.getLength()) {
	std::copy_n(a._arr, _length, _arr);
}

int& IntegerArray::operator[](int index) {
	if (index < 0 || index >= _length)
		throw bad_range();

	return _arr[index];
}

IntegerArray& IntegerArray::operator=(const IntegerArray& a) {
	if (&a == this)
		return *this;

	reallocate(a.getLength());
	std::copy_n(a._arr, _length, _arr);

	return *this;
}

void IntegerArray::resize(int newLength)
{
	if (newLength == _length)
		return;

	if (newLength <= 0)
	{
		erase();
		return;
	}

	int* data{ new int[newLength] };

	if (_length > 0)
	{
		int elementsToCopy{ (newLength > _length) ? _length : newLength };
		std::copy_n(_arr, elementsToCopy, data);
	}

	delete[] _arr;

	_arr = data;
	_length = newLength;
}

void IntegerArray::erase() {
	delete[] _arr;
	_arr = nullptr;
	_length = 0;
}

void IntegerArray::reallocate(int newLength) {
	if (newLength <= 0)
		throw bad_length();

	erase();

	_arr = new int[newLength];
	_length = newLength;
}

void IntegerArray::insertBefore(int value, int index)
{
	if (index < 0 || index >= _length)
		throw bad_range();

	int* data{ new int[_length + 1] };

	std::copy_n(_arr, index, data);

	data[index] = value;

	std::copy_n(_arr + index, _length - index, data + index + 1);

	delete[] _arr;
	_arr = data;
	++_length;
}

void IntegerArray::remove(int index)
{
	if (index < 0 || index >= _length)
		throw bad_range();


	if (_length == 1)
	{
		erase();
		return;
	}

	int* data{ new int[_length - 1] };

	std::copy_n(_arr, index, data);

	std::copy_n(_arr + index + 1, _length - index - 1, data + index);

	delete[] _arr;
	_arr = data;
	--_length;
}

int IntegerArray::find(int value) {
	for (int i = 0; i < _length; i++)
	{
		if (_arr[i] == value)
			return i;
	}
	return -5;
}

IntegerArray IntegerArray::copy() const {
	IntegerArray result(_length);
	for (int i = 0; i < _length; i++) {
		result._arr[i] = _arr[i];
	}
	return result;
}

/*void IntegerArray::pushBack(int value) {
	if (size == _length) {
		size *= 2;
		int* newArr = new int[size];
		for (int i = 0; i < size; i++) {
			newArr[i] = _arr[i];
		}
		delete[] newArr;
		_arr = newArr;
	}
	_arr[size] = value;
	size++;
}

//void IntegerArray::pushFront(int value) {
	if (size == _length) {
		size *= 2;
		int* newArr = new int[size];
		for (int i = 0; i < size; i++) {
			newArr[i] = _arr[i];
		}
		delete[] newArr;
		_arr = newArr;
	}
	for (int i = size; i > 0; i--) {
		_arr[i] = _arr[i - 1];
	}
	_arr[0] = value;
	size++;
}*/

IntegerArray::~IntegerArray() {
	delete[] _arr;
}