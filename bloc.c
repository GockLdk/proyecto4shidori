#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int crea ()
{
	FILE *archivo;
	char buffercito[100];
	char nom[25];
	printf("Dame el nombre de tu nuevo archivo\nDebe llevar al final .txt\n");
	scanf(" %[^\n]s",nom);

	archivo = fopen (nom,"w");

	if (!archivo)
	{
		system("clear");
		printf("Error al abrir el archivo \n");
		sleep(2);
		return 1;
	}

	system("clear");
	printf("Reglas:\n1.-Maximo 100 caracteres por renglon (luego presionar enter)\n2.-Para finalizar la edicion en el ultimo renglon escribir COMMIT (luego presiona enter)\n");
	sleep(3);
	printf("Ya puedes empezar a escribir...\n");

	while(strcmp(buffercito,"COMMIT")!=0)
	{
		scanf(" %[^\n]s",buffercito);
		fprintf(archivo, "%s\n",buffercito);
	}

	fclose(archivo);	
	system("clear");
	printf("Archivo creado exitosamente! \n");
	sleep(3);
	system("clear");	
return 0;
}

int abrir()
{
	FILE *archivo;
	char buffercito[100];
	char nom[25];

	printf("Cual es el nombre del archivo que desea abrir?\n");
	scanf(" %[^\n]s",nom);
	archivo = fopen(nom,"r");

	if (!archivo)
	{
		system("clear");
		printf("No existe el archivo \n");
		sleep(2);
		return 1;
	}

	system("clear");
	printf("Su archivo contiene....\n");
	sleep (2);
	printf("********************************************************************************\n");
	while (!feof(archivo))
	{
		fscanf(archivo," %[^\n]s",buffercito);
		if(feof(archivo)) break;
		printf("%s\n", buffercito);
	}
	printf("********************************************************************************\n\n");

	printf("Presione Enter para continuar...\n");
	getchar();
	getchar();
	system("clear");
return 0;	
}

int escribir ()
{
	FILE *archivo;
	char buffercito[100];
	char nom[25];

	printf("Cual es el nombre del archivo que usar abrir?\n");
	scanf(" %[^\n]s",nom);
	archivo = fopen(nom,"r+t");

	if (!archivo)
	{
		system("clear");
		printf("No existe el archivo \n");
		sleep(2);
		system("clear");
		return 1;
	}

	system("clear");
	printf("Su archivo contiene....\n");
	sleep (2);
	printf("********************************************************************************\n");
	while (!feof(archivo))
	{
		fscanf(archivo," %[^\n]s",buffercito);
		if(feof(archivo)) break;
		printf("%s\n", buffercito);
	}
	printf("********************************************************************************\n\n");

	printf("Presione Enter para continuar...\n");
	getchar();
	getchar();
	system("clear");
	printf("Reglas:\n1.-Maximo 100 caracteres por renglon (luego presionar enter)\n2.-Para finalizar la edicion en el ultimo renglon escribir COMMIT (luego presiona enter)\n");
	sleep(3);
	printf("Ya puedes empezar a escribir...\n");

	scanf(" %[^\n]s",buffercito);
	fprintf(archivo, "%s\n",buffercito);
	while(strcmp(buffercito,"COMMIT")!=0)
	{
		scanf(" %[^\n]s",buffercito);
		fprintf(archivo, "%s\n",buffercito);
	}

	fclose(archivo);	
	system("clear");
	printf("Archivo modificado exitosamente! \n");
	sleep(3);
	system("clear");	
return 0;
}

int main()
{
	int opc=0;
	
	system("clear");
	while (opc != 4)
	{
		printf("***BLOC DE NOTAS COOKIE***\n");
		printf("Menu\n 1)Crear un archivo\n 2)Escribir en un archivo\n 3)Abrir un archivo\n 4)Salir\nElige el numero la opcion a desear: ");
		scanf ("%d",&opc);

		switch (opc)
		{
			case 1:
			system("clear");
			crea();	
			break;

			case 2:
			system("clear");
			escribir();
			break;

			case 3:
			system("clear");
			abrir();
			break;

			case 4:
			system("clear");
			printf("Vuelva pronto :)\n");
			sleep(2);
			break;

			default:
			system("clear");
			printf("Opcion no valida\n");
			sleep(2);
			break;
		}
	}
return 0;
}