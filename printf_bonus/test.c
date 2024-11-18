#include <stdio.h>
#include <string.h>

#include "ft_printf.h"

int main(int ac, char **av) {
	int temp;
	temp = printf("real: %+2d\n", 5);
	printf("] = %d\n", temp);
	temp = ft_printf("fake: %+2d\n", 5);
	ft_printf("] = %d\n", temp);
}

// int main() {
// 	// Avec le drapeau '-': Alignement à gauche
// 	printf("[%%----10d]\n");
// 	printf("Alignement à gauche : |%----10d|\n", 42);
// 	ft_printf("Alignement à gauche : |%----10d|\n\n", 42);

// 	// Avec le drapeau '0': Remplissage avec des zéros
// 	printf("[%%10d]\n");
// 	printf("Remplissage de zéros : |%10d|\n", 42);
// 	ft_printf("Remplissage de zéros : |%10d|\n\n", 42);

// 	// Avec le drapeau '.': Précision pour les flottants
// 	printf("[%%25.20p$#$#2d]\n");
// 	printf("Précision flottant : |%25.20p$#$#2d|\n", "99");
// 	ft_printf("Précision flottant : |%25.20p$#$#2d|\n\n", "99");

// 	// Avec le drapeau '#': Affichage spécifique pour hexadécimal et flottants
// 	printf("[%%#x]\n");
// 	printf("Hexadécimal avec #: |%#x|\n", 255);  // Inclut "0x" pour hexadécimal
// 	ft_printf("Hexadécimal avec #: |%#x|\n\n", 255);  // Inclut "0x" pour hexadécimal

// 	// Avec le drapeau '+': Affiche toujours le signe (+ ou -)
// 	printf("[%%+d]\n");
// 	printf("Signe explicite : |%0 d|\n", 42);
// 	ft_printf("Signe explicite : |%0 d|\n", 42);
// 	printf("Signe explicite : |%+d|\n", -42);
// 	ft_printf("Signe explicite : |%+d|\n\n", -42);

// 	// Avec le drapeau ' ' (espace) : Ajoute un espace pour les nombres positifs
// 	printf("[%% d]\n");
// 	printf("Espace pour les positifs : |% d|\n", 42);
// 	ft_printf("Espace pour les positifs : |% d|\n", 42);
// 	printf("Espace pour les positifs : |% d|\n", -42);
// 	ft_printf("Espace pour les positifs : |% d|\n\n", -42);

// 	// Combinaison de plusieurs drapeaux
// 	printf("[%%-#10.2d]\n");
// 	printf("Combinaison : |%-#10.2d|\n", 3); // Aligné à gauche, largeur 10, précision 2, et # pour forcer le point décimal
// 	ft_printf("Combinaison : |%-#10.2d|\n\n", 3); // Aligné à gauche, largeur 10, précision 2, et # pour forcer le point décimal

// 	printf("[%%+010.2d]\n");
// 	printf("Combinaison : |%0+10d|\n", 3); // Signe explicite, zéro padding, largeur 10, précision 2
// 	ft_printf("Combinaison : |%0+10d|\n\n", 3); // Signe explicite, zéro padding, largeur 10, précision 2

// 	return 0;
// }