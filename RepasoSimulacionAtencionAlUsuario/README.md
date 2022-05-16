# Simulación Atención al usuario
  Programa que simula el proceso de antención al usuario de una universidad. 
  El usuario al ingresar saca un ticket para ser atendido, de los cuales se genera una cola (se inserta al último), generándose un numero correlativo. 
  Dentro de la cola pueden existir hasta tres tipos de usuarios: Padres(P), Docentes(D), Alumno(A).
  
## Funcionalidades
1. Implementación de la clase “Usuario” (nombre, apellido, código, nro ticket, tipo de Usuario)
2. Implementación la clase “Cola” con Templates y debe tener como máximo de 100 usuarios.
3. Implementación del método “insertarAlFinal”, La inserción de usuarios se debería realizar al final de la lista, con generación del número de ticket correlativo.
4. Implementación del método “atenderPorTipoUsuario”, eliminándose el usuario de la lista, al inicio.
5. Implementación del método “atender”, eliminándose el usuario de la lista, al inicio.
6. Implementación de un método “obtenerNroAtenciones”, que permita devolver el número de atenciones por cada tipo de usuario.
7. Implementación de un método “mostrar” utilizando recursividad.
8. Generar un menú de atención:
      - Inserción de usuario por teclado a la cola, creación del objeto usuario dinámicamente.
      - Atender por orden de llegada y por tipo usuario, eligiéndose tipo de usuario que se desea atender en el orden que llegan.
      - Atender solamente por orden de llegada.
      - Mostrar el número de atenciones por cada tipo de usuario.
      - Mostrar los nombres de usuarios y tipo en cada cola.

## Creditos
Made with ❤️ by @luceroobispo
