# Proyecto de LED y Buzzer con Sensor Capacitivo

Este proyecto está diseñado para funcionar con un **sensor capacitivo**, un **LED** y un **buzzer** en un microcontrolador **Arduino**. Cuando se detecta un toque en el sensor capacitivo, el sistema enciende un LED y reproduce una melodía, simulando un efecto de Halloween. Al finalizar la melodía, el LED se apaga y el sistema espera 2 segundos antes de permitir otro toque.

## Características

- **Sensor capacitivo**: El sensor capacitivo detecta toques en un pin específico, permitiendo activar la funcionalidad del LED y el buzzer.
- **LED**: Un LED se enciende cuando el sensor detecta un toque y se apaga después de que se reproduce la melodía.
- **Buzzer**: Reproduce una melodía de Halloween cada vez que se detecta un toque en el sensor capacitivo.
- **Reactividad**: El sistema espera 2 segundos después de cada interacción antes de permitir que se active nuevamente.

## Componentes necesarios

- **Arduino (compatible con ESP32)**.
- **Sensor capacitivo**.
- **LED**.
- **Buzzer**.
- **Cables de conexión**.

## Conexiones

- **Sensor capacitivo** conectado al **pin 32** del Arduino (D32).
- **LED** conectado al **pin 23** del Arduino.
- **Buzzer** conectado al **pin 5** del Arduino.

## Funcionamiento del código

1. **Inicialización**: 
   - Se configura el sensor capacitivo en el pin 32 (TOUCH_PIN).
   - Se configura el LED en el pin 23 (LED_PIN).
   - Se configura el buzzer en el pin 5 (buzzerPin) y se ajusta la resolución del timer para controlar el buzzer.

2. **Detección de toque**:
   - El sensor capacitivo lee el valor del pin 32. Si el valor es menor que 30 (lo que indica un toque), se activa el LED y se reproduce una melodía.

3
