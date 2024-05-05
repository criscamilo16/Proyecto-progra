Algoritmo IDEAM
	Definir Usuario Como Lógico
	Definir contrasena Como Lógico
	Dimensionar arreglod(cantidad)
	Repetir
		Escribir '1. Iniciar sesión'
		Escribir '2. Registrarse'
		Escribir '3. Salir'
		Escribir 'Seleccione una opción: '
		Leer OPCION
		Leer datos_meteorologicos
		Según OPCION Hacer
			1:
				Escribir 'Ingrese su nombre de usuario: '
				Leer Usuario
				Escribir 'Ingrese su contraseña: '
				Leer contrasena
				Si Usuario=areglo Y contrasena=arreglo Entonces
					Escribir 'Inicio de sesión exitoso.'
					// acceder al menú posteriormente
				SiNo
					Escribir 'Nombre de usuario o contraseña incorrectos.'
				FinSi
			2:
				Escribir 'Ingrese un nombre de usuario: '
				Leer Usuario
				Escribir 'Ingrese una contraseña: '
				Leer contrasena
				Escribir 'Usuario registrado exitosamente.'
			3:
				Escribir 'Saliendo del programa...'
		FinSegún
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
	// 5. Calcular el promedio de humedad en relación con una condición meteorológica dada, determinando con qué condición se presenta el mayor porcentaje de humedad en un mes.
	Definir nublado Como Lógico
	Definir soleado Como Lógico
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
	contadorDatos <- 0 // Inicializar la suma de humedad para días nublados
	contadorDatosNublado <- 0 // Inicializar la suma de humedad para días soleados
	contadorDatosSoleado <- 0 // Inicializar el contador de datos
	// Leer los datos y calcular la suma de humedad según el tipo de día
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
	
	//6. Calcular el promedio de humedad en relación con una condición meteorológica dada, determinando con qué condición se presenta el menor porcentaje de humedad en un mes.
	Si promedioHumedadNublado>promedioHumedadSoleado Entonces
		Escribir 'Promedio de humedad', promedioHumedadSoleado, ' % ', 'soleado'
	SiNo
		Escribir 'Promedio de humedad', promedioHumedadNublado, ' % ', 'nublado'
	FinSi
	// 7. Calcular la probabilidad de incendio, teniendo en cuenta la temperatura, velocidad del viento y la condición meteorológica:
	// a. Si la temperatura es mayor a 35 grados Celsius y la condición meteorológica es soleada con una velocidad del viento entre 7 y 10 kilómetros por hora, entonces hay una alta probabilidad de incendio.
	// b. Si la velocidad del viento está entre 3 y 5 kilómetros por hora y la temperatura está entre 25 y 35 grados Celsius, entonces se considera que la temperatura es ligeramente alta y existe una probabilidad de incendio.
	// c. Si la velocidad del viento es menor a 2 kilómetros por hora y la temperatura está entre 20 y 15 grados Celsius, entonces se considera que la temperatura es normal y no hay probabilidad de incendio.
	Definir velocidadDelViento Como Entero
	Definir temperatura Como Entero
	Definir condicionMeterologica Como Cadena
	Escribir 'Ingrese los datos meteorológicos:'
	Leer velocidadDelViento
	Leer temperatura
	Leer condicionMeterologica
	Si temperatura>35 Y condicionMeterologica='soleado' Y velocidadDelViento>=7 Y velocidadDelViento<=10 Entonces
		Escribir 'Probabilidad de Incendio: ALTA'
		Escribir 'Velocidad del viento: ', velocidadDelViento, ' Km/h'
		Escribir 'Temperatura: ', temperatura, ' ºC'
	SiNo
		Si velocidadDelViento>=3 Y velocidadDelViento<=5 Y temperatura>=25 Y temperatura<=35 Entonces
			Escribir 'Probabilidad de Incendio: Existente'
			Escribir 'Velocidad del viento: ', velocidadDelViento, ' Km/h'
			Escribir 'Temperatura: ', temperatura, ' ºC'
		SiNo
			Si velocidadDelViento<2 Y temperatura>=15 Y temperatura<=20 Entonces
				Escribir 'Probabilidad de Incendio: Inexistente'
				Escribir 'Velocidad del viento: ', velocidadDelViento, ' Km/h'
				Escribir 'Temperatura: ', temperatura, ' ºC'
			FinSi
		FinSi
	FinSi
	Definir presion, humedad, condicion_meteorologica Como Entero
	Definir resultado Como Cadena
	Definir Lluvioso Como Logico
	Leer datos_meteorologicos
	Escribir 'Ingrese la presión atmosférica (en hPa):'
	Leer presion
	Escribir 'Ingrese la humedad (%):'
	Leer humedad
	Escribir 'Ingrese la condición meteorológica (1 para lluviosa, 0 para no lluviosa):'
	Leer condicion_meteorologica
	Si presion>1010 Y humedad>70 Y condicion_meteorologica=Lluvioso Entonces
		resultado <- 'Alta probabilidad de tormenta.'
	SiNo
		Si presion<1010 Y humedad>70 Y condicion_meteorologica=Lluvioso Entonces
			resultado <- 'Alta probabilidad de lluvia fuerte.'
		SiNo
			resultado <- 'No se cumple ninguna condición para prever tormenta o lluvia fuerte.'
		FinSi
	FinSi
	Escribir datos_meteorologicos, 'Presión atmosférica: ', presion, ' hPa'
	Escribir datos_meteorologicos, 'Humedad: ', humedad, '%'
	Si condicion_meteorologica=LLuvioso Entonces
		Escribir datos_meteorologicos, 'Condición meteorológica: Lluviosa'
	SiNo
		Escribir datos_meteorologicos, 'Condición meteorológica: No lluviosa'
	FinSi
	Escribir datos_meteorologicos, 'Resultado: ', resultado
	Escribir 'Los datos y el resultado han sido guardados en el archivo.'
FinAlgoritmo
