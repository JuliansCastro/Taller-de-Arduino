// the original version of this code can be found here and full disclosure - it's not mine: 
// https://github.com/kyleshockey/ghost-external-links/blob/master/ghost-external-links.js

window.jQuery || document.write("<script src='https://ajax.googleapis.com/ajax/libs/jquery/1.7.2/jquery.min.js'>\x3C/script>") || console.warn("Ghost External Links was unable to detect or add jQuery to the page.");

$(document).ready(function() {
   $("a[href^=http]").each(function(){
      var excluded = [
         // format for whitelist: 'google.com', 'apple.com', 'myawesomeblog.com'
         // add your excluded domains here
         ];
      for(i=0; i<excluded.length; i++) {
         if(this.href.indexOf(excluded[i]) != -1) {
            return true;
         }
      }
      if(this.href.indexOf(location.hostname) == -1) {
           $(this).click(function() { return true; }); 
           $(this).attr({
               target: "_blank",
               title: "Opens in a new window"
           });
           $(this).click();
      }
   })
});


# Taller básico de Arduino
Development with arduino

## Links de los ejemplos en [Tinkercad.com](https://www.tinkercad.com/)  (26/06/2020) 360h


### Módulo 1:
1. [Ejemplo 1: Blink](https://www.tinkercad.com/things/e0gzRiL9gP1-ejemplo-1-blink/editel?sharecode=ay08FT8b3fFBhm-3ZH7ngA4aT5ubjjLN4JDV97BeUUA)
2. [Ejemplo 2: Comunicación serial](https://www.tinkercad.com/things/eU47CH3TLI3-ejemplo-2-comunicacion-serial/editel?sharecode=fBCT8n6m4U__5fZ2fTRpjBNXwhF_0X8F-yxu5W9QcdE)
3. [Ejemplo 3:  Control PWM](https://www.tinkercad.com/things/j7FX1q0Dqo7-ejemplo-3-control-pwm/editel?sharecode=dk92Qc-m-E6xAAS2yrwqjimdvX8OhAOwt11PyeSXr6s)
4. [Ejemplo 4: Lectura analógica](https://www.tinkercad.com/things/bWROp4ul4Of-ejemplo-4-lectura-analogica/editel?sharecode=2qX-emEPXYNpc-FOdddp5Gm9lJsV9sHpomDEY0NsS8Q)


Descargar [Scripts de Arduino](https://github.com/JuliansCastro/Arduino/blob/master/Scripts/Module%201/Module%201.zip?raw=true) del Módulo 1.

<!--
### Módulo 2:
1.
2.
3.
4.
-->