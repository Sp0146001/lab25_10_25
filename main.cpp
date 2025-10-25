#include <iostream>


int main(){
	using u_t = unsigned;
	u_t a = 0;
	std::cin >> a;
	
	if(std::cin.eof()){
		std::cout << 1 << "\n";
	}
	else if(std::cin.fail()){
		std::cerr << "Input end\n";
		return 1;
	}
	return 0;
}
