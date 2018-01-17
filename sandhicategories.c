void checkSvaraSandhi(char * poorva_padam, char * uttara_padam, char * samasta_padam)
{
	int found;
	found = checkSavarnaDheergaSandhi(poorva_padam, uttara_padam, samasta_padam);//Check for Savarna Dheerga Sandhi
	if(found != 1)
	{
		if (poorva_padam[poorva_pada_len - 1] == 'a' || poorva_padam[poorva_pada_len - 1] == 'A')//if last letter of first word is 'a' or 'A', then it may be Guna or Vriddi Sandhi
			{
				found = checkGunaSandhi(poorva_padam, uttara_padam, samasta_padam);
				if (found != 1)
				{
					found = checkVriddiSandhi(poorva_padam, uttara_padam, samasta_padam);
				}
			}
	}
	if (found != 1)
	{
		if (ifPresent(svaras, 13, uttara_padam[0]))//If first letter of second word is any vowel then it can be Yan or Ayadi Sandhi
		{
			found = checkYanSandhi(poorva_padam, uttara_padam, samasta_padam);
			if (found != 1)
			{
				found = checkAyadiSandhi(poorva_padam, uttara_padam, samasta_padam);
			}
		}
	}
	if (found != 1)
	{
		found = checkPoorvaroopaSandhi(poorva_padam, uttara_padam, samasta_padam);
	}

}


void checkVyanjanaSandhi(char * poorva_padam, char * uttara_padam, char * samasta_padam)
{
	int found = 0;

	found = checkJastvaSandhi(poorva_padam, uttara_padam, samasta_padam);
	if (found != 1)
	{
		found = checkAnunasikaSandhi(poorva_padam, uttara_padam, samasta_padam);
	}
	if (found != 1)
	{
		found = checkVyanjanaSandhin(poorva_padam, uttara_padam, samasta_padam);
	}
	if (found != 1)
	{
		found = checkSchutvaSandhi(poorva_padam, uttara_padam, samasta_padam);
	}
	if (found != 1)
	{
		found = checkShtutvaSandhi(poorva_padam, uttara_padam, samasta_padam);
	}
	if (found != 1)
	{
		found = checkVyanjanaDental(poorva_padam, uttara_padam, samasta_padam);
	}
	if (found != 1)
	{
		found = checkVyanjanaSoftToHard(poorva_padam, uttara_padam, samasta_padam);
	}
	if (found != 1)
	{
		found = checkVyanjanaSandhi1(poorva_padam, uttara_padam, samasta_padam);
	}
	if (found != 1)
	{
		found = checkVyanjanaSandhi2(poorva_padam, uttara_padam, samasta_padam);
	}
	if (found != 1)
	{
		found = checkVyanjanaSandhi3(poorva_padam, uttara_padam, samasta_padam);
	}
	if (found != 1)
	{
		found = checkVyanjanaSandhi4(poorva_padam, uttara_padam, samasta_padam);
	}
	if (found != 1)
	{
		found = checkVyanjanaSandhi5(poorva_padam, uttara_padam, samasta_padam);
	}

}


void checkVisargaSandhi(char * poorva_padam, char * uttara_padam, char * samasta_padam)
{
	int found = 0;
	found = checkNoVisargaSandhi(poorva_padam, uttara_padam, samasta_padam);
	if (found != 1)
	{
		found = checkOkaradeshaVisargaSandhi(poorva_padam, uttara_padam, samasta_padam);
	}
	if (found != 1)
	{
		found = checkVisargaLopaSandhi1(poorva_padam, uttara_padam, samasta_padam);
	}
	if (found != 1)
	{
		found = checkVisargaLopaSandhi2(poorva_padam, uttara_padam, samasta_padam);
	}
	if (found != 1)
	{
		found = checkVisargaLopaSandhi3(poorva_padam, uttara_padam, samasta_padam);
	}
	if (found != 1)
	{
		found = checkVisargaLopaSandhi4(poorva_padam, uttara_padam, samasta_padam);
	}
	if (found != 1)
	{
		found = checkRefadeshaVisargaSandhi(poorva_padam, uttara_padam, samasta_padam);
	}
	if (found != 1)
	{
		found = checkSakaradeshaVisargaSandhi(poorva_padam, uttara_padam, samasta_padam);
	}
	

}//Refadesha and Visarga Lopa same constraint but see as or ar