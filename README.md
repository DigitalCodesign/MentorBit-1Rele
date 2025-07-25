# MentorBitRelay

Esta librería está diseñada para que puedas controlar dispositivos eléctricos de forma sencilla usando tu placa MentorBit y el **módulo de relé**.

Si estás empezando en el mundo de la electrónica, ¡no te preocupes! MentorBit está pensado para que aprender sea fácil y divertido. Esta placa ya incluye un montón de componentes (LEDs, pulsadores, pantallas, etc.) y utiliza conectores especiales (JST) para que puedas añadir nuevos sensores y módulos sin tener que pelearte con un montón de cables. Pásate por nuestra web para saber más de MentorBit y nuestros productos [pinchando aquí](https://digitalcodesign.com/).

![Render del Módulo MentorBit de Relé.](https://github.com/DigitalCodesign/MentorBit-1Rele/blob/main/assets/MentorBit_Relaymodule.png)

Con esta librería, podrás encender o apagar luces, motores, bombas o cualquier otro dispositivo eléctrico de forma remota y segura.

---

## Descripción

### ¿Qué es un módulo de relé?

Un relé es como un interruptor controlado electrónicamente. Puedes usarlo para encender o apagar dispositivos que trabajan con voltajes más altos (como 220V AC) desde tu placa MentorBit, que funciona con 5V. Esto permite que tu proyecto controle lámparas, ventiladores, electrodomésticos, y mucho más.

El módulo de relé que usamos está diseñado para funcionar de manera segura y fácil con tu placa, aislando eléctricamente la parte de control de la parte de potencia.

---

### ¿Qué hace esta librería?

La librería **MentorBit-1Rele** actúa como un "puente" entre tu programa y el módulo de relé. Con solo un par de comandos puedes encender o apagar el relé sin preocuparte por detalles técnicos como los niveles de voltaje o el tipo de señal.

Gracias a ella, podrás centrarte en lo más importante: ¡darle vida a tu proyecto!

---

### ¿Qué puedes construir con este módulo?

- Un temporizador que apague un ventilador después de cierto tiempo.
- Un sistema de riego automático que encienda una bomba de agua.
- Un sistema de seguridad que corte la energía cuando se detecte una intrusión.

Esta librería es el primer paso para integrar el control de dispositivos eléctricos en tus proyectos con MentorBit, de manera segura y profesional.

---

## Cómo empezar

Usar la librería es muy sencillo. Solo sigue estos pasos para tener tu módulo funcionando en pocos minutos.

### 1. **Conexión del Módulo**

Conecta el módulo de 1 relés a uno de los puertos JST de 4 pines de la sección de "Puertos para Módulos" en la placa MentorBit. Usa un pin digital para controlar el relé.

### 2. **Instalación de las Librerías**

Para que tu placa pueda comunicarse con el relé correctamente, solo necesitas instalar esta librería desde el gestor del IDE de Arduino:

- Abre tu entorno de programación IDE de Arduino.
- Ve al menú *Programa -> Incluir Librería -> Administrar Librerías...*
- En el buscador, escribe ***MentorBit-1Rele*** y haz clic en "Instalar".

![Ejemplo de búsqueda en el gestor de librerías del IDE de Arduino.](https://github.com/DigitalCodesign/MentorBit-1Rele/blob/main/assets/library_instalation_example.png)

¡Y listo! Ya puedes comenzar a controlar dispositivos desde tu placa.

---

## Ejemplo Básico: Encender y apagar el relé

El siguiente código enciende el relé durante un segundo y luego lo apaga durante otro segundo, repitiendo este ciclo indefinidamente.

### Copia y pega este código en tu IDE:

```cpp
// 1. Incluimos la librería que acabamos de instalar.
#include <MentorBitRele.h>

// 2. Definimos el pin al que vamos a conectar el módulo de Relé
#define PINRELE A4

// 3 Creamos el objeto rele, indicandole el pin
MentorBitRele rele(PINRELE);

void setup() {
    // Inicializamos la comunicación para depuración, si lo necesitas.
    Serial.begin(9600);

}

void loop() {
    // Encendemos el relé.
    rele.activarRele();
    Serial.println("Relé ENCENDIDO.");
    delay(1000);

    // Apagamos el relé.
    rele.desactivarRele();
    Serial.println("Relé APAGADO.");
    delay(1000);
}
```

### Para ver el resultado:

1. Carga el código en tu placa MentorBit.
2. Escucha o verifica que el relé hace "clic" cada segundo.
3. Conecta un dispositivo (siguiendo las normas de seguridad) para comprobar que se activa y desactiva con el relé.

---

## Funciones Principales

Esta librería es muy fácil de usar. Solo necesitas conocer dos funciones clave:

- <code>void activarRele()</code>  
   - **¿Qué hace?** Activa el relé (cierra el circuito).  
   - **¿Cuándo se usa?** Cada vez que quieras encender el circuito de control.

- <code>void desactivarRele()</code>  
   - **¿Qué hace?** Desactiva el relé (abre el circuito).  
   - **¿Cuándo se usa?** Cuando quieras apagar el circuito de control.

---

## Recursos Adicionales

¿Quieres saber más sobre el módulo o necesitas comprar uno? Aquí tienes algunos enlaces que te serán de utilidad:

- [Web del fabricante](https://digitalcodesign.com/)
- [Tienda Online de Canarias](https://canarias.digitalcodesign.com/shop)
- [Tienda Online de Península](https://digitalcodesign.com/shop)
- [Web Oficial de MentorBit](https://digitalcodesign.com/mentorbit)
- [Web Oficial de MentorBit módulo de relé](https://canarias.digitalcodesign.com/shop/00038812-mentorbit-modulo-rele-de-un-canal-8112?category=226&order=create_date+desc#attr=)
- [Manual de usuario del Módulo](https://drive.google.com/file/d/1lK5vpFeIYEuyuEt0PPcydhjDrGjJHMG4/view?usp=drive_link)
- [Modelo 3D de MentorBit módulo de relé en formato .STEP](https://drive.google.com/file/d/1AJDxeTkrHz8nl6D28brPWugV9nbju-jU/view?usp=drive_link)
