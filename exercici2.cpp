#include <iostream>
#include <string>

using namespace std;

class Ascensor {
private:
	int pisActual;
	int pisMinim;
	int pisMaxim;
	bool portaOberta;
public:
	Ascensor(int min, int max) {
		pisMinim = min;
		pisMaxim = max;
		pisActual = pisMinim;
		portaOberta = false;
	}
	int getPisActual() const {
		return pisActual;
	}
	int getPisMinim() const {
		return pisMinim;
	}
	int getPisMaxim() const {
		return pisMaxim;
	}
	int isPortaOberta() const {
		return portaOberta;
	}
	void obrirPorta() {
		portaOberta = true;
	}
	void tancarPorta() {
		portaOberta = false;
	}
	void isPortaOberta() {
		if (portaOberta) {
			cout << "La porta esta oberta" << endl;
		}
		else {
			cout << "La porta esta tancada" << endl;
		}
	}
	bool pujarPis() {
		if (tancarPorta && pisActual < pisMaxim) {
			pisActual++;
			return true;
		}
		else {
			return false;
		}
	}
	bool baixarPis() {
		if (tancarPorta && pisActual > pisMinim) {
			pisActual--;
			return true;
		}
		else {
			return false;
		}
	}

};