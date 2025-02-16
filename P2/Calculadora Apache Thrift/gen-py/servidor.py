import glob
import sys

from calculadora import Calculadora
from calculadora.ttypes import *
# Lo de ttypes es si hubieramos añadido tipos en el fichero.thirft

# hay que instalar antes el paquete thrift de python
# (no confundir con el compilador thrift)
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol
from thrift.server import TServer

import logging

logging.basicConfig(level=logging.DEBUG)


# Esto es para imprimir cuando haya errores en el servidor y poder depurar

class CalculadoraHandler:
    def __init__(self):
        self.log = {}

    def ping(self):
        print('Me han hecho ping()')

    def sumar(self, n1, n2):
        print('sumando ' + str(n1) + ' con ' + str(n2))
        return n1 + n2

    def restar(self, n1, n2):
        print('restando ' + str(n1) + ' con ' + str(n2))
        return n1 - n2

    def multiplicar(self, n1, n2):
        print('multiplicando ' + str(n1) + ' con ' + str(n2))
        return n1 * n2

    def dividir(self, n1, n2):
        print('dividiendo ' + str(n1) + ' con ' + str(n2))
        return n1 / n2

    def escalar2d(self, v1, v2):
        print(f'haciendo producto escalar de {v1} con {v2}')
        return (v1.x * v2.x) + (v1.y * v2.y)

    def vectorial2d(self, v1, v2):
        print(f'haciendo producto escalar de {v1} con {v2}')
        return (v1.x * v2.y) - (v1.y * v2.x)

    def escalar3d(self, v1, v2):
        print(f'haciendo producto escalar de {v1} con {v2}')
        return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z)

    def vectorial3d(self, v1, v2):
        print(f'haciendo producto escalar de {v1} con {v2}')
        result = vect3D()
        result.x = (v1.y * v2.z) - (v1.z * v2.y)
        result.y = (v1.z * v2.x) - (v1.x * v2.z)
        result.z = (v1.x * v2.y) - (v1.y * v2.x)
        return result


if __name__ == '__main__':
    handler = CalculadoraHandler()
    processor = Calculadora.Processor(handler)
    transport = TSocket.TServerSocket(host='localhost', port=9090)
    tfactory = TTransport.TBufferedTransportFactory()
    pfactory = TBinaryProtocol.TBinaryProtocolFactory()

    server = TServer.TSimpleServer(processor, transport, tfactory, pfactory)

    print('Iniciando servidor...')
    server.serve()
    print('done')
