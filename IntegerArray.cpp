#include "IntegerArray.h"

int main()
{
	try {

		IntegerArray arr(5);

		arr[0] = 7;
		arr[2] = 12;
		arr[3] = 2;

		arr.resize(10);

		arr.pushFront(50);
		arr.pushBack(150);

		arr.insertBefore(15, 3);

		arr.copy();
		arr.find(3);

		arr.remove(2);

		arr.erase();
	}
	catch (const bad_range e) {
		cout << e.what() << endl;
	}
	catch (const bad_length a) {
		cout << a.what() << endl;
	}
	return 0;
}
