# Servidor de Donaciones

Se intenta simular un servidor de donaciones con dos réplicas. Los clientes pueden registrarse e identificarse. Para no sobrecargar una réplica se balancean los registros.

Los clientes una vez identificados pueden donar o consultar la información de las donaciones.

---

## Instrucciones para ejecutar

Para ejecutar las réplicas se ejecutarán los siguientes comandos:

```ssh
$ java -cp . -Djava.rmi.server.codebase=file:./ -Djava.rmi.server.hostname=localhost -Djava.security.policy=server.policy Replica1

$ java -cp . -Djava.rmi.server.codebase=file:./ -Djava.rmi.server.hostname=localhost -Djava.security.policy=server.policy Replica2
```

Para ejecutar el cliente:

```ssh
$ java -cp . -Djava.rmi.server.codebase=file:./ -Djava.rmi.server.hostname=localhost -Djava.security.policy=server.policy Ejemplo
```