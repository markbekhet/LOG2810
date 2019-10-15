#pragma once
class Objet {
public:
	Objet(int nombre, int masse);
	int getNombre();
	int getMasse();
	void diminuerNombre(int facteur);
protected:
	int nombre_;
	int masse_;
};
