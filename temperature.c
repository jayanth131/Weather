#include <stdio.h>
#include <string.h>
#define FILE_NAME "weather(2).txt"
#define CITY_NAME_LENGHT 30
#define URL_LENGTH 250
#define FINAL_LENGTH 250

void main()
{
	char CityName[CITY_NAME_LENGHT];
	char url[URL_LENGTH];
	char final[FINAL_LENGTH];
	printf("Enter city name: ");
	scanf("%s", CityName);
	sprintf(url, "%s%s%s%s", "curl \"https://api.openweathermap.org/data/2.5/weather?q=", CityName, 
		"&appid=abe3a0f4d0b6cebfbe7393b4b4e3aa28&units=metric\">", FILE_NAME);
	system(url);

	FILE *Fp_Filelist = fopen(FILE_NAME, "r");

	fseek(Fp_Filelist, 0, SEEK_END);

	int size = ftell(Fp_Filelist);

	rewind(Fp_Filelist);

	char Value[size];

	fread(Value, size , 1, Fp_Filelist);
	fclose(Fp_Filelist) ;

	char *tokenizer = (char*)strtok(Value, ":");
	int printed = 0;

	while(tokenizer != NULL)
	{
		if ( !strcmp("{\"temp\"", tokenizer))
		{
			tokenizer = strtok(NULL, ",");
			printf("\n%s Temperature %s%cC\n", CityName, tokenizer, 248);
			tokenizer = NULL;
			printed = 1;
		}
		else
			tokenizer = strtok(NULL, ":");

	}

	if ( printed == 0)
	{
		printf("Enter correct city name.\n");
	}
}
