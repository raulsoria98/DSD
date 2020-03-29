require_relative 'lib/thrift.rb'

require_relative 'calculadora.rb'
require_relative 'calculadora_types.rb'

class CalculatorHandler
  def initialize()
    @log = {}
  end

  def ping()
    puts "ping()"
  end

  def sumar(n1, n2)
    print "sumando ", n1, " con ", n2, "\n"
    return n1 + n2
  end

  def restar(n1, n2)
    print "restando ", n1, " con ", n2, "\n"
    return n1 - n2
  end

  def multiplicar(n1, n2)
    print "multiplicando ", n1, " con ", n2, "\n"
    return n1 * n2
  end

  def dividir(n1, n2)
    print "dividiendo ", n1, " con ", n2, "\n"
    return n1 / n2
  end

  def escalar2d(v1, v2)
    print "haciendo producto escalar de ", v1, " con ", v2, "\n"
    return (v1.x * v2.x) + (v1.y * v2.y)
  end

  def vectorial2d(v1, v2)
    print "haciendo producto vectorial de ", v1, " con ", v2, "\n"
    return (v1.x * v2.y) - (v1.y * v2.x)
  end

  def escalar3d(v1, v2)
    print "haciendo producto escalar de ", v1, " con ", v2, "\n"
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z)
  end

  def vectorial3d(v1, v2)
    print "haciendo producto vectorial de ", v1, " con ", v2, "\n"
    result = Vect3D.new

    result.x = (v1.y * v2.z) - (v1.z * v2.y)
    result.y = (v1.z * v2.x) - (v1.x * v2.z)
    result.z = (v1.x * v2.y) - (v1.y * v2.x)

    return result
  end

end

handler = CalculatorHandler.new()
processor = Calculadora::Processor.new(handler)
transport = Thrift::ServerSocket.new(9090)
transportFactory = Thrift::BufferedTransportFactory.new()
server = Thrift::SimpleServer.new(processor, transport, transportFactory)

puts "Starting the server..."
server.serve()
puts "done."