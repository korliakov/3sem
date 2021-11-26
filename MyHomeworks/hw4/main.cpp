#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <algorithm>
#include <set>


template <typename T>
void foo(T& v) {

	
	auto f{
		[](std::string a) {
		std::string b = a;
		std::reverse(b.begin(), b.end());
		return a + b;
		}
	};

	for (auto i = v.begin(); i != v.end(); ++i) {
		*i = f(*i);

	}


}




int main () {




	std::vector<std::string> v;
	v.push_back("abc");
	v.push_back("yut");








	// auto f{
	// 	[](std::string a) {
	// 	std::string b = a;
	// 	std::reverse(b.begin(), b.end());
	// 	// std::string s = a + b;
	// 	return a + b;
	// }

	// };

	// for (auto i = v.begin(); i != v.end(); i++) {

	// 	// std::string s = *i;
	// 	*i = f(*i);

	// }

	// for (auto i : v) {
	// 	std::cout << i;

	// }


	foo<std::vector<std::string>>(v);

	for (auto i : v) {
		std::cout << i << "\n";

	}
}