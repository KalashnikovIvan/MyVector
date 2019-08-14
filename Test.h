#pragma once
#include "Vector.h"

class TooManyObjectsException {

};

struct C {
	inline static size_t created = 0;
	inline static size_t destroyed = 0;
	C() {
		++created;
		//if (objects >= 7) {
			//throw TooManyObjectsException();
		//}
	}
	C(const C&) {
		++created;
		//if (objects >= 7) {
			//throw TooManyObjectsException();
		//}
	}
	~C() {
		++destroyed;
	}
};

class Test {
public:
	Test();
	~Test() {
                                                                                                                                                                                                                                                                                                                                                                                                                                            		std::cout << "test completed successfully" << std::endl;
	}
};