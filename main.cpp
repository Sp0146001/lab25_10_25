#include <iostream>
#include <limits>
using u_t = unsigned;
u_t max_u(){
	using namespace std;
	using u_limit = numeric_limits< u_t >;
	return u_limit::max();
u_t min_u(){
        using namespace std;
        using u_limit = numeric_limits< u_t >;
        return u_limit::min();

bool ver_ovfl(unsigned a, unsigned b, unsigned c){
	bool p1 = (min_u/a) < a && a< (max_u/a);
	p1 = p1 && ((min_u/b) < b) && (b < (max_u/b));
	p1 = p1 && ((min_u/c) < c) && (c < (max_u/c));
	if(p1){
		bool p2 = (((min_u-a*a) < b*b) && (b*b < (max_u-a*a)));
		p2 = (((min_u-c*c) < b*b) && (b*b < (max_u-c*c)));
		p2 = (((min_u-a*a) < c*c) && (c*c < (max_u-a*a)));
	}
	return (p1 && p2);
}

bool isPyth(unsigned a, unsigned b, unsigned c){
	bool p = (ver_ovfl(a,b,c) && (a*a ==(b*b + c*c)));
	p = p || (ver_ovfl(b,a,c) && (b*b ==(a*a + c*c)));
	p = p || (ver_ovfl(c,a,b) && (c*c ==(b*b + a*a)));
	return p;
}
int main(){
	using u_t = unsigned;
	u_t a = 0, b = 0, c = 0;
	std::cin >> c >> b;
	size_t count = 0;
	while(std::cin >> a){
		if(ver_ovfl(a,b,c)){
			count+=isPyth(a,b,c) ? 1 : 0;
			c = b;
			b = a;
		}
		std::cerr << "Overflowing was detected\n";
		return 2;
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
