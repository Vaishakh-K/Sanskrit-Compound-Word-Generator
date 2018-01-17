#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "declarations.h"
#include "utilities.c"
#include "svara.c"
#include "vyanjana.c"
#include "visarga.c"
#include "sandhicategories.c"

int poorva_pada_len, uttara_pada_len;
char vargiya_vyanjanas[5][6] = {"kKgGf\0","cCjJF\0", "tTdDN\0", "wWxXn\0", "pPbBm\0"};
char anunasikas[5] = {"fFNnm"};
char svaras[14] = {"aAiIuUqQLeEoO\0"};
char upasargas[6][5] = {"pra\0", "apa\0", "ava\0", "uwa\0", "upa\0", "parA\0"};





int main()
{

	char poorva_padam[20], uttara_padam[20];
	char * samasta_padam;
	printf("Enter the poorva_padam : ");
	scanf("%s", poorva_padam);
	printf("Enter the uttara_padam : ");
	scanf("%s", uttara_padam);

	poorva_pada_len = strlen(poorva_padam);
	uttara_pada_len = strlen(uttara_padam);

	samasta_padam = (char *) malloc ((poorva_pada_len + uttara_pada_len + 2) * sizeof(char));

	//printf("%s\n", strncpy(samasta_padam, poorva_padam, poorva_pada_len - 1));
	if (ifPresent(svaras, 13, poorva_padam[poorva_pada_len - 1]))
	{
		printf("Svara Sandhi\n");
		checkSvaraSandhi(poorva_padam, uttara_padam, samasta_padam);
	}
	else if (poorva_padam[poorva_pada_len - 1] == 'H')
	{
		printf("Visarga Sandhi\n");
		checkVisargaSandhi(poorva_padam, uttara_padam, samasta_padam);
	}
	else
	{
		printf("Vyanjan Sandhi\n");
		checkVyanjanaSandhi(poorva_padam, uttara_padam, samasta_padam);
	}

	printf("%s\n", samasta_padam);
	return 0;
}



//saH api - giving so$pi. should have been visarga lopa