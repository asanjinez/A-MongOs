/*
 * log.c
 *
 *  Created on: 5 may. 2021
 *      Author: utnso
 */

#include <log.h>

t_log* iniciar_logger(char* logger_path)
{
	t_log *logger;
	if((logger = log_create(logger_path, "cliente", 0, LOG_LEVEL_INFO)) == NULL)
	{
		printf(" No pude leer el logger\n");
		exit(1);
	}
	return logger;
}
