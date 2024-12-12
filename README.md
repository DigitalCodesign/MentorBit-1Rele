# MentorBit Rele

## Descripción

Esta librería está específicamente diseñada para ser utilizada junto con el módulo **MentorBit Rele de un canal**.

El módulo **MentorBit Rele** permite controlar un rele de un solo canal, activando o desactivando su bobina mediante los métodos proporcionados.

Puedes encontrar este Módulo MentorBit y mucho más material de electrónica y robótica en nuestra tienda oficial:  [https://digitalcodesign.com/shop](https://digitalcodesign.com/shop)

## Métodos Principales

- `MentorBitRele` → Constructor de la clase, permite configurar el pin de conexión del módulo de rele.
- `activarRele` → Activa la bobina del rele (enciende el rele).
- `desactivarRele` → Desactiva la bobina del rele (apaga el rele).

## Constructor

```cpp
MentorBitRele miModuloRele(pin);
```

Donde "pin" es el número del puerto donde está conectado el Módulo de Relé de un canal para controlarlo.

### Métodos

### `void activarRele()`

Activa la bobina del rele.

### `void desactivarRele()`

Desactiva la bobina del rele.
