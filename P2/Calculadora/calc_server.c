/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calc.h"

double *
sumar_1_svc(double arg1, double arg2,  struct svc_req *rqstp)
{
	static double  result;

	result = arg1 + arg2;

	return &result;
}

double *
restar_1_svc(double arg1, double arg2,  struct svc_req *rqstp)
{
	static double  result;

	result = arg1 - arg2;

	return &result;
}

double *
multiplicar_1_svc(double arg1, double arg2,  struct svc_req *rqstp)
{
	static double  result;

	result = arg1 * arg2;

	return &result;
}

double *
dividir_1_svc(double arg1, double arg2,  struct svc_req *rqstp)
{
	static double  result;

	result = arg1 / arg2;

	return &result;
}