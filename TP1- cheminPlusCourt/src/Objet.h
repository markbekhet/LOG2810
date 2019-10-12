#pragma once
class Objet {
public:
	Objet(int nombre);
	int getNombre();
	int getMasse();
protected:
	int nombre_;
	int masse_;
};
