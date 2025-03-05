# MentorBitRele

Librería para el control de relés con módulos compatibles con MentorBit.

## Descripción

La librería `MentorBitRele` facilita el control de módulos relé de un canal compatibles con MentorBit. Permite activar y desactivar relés de manera sencilla, ideal para proyectos de automatización, control de iluminación y más.

## Modo de Empleo

1.  **Instalación:**
    * Abre el IDE compatible con MentorBit.
    * Ve a "Herramientas" -> "Gestionar librerías..."
    * Busca "MentorBitRele" e instálala.

2.  **Ejemplo básico:**

    ```c++
    #include <MentorBitRele.h>

    MentorBitRele rele(2); // Inicializa el relé en el pin 2

    void setup() {
      rele.activarRele(); // Activa el relé
      delay(5000); // Espera 5 segundos
      rele.desactivarRele(); // Desactiva el relé
    }

    void loop() {
      // El relé se activa y desactiva una vez en el setup
    }
    ```

## Constructor y Métodos Públicos

### Constructor

* `MentorBitRele(uint8_t pin = 0)`: Crea un objeto `MentorBitRele`.
    * `pin`: Número de pin al que está conectado el módulo relé. Si no se especifica, se asume que no está conectado a ningún pin inicialmente.

### Métodos

* `void activarRele()`: Activa el relé conectado.
* `void desactivarRele()`: Desactiva el relé conectado.
