int checkNoVisargaSandhi(char * poorva_padam, char *uttara_padam, char * samasta_padam)
{
    int possible = 0;
    char hrasva_svara[7] = {'i', 'u', 'q', 'L','e','o','a'};
    char dheerga_svara[7] = {'I', 'U', 'Q', 'A','E','O','A'};
    char check_for[4] = {'k', 'K', 'p', 'P'};

    if (ifPresent(hrasva_svara, 7, poorva_padam[poorva_pada_len - 2]) || ifPresent(dheerga_svara, 7, poorva_padam[poorva_pada_len - 2]))
    {
        if(ifPresent(check_for, 4, uttara_padam[0]))
        {
            possible = 1 ;
            strcpy(samasta_padam, poorva_padam);
            samasta_padam[poorva_pada_len] = ' ';
            strcat(samasta_padam+1, uttara_padam);
        }
    }

    return possible;
}

int checkOkaradeshaVisargaSandhi(char * poorva_padam, char *uttara_padam, char * samasta_padam)
{

    int i, possible = 0;
    char mridu_vyanjanam1[7] = {'g', 'j', 'd', 'x', 'b', 'f', 'n'};
    char mridu_vyanjanam2[7] = {'G', 'J', 'D', 'X', 'B', 'F', 'N'};
    char mridu_vyanjanam3 = 'm';

    if(poorva_padam[poorva_pada_len - 2] == 'a')
    {
        if(uttara_padam[0] == 'a')
        {
            possible = 1;
            strcpy(samasta_padam, poorva_padam);
            samasta_padam[poorva_pada_len - 2] = 'o';
            samasta_padam[poorva_pada_len - 1] = '$';
            strcat(samasta_padam, uttara_padam + 1);
        }
        else
        {
            for(i = 0; i < 7; i++)
          {
             if ((uttara_padam[0] == mridu_vyanjanam1[i]) || (uttara_padam[0] == mridu_vyanjanam2[i]) || uttara_padam[0] == mridu_vyanjanam3)
            {
                possible = 1 ;
                strcpy(samasta_padam, poorva_padam);
                samasta_padam[poorva_pada_len - 2] = 'o';
                samasta_padam[poorva_pada_len - 1] = ' ';
                strcat(samasta_padam, uttara_padam);
                break;
            }
          }
        }
    }
    return possible;
}

int checkVisargaLopaSandhi1(char * poorva_padam, char * uttara_padam, char *samasta_padam)
{
    int i, possible = 0;
    char hrasva_svara = 'a';
    if (poorva_padam[poorva_pada_len - 2] == 'a' && ifPresent(svaras, 13, uttara_padam[0]) && uttara_padam[0] != hrasva_svara)
        {
            strcpy(samasta_padam, poorva_padam);
            samasta_padam[poorva_pada_len - 1] = ' ';
            strcat(samasta_padam, uttara_padam);
            possible = 1;
        }

    return possible;
}

int checkVisargaLopaSandhi2(char * poorva_padam, char * uttara_padam, char *samasta_padam)
{
    int i, possible = 0;
    int present =0 ; //to check for vowels and soft consonents
    char hrasva_svara[7] = {'i', 'u', 'q', 'L', 'a','e','o'};
    char dheerga_svara[7] = {'I', 'U', 'Q', 'L', 'A','E','O'};
    char mridu_vyanjanam1[7] = {'g', 'j', 'd', 'x', 'b', 'f', 'n'};
    char mridu_vyanjanam2[7] = {'G', 'J', 'D', 'X', 'B', 'F', 'N'};
    char mridu_vyanjanam3 = 'm';
    if ((poorva_padam[poorva_pada_len - 2] == 'A'))
    {
        for(i = 0; i < 7; i++)
        {
            if((uttara_padam[0] == hrasva_svara[i]) || (uttara_padam[0] == dheerga_svara[i]) || (uttara_padam[0] == mridu_vyanjanam1[i]) || (uttara_padam[0] == mridu_vyanjanam2[i]) || (uttara_padam[0] == mridu_vyanjanam3))
             {
                possible = 1 ;
                strcpy(samasta_padam, poorva_padam);
                samasta_padam[poorva_pada_len - 1] = ' ';
                strcat(samasta_padam, uttara_padam);
                break;
             }
        }

    }
    return possible;
}

int checkVisargaLopaSandhi3(char * poorva_padam, char * uttara_padam, char * samasta_padam)
{
    int i, possible = 0;
    char hrasva_svara[7] = {'i', 'u', 'q', 'L', 'a','e','o'};
    char dheerga_svara[7] = {'I', 'U', 'Q', 'L', 'A','E','O'};

    for (i = 0; i < 7; i++)
    {
        if ((poorva_padam[poorva_pada_len - 2] == hrasva_svara[i]) || (poorva_padam[poorva_pada_len - 2] == dheerga_svara[i]))
        {
            if ( uttara_padam[0] == 'r' )
            {
                possible = 1;
                strcpy(samasta_padam, poorva_padam);
                samasta_padam[poorva_pada_len - 2] = dheerga_svara[i];
                samasta_padam[poorva_pada_len - 1] = ' ';
                strcat(samasta_padam, uttara_padam);
            }
            break;
        }
    }
    return possible;
}

int checkVisargaLopaSandhi4(char * poorva_padam, char * uttara_padam, char *samasta_padam)
{
    int i, possible = 0;
    char hrasva_svara[6] = {'i', 'u', 'q', 'L', 'e', 'o'};
    char dheerga_svara[6] = {'I', 'U', 'Q', 'A', 'E', 'O'};
    if (strcmp(poorva_padam, "saH") == 0 || strcmp(poorva_padam, "eRaH") == 0)
    {
        for (i = 0; i < 5; i++)
        {
            if (ifPresent(vargiya_vyanjanas[i], 5, uttara_padam[0]) )
            {
                possible = 1;
                break;
            }
        }

        if (possible != 1)
        {
            for(i = 0; i < 6; i++)
            {
                if ((uttara_padam[0] == hrasva_svara[i]) || (uttara_padam[0] == dheerga_svara[i]))
                {
                    possible = 1 ;
                    break;
                }
            }
        }

        if( possible == 1)
        {
            strcpy(samasta_padam, poorva_padam);
            samasta_padam[poorva_pada_len - 1] = ' ';
            strcat(samasta_padam, uttara_padam);
        }
    }

    return possible;
}

int checkRefadeshaVisargaSandhi(char * poorva_padam, char *uttara_padam, char * samasta_padam)
{
    int possible = 0;
    char hrasva_svara[7] = {'i', 'u', 'q', 'L', 'e', 'o', 'a'};
    char dheerga_svara[7] = {'I', 'U', 'Q', 'L', 'E', 'O', 'A'};
    char mridu_vyanjanam1[9] = {'g', 'j', 'd', 'x', 'b', 'f', 'n', 'y', 'l'};
    char mridu_vyanjanam2[9] = {'G', 'J', 'D', 'X', 'B', 'F', 'N', 'm', 'v'};

    if (ifPresent(hrasva_svara, 7, poorva_padam[poorva_pada_len - 2]) || ifPresent(dheerga_svara, 7, poorva_padam[poorva_pada_len - 2]))
    {
        if (ifPresent(hrasva_svara, 7, uttara_padam[0]) || ifPresent(dheerga_svara, 7, uttara_padam[0]) || ifPresent(mridu_vyanjanam1, 9, uttara_padam[0]) || ifPresent(mridu_vyanjanam2, 9, uttara_padam[0]))
        {
            strcpy(samasta_padam, poorva_padam);
            samasta_padam[poorva_pada_len - 1] = 'r';
            strcat(samasta_padam, uttara_padam);
            possible = 1;
        }
    }

    return possible;
}

int checkSakaradeshaVisargaSandhi(char * poorva_padam, char *uttara_padam, char * samasta_padam)
{
    int possible=0, i;
    char hrasva_svara[7] = {'i', 'u', 'q', 'L','e','o','a'};
    char dheerga_svara[7] = {'I', 'U', 'Q', 'A','E','O','A'};
    char karkasha_vyanjanam[3][3] = {'c', 'C', 'S', 't', 'T', 'R', 'w', 'W', 's'};
    char replace_with[3] = {'S', 'R', 's'};

    if (ifPresent(hrasva_svara, 7, poorva_padam[poorva_pada_len - 2]) || ifPresent(dheerga_svara, 7, poorva_padam[poorva_pada_len - 2]))
    {
        for(i = 0; i < 3; i++)
        {
            if (ifPresent(karkasha_vyanjanam[i], 3, uttara_padam[0]))
            {
                possible = 1;
                strcpy(samasta_padam, poorva_padam);
                samasta_padam[poorva_pada_len - 1] = replace_with[i];
                strcat(samasta_padam, uttara_padam);
                break;
            }
        }
    }

    return possible;
}


