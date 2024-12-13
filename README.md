

# MentorBit Rele

## Descripción

Esta librería está específicamente diseñada para ser utilizada junto con el módulo **MentorBit Rele de un canal**.

El módulo **MentorBit Rele** permite controlar un rele de un solo canal, activando o desactivando su bobina mediante los métodos proporcionados.

## Modo de Empleo

Una vez que tengas la librería instalada desde el Arduino IDE, inclúyela en tu proyecto con la siguiente línea:

```cpp
#include <MentorBitRele.h>
```

### Constructor

Una vez incluida la librería, usamos el constructor para crear el objeto del módulo de rele, y definir el pin al que está conectado el rele:

```cpp
MentorBitRele rele(PIN_RELE);
```

Donde `PIN_RELE` es el pin al que está conectado el rele.

### Métodos Principales

#### `activarRele()`

Activa la bobina del rele (enciende el rele).

```cpp
rele.activarRele();
```

#### `desactivarRele()`

Desactiva la bobina del rele (apaga el rele).

```cpp
rele.desactivarRele();
```

#### `configPort(const Port& port)`

Configura el puerto del rele y los pines de la placa.

```cpp
Port port;
port.gpios[0] = 7;  // Pin de salida conectado al rele
rele.configPort(port);
```

##### Parámetros

- `port`: Estructura que contiene información sobre el tipo de puerto, ubicación y pines a utilizar.
