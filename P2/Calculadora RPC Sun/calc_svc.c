/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

static double *
_sumar_1 (sumar_1_argument *argp, struct svc_req *rqstp)
{
	return (sumar_1_svc(argp->arg1, argp->arg2, rqstp));
}

static double *
_restar_1 (restar_1_argument *argp, struct svc_req *rqstp)
{
	return (restar_1_svc(argp->arg1, argp->arg2, rqstp));
}

static double *
_multiplicar_1 (multiplicar_1_argument *argp, struct svc_req *rqstp)
{
	return (multiplicar_1_svc(argp->arg1, argp->arg2, rqstp));
}

static double *
_dividir_1 (dividir_1_argument *argp, struct svc_req *rqstp)
{
	return (dividir_1_svc(argp->arg1, argp->arg2, rqstp));
}

static double *
_escalar2d_1 (escalar2d_1_argument *argp, struct svc_req *rqstp)
{
	return (escalar2d_1_svc(argp->arg1, argp->arg2, rqstp));
}

static double *
_vectorial2d_1 (vectorial2d_1_argument *argp, struct svc_req *rqstp)
{
	return (vectorial2d_1_svc(argp->arg1, argp->arg2, rqstp));
}

static double *
_escalar3d_1 (escalar3d_1_argument *argp, struct svc_req *rqstp)
{
	return (escalar3d_1_svc(argp->arg1, argp->arg2, rqstp));
}

static vect3D *
_vectorial3d_1 (vectorial3d_1_argument *argp, struct svc_req *rqstp)
{
	return (vectorial3d_1_svc(argp->arg1, argp->arg2, rqstp));
}

static void
calcprog_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		sumar_1_argument sumar_1_arg;
		restar_1_argument restar_1_arg;
		multiplicar_1_argument multiplicar_1_arg;
		dividir_1_argument dividir_1_arg;
		escalar2d_1_argument escalar2d_1_arg;
		vectorial2d_1_argument vectorial2d_1_arg;
		escalar3d_1_argument escalar3d_1_arg;
		vectorial3d_1_argument vectorial3d_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case sumar:
		_xdr_argument = (xdrproc_t) xdr_sumar_1_argument;
		_xdr_result = (xdrproc_t) xdr_double;
		local = (char *(*)(char *, struct svc_req *)) _sumar_1;
		break;

	case restar:
		_xdr_argument = (xdrproc_t) xdr_restar_1_argument;
		_xdr_result = (xdrproc_t) xdr_double;
		local = (char *(*)(char *, struct svc_req *)) _restar_1;
		break;

	case multiplicar:
		_xdr_argument = (xdrproc_t) xdr_multiplicar_1_argument;
		_xdr_result = (xdrproc_t) xdr_double;
		local = (char *(*)(char *, struct svc_req *)) _multiplicar_1;
		break;

	case dividir:
		_xdr_argument = (xdrproc_t) xdr_dividir_1_argument;
		_xdr_result = (xdrproc_t) xdr_double;
		local = (char *(*)(char *, struct svc_req *)) _dividir_1;
		break;

	case escalar2D:
		_xdr_argument = (xdrproc_t) xdr_escalar2d_1_argument;
		_xdr_result = (xdrproc_t) xdr_double;
		local = (char *(*)(char *, struct svc_req *)) _escalar2d_1;
		break;

	case vectorial2D:
		_xdr_argument = (xdrproc_t) xdr_vectorial2d_1_argument;
		_xdr_result = (xdrproc_t) xdr_double;
		local = (char *(*)(char *, struct svc_req *)) _vectorial2d_1;
		break;

	case escalar3D:
		_xdr_argument = (xdrproc_t) xdr_escalar3d_1_argument;
		_xdr_result = (xdrproc_t) xdr_double;
		local = (char *(*)(char *, struct svc_req *)) _escalar3d_1;
		break;

	case vectorial3D:
		_xdr_argument = (xdrproc_t) xdr_vectorial3d_1_argument;
		_xdr_result = (xdrproc_t) xdr_vect3D;
		local = (char *(*)(char *, struct svc_req *)) _vectorial3d_1;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

int
main (int argc, char **argv)
{
	register SVCXPRT *transp;

	pmap_unset (CALCPROG, CALCVER);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, CALCPROG, CALCVER, calcprog_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (CALCPROG, CALCVER, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, CALCPROG, CALCVER, calcprog_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (CALCPROG, CALCVER, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}
