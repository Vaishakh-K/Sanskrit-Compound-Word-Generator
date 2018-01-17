int checkAnunasikaSandhi(char * poorva_padam, char * uttara_padam, char * samasta_padam)//Recheck the rule--May be to 1 and 3 of a varga
{
	int possible = 0, i;
	if (ifPresent(anunasikas, 5, uttara_padam[0]))
	{
		for (i = 0; i < 5; i++)
		{
			if (ifPresent(vargiya_vyanjanas[i], 5, poorva_padam[poorva_pada_len - 1]))
			{
				strcpy(samasta_padam, poorva_padam);
				samasta_padam[poorva_pada_len - 1] = vargiya_vyanjanas[i][4];
				strcat(samasta_padam, uttara_padam);
				possible = 1;
				break;
			}
		}
	}
	return possible;
}

int checkSchutvaSandhi(char * poorva_padam, char * uttara_padam, char * samasta_padam)
{
	int possible = 0, i;
	if (uttara_padam[0] == 'S' || ifPresent(vargiya_vyanjanas[1], 5, uttara_padam[0]))
	{
		if (poorva_padam[poorva_pada_len - 1] == 's')
		{
			strcpy(samasta_padam, poorva_padam);
			samasta_padam[poorva_pada_len - 1] = 'S';
			strcat(samasta_padam, uttara_padam);
			possible = 1;
		}
		else
		{
			for (i = 0; i < 5; i++)
			{
				if (poorva_padam[poorva_pada_len - 1] == vargiya_vyanjanas[3][i])
				{
					strcpy(samasta_padam, poorva_padam);
					samasta_padam[poorva_pada_len - 1] = vargiya_vyanjanas[1][i];
					strcat(samasta_padam, uttara_padam);
					possible = 1;
				}
			}
		}
	}
	return possible;
}

int checkShtutvaSandhi(char * poorva_padam, char * uttara_padam, char * samasta_padam)
{
	int possible = 0, i;
	if (ifPresent(vargiya_vyanjanas[3], 5, poorva_padam[poorva_pada_len - 1]) && uttara_padam[0] == 'R')//Ending with wa varga and beginning with R gives no change
	{
		strcpy(samasta_padam, poorva_padam);
		strcat(samasta_padam, uttara_padam);
		possible = 1;
	}

	else if (uttara_padam[0] == 'R' || ifPresent(vargiya_vyanjanas[2], 5, uttara_padam[0]))
	{
		if (poorva_padam[poorva_pada_len - 1] == 's')
		{
			strcpy(samasta_padam, poorva_padam);
			samasta_padam[poorva_pada_len - 1] = 'R';
			strcat(samasta_padam, uttara_padam);
			possible = 1;
		}
		else
		{
			for (i = 0; i < 5; i++)
			{
				if (poorva_padam[poorva_pada_len - 1] == vargiya_vyanjanas[3][i])
				{
					strcpy(samasta_padam, poorva_padam);
					samasta_padam[poorva_pada_len - 1] = vargiya_vyanjanas[2][i];
					strcat(samasta_padam, uttara_padam);
					possible = 1;
					break;
				}
			}
		}
	}

	else if (poorva_padam[poorva_pada_len - 1] == 'R')//R followed by wa varga, wa varga is replaced by ta varga
	{
		for (i = 0; i < 5; i++)
		{
			if (uttara_padam[0] == vargiya_vyanjanas[3][i])
			{
				strcpy(samasta_padam, poorva_padam);
				samasta_padam[poorva_pada_len] = vargiya_vyanjanas[2][i];
				strcat(samasta_padam, uttara_padam + 1);
				possible = 1;
				break;
			}
		}
	}

	else if (ifPresent(vargiya_vyanjanas[2], 5, poorva_padam[poorva_pada_len - 1]))
	{
		if (uttara_padam[0] == 's' || ifPresent(vargiya_vyanjanas[3], 4, uttara_padam[0]))
		{
			strcpy(samasta_padam, poorva_padam);
			strcat(samasta_padam, uttara_padam);
			possible = 1;
		}
	}

	return possible;
}

int checkVyanjanaDental(char * poorva_padam, char * uttara_padam, char * samasta_padam)
{
	int found = 0;
	if (uttara_padam[0] == 'l')
	{
		if (ifPresent(vargiya_vyanjanas[3], 4, poorva_padam[poorva_pada_len - 1]))
		{
			strcpy(samasta_padam, poorva_padam);
			samasta_padam[poorva_pada_len - 1] = 'l';
			strcat(samasta_padam, uttara_padam);
			found = 1;
		}
		else if (poorva_padam[poorva_pada_len - 1] == 'n')
		{
			strcpy(samasta_padam, poorva_padam);
			samasta_padam[poorva_pada_len - 1] = 'M';
			samasta_padam[poorva_pada_len] = 'l';
			strcat(samasta_padam, uttara_padam);
			found = 1;
		}
	}

	return found;
}

int checkVyanjanaSandhin(char * poorva_padam, char * uttara_padam, char * samasta_padam)//Poorva_padam ending with n. Uttara Padam having first two of 2, 3, 4 row. Should be checked before Schutva and Shtutva
{
	int possible = 0, i;
	char replace_with[3] = {'S', 'R', 's'};
	if (poorva_padam[poorva_pada_len - 1] == 'n')
	{
		for (i = 1; i <= 3; i++)
		{
			if (uttara_padam[0] == vargiya_vyanjanas[i][0] || uttara_padam[0] == vargiya_vyanjanas[i][1])
			{
				strcpy(samasta_padam, poorva_padam);
				samasta_padam[poorva_pada_len - 1] = 'M';
				samasta_padam[poorva_pada_len] = replace_with[i - 1];
				strcat(samasta_padam, uttara_padam);
				possible = 1;
				break;
			}
		}
	}
	return possible;
}

int checkVyanjanaSoftToHard(char * poorva_padam, char * uttara_padam, char * samasta_padam)//Soft to hard consonant. Exception take care
{
	int possible = 0, present = 0, i;
	char check_for[3] = {'S', 'R', 's'};
	if (ifPresent(check_for, 3, uttara_padam[0]))
	{
		present = 1;
	}
	else
	{
		for (i = 0; i < 5; i++)
		{
			if (ifPresent(vargiya_vyanjanas[i], 2, uttara_padam[0]))
			{
				present = 1;
				break;
			}
		}
	}
	if (present == 1)
	{
		for (i = 0; i < 5; i++)
		{
			if (ifPresent(vargiya_vyanjanas[i] + 2, 2, poorva_padam[poorva_pada_len - 1]))
			{
				possible = 1;
				strcpy(samasta_padam, poorva_padam);
				samasta_padam[poorva_pada_len - 1] = vargiya_vyanjanas[i][0];
				strcat(samasta_padam, uttara_padam);
				break;
			}
		}
	}

	return possible;
}

int checkJastvaSandhi(char * poorva_padam, char * uttara_padam, char * samasta_padam)//JAshtva sandhi.. te be checked before anunasika sandhi
{
	int possible = 0, present = 0, i, j;
	char check_for[5] = {'y', 'r', 'l', 'v', 'h'};
	for (i = 0; i < 5; i++)
	{
		if (ifPresent(vargiya_vyanjanas[i], 2, poorva_padam[poorva_pada_len - 1]))
		{
			if (ifPresent(svaras, 13, uttara_padam[0]) || ifPresent(check_for, 5, uttara_padam[0]))
			{
				present = 1;
			}
			if (present != 1)
			{
				for (j = 0; j < 5; j++)
				{
					if (ifPresent(vargiya_vyanjanas[j] + 2, 2, uttara_padam[0]))
					{
						present = 1;
						break;
					}
				}
			}

		}

		if (present == 1)
		{
			strcpy(samasta_padam, poorva_padam);
			samasta_padam[poorva_pada_len - 1] = vargiya_vyanjanas[i][2];
			strcat(samasta_padam, uttara_padam);
			possible = 1;
			break;
		}

	}

	return possible;
}

int checkVyanjanaSandhi1(char * poorva_padam, char * uttara_padam,char * samasta_padam)
{
    int i = 0, possible = 0;
    char hrasva_svara[6] = {'i', 'u', 'q', 'L','e','o'};
	char dheerga_svara[6] = {'I', 'U', 'Q', 'A','E','O'};
	char semivowels[6] = {'y', 'r', 'l', 'v','S','R'};
	char gutturals_semivowels[6] = {'k', 'K', 'g', 'G', 'f', 's'};
	char semivowel ='h';

    if(uttara_padam[0] == 's')
    {
    for(i = 0; i < 6; i++)
    {
        if((poorva_padam[poorva_pada_len - 1] == hrasva_svara[i])||(poorva_padam[poorva_pada_len - 1] == dheerga_svara[i])||(poorva_padam[poorva_pada_len - 1] == semivowels[i])||(poorva_padam[poorva_pada_len - 1] == gutturals_semivowels[i])||(poorva_padam[poorva_pada_len - 1] == semivowel))
        {
            possible = 1;
            break;
        }
    }
    if( possible ==1 )
    {
        strcpy(samasta_padam, poorva_padam);
        uttara_padam[0] = 'R';
        strcat(samasta_padam,uttara_padam);
    }
        return possible;
    }

}

int checkVyanjanaSandhi2(char * poorva_padam, char * uttara_padam,char * samasta_padam)
{	
    int i=0,possible=0;
    char shortvowel[6] = {'a', 'i', 'u', 'q','L'};
	char hrasva_svara[7] = {'i', 'u', 'q', 'L','e','o','a'};
	char dheerga_svara[7] = {'I', 'U', 'Q', 'A','E','O','A'};
	int poorva_padam_present = 0 ;

	if((poorva_padam[poorva_pada_len - 1] == 'f')||(poorva_padam[poorva_pada_len - 1] == 'N')||(poorva_padam[poorva_pada_len - 1] == 'n'))
    {

         for( i=0; i<6; i++)
      {
        if(poorva_padam[poorva_pada_len - 2] == shortvowel[i])
        {
            poorva_padam_present = 1 ;
            break;
        }
      }
    }
    if (poorva_padam_present)
    {
        for(i = 0; i < 7; i++)
       	{
            if((uttara_padam[0] == hrasva_svara[i])||(uttara_padam[0] == dheerga_svara[i]))
            {
            	possible = 1;
            	strcpy(samasta_padam, poorva_padam);
            	samasta_padam[ poorva_pada_len ] = poorva_padam[poorva_pada_len - 1];
            	strcat(samasta_padam,uttara_padam);
            	break;
            }
       }

    }
    return possible;

}

int checkVyanjanaSandhi3(char * poorva_padam, char * uttara_padam,char * samasta_padam)
{	
    int i=0,possible=0;
	int poorva_padam_present = 0 ;
	char check_for[5] = {'S', 'R', 's', 'h', 'r'};
	if( poorva_padam[poorva_pada_len -1] == 'm' )
    {
        if (ifPresent(check_for, 5, uttara_padam[0]))
        {
            possible = 1;
            strcpy(samasta_padam, poorva_padam);
            samasta_padam[ poorva_pada_len - 1 ] = 'M';
            strcat(samasta_padam,uttara_padam);

		}
    }
    return possible;
}

int checkVyanjanaSandhi4(char * poorva_padam, char * uttara_padam,char * samasta_padam)
{
    int i = 0,possible = 0;
	int poorva_padam_present = 0 ;
	if( poorva_padam[poorva_pada_len -1] == 'm' )
    {
        if((uttara_padam[0] == 'y')||(uttara_padam[0] == 'l')||(uttara_padam[0] == 'v'))
        {
            possible = 1;
            puts(samasta_padam);
            strcpy(samasta_padam, poorva_padam);
            puts(samasta_padam);
            samasta_padam[ poorva_pada_len - 1 ] = 'M';
            puts(samasta_padam);
            samasta_padam[ poorva_pada_len ] = uttara_padam[0];
            puts(samasta_padam);
            strcat(samasta_padam, uttara_padam);
            puts(samasta_padam);

        }
    }
    return possible;
}
int checkVyanjanaSandhi5(char * poorva_padam, char * uttara_padam,char * samasta_padam)
{
	int i, possible = 0;
	if (ifPresent(svaras, 13, poorva_padam[poorva_pada_len]) && uttara_padam[0] == 'C')
	{
		strcpy(samasta_padam, poorva_padam);
		samasta_padam[poorva_pada_len] = 'c';
		samasta_padam[poorva_pada_len + 1] = '\0';
		strcat(samasta_padam, uttara_padam);
		possible = 1;
	}
	return possible;
}

