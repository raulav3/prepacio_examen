#include <iostream>
#include <string>

using namespace std;

class SubscripcioStreaming {
private:
	string nomPla;
	int dispositiusMaxim;
	int dispositiusActius;
	double horesReproduides;
	bool activa=true;
	void cancel·larSubscripcio() {
		activa = false;
		dispositiusActius = 0;
	}
	
public:
	SubscripcioStreaming() {
		nomPla = "basic";
		dispositiusMaxim = 1;
		dispositiusActius = 0;
		horesReproduides = 0;
		activa = true;

	}
	explicit
		SubscripcioStreaming(std::string nom) {
		nomPla = nom;
		dispositiusMaxim = 2;
		dispositiusActius = 0;
		horesReproduides = 0;
		activa = true;
	}
	SubscripcioStreaming(std::string nom, int dispositius) {
		nomPla = nom;
		if (dispositius <= 0) {
			dispositius = 1;
		}
		else {
			dispositius = 0;
		}
			horesReproduides = 0;
			activa = true;
		
		dispositiusMaxim = dispositius;

	}

	std::string getNomPla() const{
		return nomPla;
	}
	int getdispositiusActius() const {
		return dispositiusActius;

	}
	double gethoresReproduides() const {
		return horesReproduides;
	}
	bool isActiva() {
		return activa;
	}
	bool connectarDispositiu() {
		if (activa && dispositiusActius < dispositiusMaxim) {
			
				dispositiusActius++;
				return true;
		}
		else {
			cout << "error" << endl;
			return false;
		}
	}
	void desconectarDispositius() {
		if (dispositiusActius > 0) {
			dispositiusActius--;
		}
	}
	void registrarReproduccio(double hores) {
		if (activa && dispositiusActius <=1 && hores>0) {
			horesReproduides= horesReproduides + hores;

		}
	}
	~SubscripcioStreaming() {
		if (activa){
			cancel·larSubscripcio();
			dispositiusActius = 0;
			dispositiusMaxim = 0;
			cout << "La subscripcio del pla nomPla s'ha tancat automàticament en sortir d'àmbit." << endl;
		}
		
	}
};

int main() {
	SubscripcioStreaming sub(" familiar ");
	cout << "nom Pla" << sub.getNomPla() << endl;
	cout << "dispositius Actius = " << sub.getdispositiusActius() << endl;
	cout << "hores Reproduides = " << sub.gethoresReproduides() << endl;
	cout << "Pla creat: " << sub.getNomPla() << " (Activa: " << (sub.isActiva() ? "Si" : "No") << ")" << endl;
	sub.connectarDispositiu();
	sub.connectarDispositiu();
	sub.connectarDispositiu();

	sub.registrarReproduccio(3.5);
	cout << "Hores reproduides acumulades: " << sub.gethoresReproduides() << std::endl;
	cout << "Programa finalitzat." << std::endl;
	return 0;
}