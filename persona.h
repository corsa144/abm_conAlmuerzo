typedef struct{
    char apellido[31];
    char nombre[31];
    int edad;
    int isEmpty;
    int legajo;
}ePersona;

void alta( ePersona pers[], int cantidad );

void mostrarUno( ePersona per );

void mostrarTodos( ePersona pers[], int cantidad );

void baja(ePersona pers[], int cantidad);

void modificacion (ePersona pers[], int cantidad);

char getChar(char mensaje[]);

int getInt(char mensaje[]);

float getFloat(char mensaje[]);

char* getString(char mensaje[]);
