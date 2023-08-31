#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define tamano 10
/* 
  Requerimientos del proyecto
  * 1 Arreglo unidimensional
  * 1 Arreglo bidimensional
  * 1 struct
  * Apuntadores por lo menos en una funcion
  * 5 IF
  * 2 While
  * 2 DO WHILE
  * 1 SWITCH
  * 3 FOR
*/

//Funciones
void Alta();
void Mostrar();
int BuscarAlgoritmo(char *nombre, char *apellido);
void Comprar();
void Agendar();
void Buscar();


//Variables Globales
  char *carrito_n[100];
  float carrito_p[100];
  char *medicinas[10] = {"Paracetamol", "Ibuprofeno", "Omeprazol", "Amoxicilina", "Metformina", "Loratadina", "Simvastatina", "Cetirizina", "Aspirina", "Peptobismol"};
  float medicinas_p[10] = {160.80,200.99,349.99,400.00,565.02,601.01,720.20,810.10,999.89,105.05};

char *citas[2][7] = {{"22/AGO", "22/AGO", "23/AGO", "23/AGO", "24/AGO", "24/AGO", "25/AGO"},{"16:00", "17:00", "16:00", "17:00","16:00", "16:00", "17:00"}};
int tracker_ID = 0;

//Struct
struct  paciente{
int ID;
char nombre[20];
char apellido[20];
int edad;
float peso;
float estatura;    
};

typedef struct paciente paciente;

//Array de structs
paciente arrayRegistro[tamano];

int main(int argc, char *argv[]) {
  char seleccion;
  do{
  printf("          ----------------------------------------\n");
  printf("          | ¡Bienvenid@ al Hospital DON EDSON!   |\n");
  printf("          ----------------------------------------\n");
  printf("           v\n");
  printf("          ------------------------------\n");
  printf("          | Le atiende el Dr. Edson    |\n");
  printf("          ------------------------------\n");
  printf("           v\n");
  printf("          ------------------------------\n");
  printf("          |Por favor elige una opción  |\n");
  printf("          ------------------------------\n");
  printf("           v\n");
  printf("         O\n");
  printf("        /|\\\n");
  printf("         |\n");
  printf("        / \\\n");
  printf("     Dr. Edson\n\n");
  printf("          1. Dar de Alta a paciente\n");
  printf("          2. Mostrar pacientes\n");
  printf("          3. Buscar paciente\n");
  printf("          4. Comprar medicina\n");
  printf("          5. Agendar cita\n");
  printf("          6. Salir del programa\n ");  
  printf("          Seleccion: ");
  scanf(" %c", &seleccion);
  switch(seleccion){
    case '1': 
      Alta();
    break;
    case '2': 
      Mostrar();
    break;
    case '3':
      Buscar();
    break;
    case '4':
      Comprar();
    break;
    case '5':
      Agendar();
    break;
    case '6':
      printf("Gracias por preferir HOSPITAL DON EDSON, que tenga un buen dia!");
      return EXIT_SUCCESS;
    default:
    printf("Opcion invalida, favor de ingresar");
  }
  }while(seleccion !=  120);
  
  return EXIT_SUCCESS;
}

void Alta(){
  char seleccion;
  do{
  int num_pac, i = 0;  
  printf("Cuantos pacientes desea dar de alta?");
   printf("           v\n");
  printf("         O\n");
  printf("        /|\\\n");
  printf("         |\n");
  printf("        / \\\n");
  printf("     Dr. Edson\n\n");
  scanf(" %d", &num_pac);
  for(i; i<num_pac;i++){
    arrayRegistro[i].ID = tracker_ID;
    tracker_ID += 1;
    printf("Ingrese el nombre del paciente %d\n", i);
    scanf(" %s",&arrayRegistro[i].nombre[0]);
    printf("Ingrese el apellido del paciente %d\n", i);
    scanf(" %s",&arrayRegistro[i].apellido[0]);
    printf("Ingrese la edad del paciente %d\n", i);
    scanf(" %d",&arrayRegistro[i].edad);
    printf("Ingrese el peso del paciente en kg %d\n", i);
    scanf(" %f",&arrayRegistro[i].peso);
    printf("Ingrese la estatura del paciente en cm %d\n", i);
    scanf(" %f",&arrayRegistro[i].estatura);
  } 
  printf("Presione \"x\" para salir o otra tecla para continuar\n");
  scanf(" %c", &seleccion);
  }while(seleccion != 120);
  
}


void Mostrar(){
  char seleccion;
  int i = 0;
  do{ 
  for(i; i < tracker_ID; i++){
     printf("----------------------------------------\n");
     printf("Paciente ID: %d\nNombre: %s Apellido: %s \nEdad: %d anos\nPeso: %.2f kg \nEstatura: %.2f cm \n", arrayRegistro[i].ID, arrayRegistro[i].nombre, arrayRegistro[i].apellido,                arrayRegistro[i].edad, arrayRegistro[i].peso, arrayRegistro[i].estatura); 
  }
  printf("Presione \"x\" para salir o otra tecla para continuar\n");
  scanf(" %c", &seleccion);  
  }while(seleccion != 120);  
}
void Comprar(){
 int i, j, opc, x, cart_i=0;
  float total;

  printf("          ----------------------------------------\n");
  printf("          |¡Bienvenid@ a farmacia!               |\n");
  printf("          ----------------------------------------\n");
  printf("          ----------------------------------------\n");
  printf("          |Aquí podrás comprar tus medicamentos  |\n");
  printf("          ----------------------------------------\n");
  printf("          ----------------------------------------\n");
  printf("          |Por favor elige de nuestro catalogo   |\n");
  printf("          ----------------------------------------\n");
  printf("           v\n");
  printf("         O\n");
  printf("        /|\\\n");
  printf("         |\n");
  printf("        / \\\n");
  printf("     Dr. Edson\n\n");

  printf("     Nombre    |   Precio\n");
  printf("   -----------------------\n");

  for (i=0; i<10; i++){
    printf("%d  %s - $%f\n", i+1, medicinas[i], medicinas_p[i]);
  }

  do {
    printf("\n\nPor favor escriba la posición del medicamento que le gustaría comprar: ");
    scanf("%d", &opc);
    if (opc>10)
      printf("¡No existe. Por favor intente con un valor válido!\n\n");
    else {
      printf("\n------------------------------------------------------");
      printf("\n El producto *%s* se ha agregado a tu carrito ", medicinas[opc-1]);
      printf("\n------------------------------------------------------");
      printf("\n\nPara pagar presiona 1 para agregar otro producto presiona 0:  ");
      scanf("%d", &x);
      carrito_n[cart_i] = medicinas[opc-1];
      carrito_p[cart_i] = medicinas_p[opc-1];
      cart_i++;
    }
  } while(opc>10 || x!=1);

  printf(" cart i : %d\n", cart_i);
  printf("\n\nSu compra fue\n\n");
  printf("   Nombre    |   Precio\n");
  printf("  ----------------------\n");
  for (j=0; j<cart_i; j++){
    printf("%s - $%f\n", medicinas[j], medicinas_p[j]);
    total = total + medicinas_p[j];
  }
  
  printf("\n\n");
  printf("          ---------------------------\n");
  printf("          Total: $%f\n", total);
  printf("          ---------------------------\n");
  printf("          ---------------------------\n");
  printf("          |¡Gracias por su compra!     |\n");
  printf("          ---------------------------\n");
  printf("           v\n");
  printf("         O\n");
  printf("        /|\\\n");
  printf("         |\n");
  printf("        / \\\n");
  printf("     Dr. Edson\n\n");
 
}

void Agendar(){
  int i=0;
  int j=0;
  int indice;
  int opc;

  printf("          -------------------------------\n");
  printf("          |Aquí podrá ver nuestra agenda|\n");
  printf("          -------------------------------\n");
  printf("          -------------------------------\n");
  printf("          |Por favor elige una fecha    |\n");
  printf("          -------------------------------\n");
  printf("           v\n");
  printf("         O\n");
  printf("        /|\\\n");
  printf("         |\n");
  printf("        / \\\n");
  printf("     Dr. Edson\n\n");

  for (j=0; j<7; j++) {
    for (i=0; i<2; i++) {
      printf("%d - ", j+1);
      printf("| %s |", citas[i][j]);
      }
    printf("\n");
  }
  do{
    printf("\n\nPor favor escriba el número de posición de la fecha que le gustaría agendar: ");
    scanf("%d", &indice);  
    if (indice>7)
      printf("¡No existe. Por favor intente con un valor válido!\n\n");
  }while(indice>7);
  
  printf("¿Está seguro de que desea agendar el día %s a las %s? \n", citas[0][indice-1],citas[1][indice-1]);
  printf("1 para Si\n");
  printf("0 para No\n");
  scanf("%d", &opc);

  if (opc == 1) {
    printf("          --------------------------------------\n");
    printf("          |¡Su cita ha sido agendada con éxito!|\n");
    printf("          --------------------------------------\n");
    printf("           v\n");
    printf("         O\n");
    printf("        /|\\\n");
    printf("         |\n");
    printf("        / \\\n");
    printf("     Dr. Edson\n\n");
  }
  else{
    printf("          ---------------------------\n");
    printf("          |Esta bien. Vuelva pronto.|\n");
    printf("          ---------------------------\n");
    printf("           v\n");
    printf("         O\n");
    printf("        /|\\\n");
    printf("         |\n");
    printf("        / \\\n");
    printf("     Dr. Edson\n\n");
  }
};


void Buscar(){
  char seleccion;
  do{
    int selec, ID, i, test;
    char nombre[20], apellido[20];
    printf("Presione 1 para buscar por ID, 2 para buscar por paciente.\n");
    scanf(" %d", &selec);
    switch(selec){
      case 1:
        printf("Ingrese el numero de ID del paciente\n");
        scanf(" %d", &ID);
        if( ID > tracker_ID - 1 || ID < 0){
          printf("Favor de ingresar un ID en existencia, el ID  debe de ser minimo 0,  maximo es: %d\n", tracker_ID - 1);
        }else {
        i = ID;
        printf("----------------------------------------\n");
        printf("Paciente ID: %d\nNombre: %s Apellido: %s \nEdad: %d anos\nPeso: %.2f kg \nEstatura: %.2f cm \n", arrayRegistro[i].ID, arrayRegistro[i].nombre, arrayRegistro[i].apellido,                arrayRegistro[i].edad, arrayRegistro[i].peso, arrayRegistro[i].estatura);
      }
      break;
      case 2:
        printf("Ingrese el nombre del paciente\n");
        scanf(" %s", nombre);
        printf("Ingrese el apellido del paciente\n");
        scanf(" %s", apellido);
        test = BuscarAlgoritmo(nombre,apellido);
        if(test != 1){
          printf("----------------------------------------\n");
        printf("Paciente ID: %d\nNombre: %s Apellido: %s \nEdad: %d anos\nPeso: %.2f kg \nEstatura: %.2f cm \n", arrayRegistro[test].ID, arrayRegistro[test].nombre, arrayRegistro[test].apellido,                arrayRegistro[test].edad, arrayRegistro[test].peso, arrayRegistro[test].estatura);;
        }else if(test == 1) {
          printf("No existe nigun paciente con esa combinacion de nombre y apellido, favor de checar la ortografia por errores o checar la lista de pacientes\n");
        }
      break;
      default:
        printf("Favor de ingresar una de las dos opciones!\n");
      break;
    }
  printf("Presione \"x\" para salir o otra tecla para continuar\n");
  scanf(" %c", &seleccion);   
  }while(seleccion != 120);
  
}
int BuscarAlgoritmo(char *nombre, char *apellido){
  printf("Buscando el nombre: %s , apellido: %s en la lista de pacientes\n", nombre, apellido);
  int i = 0;
    for(i; i <= tracker_ID; i++){
      if( strcmp(nombre,  arrayRegistro[i].nombre) == 0 && strcmp(apellido, arrayRegistro[i].apellido) == 0){
        return arrayRegistro[i].ID;
        break;
      }
  }
  return 1;
}