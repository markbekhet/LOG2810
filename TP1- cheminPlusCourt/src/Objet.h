#pragma once
class Objet {
public:
	Objet(int nombre);
	virtual int getNombre();
	virtual int getMasse();
protected:
	int nombre;
	int masse;
};
