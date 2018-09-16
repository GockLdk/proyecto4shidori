#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
     
    int main()
    {
    FILE *fp1;
    int filas,columnas,i,j;
    int A[10][10],B[10][10],suma[10][10];
    
    system("clear");
    printf("Digite el numero de filas de las matrices (en tu archivo): ");
    scanf("%i",&filas);
    system("clear");
    printf("Digite el numero de columnas de las matrices(en tu archivo): ");
    scanf("%i",&columnas);
     
    fp1 = fopen("matrizA.txt", "r");   //Abrimos el archivo
     
    for(i=0;i<filas;i++)                               
        for(j=0;j<columnas;j++){
            fscanf(fp1, "%i", &A[i][j]);            // Guardamos el valor del primer renglon en A en la posicion i,j
    }
    fclose(fp1); // cerramos el archivo
     
    fp1 = fopen("matrizB.txt", "r");  //Abrimos el archivo

    for(i=0;i<filas;i++)                      // Guardamos el valor del primer renglon en B en la posicion i,j
        for(j=0;j<columnas;j++){
            fscanf(fp1, "%i", &B[i][j]);      
    }        
    fclose(fp1);  // cerramos el archivo

    system("clear");
    printf("Sumando...\nEspere por favor :) \n");
    sleep (3);

    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            suma[i][j] = A[i][j] + B[i][j]; //sumamos posicion por posicion y se guarda en suma
        }
    }

    fp1 = fopen("matrizR.txt", "w");  //Abrimos y creamos el archivo

    for(i=0;i<filas;i++)                             

        for(j=0;j<columnas;j++){
            fprintf(fp1, "%i \n", suma[i][j]);      //Guardamos suma posicion por posicion en el archivo
    }
    fclose(fp1);  // cerramos el archivo

    system("clear");
    printf("Matriz Resultante:\n");

    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            printf("%i ",suma[i][j]);
        }
    }
    
    sleep(4);
    printf("\nListo! :3\nYa esta su matriz resultante en el archivo 'matrizR.txt'\n");
    return 0;
    }