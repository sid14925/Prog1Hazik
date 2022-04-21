#include <iostream>
#include <stdexcept>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <vector>

template<typename C>
void print(const C& c, char sep = '\n'){
		std::cout<< "Container elements:\n";

		for(const auto elem : c){
			std::cout << elem << sep;
		}

		std::cout << std::endl;
}


int main()
try{
	
	const std::string iname {"input_floats.txt"};
	std::ifstream ifs {iname};
	if(!ifs) throw std::runtime_error("Could not read file:" + iname);

	std::vector<double> vd;
	for(double d; ifs >> d;){
		vd.push_back(d);
	}

	print(vd);

	std::vector<int> vi(vd.size());
	/*for(auto& d : vd){
			vi.push_back(d);
	}*/
	//std::copy(vd.begin(), vd.end(), vi.begin());
	print(vi);






	//önálló feladat(5,6):

	std::cout.precision(10);

	for(int i=0; i<vd.size();i++){
		std::cout << vd[i] << '\t' << vi[i] << std::endl;
	}


	double sumvd=0;
	for(int i=0; i<vd.size();i++){
		sumvd=sumvd+vd[i];
	}

	int sumvi=0;
	for(int i=0; i<vd.size();i++){
		sumvi=sumvi+vd[i];
	}

	std::cout << sumvd << '\t' << sumvi<< '\t' << abs(sumvd-sumvi);

	//



	std::reverse(vd.begin(), vd.end());
	print(vd);


	double vd_mean = sumvd /vd.size();
	std::cout << "Mean value of vd:"<<vd_mean << std::endl;


	//önálló feladat(9):

	std::vector<double> vd2;

	for(int i=0; i<vd.size();i++){
		if(vd[i]<vd_mean){
			vd2.push_back(vd[i]);
	}
	};

	print(vd2);

	//


	//rendezés(10):
	std::sort(vd.begin(), vd.end());
	print(vd);



} catch (std::exception& e){
		std::cerr <<e.what() << '\n';
		return 1;
} catch (...) {
		std::cerr << "Unknown exception\n";
		return 2;
}