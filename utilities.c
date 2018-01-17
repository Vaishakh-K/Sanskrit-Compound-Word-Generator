
int ifPresent(char * set, int len, char ch)
{
	int i, present = 0;

	for (i = 0; i < len; i++)
	{
		if (set[i] == ch)
		{
			present = 1;
			break;
		}
	}
	//printf("%s %d\n", set, present);
	return present;
}

int ifSubstr(char * word, char * sub)
{
	int i;
	int present = 1;
	if (word[0] == sub[0])
	{
		for (i = 1; sub[i] != '\0'; i++)
		{
			if (sub[i] != word[i])
			{
				present = 0;
				break;
			}
		}
		return present;
	}

	else
		return 0;
}

int replacenwithN(char * word)
{
	int i;
	for (i = 0; word[i] != '\0'; i++)
	{
		if (word[i] == 'n')
			word[i] = 'N';
	}
}