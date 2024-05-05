Algoritmo IDEAM
	Definir Usuario Como L�gico
	Definir contrasena Como L�gico
	Dimensionar arreglod(cantidad)
	Repetir
		Escribir '1. Iniciar sesi�n'
		Escribir '2. Registrarse'
		Escribir '3. Salir'
		Escribir 'Seleccione una opci�n: '
		Leer OPCION
		Leer datos_meteorologicos
		Seg�n OPCION Hacer
	1:
		Escribir 'Ingrese su nombre de usuario: '
		Leer Usuario
		Escribir 'Ingrese su contrase�a: '
		Leer contrasena
		Si Usuario=areglo Y contrasena=arreglo Entonces
			Escribir 'Inicio de sesi�n exitoso.'
			// acceder al men� posteriormente
		SiNo
			Escribir 'Nombre de usuario o contrase�a incorrectos.'
		FinSi
	2:
		Escribir 'Ingrese un nombre de usuario: '
		Leer Usuario
		Escribir 'Ingrese una contrase�a: '
		Leer contrasena
		Escribir 'Usuario registrado exitosamente.'
	3:
		Escribir 'Saliendo del programa...'
FinSeg�n
Hasta Que OPCION=3
Definir lapsotiempo, a, b, x Como Entero
Definir a, j Como Entero
Definir prom Como Real
Escribir 'ingrese el lapso de tiempo'
Leer lapsotiempo
Dimensionar arreglo(lapsotiempo)
Para i<-0 Hasta lapsotiempo Con Paso 1 Hacer
	arreglo[i] <- datos_meteorologicos
FinPara
x <- 1
Mientras x<=lapsotiempo Hacer
	Si x==1 Entonces
		a <- datos_meteorologicos
		b <- datos_meteorologicos
	SiNo
		Si datos_meteorologicos>a Entonces
			a <- datos_meteorologicos
		SiNo
			Si datos_meteorologicos<b Entonces
				b <- datos_meteorologicos
			FinSi
		FinSi
	FinSi
	x <- x+1
FinMientras
Escribir 'la temperatura maxima es: ', a
Escribir 'la temperatura minima es: ', b
Dimensionar a(mes)
Para j<-0 Hasta lapsotiempo Con Paso 1 Hacer
	a[j] <- temperatura_mes
FinPara
prom <- 0
Para j<-0 Hasta mes-1 Con Paso 1 Hacer
	prom <- prom+a[j]
FinPara
prom <- prom/mes
Escribir 'El promedio de las temperaturas es: ', prom
// 5. Calcular el promedio de humedad en relaci�n con una condici�n meteorol�gica dada, determinando con qu� condici�n se presenta el mayor porcentaje de humedad en un mes.
Definir nublado Como L�gico
Definir soleado Como L�gico
Leer datos_meteorologicos
Definir humedad Como Real
Definir sumaHumedadNublado Como Real
Definir sumaHumedadSoleado Como Real
Definir cantidadDatos Como Entero
Definir contadorDatosNublado Como Entero
Definir contadorDatosSoleado Como Entero
Definir promedioHumedadNublado Como Real
Definir promedioHumedadSoleado Como Real
sumaHumedadNublado <- 0
sumaHumedadSoleado <- 0
contadorDatos <- 0 // Inicializar la suma de humedad para d�as nublados
contadorDatosNublado <- 0 // Inicializar la suma de humedad para d�as soleados
contadorDatosSoleado <- 0 // Inicializar el contador de datos
// Leer los datos y calcular la suma de humedad seg�n el tipo de d�a
Mientras contadorDatos<cantidadDatos Hacer // Inicializar el contador de datos nublados
	Si nublado Entonces // Inicializar el contador de datas soleados 
		Leer humedad
		Leer nublado
		sumaHumedadNublado <- sumaHumedadNublado+humedad
		contadorDatosNublado <- contadorDatosNublado+1
	SiNo
		Leer humedad
		sumaHumedadSoleado <- sumaHumedadSoleado+humedad
		contadorDatosSoleado <- contadorDatosSoleado+1
	FinSi
	contadorDatos <- contadorDatos+1
FinMientras
promedioHumedadNublado <- sumaHumedadNublado/contadorDatosNublado // Incrementar el contador de datos
promedioHumedadSoleado <- sumaHumedadSoleado/contadorDatosSoleado
Si promedioHumedadNublado<promedioHumedadSoleado Entonces
	Escribir 'Promedio de humedad', promedioHumedadSoleado, ' % ', 'soleado'
SiNo
	Escribir 'Promedio de humedad', promedioHumedadNublado, ' % ', 'nublado'
FinSi

//6. Calcular el promedio de humedad en relaci�n con una condici�n meteorol�gica dada, determinando con qu� condici�n se presenta el menor porcentaje de humedad en un mes.
Si promedioHumedadNublado>promedioHumedadSoleado Entonces
	Escribir 'Promedio de humedad', promedioHumedadSoleado, ' % ', 'soleado'
SiNo
	Escribir 'Promedio de humedad', promedioHumedadNublado, ' % ', 'nublado'
FinSi
// 7. Calcular la probabilidad de incendio, teniendo en cuenta la temperatura, velocidad del viento y la condici�n meteorol�gica:
// a. Si la temperatura es mayor a 35 grados Celsius y la condici�n meteorol�gica es soleada con una velocidad del viento entre 7 y 10 kil�metros por hora, entonces hay una alta probabilidad de incendio.
// b. Si la velocidad del viento est� entre 3 y 5 kil�metros por hora y la temperatura est� entre 25 y 35 grados Celsius, entonces se considera que la temperatura es ligeramente alta y existe una probabilidad de incendio.
// c. Si la velocidad del viento es menor a 2 kil�metros por hora y la temperatura est� entre 20 y 15 grados Celsius, entonces se considera que la temperatura es normal y no hay probabilidad de incendio.
Definir velocidadDelViento Como Entero
Definir temperatura Como Entero
Definir condicionMeterologica Como Cadena
Escribir 'Ingrese los datos meteorol�gicos:'
Leer velocidadDelViento
Leer temperatura
Leer condicionMeterologica
Si temperatura>35 Y condicionMeterologica='soleado' Y velocidadDelViento>=7 Y velocidadDelViento<=10 Entonces
	Escribir 'Probabilidad de Incendio: ALTA'
	Escribir 'Velocidad del viento: ', velocidadDelViento, ' Km/h'
	Escribir 'Temperatura: ', temperatura, ' �C'
SiNo
	Si velocidadDelViento>=3 Y velocidadDelViento<=5 Y temperatura>=25 Y temperatura<=35 Entonces
		Escribir 'Probabilidad de Incendio: Existente'
		Escribir 'Velocidad del viento: ', velocidadDelViento, ' Km/h'
		Escribir 'Temperatura: ', temperatura, ' �C'
	SiNo
		Si velocidadDelViento<2 Y temperatura>=15 Y temperatura<=20 Entonces
			Escribir 'Probabilidad de Incendio: Inexistente'
			Escribir 'Velocidad del viento: ', velocidadDelViento, ' Km/h'
			Escribir 'Temperatura: ', temperatura, ' �C'
		FinSi
	FinSi
FinSi
Definir presion, humedad, condicion_meteorologica Como Entero
Definir resultado Como Cadena
Definir Lluvioso Como Logico
Leer datos_meteorologicos
Escribir 'Ingrese la presi�n atmosf�rica (en hPa):'
Leer presion
Escribir 'Ingrese la humedad (%):'
Leer humedad
Escribir 'Ingrese la condici�n meteorol�gica (1 para lluviosa, 0 para no lluviosa):'
Leer condicion_meteorologica
Si presion>1010 Y humedad>70 Y condicion_meteorologica=Lluvioso Entonces
	resultado <- 'Alta probabilidad de tormenta.'
SiNo
	Si presion<1010 Y humedad>70 Y condicion_meteorologica=Lluvioso Entonces
		resultado <- 'Alta probabilidad de lluvia fuerte.'
	SiNo
		resultado <- 'No se cumple ninguna condici�n para prever tormenta o lluvia fuerte.'
	FinSi
FinSi
Escribir datos_meteorologicos, 'Presi�n atmosf�rica: ', presion, ' hPa'
Escribir datos_meteorologicos, 'Humedad: ', humedad, '%'
Si condicion_meteorologica=LLuvioso Entonces
	Escribir datos_meteorologicos, 'Condici�n meteorol�gica: Lluviosa'
SiNo
	Escribir datos_meteorologicos, 'Condici�n meteorol�gica: No lluviosa'
FinSi
Escribir datos_meteorologicos, 'Resultado: ', resultado
Escribir 'Los datos y el resultado han sido guardados en el archivo.'
FinAlgoritmo