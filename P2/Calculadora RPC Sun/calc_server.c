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

double *
escalar2d_1_svc(vect2D arg1, vect2D arg2,  struct svc_req *rqstp)
{
	static double  result;

	result = (arg1.x * arg2.x) + (arg1.y * arg2.y);

	return &result;
}

double *
vectorial2d_1_svc(vect2D arg1, vect2D arg2,  struct svc_req *rqstp)
{
	static double  result;

	result = (arg1.x * arg2.y) - (arg1.y * arg2.x);

	return &result;
}

double *
escalar3d_1_svc(vect3D arg1, vect3D arg2,  struct svc_req *rqstp)
{
	static double  result;

	result = (arg1.x * arg2.x) + (arg1.y * arg2.y) + (arg1.z * arg2.z);

	return &result;
}

vect3D *
vectorial3d_1_svc(vect3D arg1, vect3D arg2,  struct svc_req *rqstp)
{
	static vect3D  result;

	result.x = (arg1.y * arg2.z) - (arg1.z * arg2.y);
	result.y = (arg1.z * arg2.x) - (arg1.x * arg2.z);
	result.z = (arg1.x * arg2.y) - (arg1.y * arg2.x);

	return &result;
}
