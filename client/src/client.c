#include "client.h"
#include <readline/readline.h>
int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger; // esto es una variable que apunta a una estructura t_log
	t_config* config; // lo mismo con la config

	/* ---------------- LOGGING ---------------- */
	
	logger = iniciar_logger();// esta funcion inicia el logger (basicamente crea la estructura de logger con todos los datos y cuando termina la funcion
								//devuelve la direccion de memoria del logger y se la asigna a logger que es lo que usamos para manejar la estructura)
	
	
	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"

	log_info(logger,"hola soy un log \n");

	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */

	config = iniciar_config();



	// Usando el config creado previamente, leemos los valores del config y los 
	// dejamos en las variables 'ip', 'puerto' y 'valor'

	ip = config_get_string_value (config, "IP");
	puerto = config_get_string_value (config, "PUERTO");
	valor = config_get_string_value (config, "CLAVE");

	// Loggeamos el valor de config

	log_info(logger, valor );
	log_info(logger, "ademas recibi estos valores del archivo config que son:\nIP=%s y el PUERTO=%s",ip,puerto);

	/* ---------------- LEER DE CONSOLA ---------------- */

	leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);

	// Enviamos al servidor el valor de CLAVE como mensaje

	// Armamos y enviamos el paquete
	paquete(conexion);

	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
}

t_log* iniciar_logger(void)
{
	t_log* nuevo_logger = log_create ("Cliente.log" , "CLient_log" , true , LOG_LEVEL_INFO);

	if (nuevo_logger == NULL) {
    abort();
}

	return nuevo_logger;
}

t_config* iniciar_config(void)
{
	t_config* nuevo_config = config_create ("cliente.config");

	if (nuevo_config == NULL) {
    abort();
}

	return nuevo_config;
}

void leer_consola(t_log* logger)
{
	char* leido;

	// La primera te la dejo de yapa
	
	log_info(logger,"Ahora leo y loggeo desde la consola: ");

	// El resto, las vamos leyendo y logueando hasta recibir un string vacío

	while(*leido != '\0')
	{		
		leido = readline("> ");
		log_info(logger, leido);
	}

	// ¡No te olvides de liberar las lineas antes de regresar!

	free(leido);

}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config) 
	  con las funciones de las commons y del TP mencionadas en el enunciado */

	  log_destroy(logger);
	  config_destroy(config);
}
