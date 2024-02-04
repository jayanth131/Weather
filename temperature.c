#include <stdio.h>
#include <string.h>
#define FILE_NAME "weather7.txt"
#define CITY_NAME_LENGHT 20
#define URL_LENGTH 200
#define FINAL_LENGTH 200

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

	FILE *FpFilelist = fopen(FILE_NAME, "r");

	fseek(FpFilelist, 0, SEEK_END);

	int size = ftell(FpFilelist);

	rewind(FpFilelist);

	char Value[size];

	fread(Value, size , 1, FpFilelist);

	char *token = (char*)strtok(Value, ":");
	int printed = 0;

	while(token != NULL)
	{
		if ( !strcmp("{\"temp\"", token))
		{
			token = strtok(NULL, ",");
			printf("\n%s Temperature %s%cC\n", CityName, token, 248);
			token = NULL;
			printed = 1;
		}
		else
			token = strtok(NULL, ":");

	}

	if ( printed == 0)
	{
		printf("Enter correct city name.\n");
	}
}