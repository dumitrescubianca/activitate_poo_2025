#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Clasa
class Rezervare {

protected:
	const int codRezervare;

private:
	static int nextld; // cntor global pt coduri
	string data;
	string numeClient;
	int nrZile;
	bool confirmata;
	char* camera;

public:

	//Constructor default (fără parametrii)
	Rezervare() : codRezervare(codRezervare) {

		this->data = "";
		this->numeClient = "";
		this->nrZile = 0;
		this->confirmata = true;
		this->camera = nullptr;

	}

	//Constructor cu parametrii 
	Rezervare(string data = "", string numeClient = "", int nrZile = 0, bool confirmata = true, const char* camera = nullptr) : codRezervare(codRezervare) {

		this->data = data;
		this->numeClient = numeClient;
		this->nrZile = nrZile;
		this->confirmata = confirmata;
		if (camera != nullptr)
		{

			this->camera = new char[strlen(camera) + 1];
			strcpy_s(this->camera, strlen(camera) + 1, camera);

		} 
		else {

			this->camera = nullptr;

		}

	}

	//Constructorul de copiere 
	Rezervare(const Rezervare& p) : codRezervare(p.codRezervare) {

		this->data = p.data;
		this->numeClient = p.numeClient;
		this->nrZile = p.nrZile;
		this->confirmata = p.confirmata;
		if (p.camera != nullptr)
		{

			this->camera = new char[strlen(p.camera) + 1];
			strcpy_s(this->camera, strlen(p.camera) + 1, p.camera);

		}
		else {

			this->camera = nullptr;

		}
	}

	//Destructorul
	~Rezervare() {

		if (this->camera != nullptr)
		{
			delete[] this->camera;
		}

	}

	//Operatorul=
	Rezervare& operator=(const Rezervare& p) {

		if (this->camera != nullptr)
		{
			delete[] this->camera;
		}

		this->data = p.data;
		this->numeClient = p.numeClient;
		this->nrZile = p.nrZile;
		this->confirmata = p.confirmata;
		if (p.camera != nullptr)
		{
			this->camera = new char[strlen(p.camera) + 1];
			strcpy_s(this->camera, strlen(p.camera) + 1, p.camera);
		}
		else
		{
			this->camera = nullptr;
		}

		return *this;

	}

	//Getteri și setteri
	string getData()
	{
		return this->data;
	}

	string getNumeClient()
	{
		return this->numeClient;
	}

	int getNrZile()
	{
		return this->nrZile;
	}

	bool getConfirmata()
	{
		return this->confirmata;
	}

	char* getCamera()
	{
		return this->camera;
	}


	//Afișare de la tastatură
	friend ostream& operator<<(ostream& out, Rezervare& r) {

		out << r.data << " " << r.numeClient << " " << r.nrZile << " " << r.confirmata << " " << r.camera << " ";
		if (r.camera != nullptr)
		{
			out << r.camera;
		}
		return out;

	}


	//Operatori
	bool operator!()
	{
		if (confirmata == 0 && nrZile > 30)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void operator~()
	{
		if (confirmata == 0)
		{
			confirmata = 1;
		}
		else
		{
			confirmata = 0;
		}
	}

};

int Rezervare::nextld = 0;

//Afisare in main
int main() {

	Rezervare p1("12/08/2021", "Ionescu Ion", 35, true, "abc");
	cout << "Data: " << p1.getData() << endl;
	cout << "Nume: " << p1.getNumeClient() << endl;
	cout << "Nr Zile: " << p1.getNrZile() << endl;
	cout << "Confirmata: " << p1.getConfirmata() << endl;
	cout << "Camera: " << p1.getCamera() << endl;
	cout << endl;

	Rezervare p2("05/10/2018", "Popescu Vasile", 15, false, "def");
	cout << "Data: " << p2.getData() << endl;
	cout << "Nume: " << p2.getNumeClient() << endl;
	cout << "Nr Zile: " << p2.getNrZile() << endl;
	cout << "Confirmata: " << p2.getConfirmata() << endl;
	cout << "Camera: " << p2.getCamera() << endl;
	cout << endl;

	bool ok = !p1;
	cout << (p1.getNrZile() > 30 ? "Expirata" : "Ok") << endl;

	~p1;
	cout << "Dupa ~" << endl << p1 << endl;

}