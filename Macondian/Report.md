# Reporte de Trabajo: Simulador Macondian

**Estudiante:** [Maria Fernanda Barboza Carnet: 23-10032]  
**Herramienta de apoyo:** Gemini 2.5 Flas (Google Ai)

---

## Introducción y Propósito
Para este proyecto del simulador Macondian, trabajé en la creación de la interfaz y en la lógica para procesar los datos que vienen de los sensores. Durante el desarrollo me apoyé en la herramienta Gemini para consultar dudas sobre TypeScript, estilos en React y el cálculo matemático de las coordenadas para la gráfica.

---

## Lo que hice en cada parte

### 1. Ajustes en la imagen (`Image.tsx`)
En la primera tarea me enfoque en que la imagen no se viera plana ni pegada a los bordes. 
* Le agregué un contenedor `div` alrededor para darle estilo de tarjeta.
* Usé propiedades CSS en línea como `borderRadius` para redondearle las esquinas y `boxShadow` para darle esa sombra alrededor.
* Con `objectFit: "contain"` me aseguré de que la imagen mantenga la proporción sin deformarse.

### 2. Procesamiento de los datos de sensores (`List.tsx`)
La señal llegaba como una lista de texto crudo con formato de par clave-valor (por ejemplo `S1:45`).
* Separé cada elemento usando `.split(":")` para obtener por un lado el nombre del sensor y por el otro su valor.
* Convertí el valor a número con `parseFloat()` para poder hacer comparaciones.
* Puse una condición sencilla: si el valor es mayor a 50 se marca como "Crítico / Alto" en la tabla, y si es menor queda como "Normal".

### 3. Creación del gráfico SVG (`Chart.tsx`)
Para la tercera parte necesitaba dibujar la gráfica con las señales sin usar librerías externas.
* Calculé las coordenadas (X, Y) mapeando cada valor de los datos a las dimensiones del contenedor SVG.
* Resté el valor Y a la altura total para que el gráfico no quedara invertido (ya que en SVG la posición 0 empieza arriba).
* Uní todos los puntos calculados y se los pasé a la etiqueta `<polyline>` para trazar la línea.

---

## Conclusiones
Completar este proyecto me ayudó a entender mejor cómo manipular cadenas de texto y transformarlas en datos visuales dentro de React. Apoyarme en la IA como tutor me sirvió para aclarar dudas de sintaxis sin perder tiempo en errores pequeños de código.