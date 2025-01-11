#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/*
Faites une application en c/c++ en utilisant la structure de données de votre choix permettant à l’utilisateur de saisir 6 nombres entiers pour calculer et afficher le plus grand nombre et le petit nombres saisis. 
Et dans le cas où le même nombre est saisi 6 fois, le programme affiche le texte suivant : « Pas de plus petit, Pas de plus grand nombre ! »

Enregistrez les 6 nombres saisis par l’utilisateur dans une structure de données de votre choix, ensuite faite la comparaison demandée.
*/



int main()
{
	cout << "Enter 6 different integers" << endl;
	int number[6];

	for (int i = 0; i < 6; i++)
	{
		cout << "Enter the number #" << i+1 << " : ";
		cin >> number[i];
		cout << endl;
	}

	int max = 0;
	
	for (int i = 0; i < 6; i++)
	{
		if (number[i] > max)
		{
			max = number[i];
		}
	}


	int min = max;

	for (int i = 0; i < 6; i++)
	{
		if (number[i] < min)
		{
			min = number[i];
		}
	}

	if (min == max)
	{
		cout << "There's no smallest or largest number!" << endl;
	}
	else
	{
		cout << "Smallest number : " << min << endl;
		cout << "Largest number : " << max << endl;
	}
	

	return 0;
}