int checkSavarnaDheergaSandhi(char * poorva_padam, char * uttara_padam, char * samasta_padam)
{
	int i, possibe = 0;
	char hrasva_svara[5] = {'a', 'i', 'u', 'q', 'L'};
	char dheerga_svara[5] = {'A', 'I', 'U', 'Q', 'L'};

	for (i = 0; i < 5; i++)
	{
		if ((poorva_padam[poorva_pada_len - 1] == hrasva_svara[i] || poorva_padam[poorva_pada_len - 1] == dheerga_svara[i])  && (uttara_padam[0] == hrasva_svara[i] || uttara_padam[0] == dheerga_svara[i]))
		{
			strcpy(samasta_padam, poorva_padam);
			samasta_padam[poorva_pada_len - 1] = dheerga_svara[i];
			strcat(samasta_padam, uttara_padam + 1);
			possibe = 1;
			break;
		}
	}

	return possibe;

}

int checkGunaSandhi(char * poorva_padam, char * uttara_padam, char * samasta_padam)
{
	int i, possibe = 0;
	char uttara_padam_start[4] = {'i', 'I', 'u', 'U'};
	char replace_with[5] = {'e', 'e', 'o', 'o'};
	char test[5][15] = {"pra\0", "vawsawara\0", "kambala\0", "vasana\0", "qNa\0"};
	/*printf("%d %d\n", ifSubstr(uttara_padam, "Ir"), strcmp(poorva_padam, "pra"));
	printf("%d\n", strlen(poorva_padam));*/
	
	if (((strcmp(poorva_padam, "pra") == 0) && (ifSubstr(uttara_padam, "Uha") || ifSubstr(uttara_padam, "UDa") || ifSubstr(uttara_padam, "UDi"))))
	{
		strcpy(samasta_padam, poorva_padam);
		samasta_padam[poorva_pada_len - 1] = 'O';
		strcat(samasta_padam, uttara_padam + 1);
	}

	else if ((strcmp(poorva_padam, "akSa") == 0) && (ifSubstr(uttara_padam, "Uhini") || ifSubstr(uttara_padam, "UhinI")))
	{
		strcpy(samasta_padam, poorva_padam);
		samasta_padam[poorva_pada_len - 1] = 'O';
		strcat(samasta_padam, uttara_padam + 1);
		replacenwithN(samasta_padam);
	}//look into this

	else if (poorva_padam[poorva_pada_len - 1] == 'a' && ifSubstr(uttara_padam, "Uha"))
	{
		strcpy(samasta_padam, poorva_padam);
		samasta_padam[poorva_pada_len - 1] = 'O';
		strcat(samasta_padam, uttara_padam + 1);
	}

	else if ((strcmp(poorva_padam, "sva") == 0)  && (ifSubstr(uttara_padam, "Ir") || ifSubstr(uttara_padam, "IriN")))
	{
		strcpy(samasta_padam, poorva_padam);
		samasta_padam[poorva_pada_len - 1] = 'E';
		strcat(samasta_padam, uttara_padam + 1);
	}

	else if (uttara_padam[0] == 'q')
	{

		strcpy(samasta_padam, poorva_padam);
		samasta_padam[poorva_pada_len - 1] = 'a';
		samasta_padam[poorva_pada_len] = 'r';
		strcat(samasta_padam, uttara_padam + 1);
		possibe = 1;

		if (ifSubstr(uttara_padam, "qNa"))
		{
			for (i = 0; i < 5; i++)
			{
				if (strcmp(test[i], poorva_padam) == 0)
				{
					samasta_padam[poorva_pada_len - 1] = 'A';
					break;
				}
			}
		}

		for (i = 0; i < 6; i++)
		{
			if (strcmp(upasargas[i], poorva_padam) == 0)
			{
				samasta_padam[poorva_pada_len - 1] = 'A';
				break;
			}
		}
	}

	else if (uttara_padam[0] == 'L')
	{
		strcpy(samasta_padam, poorva_padam);
		samasta_padam[poorva_pada_len - 1] = 'a';
		samasta_padam[poorva_pada_len] = 'l';
		strcat(samasta_padam, uttara_padam + 1);
		possibe = 1;
	}
	else
	{
		for (i = 0; i < 4; i++)
		{
			if (uttara_padam[0] == uttara_padam_start[i])
			{
				strcpy(samasta_padam, poorva_padam);
				samasta_padam[poorva_pada_len - 1] = replace_with[i];
				strcat(samasta_padam, uttara_padam + 1);
				possibe = 1;
				break;
			}
		}
	}
	//Vriddi substitutes exceptions

	return possibe;
}

int checkVriddiSandhi(char * poorva_padam, char * uttara_padam, char * samasta_padam)
{
	int i, possibe = 0;
	char uttara_padam_start[4] = {'e', 'E', 'o', 'O'};
	char replace_with[5] = {'E', 'E', 'O', 'O'};


	for (i = 0; i < 4; i++)
	{
		if (uttara_padam[0] == uttara_padam_start[i])
		{
			strcpy(samasta_padam, poorva_padam);
			samasta_padam[poorva_pada_len - 1] = replace_with[i];
			strcat(samasta_padam, uttara_padam + 1);
			possibe = 1;
			break;
		}
	}

	for (i = 0; i < 6; i++)
	{
		if (strcmp(upasargas[i], poorva_padam) == 0)
		{
			if (samasta_padam[poorva_pada_len - 1] == 'E')
			{
				samasta_padam[poorva_pada_len - 1] = 'e';
				break;
			}
			else
			{
				samasta_padam[poorva_pada_len - 1] = 'o';
				break;
			}
			
		}
	}
	return possibe;
}

int checkYanSandhi(char * poorva_padam, char * uttara_padam, char *samasta_padam)
{
    int i, possibe = 0;
	char hrasva_svara[7] = {'i', 'u', 'q', 'L', 'a','e','o'};
	char dheerga_svara[7] = {'I', 'U', 'Q', 'L', 'A','E','O'};
	char replace_with[4] = {'y' ,'v', 'r', 'l'};
	char poorva_padam_end[4] = {'i', 'u', 'q', 'L'};

	for (i = 0; i < 4; i++)
	{
		if ((poorva_padam[poorva_pada_len - 1] == poorva_padam_end[i]) && ((uttara_padam[0] != hrasva_svara[i]) && ((uttara_padam[0]) != dheerga_svara[i])))
		{
			strcpy(samasta_padam, poorva_padam);
			samasta_padam[poorva_pada_len - 1] = replace_with[i];
			strcat(samasta_padam, uttara_padam);
			possibe = 1;
			break;
		}
	}

	return possibe;

}

int checkAyadiSandhi(char * poorva_padam, char * uttara_padam, char *samasta_padam)
{
    int i, possibe = 0;
	char replace_with[4][3] = {"ay\0", "av\0", "Ay\0", "Av\0"};
	char poorva_padam_end[4] = {'e', 'o', 'E', 'O'};
	char hrasva_svara='a';

	for (i = 0; i < 4; i++)
	{
	    if(i < 2) // e , o case
        {
			if ((poorva_padam[poorva_pada_len - 1] == poorva_padam_end[i]) && (uttara_padam[0] != hrasva_svara ))
			{
				strncpy(samasta_padam, poorva_padam, poorva_pada_len - 1);
            	strcat(samasta_padam, replace_with[i]);
				strcat(samasta_padam, uttara_padam);
				possibe = 1;
				break;
			}
	   }
	   else
       {
        	if ((poorva_padam[poorva_pada_len - 1] == poorva_padam_end[i]))
			{
				strncpy(samasta_padam, poorva_padam, poorva_pada_len - 1);
            	strcat(samasta_padam, replace_with[i]);
				strcat(samasta_padam, uttara_padam);
				possibe = 1;
				break;
			}

       }
	}
	return possibe;
}

int checkPoorvaroopaSandhi(char * poorva_padam, char * uttara_padam,char * samasta_padam)
{
    int i, possibe = 0;
	char replace_with = '$';
	char poorva_padam_end[2] = {'e', 'o'};
	char hrasva_svara = 'a';

	for (i = 0; i < 2; i++)
	{
		if ((poorva_padam[poorva_pada_len - 1] == poorva_padam_end[i]) && (uttara_padam[0] == hrasva_svara))
		{
			strcpy(samasta_padam, poorva_padam);
			samasta_padam[poorva_pada_len] = replace_with;
			strcat(samasta_padam, uttara_padam + 1 );
			possibe = 1;
			break;
		}
	}
	return possibe;
}
