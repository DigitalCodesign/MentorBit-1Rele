/*


            ██████╗    ██╗    ██████╗    ██╗   ████████╗    █████╗    ██╗               
            ██╔══██╗   ██║   ██╔════╝    ██║   ╚══██╔══╝   ██╔══██╗   ██║               
            ██║  ██║   ██║   ██║  ███╗   ██║      ██║      ███████║   ██║               
            ██║  ██║   ██║   ██║   ██║   ██║      ██║      ██╔══██║   ██║               
            ██████╔╝   ██║   ╚██████╔╝   ██║      ██║      ██║  ██║   ███████╗          
            ╚═════╝    ╚═╝    ╚═════╝    ╚═╝      ╚═╝      ╚═╝  ╚═╝   ╚══════╝          
                                                                                        
     ██████╗    ██████╗    ██████╗    ███████╗   ███████╗   ██╗    ██████╗    ███╗   ██╗
    ██╔════╝   ██╔═══██╗   ██╔══██╗   ██╔════╝   ██╔════╝   ██║   ██╔════╝    ████╗  ██║
    ██║        ██║   ██║   ██║  ██║   █████╗     ███████╗   ██║   ██║  ███╗   ██╔██╗ ██║
    ██║        ██║   ██║   ██║  ██║   ██╔══╝     ╚════██║   ██║   ██║   ██║   ██║╚██╗██║
    ╚██████╗   ╚██████╔╝   ██████╔╝   ███████╗   ███████║   ██║   ╚██████╔╝   ██║ ╚████║
     ╚═════╝    ╚═════╝    ╚═════╝    ╚══════╝   ╚══════╝   ╚═╝    ╚═════╝    ╚═╝  ╚═══╝ 
        

    @author Digital Codesign
    @version 1.1.0
    @date Fecha de creación: Septiembre de 2024
    @date Fecha de versión: Mayo de 2026
    @see Repositorio: https://github.com/DigitalCodesign/MentorBit-1Rele
    * @brief Descripción: 
        Esta librería está específicamente diseñada para ser utilizada junto con 
        el módulo MentorBit Relé de un canal. Se ha optimizado para garantizar 
        una configuración de hardware segura (iniciando siempre en estado apagado) 
        y se han añadido métodos de control de estado interno.
    * @details Métodos principales:
        - MentorBitRele   -> Constructor de la clase.
        - activarRele     -> Activa la bobina del relé, permitiendo el paso de corriente.
        - desactivarRele  -> Apaga la bobina del relé, cortando el paso de corriente.
    * Métodos extendidos y de control (Quality of Life):
        - conmutar        -> Invierte el estado actual del relé (de encendido a apagado y viceversa).
        - estaActivo      -> Permite consultar si el relé está encendido sin tener que leer el hardware.

*/

#include <MentorBitRele.h>

/**
 * @brief Constructor de la clase MentorBitRele.
 * Asigna el pin de control y, por seguridad, asegura que el relé comience apagado.
 * @param pin Pin digital utilizado para excitar la bobina del relé (por defecto 0).
 */
MentorBitRele::MentorBitRele(uint8_t pin) : _estado_actual(false) {

    _port.gpios[1] = pin;

    if (pin) {
        pinMode(_port.gpios[1], OUTPUT);
        desactivarRele();
    }

}

/**
 * @brief Configura el puerto de hardware asociado al módulo.
 * Define internamente el pin asignado como salida (OUTPUT) para poder enviar 
 * la señal de control. Además, fuerza el estado inicial a apagado por seguridad.
 * @param port Estructura constante por referencia con la configuración del puerto.
 */
void MentorBitRele::configPort(const Port& port) {

    _port.type = port.type;
    _port.location = port.location;
    _port.gpios[0] = port.gpios[0];
    _port.gpios[1] = port.gpios[1];

    pinMode(_port.gpios[1], OUTPUT);
    desactivarRele();

}

/**
 * @brief Activa la bobina electromagnética del relé.
 * Envía una señal HIGH al pin de control, cerrando el circuito de potencia 
 * (en la configuración normalmente abierto o NO).
 */
void MentorBitRele::activarRele() {

    digitalWrite(_port.gpios[1], HIGH);
    _estado_actual = true;

}

/**
 * @brief Desactiva la bobina electromagnética del relé.
 * Envía una señal LOW al pin de control, abriendo el circuito de potencia y 
 * deteniendo el flujo de corriente.
 */
void MentorBitRele::desactivarRele() {

    digitalWrite(_port.gpios[1], LOW);
    _estado_actual = false;

}

/**
 * @brief Cambia el estado actual del relé al opuesto.
 * Si el relé está activado, lo apaga; si está apagado, lo enciende. 
 * Ideal para controlar el relé usando un único botón físico en el proyecto.
 */
void MentorBitRele::conmutar() {

    if (_estado_actual) desactivarRele();
    else activarRele();

}

/**
 * @brief Comprueba si el relé se encuentra actualmente activado.
 * Lee una variable de estado interna, por lo que es extremadamente rápido y 
 * no interfiere con las lecturas de hardware del microcontrolador.
 * @return true si el relé está encendido, false si está apagado.
 */
bool MentorBitRele::estaActivo() const {

    return _estado_actual;

}
