#include <iostream>

void print() {}

template<typename T, typename... Types>
void print(const T& firstArg, const Types&... args) {
	std::cout << firstArg << " " << sizeof...(args) << std::endl;
	print(args...);
}

template <typename... Types>  // 这个无论是print(2, "hello", 1);还是print(1);调用，都不会用这个，不会打印print（。。。），所以被覆盖了没啥用
void print(const Types&... args) {
  std::cout << "print(...)" << std::endl;
}

int main(int argc, char *argv[]) {
	print(2, "hello", 1);
	print(1);

	return 0;
}
