#include "stdafx.h"
#include "Test.h"
#include <iostream>
#include <vector>

using namespace std;

Test::Test()
{
	try {
		Vector<C> v(4);
		cout << "constructor" << "\n";
		cout << "Size:" << v.Size() << "\n";
		cout << "Capacity:" << v.Capacity() << "\n";
		cout << "\n";

		Vector<C> * v2 = new Vector<C>(v);
		delete v2;
		auto v3(v);
		cout << "copy constructor" << "\n";
		cout << "Size:" << v3.Size() << "\n";
		cout << "Capacity:" << v3.Capacity() << "\n";
		cout << "\n";

		v.Reserve(20);
		cout << "Reserve" << "\n";
		cout << "Size:" << v.Size() << "\n";
		cout << "Capacity:" << v.Capacity() << "\n";
		cout << "\n";

		v.Resize(3);
		cout << "Resize" << "\n";
		cout << "Size:" << v.Size() << "\n";
		cout << "Capacity:" << v.Capacity() << "\n";
		cout << "\n";

		C obj;
		v.PushBack(obj);
		cout << "PushBack" << "\n";
		cout << "Size:" << v.Size() << "\n";
		cout << "Capacity:" << v.Capacity() << "\n";
		cout << "\n";

		v.PopBack();
		cout << "PopBack" << "\n";
		cout << "Size:" << v.Size() << "\n";
		cout << "Capacity:" << v.Capacity() << "\n";
		cout << "\n";

		Vector<C> v4;
		v4.Swap(v);
		cout << "Swap" << "\n";
		cout << "v4 Size:" << v4.Size() << "\n";
	    cout << "v  Size:" << v.Size() << "\n";
		cout << "v4 Capacity:" << v4.Capacity() << "\n";
		cout << "v  Capacity:" << v.Capacity() << "\n";
		cout << "\n";
	}
	catch (...) {
		cout << "Exception\n";
	}
}

