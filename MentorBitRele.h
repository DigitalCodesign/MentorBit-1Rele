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

#ifndef MentorBitRele_h
#define MentorBitRele_h

#include <Arduino.h>
#include <MentorPort.h>

class MentorBitRele : public MentorPort {

    public: 

        MentorBitRele(uint8_t pin = 0);

        void configPort(const Port& port) override;

        void activarRele();
        void desactivarRele();
        void conmutar();
        bool estaActivo() const;

    private:

        Port _port;
        bool _estado_actual;

};

#endif