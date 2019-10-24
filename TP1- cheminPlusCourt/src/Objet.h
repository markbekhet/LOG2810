#pragma once
class Objet {
public:
	Objet(int nombre, int masse);
	int getNombre();
	int getMasse();
	void diminuerNombre(int facteur);
	void augmenterNombre(int facteur);
protected:
	int nombre_;
	int masse_;
};
