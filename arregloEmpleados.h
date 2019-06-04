
typedef struct{
int id;
char nombre[51];
char apellido [51];
float sueldo;
int sector;
int isEmpty;
}eEmpleados;




/**
 * \brief Harcodea los autores y los libros
 * \param autores es el array del tipo estructura eAutores
 * \param tamAut es el tamaño del array autores
 * \param libros es el array del tipo estructura eLibros
 * \param tamLib es el tamaño de libros
 *
 **/
void inicializarEmpleados (eEmpleados lista[], int tam);

/**
 * \brief Harcodea los autores y los libros
 * \param autores es el array del tipo estructura eAutores
 * \param tamAut es el tamaño del array autores
 * \param libros es el array del tipo estructura eLibros
 *
 **/
void mostrarEmpleado (eEmpleados lista[], int ind);

/**
 * \brief Imprime los datos del empleado
 * \param toma la estructura empleados
 * \param el indice del array que desea imprimir
 *
 **/
int buscarVacio (eEmpleados lista[], int tam);


/**
 * \brief Pide y valida los datos de la estructura socios
 * \param socios es el array del tipo estructura eSocios
 * \param tamSoc es el tamaño de socios para recorrerlo
 * \param contId es el contador para el id autoincremental
 * \return devuelve el valor del contador
 **/
int altaEmpleados (eEmpleados lista [], int tam, int contId);

/**
 * \brief Busca empleado con un indice
 * \param array de empleados
 * \param tamaño del array empleados
 * \param id del legajo que se quiere buscar
 *
 **/

int buscarEmpleado (eEmpleados lista[], int tam, int idIndicado);


 /**
 * \brief modifica los datos del empleado
 * \param array de empleados
 * \param tamaño del array
 *
 **/

void modificarEmpleados (eEmpleados lista[], int tam);

 /**
 * \brief baja un empleado de manera logica
 * \param array de empleados
 * \param tamaño del array
 *
 **/
void bajaEmpelado (eEmpleados lista[], int tam);

  /**
 * \brief mostrar empleados
 * \param array de empleados
 * \param tamaño del array
 *
 **/
void mostrarEmpleados(eEmpleados lista[], int tam);

  /**
 * \brief Ordena el array teniendo en cuenta el apellido y despues el sector
 * \param array de empleados a ordenar
 * \param tamaño del array
 *
 **/
void ordenarPorApellido (eEmpleados lista[], int tam);

/**
 * \brief imprime el total y promedio de salario mensual
 * \param array de empleados  del cual desea calcular el total y promedio
 * \param tamaño del array de empleados
 * \param devuelve el promedio de los empleados
 **/

float promedioSalarios (eEmpleados lista [], int tam);
  /**
 * \brief muestra la cantidad de empleados que superan el promedio mensual de sueldo
 * \param array de empleados
 * \param tamaño del array
 *
 **/

void bienPagos (eEmpleados lista [], int tam);

