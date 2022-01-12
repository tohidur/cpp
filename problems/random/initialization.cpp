#include<iostream>

class Vector {
	public:
		Vector(int s):
            elem{new double[s]},
            sz{s} {}

		double& operator[](int i) {
            return elem[i];
        }

		int size() {
            return sz;
        }

	private:
		double* elem;
		int sz;
};

int main() {
    Vector v(5);
    for (int i=0; i!=v.size(); ++i)
        std::cin>>v[i];

    for (int i=0; i!=v.size(); ++i)
        std::cout << v[i] << '\n';


    std::cout << '\n' << v.operator[](1) << '\n';
    std::cout << '\n' << v[1] << '\n';
}
