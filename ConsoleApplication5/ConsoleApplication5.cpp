#include <iostream>
#include <list>

class heap {
private: 
	std::list<int> list;

public: 
	heap() {}
	heap(std::list<int> a) {
		//list.~list();
		this->list = a;

		buildHeap();
	}
	std::list<int>::iterator getNodo(int pos) {
		std::list<int>::iterator nodo = list.begin();
		while (pos != 0) {
			nodo++;
			pos--;
		}
		return nodo;
	}

	std::list<int>::iterator padre(int pos) {
		std::list<int>::iterator padre = list.begin();
		pos = (pos - 1) / 2;
		while (pos != 0) {
			padre++;
			pos--;
		}
		return padre;
	}

	std::list<int>::iterator hijoIzquierdo(int pos) {
		std::list<int>::iterator padre = list.begin();
		pos = (pos * 2) + 1;
		while (pos != 0) {
			padre++;
			pos--;
		}
		return padre;
	}

	std::list<int>::iterator hijoDerecho(int pos) {
		std::list<int>::iterator padre = list.begin();
		pos = (pos * 2) + 2;
		while (pos != 0) {
			padre++;
			pos--;
		}
		return padre;
	}

	void intercambio(std::list<int>::iterator a, std::list<int>::iterator b) {
		int aux = *a;
		*a = *b;
		*b = aux;
	}

	void insert(int dato) {
		if (list.empty())
			list.push_front(dato);
		else {
			list.push_back(dato);

			int pos = list.size() - 1;
			std::list<int>::iterator nuevo = list.end();
			std::list<int>::iterator papa = padre(pos);
			while (*nuevo > *papa) {
				intercambio(nuevo, papa);

				nuevo = papa;
				pos = (pos - 1) / 2;

				papa = padre(pos);
			}
		}
	}

	int eliminar() {
		if (list.size() < 1)
			return NULL;

		int max = list.front();
		*list.begin() = *list.end();
		list.pop_back();

		this->Heapify(0, list.size()-1);
		return max;
	}

	void Heapify(int i, int sizeHeap) {
		int posHijoD = i * 2 + 2;
		int posHijoI = i * 2 + 1;

		std::list<int>::iterator nodo;

		int posGrande = i;
		std::list<int>::iterator grande;
		
		if (posHijoI <= sizeHeap) {
			nodo = this->getNodo(i);
			grande = nodo;
			std::list<int>::iterator hijoI = this->getNodo(posHijoI);
			if (*hijoI > *grande) {
				posGrande = posHijoI;
				grande = hijoI;
			}
		}
		if (posHijoD <= sizeHeap) {
			std::list<int>::iterator hijoD = this->getNodo(posHijoD);
			if (*hijoD > *grande) {
				posGrande = posHijoD;
				grande = hijoD;
			}
		}

		if (posGrande != i) {
			this->intercambio(grande, nodo);
			this->Heapify(posGrande, sizeHeap);
		}
		
	}

	void buildHeap() {
		for (int i = list.size() / 2; i >= 0; i--) {
			Heapify(i, list.size() - 1);
		}
	}

	void show() {
		for (auto& a : list) {
			std::cout << a << " ";
		}
	}

	~heap() {
	}
};

int main(){
	std::list<int> a = { 30,48,15,67,24,17,5 };
	//heap* m = new heap(a);
	//m->show();
	//delete m;
}