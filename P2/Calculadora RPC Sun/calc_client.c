/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calc.h"


void
calcprog_1(char *host)
{
	CLIENT *clnt;

#ifndef	DEBUG
	clnt = clnt_create (host, CALCPROG, CALCVER, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	int opcion = -1;

	double a, b;
	double *resultado;
	vect2D vectorA2, vectorB2;
	vect2D *vResultado2;

	vect3D vectorA3, vectorB3;
	vect3D *vResultado3;

	printf("\t1. Suma de numeros\n");
	printf("\t2. Resta de numeros\n");
	printf("\t3. Multiplicacion de numeros\n");
	printf("\t4. Division de numeros\n");
	printf("\t5. Escalar de vector 2D\n");
	printf("\t6. Vectorial de vector 2D\n");
	printf("\t7. Escalar de vector 3D\n");
	printf("\t8. Vectorial de vector 3D\n");
	do
	{
		printf("\nSeleccione una opcion: ");
		scanf("%d", &opcion);
	} while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5 && opcion != 6 && opcion != 7 && opcion != 8);

	switch (opcion)
	{
	case 1:
		printf("\nIntroduzca el primer numero: ");
		scanf("%lf", &a);
		printf("Introduzca el segundo numero: ");
		scanf("%lf", &b);
		resultado = sumar_1(a, b, clnt);
		if (resultado == (double *) NULL) {
			clnt_perror (clnt, "call failed");
		}
		printf("\nOperacion: %g + %g = %g\n", a, b, *resultado);
		break;

	case 2:
		printf("\nIntroduzca el primer numero: ");
		scanf("%lf", &a);
		printf("Introduzca el segundo numero: ");
		scanf("%lf", &b);
		resultado = restar_1(a, b, clnt);
		if (resultado == (double *) NULL) {
			clnt_perror (clnt, "call failed");
		}
		printf("\nOperacion: %g - %g = %g\n", a, b, *resultado);
		break;
	
	case 3:
		printf("\nIntroduzca el primer numero: ");
		scanf("%lf", &a);
		printf("Introduzca el segundo numero: ");
		scanf("%lf", &b);
		resultado = multiplicar_1(a, b, clnt);
		if (resultado == (double *) NULL) {
			clnt_perror (clnt, "call failed");
		}
		printf("\nOperacion: %g * %g = %g\n", a, b, *resultado);
		break;

	case 4:
		printf("\nIntroduzca el primer numero: ");
		scanf("%lf", &a);
		printf("Introduzca el segundo numero: ");
		scanf("%lf", &b);
		resultado = dividir_1(a, b, clnt);
		if (resultado == (double *) NULL) {
			clnt_perror (clnt, "call failed");
		}
		printf("\nOperacion: %g / %g = %g\n", a, b, *resultado);
		break;

	case 5:
		printf("\nIntroduzca el primer numero del primer vector: ");
		scanf("%lf", &vectorA2.x);
		printf("Introduzca el segundo numero del primer vector: ");
		scanf("%lf", &vectorA2.y);
		printf("\nIntroduzca el primer numero del segundo vector: ");
		scanf("%lf", &vectorB2.x);
		printf("Introduzca el segundo numero del segundo vector: ");
		scanf("%lf", &vectorB2.y);
		resultado = escalar2d_1(vectorA2, vectorB2, clnt);
		if (resultado == (double *) NULL) {
			clnt_perror (clnt, "call failed");
		}
		printf("\nOperacion: <%g,%g> * <%g,%g> = %g\n", vectorA2.x, vectorA2.y, vectorB2.x, vectorB2.y, *resultado);
		break;
	
	case 6:
		printf("\nIntroduzca el primer numero del primer vector: ");
		scanf("%lf", &vectorA2.x);
		printf("Introduzca el segundo numero del primer vector: ");
		scanf("%lf", &vectorA2.y);
		printf("\nIntroduzca el primer numero del segundo vector: ");
		scanf("%lf", &vectorB2.x);
		printf("Introduzca el segundo numero del segundo vector: ");
		scanf("%lf", &vectorB2.y);
		resultado = vectorial2d_1(vectorA2, vectorB2, clnt);
		if (resultado == (double *) NULL) {
			clnt_perror (clnt, "call failed");
		}
		printf("\nOperacion: <%g,%g> x <%g,%g> = %gk\n", vectorA2.x, vectorA2.y, vectorB2.x, vectorB2.y, *resultado);
		break;
	
	case 7:
		printf("\nIntroduzca el primer numero del primer vector: ");
		scanf("%lf", &vectorA3.x);
		printf("Introduzca el segundo numero del primer vector: ");
		scanf("%lf", &vectorA3.y);
		printf("Introduzca el tercer numero del primer vector: ");
		scanf("%lf", &vectorA3.z);
		printf("\nIntroduzca el primer numero del segundo vector: ");
		scanf("%lf", &vectorB3.x);
		printf("Introduzca el segundo numero del segundo vector: ");
		scanf("%lf", &vectorB3.y);
		printf("Introduzca el tercer numero del segundo vector: ");
		scanf("%lf", &vectorB3.z);
		resultado = escalar3d_1(vectorA3, vectorB3, clnt);
		if (resultado == (double *) NULL) {
			clnt_perror (clnt, "call failed");
		}
		printf("\nOperacion: <%g,%g,%g> * <%g,%g,%g> = %g\n", vectorA3.x, vectorA3.y, vectorA3.z, vectorB3.x, vectorB3.y, vectorB3.z, *resultado);
		break;
	
	case 8:
		printf("\nIntroduzca el primer numero del primer vector: ");
		scanf("%lf", &vectorA3.x);
		printf("Introduzca el segundo numero del primer vector: ");
		scanf("%lf", &vectorA3.y);
		printf("Introduzca el tercer numero del primer vector: ");
		scanf("%lf", &vectorA3.z);
		printf("\nIntroduzca el primer numero del segundo vector: ");
		scanf("%lf", &vectorB3.x);
		printf("Introduzca el segundo numero del segundo vector: ");
		scanf("%lf", &vectorB3.y);
		printf("Introduzca el tercer numero del segundo vector: ");
		scanf("%lf", &vectorB3.z);
		vResultado3 = vectorial3d_1(vectorA3, vectorB3, clnt);
		if (vResultado3 == (vect3D *) NULL) {
			clnt_perror (clnt, "call failed");
		}
		printf("\nOperacion: <%g,%g,%g> x <%g,%g,%g> = %gi %gj %gk\n", vectorA3.x, vectorA3.y, vectorA3.z, vectorB3.x, vectorB3.y, vectorB3.z, (*vResultado3).x, (*vResultado3).y, (*vResultado3).z);
		break;
	
	default:
		break;
	}
	
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	calcprog_1 (host);
exit (0);
}
