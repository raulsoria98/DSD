var http = require("http");
var url = require("url");
var fs = require("fs");
var path = require("path");
var socketio = require("socket.io");

var MongoClient = require('mongodb').MongoClient;
var MongoServer = require('mongodb').Server;
var mimeTypes = { "html": "text/html", "jpeg": "image/jpeg", "jpg": "image/jpeg", "png": "image/png", "js": "text/javascript", "css": "text/css", "swf": "application/x-shockwave-flash"};

var httpServer = http.createServer(
	function(request, response) {
		var uri = url.parse(request.url).pathname;
		if (uri=="/") uri = "/cliente.html";
		var fname = path.join(process.cwd(), uri);
		fs.exists(fname, function(exists) {
			if (exists) {
				fs.readFile(fname, function(err, data){
					if (!err) {
						var extension = path.extname(fname).split(".")[1];
						var mimeType = mimeTypes[extension];
						response.writeHead(200, mimeType);
						response.write(data);
						response.end();
					}
					else {
						response.writeHead(200, {"Content-Type": "text/plain"});
						response.write('Error de lectura en el fichero: '+uri);
						response.end();
					}
				});
			}
			else{
				console.log("Peticion invalida: "+uri);
				response.writeHead(200, {"Content-Type": "text/plain"});
				response.write('404 Not Found\n');
				response.end();
			}
		});
	}
);

var temperatura = 18;
var luminosidad = 40;
var persianas = 'cerradas';
var aire = 'apagado';
var MAX_TEMP = 45;
var MIN_TEMP = 5;
var MAX_LUM = 80;
var MIN_LUM = 10;

function cambiarPersianas() {
    if(persianas == 'cerradas')
        persianas = 'abiertas';
    else if(persianas == 'abiertas')
        persianas = 'cerradas';
}

function cambiarAire() {
    if(aire == 'apagado')
        aire = 'encendido';
    else if(aire == 'encendido')
        aire = 'apagado';
}

MongoClient.connect("mongodb://localhost:27017/", function(err, db) {
	httpServer.listen(8080);
	var io = socketio.listen(httpServer);

	var dbo = db.db("sistema_domotico");
	dbo.createCollection("sensores", function(err, collection){
    	io.sockets.on('connection',
		function(client) {
			client.on('poner-temperatura', function (data) {
                temperatura = data.temperatura;
                collection.insert(data, {safe:true}, function(err, result) {});
                io.sockets.emit("actualizar-temperatura", temperatura);

                if(temperatura > MAX_TEMP) {
                    io.sockets.emit("alerta-temperatura", "¡ATENCIÓN! La temperatura sobrepasa el umbral máximo");
                    
                    if(luminosidad > MAX_LUM && persianas == 'abiertas') {
                        cambiarPersianas();
                        io.sockets.emit("actualizar-persianas", persianas);
                    }
                }
                else if(temperatura < MIN_TEMP)
                    io.sockets.emit("alerta-temperatura", "¡ATENCIÓN! La temperatura está por debajo del umbral mínimo");
                else
                    io.sockets.emit("alerta-temperatura", "");
            });

            client.on('poner-luminosidad', function (data) {
                luminosidad = data.luminosidad;
                collection.insert(data, {safe:true}, function(err, result) {});
                io.sockets.emit("actualizar-luminosidad", luminosidad);

                if(luminosidad > MAX_LUM) {
                    io.sockets.emit("alerta-luminosidad", "¡ATENCIÓN! La luminosidad sobrepasa el umbral máximo");
                    
                    if(temperatura > MAX_TEMP && persianas == 'abiertas') {
                        cambiarPersianas();
                        io.sockets.emit("actualizar-persianas", persianas);
                    }
                }
                else if(luminosidad < MIN_LUM)
                    io.sockets.emit("alerta-luminosidad", "¡ATENCIÓN! La luminosidad está por debajo del umbral mínimo");
                else
                    io.sockets.emit("alerta-luminosidad", "");
            });

            client.on('cambiar-persianas', function () {
                cambiarPersianas();
                
                io.sockets.emit("actualizar-persianas", persianas);
            });

            client.on('cambiar-aire', function () {
                cambiarAire();
                
                io.sockets.emit("actualizar-aire", aire);
            });

            client.on('obtener-temperatura', function () {
                io.sockets.emit("actualizar-temperatura", temperatura);
            });

            client.on('obtener-luminosidad', function () {
                io.sockets.emit("actualizar-luminosidad", luminosidad);
            });

            client.on('obtener-persianas', function () {
                io.sockets.emit("actualizar-persianas", persianas);
            });

            client.on('obtener-aire', function () {
                io.sockets.emit("actualizar-aire", aire);
            });
		});
    });
});

console.log("Servicio domótico iniciado");