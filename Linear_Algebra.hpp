#include <iostream>
using namespace std;

namespace LA{

template <typename T>
class vector{
public:
	T *vec;
	int dim;

	vector(const int);
	~vector();
	
	T& operator()(const int);
	
	vector<T> operator+(const vector<T>&);
	vector<T> operator-(const vector<T>&);

	void operator=(const vector<T>&);
	void operator+=(const vector<T>&);
	void operator-=(const vector<T>&);

	void show();
};

template <typename T>
vector<T> vector<T>::operator+(const vector<T> &obj){
	/*
	if(dim != obj.dim){
		cout << "error dim doesn't not match."
	}
	*/
	vector<T> ans(dim);
	for(int i=0; i<dim; ++i){
		ans.vec[i] = vec[i] + obj.vec[i];
	}
	return ans;
}

template <typename T>
vector<T> vector<T>::operator-(const vector<T> &obj){
	vector<T> ans(dim);
	for(int i=0; i<dim; ++i){
		ans.vec[i] = vec[i] - obj.vec[i];
	}
	return ans;
}

template <typename T>
void vector<T>::operator=(const vector<T> &obj){
	for(int i=0; i<dim; ++i){
		this->vec[i] = obj.vec[i];
	}
}

template <typename T>
void vector<T>::operator+=(const vector<T> &obj){
	for(int i=0; i<dim; ++i){
		this->vec[i] = this->vec[i] + obj.vec[i];
	}
}

template <typename T>
void vector<T>::operator-=(const vector<T> &obj){
	for(int i=0; i<dim; ++i){
		this->vec[i] = this->vec[i] - obj.vec[i];
	}
}

template <typename T>
vector<T>::vector(const int N){
	vec = new T[N];
	for(int i=0; i<N; ++i){
		vec[i] = 0.;
	}
	dim = N;
}

template <typename T>
vector<T>::~vector(){
	delete[] vec;
}

template <typename T>
T& vector<T>::operator()(const int i){
	return vec[i];
}

template <typename T>
void vector<T>::show(){
	for(int i=0; i<dim; ++i){
		cout << vec[i] << endl;
	}
	cout << endl;
}

/* scalar multiplication */

template <typename T>
vector<T> operator*(const T &k, const vector<T> &obj){
	vector<T> ans(obj.dim);
	for(int i=0; i<obj.dim; ++i){
		ans.vec[i] = k * obj.vec[i];
	}
	return ans;
}

/*
vector<double> operator*(const double &k, const vector<double> &obj){
	vector<double> ans(obj.dim);
	for(int i=0; i<obj.dim; ++i){
		ans.vec[i] = k * obj.vec[i];
	}
	return ans;
}
*/
}
