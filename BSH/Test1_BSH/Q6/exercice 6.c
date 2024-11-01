#include <stdint.h>

int main() {
	
	int valeur_tension, valeur_courant, valeur_puissance, valeur_resistance;
	
	int valeur_tension_intermediere, valeur_courant_intermediere, valeur_puissance_intermediere;

	uint32_t frame = 0b1111010110101010;

	valeur_tension_intermediere = frame & 0b1111000000000000;
	// on isole les bits qui nous interesse (dans ce cas pour la valeur de la tension)
	valeur_tension = valeur_tension_intermediere >> 12;
	//etant donné que nous avons une valeur beaucoup trop haute nous devons decaler la valeur en direction du LSB

	valeur_courant_intermediere = frame & 0b0000111100000000;
	// on isole les bits qui nous interesse (dans ce cas pour la valeur de la tension)
	valeur_courant = valeur_courant_intermediere >> 8;
	//etant donné que nous avons une valeur beaucoup trop haute nous devons decaler la valeur en direction du LSB

	valeur_puissance_intermediere = frame & 0b0000000011110000;
	// on isole les bits qui nous interesse (dans ce cas pour la valeur de la tension)
	valeur_puissance = valeur_puissance_intermediere >> 4;
	//etant donné que nous avons une valeur beaucoup trop haute nous devons decaler la valeur en direction du LSB

	valeur_resistance = frame & 0b0000000000001111;
	// on isole les bits qui nous interesse (dans ce cas pour la valeur de la resistance) et etant donné que nous sommes deja au LSB nous n'avons pas a faire de decalage
}