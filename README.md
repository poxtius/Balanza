# Programas para calibración de balanzas con controlador HX711

Visitar las siguientes páginas donde he sacado la información más relevante:

[Web](https://www.prometec.net/balanza-con-celula-de-carga/) BALANZA CON CÉLULA DE CARGA

[Web](https://www.prometec.net/balanza-hx711-programa-final/) BALANZA HX711


Para usar el sigueinte código hay que tener en cuenta que tiene dos programas por lo que hay que quitar los comentarios a la parte que se quiera utilizar y comentar la que no se quieras usar. 

```
/// Esta zona del codigo hace una medición con nuestra escala ajustada 
/// y con la bascula con tara para que nos reste el peso de la plataforma que le ponemos encima 
///como soporte para las cosas a pesar.

void setup() {
  Serial.begin(57600);
  balanza.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  delay(250);
  balanza.set_scale(-1050);
  balanza.tare(10);
 
}

void loop() {

  if (balanza.is_ready()) {
    long reading = balanza.get_units(10);
    //Serial.print("HX711 reading: ");
    Serial.println(reading);
  } else {
    Serial.println("HX711 not found.");
  }

  delay(1000);
  
}```

Y el otro programa sería el siguiente:

```
//Esta zona del código la usamos para conseguir los valores que luego vamos a usar para luego calcular la escala.

void setup() {
  Serial.begin(57600);
  balanza.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
}

void loop() {

  if (balanza.is_ready()) {
    long reading = balanza.read();
    //Serial.print("HX711 reading: ");
    Serial.println(reading);
  } else {
    Serial.println("HX711 not found.");
  }

  delay(1000);
  
} ```