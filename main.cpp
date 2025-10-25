#include <iostream>

bool isPyth(unsigned a, unsigned b, unsigned c){
	bool p = ;
	bool p =p ||  ;
	bool p =p ||  ;
	return p;
}
int main(){
	using u_t = unsigned;
	u_t a = b = c = 0;
	size_t count = 0;
	while(std::cin >> a){
		count+=isPyth(a,b,c) ? 1 : 0;
	}
	if(std::cin.eof()){
		std::cout << count << "\n";
	}
	else if(std::cin.fail()){
		std::cerr << "Input end\n";
		return 1;
	}
	return 0;
}
