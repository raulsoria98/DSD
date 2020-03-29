from calculadora import Calculadora

from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol

from argparse import ArgumentParser
parser = ArgumentParser()
parser.add_argument('n_1', help = 'primer numero', type = int)
parser.add_argument('operator', help = 'operador')
parser.add_argument('n_2', help = 'segundo numero', type = int)
args = parser.parse_args()

transport = TSocket.TSocket('localhost', 9090)
transport = TTransport.TBufferedTransport(transport)
protocol = TBinaryProtocol.TBinaryProtocol(transport)

# creamos el cliente
client = Calculadora.Client(protocol)

transport.open()

print('Hacemos ping al server')
client.ping()

resultado = client.suma(1, 1)
print('1+1 = ' + str(resultado))

resultado = client.resta(1, 1)
print('1-1 = ' + str(resultado))

transport.close()